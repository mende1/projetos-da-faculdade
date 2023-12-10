/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INTEGER = 259,
     BOOLEAN = 260,
     VOID = 261,
     PLUS = 262,
     MINUS = 263,
     TIMES = 264,
     DIVIDE = 265,
     LT = 266,
     LEQ = 267,
     GT = 268,
     GEQ = 269,
     EQ = 270,
     NEQ = 271,
     ASSIGN = 272,
     COLON = 273,
     SEMICOLON = 274,
     LPAREN = 275,
     RPAREN = 276,
     LBRACE = 277,
     RBRACE = 278,
     FUNCTION = 279,
     IF = 280,
     ELSE = 281,
     WHILE = 282,
     RETURN = 283,
     PRINT = 284,
     COMMA = 285,
     INTEGER_CONST = 286,
     BOOLEAN_CONST_TRUE = 287,
     BOOLEAN_CONST_FALSE = 288,
     ERROR = 289
   };
#endif
/* Tokens.  */
#define ID 258
#define INTEGER 259
#define BOOLEAN 260
#define VOID 261
#define PLUS 262
#define MINUS 263
#define TIMES 264
#define DIVIDE 265
#define LT 266
#define LEQ 267
#define GT 268
#define GEQ 269
#define EQ 270
#define NEQ 271
#define ASSIGN 272
#define COLON 273
#define SEMICOLON 274
#define LPAREN 275
#define RPAREN 276
#define LBRACE 277
#define RBRACE 278
#define FUNCTION 279
#define IF 280
#define ELSE 281
#define WHILE 282
#define RETURN 283
#define PRINT 284
#define COMMA 285
#define INTEGER_CONST 286
#define BOOLEAN_CONST_TRUE 287
#define BOOLEAN_CONST_FALSE 288
#define ERROR 289




/* Copy the first part of user declarations.  */
#line 1 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"

#include <stdio.h>
#include <stdlib.h>

#include "expr.h"
#include "type.h"
#include "stmt.h"
#include "param_list.h"

/* interface to lexer */

struct decl* parser_result = 0;
 
extern int yylineno; /* from lexer */
void yyerror(const char *);
int yydebug = 1;
int yylex();
extern char *yytext;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
{
   int d;
   char *name;
   int integer;
   struct type *type;
   struct expr *expr;
   struct stmt *stmt;
   struct decl *decl;
   struct param_list *param_list;
}
/* Line 193 of yacc.c.  */
#line 195 "blite.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 208 "blite.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    17,    19,
      21,    31,    32,    34,    38,    40,    44,    48,    54,    58,
      64,    67,    69,    73,    75,    77,    80,    83,    85,    87,
      90,    93,    97,   100,   102,   108,   116,   122,   125,   127,
     131,   133,   135,   139,   143,   145,   149,   153,   155,   159,
     163,   167,   171,   175,   179,   181,   183,   185,   187,   191,
     193,   197,   202,   204
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    -1,    37,    38,    -1,    38,    -1,
      44,    19,    -1,    40,    -1,     4,    -1,     5,    -1,     6,
      -1,     3,    18,    24,    39,    20,    41,    21,    17,    45,
      -1,    -1,    42,    -1,    42,    30,    43,    -1,    43,    -1,
       3,    18,    39,    -1,     3,    18,    39,    -1,     3,    18,
      39,    17,    55,    -1,    22,    46,    23,    -1,    22,    47,
      19,    46,    23,    -1,    46,    48,    -1,    48,    -1,    47,
      19,    44,    -1,    44,    -1,    45,    -1,    49,    19,    -1,
      50,    19,    -1,    51,    -1,    52,    -1,    53,    19,    -1,
      60,    19,    -1,     3,    17,    55,    -1,    28,    55,    -1,
      28,    -1,    25,    20,    55,    21,    48,    -1,    25,    20,
      55,    21,    48,    26,    48,    -1,    27,    20,    55,    21,
      48,    -1,    29,    54,    -1,    55,    -1,    54,    30,    55,
      -1,    56,    -1,    58,    -1,    56,     7,    57,    -1,    56,
       8,    57,    -1,    57,    -1,    57,     9,    59,    -1,    57,
      10,    59,    -1,    59,    -1,    59,    11,    59,    -1,    59,
      12,    59,    -1,    59,    13,    59,    -1,    59,    14,    59,
      -1,    59,    15,    59,    -1,    59,    16,    59,    -1,     3,
      -1,    31,    -1,    33,    -1,    32,    -1,    20,    55,    21,
      -1,    60,    -1,     3,    20,    21,    -1,     3,    20,    61,
      21,    -1,    55,    -1,    61,    30,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    83,    97,   101,   102,   106,   108,   110,
     115,   121,   122,   126,   139,   144,   149,   151,   156,   158,
     163,   176,   180,   193,   198,   199,   200,   201,   202,   203,
     204,   208,   218,   220,   225,   227,   232,   237,   242,   244,
     249,   251,   256,   258,   260,   265,   267,   269,   274,   276,
     278,   280,   282,   284,   289,   291,   293,   295,   297,   299,
     303,   305,   310,   312
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTEGER", "BOOLEAN", "VOID",
  "PLUS", "MINUS", "TIMES", "DIVIDE", "LT", "LEQ", "GT", "GEQ", "EQ",
  "NEQ", "ASSIGN", "COLON", "SEMICOLON", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "FUNCTION", "IF", "ELSE", "WHILE", "RETURN", "PRINT", "COMMA",
  "INTEGER_CONST", "BOOLEAN_CONST_TRUE", "BOOLEAN_CONST_FALSE", "ERROR",
  "$accept", "program", "declarations", "declaration", "type",
  "func_declaration", "params", "param_list", "param", "var_declaration",
  "block", "statements", "local_declarations", "statement",
  "assignment_statement", "return_statement", "if_statement",
  "while_statement", "print_statement", "print_arguments", "expr",
  "expr_add_minus", "expr_mult_div", "expr_relational", "expr_primary",
  "function_call", "function_call_arguments", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    39,    39,
      40,    41,    41,    42,    42,    43,    44,    44,    45,    45,
      46,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    49,    50,    50,    51,    51,    52,    53,    54,    54,
      55,    55,    56,    56,    56,    57,    57,    57,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       9,     0,     1,     3,     1,     3,     3,     5,     3,     5,
       2,     1,     3,     1,     1,     2,     2,     1,     1,     2,
       2,     3,     2,     1,     5,     7,     5,     2,     1,     3,
       1,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     3,     1,
       3,     4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     6,     0,     0,     1,     3,
       5,     7,     8,     9,     0,    16,     0,     0,    11,    54,
       0,    55,    57,    56,    17,    40,    44,    41,    47,    59,
       0,     0,    12,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      62,     0,    58,    42,    47,    43,    45,    46,    48,    49,
      50,    51,    52,    53,    15,     0,    13,    61,     0,     0,
      10,    63,     0,     0,     0,    33,     0,    23,    24,     0,
       0,    21,     0,     0,    27,    28,     0,     0,     0,     0,
       0,     0,    32,    37,    38,     0,    18,    20,     0,    25,
      26,    29,    30,    31,     0,     0,     0,    22,     0,     0,
       0,    39,    19,    34,    36,     0,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    15,     5,    31,    32,    33,     6,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    93,
      24,    25,    26,    27,    28,    29,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int8 yypact[] =
{
      12,    10,    37,    12,   -78,   -78,    20,     0,   -78,   -78,
     -78,   -78,   -78,   -78,    21,    28,    34,    26,    63,    47,
      26,   -78,   -78,   -78,   -78,    36,    40,   -78,     7,   -78,
      51,    55,    53,   -78,    31,    59,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    21,    64,    63,   -78,
     -78,   -13,   -78,    40,   -78,    40,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,    66,   -78,   -78,    26,    71,
     -78,   -78,    -8,    72,    74,    26,    26,   -78,   -78,    50,
      76,   -78,    78,    83,   -78,   -78,    84,    86,    26,    21,
      26,    26,   -78,    89,   -78,    -4,   -78,   -78,    71,   -78,
     -78,   -78,   -78,   -78,    99,   100,    26,   -78,    62,    79,
      79,   -78,   -78,    96,   -78,    79,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   120,   -11,   -78,   -78,   -78,    77,   -62,
      61,    29,   -78,   -77,   -78,   -78,   -78,   -78,   -78,   -78,
     -20,   -78,    24,   -78,    73,   -68,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      35,    87,    97,    16,    11,    12,    13,    77,    67,    88,
      89,    87,    34,    88,    50,     1,    34,    68,    40,    41,
      42,    43,    44,    45,    14,    11,    12,    13,     7,    19,
      87,    97,   113,   114,    19,    64,   107,     8,   116,    10,
      87,    87,    87,    36,    37,    17,    20,    87,    71,    38,
      39,    20,    49,    95,    18,    92,    94,    21,    22,    23,
      53,    55,    21,    22,    23,    95,    30,    34,   103,    46,
     104,   105,    69,    96,    72,    73,    47,    74,    75,    76,
      52,    65,    95,    48,    69,   112,   111,    73,    69,    74,
      75,    76,    90,    69,    91,    98,    73,    99,    74,    75,
      76,    69,   100,   101,    73,   102,    74,    75,    76,    54,
      54,    56,    57,    58,    59,    60,    61,    62,    63,   106,
     109,   110,   115,     9,     0,    66,    70,   108
};

static const yytype_int8 yycheck[] =
{
      20,    69,    79,    14,     4,     5,     6,    69,    21,    17,
      18,    79,    20,    17,    34,     3,    20,    30,    11,    12,
      13,    14,    15,    16,    24,     4,     5,     6,    18,     3,
      98,   108,   109,   110,     3,    46,    98,     0,   115,    19,
     108,   109,   110,     7,     8,    17,    20,   115,    68,     9,
      10,    20,    21,     3,    20,    75,    76,    31,    32,    33,
      36,    37,    31,    32,    33,     3,     3,    20,    88,    18,
      90,    91,    22,    23,     3,    25,    21,    27,    28,    29,
      21,    17,     3,    30,    22,    23,   106,    25,    22,    27,
      28,    29,    20,    22,    20,    19,    25,    19,    27,    28,
      29,    22,    19,    19,    25,    19,    27,    28,    29,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    30,
      21,    21,    26,     3,    -1,    48,    65,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    36,    37,    38,    40,    44,    18,     0,    38,
      19,     4,     5,     6,    24,    39,    39,    17,    20,     3,
      20,    31,    32,    33,    55,    56,    57,    58,    59,    60,
       3,    41,    42,    43,    20,    55,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    18,    21,    30,    21,
      55,    61,    21,    57,    59,    57,    59,    59,    59,    59,
      59,    59,    59,    59,    39,    17,    43,    21,    30,    22,
      45,    55,     3,    25,    27,    28,    29,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    60,    17,    18,
      20,    20,    55,    54,    55,     3,    23,    48,    19,    19,
      19,    19,    19,    55,    55,    55,    30,    44,    46,    21,
      21,    55,    23,    48,    48,    26,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 79 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { parser_result = (yyvsp[(1) - (1)].decl); return 0;;}
    break;

  case 3:
#line 84 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    {
      if ((yyvsp[(2) - (2)].decl) != NULL) {
         struct decl *current = (yyvsp[(1) - (2)].decl);
         while (current->next != NULL) {
            current = current->next;
         }
         current->next = (yyvsp[(2) - (2)].decl);
         (yyval.decl) = (yyvsp[(1) - (2)].decl);  // Result is the head of the list
      } else {
         (yyval.decl) = (yyvsp[(1) - (2)].decl);  // No new declaration, result is the same as before
      }
   
   ;}
    break;

  case 4:
#line 97 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].decl); ;}
    break;

  case 5:
#line 101 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.decl) = (yyvsp[(1) - (2)].decl);  ;}
    break;

  case 6:
#line 102 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].decl); ;}
    break;

  case 7:
#line 107 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.type) = type_create(TYPE_INTEGER, NULL, NULL); ;}
    break;

  case 8:
#line 109 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.type) = type_create(TYPE_BOOLEAN, NULL, NULL); ;}
    break;

  case 9:
#line 111 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.type) = type_create(TYPE_VOID, NULL, NULL); ;}
    break;

  case 10:
#line 116 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.decl) = func_decl_create((yyvsp[(1) - (9)].name), (yyvsp[(4) - (9)].type), (yyvsp[(6) - (9)].param_list), (yyvsp[(9) - (9)].stmt)); ;}
    break;

  case 11:
#line 121 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    {(yyval.param_list) = NULL;;}
    break;

  case 13:
#line 127 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { 
      if ((yyvsp[(3) - (3)].param_list) != NULL) {
         struct param_list *current = (yyvsp[(1) - (3)].param_list);
         while (current->next != NULL) {
            current = current->next;
         }
         current->next = (yyvsp[(3) - (3)].param_list);
         (yyval.param_list) = (yyvsp[(1) - (3)].param_list);  // Result is the head of the list
      } else {
         (yyval.param_list) = (yyvsp[(1) - (3)].param_list);  // No new param, result is the same as before
      }
   ;}
    break;

  case 14:
#line 140 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    {(yyval.param_list) = (yyvsp[(1) - (1)].param_list);;}
    break;

  case 15:
#line 145 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    {(yyval.param_list) = param_create((yyvsp[(1) - (3)].name), (yyvsp[(3) - (3)].type)); ;}
    break;

  case 16:
#line 150 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.decl) = var_decl_create((yyvsp[(1) - (3)].name), (yyvsp[(3) - (3)].type), NULL); ;}
    break;

  case 17:
#line 152 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.decl) = var_decl_create((yyvsp[(1) - (5)].name), (yyvsp[(3) - (5)].type), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 18:
#line 157 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.stmt) = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, (yyvsp[(2) - (3)].stmt), NULL, NULL); ;}
    break;

  case 19:
#line 159 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.stmt) = stmt_create(STMT_BLOCK, (yyvsp[(2) - (5)].decl), NULL, NULL, NULL, (yyvsp[(4) - (5)].stmt), NULL, NULL); ;}
    break;

  case 20:
#line 164 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { 
      if ((yyvsp[(2) - (2)].stmt) != NULL) {
         struct stmt *current = (yyvsp[(1) - (2)].stmt);
         while (current->next != NULL) {
            current = current->next;
         }
         current->next = (yyvsp[(2) - (2)].stmt);
         (yyval.stmt) = (yyvsp[(1) - (2)].stmt);  // Result is the head of the list
      } else {
         (yyval.stmt) = (yyvsp[(1) - (2)].stmt);  // No new statement, result is the same as before
      }
   ;}
    break;

  case 22:
#line 181 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { 
      if ((yyvsp[(3) - (3)].decl) != NULL) {
         struct decl *current = (yyvsp[(1) - (3)].decl);
         while (current->next != NULL) {
            current = current->next;
         }
         current->next = (yyvsp[(3) - (3)].decl);
         (yyval.decl) = (yyvsp[(1) - (3)].decl);  // Result is the head of the list
      } else {
         (yyval.decl) = (yyvsp[(1) - (3)].decl);  // No new declaration, result is the same as before
      }
   ;}
    break;

  case 23:
#line 194 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].decl); ;}
    break;

  case 30:
#line 204 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.stmt) = stmt_create(STMT_EXPR, NULL, NULL, (yyvsp[(1) - (2)].expr), NULL, NULL, NULL, NULL);  ;}
    break;

  case 31:
#line 209 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    {
      struct expr *left = expr_create_var((yyvsp[(1) - (3)].name));
      struct expr *right = (yyvsp[(3) - (3)].expr);
      struct expr *assignment_expr = expr_create(EXPR_ASSIGN, left, right);
      (yyval.stmt) = stmt_create(STMT_EXPR, NULL, NULL, assignment_expr, NULL, NULL, NULL, NULL);
   ;}
    break;

  case 32:
#line 219 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.stmt) = stmt_create(STMT_RETURN, NULL, NULL, (yyvsp[(2) - (2)].expr), NULL, NULL, NULL, NULL); ;}
    break;

  case 33:
#line 221 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.stmt) = stmt_create(STMT_RETURN, NULL, NULL, NULL, NULL, NULL, NULL, NULL); ;}
    break;

  case 34:
#line 226 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.stmt) = if_create((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt)); ;}
    break;

  case 35:
#line 228 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.stmt) = if_else_create((yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt)); ;}
    break;

  case 36:
#line 233 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.stmt) = while_create((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt)); ;}
    break;

  case 37:
#line 238 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    {(yyval.stmt) = print_stmt_create((yyvsp[(2) - (2)].expr));;}
    break;

  case 38:
#line 243 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 39:
#line 245 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    {  (yyval.expr) = expr_create_arg((yyvsp[(3) - (3)].expr), (yyvsp[(1) - (3)].expr)); ;}
    break;

  case 40:
#line 250 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 41:
#line 252 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 42:
#line 257 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 43:
#line 259 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));;}
    break;

  case 44:
#line 261 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 45:
#line 266 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create(EXPR_MUL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 46:
#line 268 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 47:
#line 270 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 48:
#line 275 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create(EXPR_LT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr));  ;}
    break;

  case 49:
#line 277 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create(EXPR_LTEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 50:
#line 279 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create(EXPR_GT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 51:
#line 281 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create(EXPR_GTEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 52:
#line 283 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create(EXPR_EQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 53:
#line 285 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create(EXPR_NEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 54:
#line 290 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create_var((yyvsp[(1) - (1)].name)); ;}
    break;

  case 55:
#line 292 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = create_integer_literal(atoi(yytext)); ;}
    break;

  case 56:
#line 294 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = create_boolean_literal(0); ;}
    break;

  case 57:
#line 296 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = create_boolean_literal(1); ;}
    break;

  case 58:
#line 298 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 60:
#line 304 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create_call((yyvsp[(1) - (3)].name), NULL); ;}
    break;

  case 61:
#line 306 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create_call((yyvsp[(1) - (4)].name), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 62:
#line 311 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create_arg((yyvsp[(1) - (1)].expr), NULL);;}
    break;

  case 63:
#line 313 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"
    { (yyval.expr) = expr_create_arg((yyvsp[(3) - (3)].expr), (yyvsp[(1) - (3)].expr)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1823 "blite.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 316 "/Users/mendel/UFBA/compiladores/t2-t3-ast/T2-T3-AST/src/blite.y"


void yyerror(const char *s) {
   fprintf(stdout, "%s\n", s);
}
