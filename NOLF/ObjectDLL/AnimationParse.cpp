
/*  A Bison parser, made from animationparse.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define yyparse yyanimationparse
#define yylex yyanimationlex
#define yyerror yyanimationerror
#define yylval yyanimationlval
#define yychar yyanimationchar
#define yydebug yyanimationdebug
#define yynerrs yyanimationnerrs
#define	ERROR_TOKEN	258
#define	PROPERTIES	259
#define	ANIMATIONS	260
#define	TRANSITIONS	261
#define	STRING	262
#define	BRACE_LEFT	263
#define	BRACE_RIGHT	264
#define	SET_ADD	265
#define	SET_REMOVE	266
#define	SET_CONSTANT	267
#define	SET_NOT	268
#define	COMMA	269

#line 2 "animationparse.y"


#include "StdAfx.h"
#include "AnimationLex.h"
#include "AnimationParser.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE

void yyerror(const char* szError);


#line 15 "animationparse.y"
typedef union 
{
	char	szString[256];
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
	{
	  int timestamp;
	  int first_line;
	  int first_column;
	  int last_line;
	  int last_column;
	  char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		60
#define	YYFLAG		-32768
#define	YYNTBASE	15

#define YYTRANSLATE(x) ((unsigned)(x) <= 269 ? yytranslate[x] : 38)

static const char yytranslate[] = {	 0,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,	 2,
	 2,	 2,	 2,	 2,	 2,	 1,	 2,	 3,	 4,	 5,
	 6,	 7,	 8,	 9,	10,	11,	12,	13,	14
};

#if YYDEBUG != 0
static const short yyprhs[] = {	 0,
	 0,	 1,	 4,	 5,	 6,	 7,	17,	20,	21,	22,
	28,	30,	33,	35,	38,	39,	40,	46,	49,	50,
	51,	73,	76,	77,	80,	81,	84,	85,	88,	89,
	92,	93,	96,	97
};

static const short yyrhs[] = {	-1,
	15,	16,	 0,	 0,	 0,	 0,	 4,	17,	20,	 5,
	18,	25,	 6,	19,	28,	 0,	21,	20,	 0,	 0,
	 0,	37,	22,	 8,	23,	 9,	 0,	24,	 0,	23,
	24,	 0,	37,	 0,	26,	25,	 0,	 0,	 0,	37,
	27,	 8,	36,	 9,	 0,	29,	28,	 0,	 0,	 0,
	37,	30,	 8,	31,	 9,	10,	 8,	32,	 9,	11,
	 8,	33,	 9,	12,	 8,	34,	 9,	13,	 8,	35,
	 9,	 0,	31,	37,	 0,	 0,	32,	37,	 0,	 0,
	33,	37,	 0,	 0,	34,	37,	 0,	 0,	35,	37,
	 0,	 0,	36,	37,	 0,	 0,	 7,	 0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
	27,	28,	32,	34,	36,	38,	41,	43,	47,	48,
	52,	53,	57,	61,	63,	67,	68,	72,	74,	78,
	79,	87,	89,	93,	95,	99,   101,   105,   107,   111,
   113,   117,   119,   123
};

static const char * const yytname[] = {   "$","error","$undefined.","ERROR_TOKEN",
"PROPERTIES","ANIMATIONS","TRANSITIONS","STRING","BRACE_LEFT","BRACE_RIGHT",
"SET_ADD","SET_REMOVE","SET_CONSTANT","SET_NOT","COMMA","input","line","@1",
"@2","@3","properties","property","@4","property_elements","property_element",
"animations","animation","@5","transitions","transition","@6","transition_current_set",
"transition_add_set","transition_remove_set","transition_constant_set","transition_not_set",
"property_set","string",""
};
#endif

static const short yyr1[] = {	 0,
	15,	15,	17,	18,	19,	16,	20,	20,	22,	21,
	23,	23,	24,	25,	25,	27,	26,	28,	28,	30,
	29,	31,	31,	32,	32,	33,	33,	34,	34,	35,
	35,	36,	36,	37
};

static const short yyr2[] = {	 0,
	 0,	 2,	 0,	 0,	 0,	 9,	 2,	 0,	 0,	 5,
	 1,	 2,	 1,	 2,	 0,	 0,	 5,	 2,	 0,	 0,
	21,	 2,	 0,	 2,	 0,	 2,	 0,	 2,	 0,	 2,
	 0,	 2,	 0,	 1
};

static const short yydefact[] = {	 1,
	 0,	 3,	 2,	 8,	34,	 0,	 8,	 9,	 4,	 7,
	 0,	15,	 0,	 0,	15,	16,	 0,	11,	13,	 5,
	14,	 0,	10,	12,	19,	33,	 6,	19,	20,	 0,
	18,	 0,	17,	32,	23,	 0,	 0,	22,	 0,	25,
	 0,	 0,	24,	 0,	27,	 0,	 0,	26,	 0,	29,
	 0,	 0,	28,	 0,	31,	 0,	21,	30,	 0,	 0
};

static const short yydefgoto[] = {	 1,
	 3,	 4,	12,	25,	 6,	 7,	11,	17,	18,	14,
	15,	22,	27,	28,	32,	36,	41,	46,	51,	56,
	30,	 8
};

static const short yypact[] = {-32768,
	 2,-32768,-32768,	-3,-32768,	 6,	-3,-32768,-32768,-32768,
	18,	-3,	-3,	21,	-3,-32768,	 0,-32768,-32768,-32768,
-32768,	20,-32768,-32768,	-3,-32768,-32768,	-3,-32768,	 1,
-32768,	22,-32768,-32768,-32768,	 5,	23,-32768,	24,-32768,
	 8,	25,-32768,	27,-32768,	12,	19,-32768,	29,-32768,
	13,	28,-32768,	30,-32768,	16,-32768,-32768,	40,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,-32768,	35,-32768,-32768,-32768,	26,	31,
-32768,-32768,	17,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   -12
};


#define	YYLAST		46


static const short yytable[] = {	16,
	19,	59,	16,	 5,	19,	 2,	 5,	 5,	23,	33,
	 9,	 5,	29,	37,	 5,	29,	42,	34,	 5,	 5,
	47,	52,	 5,	38,	57,	13,	20,	26,	43,	35,
	49,	40,	39,	48,	45,	44,	50,	55,	53,	60,
	54,	10,	24,	58,	31,	21
};

static const short yycheck[] = {	12,
	13,	 0,	15,	 7,	17,	 4,	 7,	 7,	 9,	 9,
	 5,	 7,	25,	 9,	 7,	28,	 9,	30,	 7,	 7,
	 9,	 9,	 7,	36,	 9,	 8,	 6,	 8,	41,	 8,
	12,	 8,	10,	46,	 8,	11,	 8,	 8,	51,	 0,
	13,	 7,	17,	56,	28,	15
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */

#line 3 "bison.simple"



/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.



   This program is free software; you can redistribute it and/or modify

   it under the terms of the GNU General Public License as published by

   the Free Software Foundation; either version 2, or (at your option)

   any later version.



   This program is distributed in the hope that it will be useful,

   but WITHOUT ANY WARRANTY; without even the implied warranty of

   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the

   GNU General Public License for more details.



   You should have received a copy of the GNU General Public License

   along with this program; if not, write to the Free Software

   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */



/* As a special exception, when this file is copied by Bison into a

   Bison output file, you may use that output file without restriction.

   This special exception was added by the Free Software Foundation

   in version 1.24 of Bison.  */



#ifndef alloca

#ifdef __GNUC__

#define alloca __builtin_alloca

#else /* not GNU C.  */

#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)

#include <alloca.h>

#else /* not sparc */

#if defined (MSDOS) && !defined (__TURBOC__)

#include <malloc.h>

#else /* not MSDOS, or __TURBOC__ */

#if defined(_AIX)

#include <malloc.h>

 #pragma alloca

#else /* not MSDOS, __TURBOC__, or _AIX */

#ifdef __hpux

#ifdef __cplusplus

extern "C" {

void *alloca (unsigned int);

};

#else /* not __cplusplus */

void *alloca ();

#endif /* not __cplusplus */

#endif /* __hpux */

#endif /* not _AIX */

#endif /* not MSDOS, or __TURBOC__ */

#endif /* not sparc.  */

#endif /* not GNU C.  */

#endif /* alloca not defined.  */



/* This is the parser code that is written into each bison parser

  when the %semantic_parser declaration is not specified in the grammar.

  It was written by Richard Stallman by simplifying the hairy parser

  used when %semantic_parser is specified.  */



/* Note: there must be only one dollar sign in this file.

   It is replaced by the list of actions, each action

   as one case of the switch.  */



#define yyerrok		(yyerrstatus = 0)

#define yyclearin	(yychar = YYEMPTY)

#define YYEMPTY		-2

#define YYEOF		0

#define YYACCEPT	return(0)

#define YYABORT 	return(1)

#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.

   This remains here temporarily to ease the

   transition to the new meaning of YYERROR, for GCC.

   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
	{ yychar = (token), yylval = (value);			\
	  yychar1 = YYTRANSLATE (yychar);				\
	  YYPOPSTACK;						\
	  goto yybackup;						\
	}								\
  else								\
	{ yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)



#define YYTERROR	1

#define YYERRCODE	256



#ifndef YYPURE

#define YYLEX		yylex()

#endif



#ifdef YYPURE

#ifdef YYLSP_NEEDED

#ifdef YYLEX_PARAM

#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)

#else

#define YYLEX		yylex(&yylval, &yylloc)

#endif

#else /* not YYLSP_NEEDED */

#ifdef YYLEX_PARAM

#define YYLEX		yylex(&yylval, YYLEX_PARAM)

#else

#define YYLEX		yylex(&yylval)

#endif

#endif /* not YYLSP_NEEDED */

#endif



/* If nonreentrant, generate the variables here */



#ifndef YYPURE



int	yychar;			/*  the lookahead symbol		*/

YYSTYPE	yylval;			/*  the semantic value of the		*/

				/*  lookahead symbol			*/



#ifdef YYLSP_NEEDED

YYLTYPE yylloc;			/*  location data for the lookahead	*/

				/*  symbol				*/

#endif



int yynerrs;			/*  number of parse errors so far	   */

#endif  /* not YYPURE */



#if YYDEBUG != 0

int yydebug;			/*  nonzero means print parse trace	*/

/* Since this is uninitialized, it does not stop multiple parsers

   from coexisting.  */

#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/



#ifndef	YYINITDEPTH

#define YYINITDEPTH 200

#endif



/*  YYMAXDEPTH is the maximum size the stacks can grow to

	(effective only if the built-in stack extension method is used).  */



#if YYMAXDEPTH == 0

#undef YYMAXDEPTH

#endif



#ifndef YYMAXDEPTH

#define YYMAXDEPTH 10000

#endif



/* Prevent warning if -Wstrict-prototypes.  */

#ifdef __GNUC__

int yyparse (void);

#endif



#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */

#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)

#else				/* not GNU C or C++ */

#ifndef __cplusplus



/* This is the most reliable way to avoid incompatibilities

   in available built-in functions on various systems.  */

static void

__yy_memcpy (from, to, count)

	 char *from;

	 char *to;

	 int count;

{

  register char *f = from;

  register char *t = to;

  register int i = count;



  while (i-- > 0)

	*t++ = *f++;

}



#else /* __cplusplus */



/* This is the most reliable way to avoid incompatibilities

   in available built-in functions on various systems.  */

static void

__yy_memcpy (char *from, char *to, int count)

{

  register char *f = from;

  register char *t = to;

  register int i = count;



  while (i-- > 0)

	*t++ = *f++;

}



#endif

#endif



#line 192 "bison.simple"



/* The user can define YYPARSE_PARAM as the name of an argument to be passed

   into yyparse.  The argument should have type void *.

   It should actually point to an object.

   Grammar actions can access the variable by casting it

   to the proper pointer type.  */



#ifdef YYPARSE_PARAM

#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;

#else

#define YYPARSE_PARAM

#define YYPARSE_PARAM_DECL

#endif



int

yyparse(YYPARSE_PARAM)

	 YYPARSE_PARAM_DECL

{

  register int yystate;

  register int yyn;

  register short *yyssp;

  register YYSTYPE *yyvsp;

  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */

  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */



  short	yyssa[YYINITDEPTH];	/*  the state stack			*/

  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/



  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */

  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */



#ifdef YYLSP_NEEDED

  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/

  YYLTYPE *yyls = yylsa;

  YYLTYPE *yylsp;



#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)

#else

#define YYPOPSTACK   (yyvsp--, yyssp--)

#endif



  int yystacksize = YYINITDEPTH;



#ifdef YYPURE

  int yychar;

  YYSTYPE yylval;

  int yynerrs;

#ifdef YYLSP_NEEDED

  YYLTYPE yylloc;

#endif

#endif



  YYSTYPE yyval;		/*  the variable used to return		*/

				/*  semantic values from the action	*/

				/*  routines				*/

  yyval.szString[0] = '\0';

  int yylen;



#if YYDEBUG != 0

  if (yydebug)

	fprintf(stderr, "Starting parse\n");

#endif



  yystate = 0;

  yyerrstatus = 0;

  yynerrs = 0;

  yychar = YYEMPTY;		/* Cause a token to be read.  */



  /* Initialize stack pointers.

	 Waste one element of value and location stack

	 so that they stay on the same level as the state stack.

	 The wasted elements are never initialized.  */



  yyssp = yyss - 1;

  yyvsp = yyvs;

#ifdef YYLSP_NEEDED

  yylsp = yyls;

#endif



/* Push a new state, which is found in  yystate  .  */

/* In all cases, when you get here, the value and location stacks

   have just been pushed. so pushing a state here evens the stacks.  */

yynewstate:



  *++yyssp = yystate;



  if (yyssp >= yyss + yystacksize - 1)

	{

	  /* Give user a chance to reallocate the stack */

	  /* Use copies of these so that the &'s don't force the real ones into memory. */

	  YYSTYPE *yyvs1 = yyvs;

	  short *yyss1 = yyss;

#ifdef YYLSP_NEEDED

	  YYLTYPE *yyls1 = yyls;

#endif



	  /* Get the current used size of the three stacks, in elements.  */

	  int size = yyssp - yyss + 1;



#ifdef yyoverflow

	  /* Each stack pointer address is followed by the size of

	 the data in use in that stack, in bytes.  */

#ifdef YYLSP_NEEDED

	  /* This used to be a conditional around just the two extra args,

	 but that might be undefined if yyoverflow is a macro.  */

	  yyoverflow("parser stack overflow",

		 &yyss1, size * sizeof (*yyssp),

		 &yyvs1, size * sizeof (*yyvsp),

		 &yyls1, size * sizeof (*yylsp),

		 &yystacksize);

#else

	  yyoverflow("parser stack overflow",

		 &yyss1, size * sizeof (*yyssp),

		 &yyvs1, size * sizeof (*yyvsp),

		 &yystacksize);

#endif



	  yyss = yyss1; yyvs = yyvs1;

#ifdef YYLSP_NEEDED

	  yyls = yyls1;

#endif

#else /* no yyoverflow */

	  /* Extend the stack our own way.  */

	  if (yystacksize >= YYMAXDEPTH)

	{

	  yyerror("parser stack overflow");

	  return 2;

	}

	  yystacksize *= 2;

	  if (yystacksize > YYMAXDEPTH)

	yystacksize = YYMAXDEPTH;

	  yyss = (short *) alloca (yystacksize * sizeof (*yyssp));

	  __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));

	  yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));

	  __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));

#ifdef YYLSP_NEEDED

	  yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));

	  __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));

#endif

#endif /* no yyoverflow */



	  yyssp = yyss + size - 1;

	  yyvsp = yyvs + size - 1;

#ifdef YYLSP_NEEDED

	  yylsp = yyls + size - 1;

#endif



#if YYDEBUG != 0

	  if (yydebug)

	fprintf(stderr, "Stack size increased to %d\n", yystacksize);

#endif



	  if (yyssp >= yyss + yystacksize - 1)

	YYABORT;

	}



#if YYDEBUG != 0

  if (yydebug)

	fprintf(stderr, "Entering state %d\n", yystate);

#endif



  goto yybackup;

 yybackup:



/* Do appropriate processing given the current state.  */

/* Read a lookahead token if we need one and don't already have one.  */

/* yyresume: */



  /* First try to decide what to do without reference to lookahead token.  */



  yyn = yypact[yystate];

  if (yyn == YYFLAG)

	goto yydefault;



  /* Not known => get a lookahead token if don't already have one.  */



  /* yychar is either YYEMPTY or YYEOF

	 or a valid token in external form.  */



  if (yychar == YYEMPTY)

	{

#if YYDEBUG != 0

	  if (yydebug)

	fprintf(stderr, "Reading a token: ");

#endif

	  yychar = YYLEX;

	}



  /* Convert token to internal form (in yychar1) for indexing tables with */



  if (yychar <= 0)		/* This means end of input. */

	{

	  yychar1 = 0;

	  yychar = YYEOF;		/* Don't call YYLEX any more */



#if YYDEBUG != 0

	  if (yydebug)

	fprintf(stderr, "Now at end of input.\n");

#endif

	}

  else

	{

	  yychar1 = YYTRANSLATE(yychar);



#if YYDEBUG != 0

	  if (yydebug)

	{

	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);

	  /* Give the individual parser a way to print the precise meaning

		 of a token, for further debugging info.  */

#ifdef YYPRINT

	  YYPRINT (stderr, yychar, yylval);

#endif

	  fprintf (stderr, ")\n");

	}

#endif

	}



  yyn += yychar1;

  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)

	goto yydefault;



  yyn = yytable[yyn];



  /* yyn is what to do for this token type in this state.

	 Negative => reduce, -yyn is rule number.

	 Positive => shift, yyn is new state.

	   New state is final state => don't bother to shift,

	   just return success.

	 0, or most negative number => error.  */



  if (yyn < 0)

	{

	  if (yyn == YYFLAG)

	goto yyerrlab;

	  yyn = -yyn;

	  goto yyreduce;

	}

  else if (yyn == 0)

	goto yyerrlab;



  if (yyn == YYFINAL)

	YYACCEPT;



  /* Shift the lookahead token.  */



#if YYDEBUG != 0

  if (yydebug)

	fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);

#endif



  /* Discard the token being shifted unless it is eof.  */

  if (yychar != YYEOF)

	yychar = YYEMPTY;



  *++yyvsp = yylval;

#ifdef YYLSP_NEEDED

  *++yylsp = yylloc;

#endif



  /* count tokens shifted since error; after three, turn off error status.  */

  if (yyerrstatus) yyerrstatus--;



  yystate = yyn;

  goto yynewstate;



/* Do the default action for the current state.  */

yydefault:



  yyn = yydefact[yystate];

  if (yyn == 0)

	goto yyerrlab;



/* Do a reduction.  yyn is the number of a rule to reduce with.  */

yyreduce:

  yylen = yyr2[yyn];

  if (yylen > 0)

	yyval = yyvsp[1-yylen]; /* implement default value of the action */



#if YYDEBUG != 0

  if (yydebug)

	{

	  int i;



	  fprintf (stderr, "Reducing via rule %d (line %d), ",

		   yyn, yyrline[yyn]);



	  /* Print the symbols being reduced, and their result.  */

	  for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)

	fprintf (stderr, "%s ", yytname[yyrhs[i]]);

	  fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);

	}

#endif




  switch (yyn) {

case 3:
#line 32 "animationparse.y"
{ g_pParser->BeginProperties(); ;
	break;}
case 4:
#line 34 "animationparse.y"
{ g_pParser->BeginAnimations(); ;
	break;}
case 5:
#line 36 "animationparse.y"
{ g_pParser->BeginTransitions(); ;
	break;}
case 9:
#line 47 "animationparse.y"
{ g_pParser->AddPropertyGroup(yyvsp[0].szString); ;
	break;}
case 13:
#line 57 "animationparse.y"
{ g_pParser->AddPropertyToCurrentGroup(yyvsp[0].szString); ;
	break;}
case 16:
#line 67 "animationparse.y"
{ g_pParser->AddAnimation(yyvsp[0].szString); ;
	break;}
case 20:
#line 78 "animationparse.y"
{ g_pParser->AddTransition(yyvsp[0].szString); ;
	break;}
case 22:
#line 88 "animationparse.y"
{ g_pParser->AddPropertyToCurrentTransitionInitialSet(yyvsp[0].szString); ;
	break;}
case 24:
#line 94 "animationparse.y"
{ g_pParser->AddPropertyToCurrentTransitionAddSet(yyvsp[0].szString); ;
	break;}
case 26:
#line 100 "animationparse.y"
{ g_pParser->AddPropertyToCurrentTransitionRemoveSet(yyvsp[0].szString); ;
	break;}
case 28:
#line 106 "animationparse.y"
{ g_pParser->AddPropertyToCurrentTransitionConstantSet(yyvsp[0].szString); ;
	break;}
case 30:
#line 112 "animationparse.y"
{ g_pParser->AddPropertyToCurrentTransitionNotSet(yyvsp[0].szString); ;
	break;}
case 32:
#line 118 "animationparse.y"
{ g_pParser->AddPropertyToCurrentAnimation(yyvsp[0].szString); ;
	break;}
case 34:
#line 124 "animationparse.y"
{
		;
	break;}
}
   /* the action file gets copied in in place of this dollarsign */

#line 487 "bison.simple"



  yyvsp -= yylen;

  yyssp -= yylen;

#ifdef YYLSP_NEEDED

  yylsp -= yylen;

#endif



#if YYDEBUG != 0

  if (yydebug)

	{

	  short *ssp1 = yyss - 1;

	  fprintf (stderr, "state stack now");

	  while (ssp1 != yyssp)

	fprintf (stderr, " %d", *++ssp1);

	  fprintf (stderr, "\n");

	}

#endif



  *++yyvsp = yyval;



#ifdef YYLSP_NEEDED

  yylsp++;

  if (yylen == 0)

	{

	  yylsp->first_line = yylloc.first_line;

	  yylsp->first_column = yylloc.first_column;

	  yylsp->last_line = (yylsp-1)->last_line;

	  yylsp->last_column = (yylsp-1)->last_column;

	  yylsp->text = 0;

	}

  else

	{

	  yylsp->last_line = (yylsp+yylen-1)->last_line;

	  yylsp->last_column = (yylsp+yylen-1)->last_column;

	}

#endif



  /* Now "shift" the result of the reduction.

	 Determine what state that goes to,

	 based on the state we popped back to

	 and the rule number reduced by.  */



  yyn = yyr1[yyn];



  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;

  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)

	yystate = yytable[yystate];

  else

	yystate = yydefgoto[yyn - YYNTBASE];



  goto yynewstate;



yyerrlab:   /* here on detecting error */



  if (! yyerrstatus)

	/* If not already recovering from an error, report this error.  */

	{

	  ++yynerrs;



#ifdef YYERROR_VERBOSE

	  yyn = yypact[yystate];



	  if (yyn > YYFLAG && yyn < YYLAST)

	{

	  int size = 0;

	  char *msg;

	  int x, count;



	  count = 0;

	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */

	  for (x = (yyn < 0 ? -yyn : 0);

		   x < (sizeof(yytname) / sizeof(char *)); x++)

		if (yycheck[x + yyn] == x)

		  size += strlen(yytname[x]) + 15, count++;

	  msg = (char *) malloc(size + 15);

	  if (msg != 0)

		{

		  strcpy(msg, "parse error");



		  if (count < 5)

		{

		  count = 0;

		  for (x = (yyn < 0 ? -yyn : 0);

			   x < (sizeof(yytname) / sizeof(char *)); x++)

			if (yycheck[x + yyn] == x)

			  {

			strcat(msg, count == 0 ? ", expecting `" : " or `");

			strcat(msg, yytname[x]);

			strcat(msg, "'");

			count++;

			  }

		}

		  yyerror(msg);

		  free(msg);

		}

	  else

		yyerror ("parse error; also virtual memory exceeded");

	}

	  else

#endif /* YYERROR_VERBOSE */

	yyerror("parse error");

	}



  goto yyerrlab1;

yyerrlab1:   /* here on error raised explicitly by an action */



  if (yyerrstatus == 3)

	{

	  /* if just tried and failed to reuse lookahead token after an error, discard it.  */



	  /* return failure if at end of input */

	  if (yychar == YYEOF)

	YYABORT;



#if YYDEBUG != 0

	  if (yydebug)

	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);

#endif



	  yychar = YYEMPTY;

	}



  /* Else will try to reuse lookahead token

	 after shifting the error token.  */



  yyerrstatus = 3;		/* Each real token shifted decrements this */



  goto yyerrhandle;



yyerrdefault:  /* current state does not do anything special for the error token. */



#if 0

  /* This is wrong; only states that explicitly want error tokens

	 should shift them.  */

  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/

  if (yyn) goto yydefault;

#endif



yyerrpop:   /* pop the current state because it cannot handle the error token */



  if (yyssp == yyss) YYABORT;

  yyvsp--;

  yystate = *--yyssp;

#ifdef YYLSP_NEEDED

  yylsp--;

#endif



#if YYDEBUG != 0

  if (yydebug)

	{

	  short *ssp1 = yyss - 1;

	  fprintf (stderr, "Error: state stack now");

	  while (ssp1 != yyssp)

	fprintf (stderr, " %d", *++ssp1);

	  fprintf (stderr, "\n");

	}

#endif



yyerrhandle:



  yyn = yypact[yystate];

  if (yyn == YYFLAG)

	goto yyerrdefault;



  yyn += YYTERROR;

  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)

	goto yyerrdefault;



  yyn = yytable[yyn];

  if (yyn < 0)

	{

	  if (yyn == YYFLAG)

	goto yyerrpop;

	  yyn = -yyn;

	  goto yyreduce;

	}

  else if (yyn == 0)

	goto yyerrpop;



  if (yyn == YYFINAL)

	YYACCEPT;



#if YYDEBUG != 0

  if (yydebug)

	fprintf(stderr, "Shifting error token, ");

#endif



  *++yyvsp = yylval;

#ifdef YYLSP_NEEDED

  *++yylsp = yylloc;

#endif



  yystate = yyn;

  goto yynewstate;

}

#line 128 "animationparse.y"


