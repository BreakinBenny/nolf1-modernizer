// ----------------------------------------------------------------------- //
// MODULE: MuzzleFlashFX.cpp
//
// PURPOSE: MuzzleFlash special FX - Implementation
//
// CREATED: 12/17/99
//
// (c) 1999-2000 Monolith Productions, Inc.  All Rights Reserved
// ----------------------------------------------------------------------- //
#include "stdafx.h"
#include "MuzzleFlashFX.h"
#include "iltclient.h"
#include "ClientUtilities.h"
#include "iltmodel.h"
#include "ilttransform.h"
#include "iltcustomdraw.h"
#include "VarTrack.h"

VarTrack	g_vtReallyClose;

// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::Init
//
//	PURPOSE: Init the MuzzleFlash
// ----------------------------------------------------------------------- //
LTBOOL CMuzzleFlashFX::Init(HLOCALOBJ hServObj, HMESSAGEREAD hMessage)
{
	if (!CSpecialFX::Init(hServObj, hMessage)) return LTFALSE;
	if (!hMessage) return LTFALSE;

	// Don't support server-side versions of this fx...

	return LTFALSE;
}

// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::Init
//
//	PURPOSE: Init the MuzzleFlash
// ----------------------------------------------------------------------- //
LTBOOL CMuzzleFlashFX::Init(SFXCREATESTRUCT* psfxCreateStruct)
{
	if (!CSpecialFX::Init(psfxCreateStruct)) return LTFALSE;

	MUZZLEFLASHCREATESTRUCT* pMF = (MUZZLEFLASHCREATESTRUCT*)psfxCreateStruct;

	m_cs = *((MUZZLEFLASHCREATESTRUCT*)pMF);

	if (!m_cs.pWeapon) return LTFALSE;

	// Set our server object to our hParent so we get notified when
	// the hParent goes away...

	if (!m_hServerObject)
	{
		m_hServerObject = m_cs.hParent;
	}

	return LTTRUE;
}


// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::CreateObject
//
//	PURPOSE: Create fx objects
// ----------------------------------------------------------------------- //
LTBOOL CMuzzleFlashFX::CreateObject(ILTClient *pClientDE)
{
	if (!pClientDE || !CSpecialFX::CreateObject(pClientDE)) return LTFALSE;

	if (!g_vtReallyClose.IsInitted())
	{
		g_vtReallyClose.Init(pClientDE, "MFReallyClose", NULL, 1.0f);
	}

	return ResetFX();
}

// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::Setup
//
//	PURPOSE: Create fx objects
// ----------------------------------------------------------------------- //
LTBOOL CMuzzleFlashFX::Setup(MUZZLEFLASHCREATESTRUCT & cs)
{
	LTBOOL bRet = LTFALSE;

	if (!m_pClientDE)
	{
		if (Init(&cs))
		{
			bRet = CreateObject(g_pLTClient);
		}
	}
	else
	{
		bRet = Reset(cs);
	}

	return bRet;
}


// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::Reset
//
//	PURPOSE: Reset the muzzle flash
// ----------------------------------------------------------------------- //
LTBOOL CMuzzleFlashFX::Reset(MUZZLEFLASHCREATESTRUCT & cs)
{
	if (!m_pClientDE) return LTFALSE;

	m_cs = cs;

	ReallyHide();
	return ResetFX();
}

// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::ResetFX
//
//	PURPOSE: Reset all the fx...
// ----------------------------------------------------------------------- //
LTBOOL CMuzzleFlashFX::ResetFX()
{
	if (!m_pClientDE) return LTFALSE;

	m_bUsingParticles = LTFALSE;
	m_bUsingLight	 = LTFALSE;
	m_bUsingScale	 = LTFALSE;

	// Create/Reset the fx specified by the weapon...

	if (!m_cs.pWeapon) return LTFALSE;

	CMuzzleFX* pMuzzleFX = LTNULL;
	if (m_cs.bPlayerView)
	{
		pMuzzleFX = m_cs.pWeapon->pPVMuzzleFX;
	}
	else
	{
		pMuzzleFX = m_cs.pWeapon->pHHMuzzleFX;
	}

	if (!pMuzzleFX) return LTFALSE;


	// Create/Update the dynamic light...

	if (pMuzzleFX->pDLightFX)
	{
		if (m_cs.bPlayerView || GetConsoleInt("MuzzleLight", 1))
		{
			m_bUsingLight = (LTBOOL) !!(g_pFXButeMgr->CreateDLightFX(
				pMuzzleFX->pDLightFX, m_cs.vPos, &m_Light));
		}
	}


	// Create/Update the scale fx...

	if (pMuzzleFX->pScaleFX)
	{
		LTVector vU, vR, vF;
		m_pClientDE->GetRotationVectors(&(m_cs.rRot), &vU, &vR, &vF);

		m_bUsingScale = (LTBOOL) !!(g_pFXButeMgr->CreateScaleFX(pMuzzleFX->pScaleFX,
			m_cs.vPos, vF, LTNULL, &(m_cs.rRot), &m_Scale));

		// Make camera-relative if player view...

		if (m_bUsingScale && m_cs.bPlayerView)
		{
			if (m_Scale.GetObject())
			{
				uint32 dwFlags = m_pClientDE->GetObjectFlags(m_Scale.GetObject());
				m_pClientDE->SetObjectFlags(m_Scale.GetObject(), dwFlags | FLAG_REALLYCLOSE);
			}
		}
	}

	// Create/Update the particle muzzle fx...

	if (pMuzzleFX->pPMuzzleFX)
	{
		MFPCREATESTRUCT mfpcs;
		mfpcs.pPMuzzleFX	= pMuzzleFX->pPMuzzleFX;
		mfpcs.bPlayerView	= m_cs.bPlayerView;
		mfpcs.vPos		= m_cs.vPos;
		mfpcs.rRot		= m_cs.rRot;
		mfpcs.hFiredFrom	= m_cs.bPlayerView ? LTNULL : m_cs.hParent;

		if (!m_Particle.GetObject())
		{
			if (m_Particle.Init(&mfpcs))
			{
				m_Particle.CreateObject(m_pClientDE);

				// Make camera-relative if player view...

				if (m_cs.bPlayerView)
				{
					if (m_Particle.GetObject())
					{
						uint32 dwFlags = m_pClientDE->GetObjectFlags(m_Particle.GetObject());

						if (g_vtReallyClose.GetFloat())
						{
							m_pClientDE->SetObjectFlags(m_Particle.GetObject(), dwFlags | FLAG_REALLYCLOSE);
						}
						else
						{
							m_pClientDE->SetObjectFlags(m_Particle.GetObject(), dwFlags & ~FLAG_REALLYCLOSE);
						}
					}
				}
			}
		}
		else
		{
			m_Particle.Reset(mfpcs);
		}

		m_bUsingParticles = LTTRUE;
	}

	return LTTRUE;
}


// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::Update
//
//	PURPOSE: Update the fx
// ----------------------------------------------------------------------- //
LTBOOL CMuzzleFlashFX::Update()
{
	if (!m_pClientDE || m_bHidden) return LTFALSE;

	// If we we're not a player-view muzzle fx,  If our
	// server object has been removed, we should go away...

	if (!m_cs.bPlayerView && !m_hServerObject) return LTFALSE;

	// Set/Clear the FLAG_REALLYCLOSE

	if (m_bUsingParticles && m_Particle.GetObject())
	{
		uint32 dwFlags = m_pClientDE->GetObjectFlags(m_Particle.GetObject());

		if (m_cs.bPlayerView)
		{
			if (g_vtReallyClose.GetFloat())
			{
				m_pClientDE->SetObjectFlags(m_Particle.GetObject(), dwFlags | FLAG_REALLYCLOSE);
			}
			else
			{
				m_pClientDE->SetObjectFlags(m_Particle.GetObject(), dwFlags & ~FLAG_REALLYCLOSE);
			}
		}
		else
		{
			m_pClientDE->SetObjectFlags(m_Particle.GetObject(), dwFlags & ~FLAG_REALLYCLOSE);
		}
	}

	if (m_bUsingScale && m_Scale.GetObject())
	{
		uint32 dwFlags = m_pClientDE->GetObjectFlags(m_Scale.GetObject());

		if (m_cs.bPlayerView)
		{
			m_pClientDE->SetObjectFlags(m_Scale.GetObject(), dwFlags | FLAG_REALLYCLOSE);
		}
		else
		{
			m_pClientDE->SetObjectFlags(m_Scale.GetObject(), dwFlags & ~FLAG_REALLYCLOSE);
		}
	}


	// Update all the fx, and see if we're done...

	LTBOOL bParticleDone	= m_bUsingParticles	? !m_Particle.Update()	: LTTRUE;
	LTBOOL bLightDone	= m_bUsingLight	? !m_Light.Update()		: LTTRUE;
	LTBOOL bScaleDone	= m_bUsingScale	? !m_Scale.Update()		: LTTRUE;


	// Keep the objects in the correct place...

	if (!m_cs.bPlayerView && m_cs.hParent)
	{
		HOBJECT hObj;
		LTRotation rRot;
		LTVector vPos;

		GetAttachmentSocketTransform(m_cs.hParent, "Flash", vPos, rRot);

		if (m_bUsingScale)
		{
			hObj = m_Scale.GetObject();
			if (hObj)
			{
				m_pClientDE->SetObjectPos(hObj, &vPos);
				m_pClientDE->SetObjectRotation(hObj, &rRot);
			}
		}

		if (m_bUsingParticles)
		{
			hObj = m_Particle.GetObject();
			if (hObj)
			{
				m_pClientDE->SetObjectPos(hObj, &vPos);
				m_pClientDE->SetObjectRotation(hObj, &rRot);
			}
		}

		if (m_bUsingLight)
		{
			hObj = m_Light.GetObject();
			if (hObj)
			{
				m_pClientDE->SetObjectPos(hObj, &vPos);
			}
		}
	}

	return !(bParticleDone && bLightDone && bScaleDone);
}


// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::Hide
//
//	PURPOSE: Hide the fx
// ----------------------------------------------------------------------- //
void CMuzzleFlashFX::Hide()
{
	m_bHidden = LTTRUE;
	ReallyHide();
}

// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::ReallyHide
//
//	PURPOSE: Hide the fx
// ----------------------------------------------------------------------- //
void CMuzzleFlashFX::ReallyHide()
{
	if (!m_pClientDE) return;

	HOBJECT hObj;
	uint32 dwFlags;

	// Hide particles...

	hObj = m_Particle.GetObject();
	if (hObj)
	{
		dwFlags = m_pClientDE->GetObjectFlags(hObj);
		m_pClientDE->SetObjectFlags(hObj, dwFlags & ~FLAG_VISIBLE);
	}

	// Hide light...

	hObj = m_Light.GetObject();
	if (hObj)
	{
		dwFlags = m_pClientDE->GetObjectFlags(hObj);
		m_pClientDE->SetObjectFlags(hObj, dwFlags & ~FLAG_VISIBLE);
	}

	// Hide scale fx...

	hObj = m_Scale.GetObject();
	if (hObj)
	{
		dwFlags = m_pClientDE->GetObjectFlags(hObj);
		m_pClientDE->SetObjectFlags(hObj, dwFlags & ~FLAG_VISIBLE);
	}
}

// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::Show
//
//	PURPOSE: Show the fx
// ----------------------------------------------------------------------- //
void CMuzzleFlashFX::Show()
{
	if (!m_pClientDE) return;

	HOBJECT hObj;
	uint32 dwFlags;

	m_bHidden = LTFALSE;

	// Show particles...

	if (m_bUsingParticles)
	{
		hObj = m_Particle.GetObject();
		if (hObj)
		{
			dwFlags = m_pClientDE->GetObjectFlags(hObj);
			m_pClientDE->SetObjectFlags(hObj, dwFlags | FLAG_VISIBLE);
		}
	}

	// Show light...

	if (m_bUsingLight && GetConsoleInt("MuzzleLight", 1))
	{
		hObj = m_Light.GetObject();
		if (hObj)
		{
			dwFlags = m_pClientDE->GetObjectFlags(hObj);
			m_pClientDE->SetObjectFlags(hObj, dwFlags | FLAG_VISIBLE);
		}
	}

	// Show scale fx...

	if (m_bUsingScale)
	{
		hObj = m_Scale.GetObject();
		if (hObj)
		{
			dwFlags = m_pClientDE->GetObjectFlags(hObj);
			m_pClientDE->SetObjectFlags(hObj, dwFlags | FLAG_VISIBLE);
		}
	}
}

// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::SetPos
//
//	PURPOSE: Set the fx positions
// ----------------------------------------------------------------------- //
void CMuzzleFlashFX::SetPos(LTVector vWorldPos, LTVector vCamRelPos)
{
	if (!m_pClientDE) return;

	HOBJECT hObj;

	//m_pClientDE->CPrint("WorldPos: %.2f, %.2f, %.2f", VEC_EXPAND(vWorldPos));
	//m_pClientDE->CPrint("CamRelPos: %.2f, %.2f, %.2f", VEC_EXPAND(vCamRelPos));

	if (m_bUsingParticles)
	{
		hObj = m_Particle.GetObject();
		if (hObj)
		{
			if (g_vtReallyClose.GetFloat())
			{
				m_pClientDE->SetObjectPos(hObj, &vCamRelPos, LTTRUE);
			}
			else
			{
				m_pClientDE->SetObjectPos(hObj, &vWorldPos, LTTRUE);
			}
		}
	}

	if (m_bUsingLight)
	{
		hObj = m_Light.GetObject();
		if (hObj)
		{
			m_pClientDE->SetObjectPos(hObj, &vWorldPos, LTTRUE);
		}
	}

	if (m_bUsingScale)
	{
		hObj = m_Scale.GetObject();
		if (hObj)
		{
			m_pClientDE->SetObjectPos(hObj, &vCamRelPos, LTTRUE);
		}
	}
}

// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::SetRot
//
//	PURPOSE: Set the fx rotations
// ----------------------------------------------------------------------- //
void CMuzzleFlashFX::SetRot(LTRotation rRot)
{
	if (!m_pClientDE) return;

	HOBJECT hObj;

	if (m_bUsingParticles)
	{
		hObj = m_Particle.GetObject();
		if (hObj)
		{
			if (g_vtReallyClose.GetFloat())
			{
				LTRotation rInitRot;
				rInitRot.Init();
				m_pClientDE->SetObjectRotation(hObj, &rInitRot);
			}
			else
			{
				m_pClientDE->SetObjectRotation(hObj, &rRot);
			}
		}
	}

	if (m_bUsingLight)
	{
		hObj = m_Light.GetObject();
		if (hObj)
		{
			m_pClientDE->SetObjectRotation(hObj, &rRot);
		}
	}

	if (m_bUsingScale)
	{
		hObj = m_Scale.GetObject();
		if (hObj)
		{
			LTRotation rTempRot = rRot;

			// Camera relative rotation...
			if (m_cs.bPlayerView)
			{
				rTempRot.Init();
			}

			m_pClientDE->SetObjectRotation(hObj, &rTempRot);
		}
	}
}


// ----------------------------------------------------------------------- //
//	ROUTINE: CMuzzleFlashFX::Term
//
//	PURPOSE: If Term() is called on the CMuzzleFlashFX, Setup must be
//			called on the object to re-create any engine objects
//			associated with the fx.
// ----------------------------------------------------------------------- //
void CMuzzleFlashFX::Term()
{
	// Set our clientde pointer to NULL, this is how Setup knows to
	// create our sub-objects...
	m_pClientDE = LTNULL;

	// Term our sub-objects...

	m_Particle.Term();
	m_Scale.Term();
	m_Light.Term();
}