
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "cg2.y"


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
extern int yylex();

extern int yyparse();
extern FILE *yyin;

int label=0;
int tempVariable=0;
int nestLabel[10];
int nesting = 0;

char* genTempVariable(int id){
    char* temp = (char*)malloc(10*sizeof(char));
    temp[0]='t';
    snprintf(temp,10,"t%d",id);
    return temp;
}

int gencode(char* lhs, char*op, char* rhs){
    printf("t%d = %s %s %s \n",tempVariable, lhs, op, rhs);
    return tempVariable;
}



void assignment(char* lhs, char* rhs){
    printf("%s = %s \n",lhs,rhs);
}

void yyerror();



/* Line 189 of yacc.c  */
#line 113 "cg2.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MINUS = 258,
     PLUS = 259,
     MOD = 260,
     DIV = 261,
     MULT = 262,
     NOT = 263,
     EQ = 264,
     NEQ = 265,
     LT = 266,
     GT = 267,
     LTE = 268,
     GTE = 269,
     OR = 270,
     AND = 271,
     ASSIGN = 272,
     COMMA = 273,
     COLON = 274,
     SEMICOLON = 275,
     IDENTIFIER = 276,
     INTVAL = 277,
     REALVAL = 278,
     BOOLVAL = 279,
     CHARVAL = 280,
     IF = 281,
     ELSE = 282,
     ELSEIF = 283,
     THEN = 284,
     PROGRAM = 285,
     INT = 286,
     REAL = 287,
     BOOLEAN = 288,
     CHAR = 289,
     VAR = 290,
     FOR = 291,
     DO = 292,
     WHILE = 293,
     ARRAY = 294,
     PROG_BEGIN = 295,
     END = 296,
     READ = 297,
     WRITE = 298,
     TO = 299,
     DOWNTO = 300,
     PERIOD = 301,
     TXT = 302,
     LCPAREN = 303,
     RCPAREN = 304,
     LPAREN = 305,
     RPAREN = 306,
     LSPAREN = 307,
     RSPAREN = 308,
     UNDERSCORE = 309,
     SQUOTE = 310,
     DQUOTE = 311,
     OF = 312
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 39 "cg2.y"

char* lexeme;
char* arrtype;



/* Line 214 of yacc.c  */
#line 213 "cg2.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 225 "cg2.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    14,    17,    23,    37,    38,    40,
      42,    44,    46,    50,    51,    53,    55,    57,    59,    61,
      63,    67,    74,    79,    84,    91,    96,   101,   103,   105,
     107,   111,   113,   117,   119,   123,   127,   131,   135,   139,
     143,   145,   149,   151,   156,   158,   161,   163,   165,   167,
     169,   170,   177,   178,   179,   184,   185,   186,   187,   196,
     197,   198,   211,   212,   213,   226,   228,   230,   232,   234,
     236,   238,   240
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,    30,    21,    20,    61,    40,
      64,    41,    46,    -1,    35,    62,    -1,    71,    19,    63,
      20,    62,    -1,    71,    19,    39,    52,    22,    46,    46,
      22,    53,    57,    63,    20,    62,    -1,    -1,    31,    -1,
      32,    -1,    33,    -1,    34,    -1,    65,    20,    64,    -1,
      -1,    66,    -1,    67,    -1,    69,    -1,    77,    -1,    82,
      -1,    72,    -1,    21,    17,    73,    -1,    21,    52,    74,
      53,    17,    73,    -1,    42,    50,    71,    51,    -1,    42,
      50,    68,    51,    -1,    21,    52,    74,    53,    18,    71,
      -1,    21,    52,    74,    53,    -1,    43,    50,    70,    51,
      -1,    47,    -1,    71,    -1,    68,    -1,    21,    18,    71,
      -1,    21,    -1,    40,    64,    41,    -1,    74,    -1,    73,
       4,    74,    -1,    73,     3,    74,    -1,    73,    89,    74,
      -1,    74,     7,    75,    -1,    74,     6,    75,    -1,    74,
       5,    75,    -1,    75,    -1,    50,    73,    51,    -1,    21,
      -1,    21,    52,    74,    53,    -1,    76,    -1,     8,    75,
      -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,    -1,
      26,    73,    29,    78,    72,    79,    -1,    -1,    -1,    80,
      27,    81,    72,    -1,    -1,    -1,    -1,    38,    73,    37,
      40,    83,    64,    84,    41,    -1,    -1,    -1,    36,    21,
      17,    73,    44,    73,    37,    40,    85,    64,    86,    41,
      -1,    -1,    -1,    36,    21,    17,    73,    45,    73,    37,
      40,    87,    64,    88,    41,    -1,     9,    -1,    10,    -1,
      11,    -1,    12,    -1,    13,    -1,    14,    -1,    15,    -1,
      16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    61,    65,    68,    69,    70,    74,    75,
      76,    77,    80,    81,    85,    86,    87,    88,    89,    90,
      93,    94,   110,   111,   115,   121,   130,   134,   135,   136,
     139,   140,   143,   146,   147,   153,   160,   170,   176,   182,
     189,   193,   194,   195,   211,   212,   219,   220,   221,   222,
     227,   227,   230,   230,   230,   231,   236,   245,   235,   252,
     263,   251,   270,   281,   269,   289,   290,   291,   292,   293,
     294,   295,   296
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MINUS", "PLUS", "MOD", "DIV", "MULT",
  "NOT", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "OR", "AND", "ASSIGN",
  "COMMA", "COLON", "SEMICOLON", "IDENTIFIER", "INTVAL", "REALVAL",
  "BOOLVAL", "CHARVAL", "IF", "ELSE", "ELSEIF", "THEN", "PROGRAM", "INT",
  "REAL", "BOOLEAN", "CHAR", "VAR", "FOR", "DO", "WHILE", "ARRAY",
  "PROG_BEGIN", "END", "READ", "WRITE", "TO", "DOWNTO", "PERIOD", "TXT",
  "LCPAREN", "RCPAREN", "LPAREN", "RPAREN", "LSPAREN", "RSPAREN",
  "UNDERSCORE", "SQUOTE", "DQUOTE", "OF", "$accept", "s", "program",
  "var_decl_section", "var_decl_list", "type", "statement_list",
  "statement", "assignment_stmt", "read_stmt", "arr_list", "write_stmt",
  "write_list", "var_list", "block_stmt", "expr", "term", "factor",
  "const", "conditional_stmt", "$@1", "if_st", "$@2", "$@3", "loop", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "relop", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    61,    62,    62,    62,    63,    63,
      63,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    70,    70,    70,
      71,    71,    72,    73,    73,    73,    73,    74,    74,    74,
      74,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      78,    77,    80,    81,    79,    79,    83,    84,    82,    85,
      86,    82,    87,    88,    82,    89,    89,    89,    89,    89,
      89,    89,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     8,     2,     5,    13,     0,     1,     1,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       3,     6,     4,     4,     6,     4,     4,     1,     1,     1,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     4,     1,     2,     1,     1,     1,     1,
       0,     6,     0,     0,     4,     0,     0,     0,     8,     0,
       0,    12,     0,     0,    12,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     7,     0,    31,
       4,     0,    13,     0,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,    14,    15,    16,    19,    17,    18,
      30,     8,     9,    10,    11,     0,     0,     0,     0,     0,
      42,    46,    47,    48,    49,     0,     0,    33,    40,    44,
       0,     0,     0,     0,     0,     0,    13,     0,     7,    20,
       0,    45,     0,     0,     0,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    50,     0,     0,     0,     0,     0,
       0,    32,    31,     0,     0,    27,    29,     0,    28,     3,
      12,     0,     5,     0,     0,    41,    35,    34,     0,    36,
      39,    38,    37,     0,    56,     0,    23,    22,    26,     0,
       0,    43,    52,     0,     0,    13,     0,     0,    21,    51,
       0,     0,     0,    57,    25,     0,    53,     0,     0,     0,
       0,     0,     0,    59,    62,    58,    24,     0,    54,    13,
      13,     0,    60,    63,     7,     0,     0,     6,    61,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    10,    36,    22,    23,    24,    25,
      83,    26,    87,    11,    27,    46,    47,    48,    49,    28,
      98,   119,   120,   132,    29,   115,   129,   139,   145,   140,
     146,    75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int16 yypact[] =
{
      -4,     6,    40,   -68,    34,   -68,    21,    37,    19,    46,
     -68,    48,   123,    37,    54,     8,    53,    47,    53,   123,
      22,    31,    28,    51,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,    30,    64,    53,    53,    53,
      43,   -68,   -68,   -68,   -68,    53,   142,    29,   -68,   -68,
      84,    96,    61,    83,    36,    67,   123,    92,    37,   164,
       2,   -68,    53,     1,    53,    53,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,    53,    53,    53,    53,    53,
      75,   -68,    10,    68,    81,   -68,   -68,    97,   -68,   -68,
     -68,    88,   -68,   118,    13,   -68,    29,    29,   107,    29,
     -68,   -68,   -68,    35,   -68,    53,   -68,   -68,   -68,   114,
      53,   -68,   149,    53,    53,   123,    17,   140,   164,   -68,
     143,   113,   127,   -68,   154,   132,   -68,   146,   147,   148,
      37,   131,   107,   -68,   -68,   -68,   -68,   150,   -68,   123,
     123,   170,   -68,   -68,    37,   151,   152,   -68,   -68,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   -68,   -55,    57,   -19,   -68,   -68,   -68,
     137,   -68,   -68,   -12,   -67,   -16,   -32,    14,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int16 yytable[] =
{
      52,    30,    51,    92,    64,    65,    60,    76,    77,    78,
      66,    67,    68,    69,    70,    71,    72,    73,    76,    77,
      78,    59,    76,    77,    78,    37,     1,     4,    13,    63,
      94,   112,    96,    97,    76,    77,    78,    90,    64,    65,
       5,    84,    88,    99,    66,    67,    68,    69,    70,    71,
      72,    73,    95,    61,     6,    93,     7,    82,     9,    12,
      38,    39,   105,   103,    13,   138,   111,    14,    50,    55,
     124,    56,    53,   116,    40,    41,    42,    43,    44,   113,
     114,    54,    57,    85,    58,    31,    32,    33,    34,   147,
     100,   101,   102,    35,   118,    62,   123,   121,   122,    64,
      65,    79,    81,    45,    82,    66,    67,    68,    69,    70,
      71,    72,    73,    89,    91,   104,    64,    65,   136,   106,
     142,   143,    66,    67,    68,    69,    70,    71,    72,    73,
      64,    65,   107,    80,   109,   110,    66,    67,    68,    69,
      70,    71,    72,    73,    15,    64,    65,    19,   108,    16,
     127,    66,    67,    68,    69,    70,    71,    72,    73,    17,
     117,    18,   125,    19,   128,    20,    21,    64,    65,   -55,
     126,    74,   130,    66,    67,    68,    69,    70,    71,    72,
      73,    31,    32,    33,    34,   131,   133,   134,   137,   135,
     144,    86,   148,   149,   141
};

static const yytype_uint8 yycheck[] =
{
      19,    13,    18,    58,     3,     4,    38,     5,     6,     7,
       9,    10,    11,    12,    13,    14,    15,    16,     5,     6,
       7,    37,     5,     6,     7,    17,    30,    21,    18,    45,
      62,    98,    64,    65,     5,     6,     7,    56,     3,     4,
       0,    53,    54,    75,     9,    10,    11,    12,    13,    14,
      15,    16,    51,    39,    20,    53,    35,    21,    21,    40,
      52,     8,    52,    79,    18,   132,    53,    19,    21,    41,
      53,    20,    50,   105,    21,    22,    23,    24,    25,    44,
      45,    50,    52,    47,    20,    31,    32,    33,    34,   144,
      76,    77,    78,    39,   110,    52,   115,   113,   114,     3,
       4,    17,    41,    50,    21,     9,    10,    11,    12,    13,
      14,    15,    16,    46,    22,    40,     3,     4,   130,    51,
     139,   140,     9,    10,    11,    12,    13,    14,    15,    16,
       3,     4,    51,    37,    46,    17,     9,    10,    11,    12,
      13,    14,    15,    16,    21,     3,     4,    40,    51,    26,
      37,     9,    10,    11,    12,    13,    14,    15,    16,    36,
      46,    38,    22,    40,    37,    42,    43,     3,     4,    20,
      27,    29,    18,     9,    10,    11,    12,    13,    14,    15,
      16,    31,    32,    33,    34,    53,    40,    40,    57,    41,
      20,    54,    41,    41,   137
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    59,    60,    21,     0,    20,    35,    61,    21,
      62,    71,    40,    18,    19,    21,    26,    36,    38,    40,
      42,    43,    64,    65,    66,    67,    69,    72,    77,    82,
      71,    31,    32,    33,    34,    39,    63,    17,    52,     8,
      21,    22,    23,    24,    25,    50,    73,    74,    75,    76,
      21,    73,    64,    50,    50,    41,    20,    52,    20,    73,
      74,    75,    52,    73,     3,     4,     9,    10,    11,    12,
      13,    14,    15,    16,    29,    89,     5,     6,     7,    17,
      37,    41,    21,    68,    71,    47,    68,    70,    71,    46,
      64,    22,    62,    53,    74,    51,    74,    74,    78,    74,
      75,    75,    75,    73,    40,    52,    51,    51,    51,    46,
      17,    53,    72,    44,    45,    83,    74,    46,    73,    79,
      80,    73,    73,    64,    53,    22,    27,    37,    37,    84,
      18,    53,    81,    40,    40,    41,    71,    57,    72,    85,
      87,    63,    64,    64,    20,    86,    88,    62,    41,    41
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 59 "cg2.y"
    { printf("valid input");return 0;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 93 "cg2.y"
    {assignment((yyvsp[(1) - (3)].lexeme),(yyvsp[(3) - (3)].lexeme));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 95 "cg2.y"
    {
        char* temp1 = genTempVariable(tempVariable++);
        char* temp2 = genTempVariable(tempVariable++);
        char* temp3 = genTempVariable(tempVariable++);
        char* temp4 = genTempVariable(tempVariable++);
        printf("%s = %s\n", temp1, (yyvsp[(3) - (6)].lexeme));
        int size=4;
        printf("%s = %d * %s\n", temp2, size, temp1); // t2 = size * t1
        printf("%s = &%s\n", temp3, (yyvsp[(1) - (6)].lexeme)); // t3 = &b
        printf("%s = %s + %s\n", temp4, temp2, temp3); // t4 = t2 + t3
        printf("*%s = %s\n", temp4, (yyvsp[(6) - (6)].lexeme)); // *(t4) = rhs
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 116 "cg2.y"
    {
        char* temp = genTempVariable(tempVariable++);
        printf("%s = %s[%s]\n", temp, (yyvsp[(1) - (6)].lexeme), (yyvsp[(3) - (6)].lexeme));
        (yyval.lexeme) = temp;
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 122 "cg2.y"
    {
        char* temp = genTempVariable(tempVariable++);
        printf("%s = %s[%s]\n", temp, (yyvsp[(1) - (4)].lexeme), (yyvsp[(3) - (4)].lexeme));
        (yyval.lexeme) = temp;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 146 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 147 "cg2.y"
    {
                                int a = gencode((yyvsp[(1) - (3)].lexeme),"+", (yyvsp[(3) - (3)].lexeme));
                                char* tempVar = genTempVariable(a);
                                (yyval.lexeme)=tempVar;
                                tempVariable++;
                          ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 153 "cg2.y"
    {
                                int a = gencode((yyvsp[(1) - (3)].lexeme),"-", (yyvsp[(3) - (3)].lexeme));
                                char* tempVar = genTempVariable(a);
                                (yyval.lexeme)=tempVar;
                                tempVariable++;
                          ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 160 "cg2.y"
    {int a = gencode((yyvsp[(1) - (3)].lexeme),(yyvsp[(2) - (3)].lexeme),(yyvsp[(3) - (3)].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                       ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 170 "cg2.y"
    {
                                int a = gencode((yyvsp[(1) - (3)].lexeme),"*", (yyvsp[(3) - (3)].lexeme));
                                char* tempVar = genTempVariable(a);
                                (yyval.lexeme)=tempVar;
                                tempVariable++;
                          ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 176 "cg2.y"
    {
                                int a = gencode((yyvsp[(1) - (3)].lexeme),"/", (yyvsp[(3) - (3)].lexeme));
                                char* tempVar = genTempVariable(a);
                                (yyval.lexeme)=tempVar;
                                tempVariable++;
                          ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 182 "cg2.y"
    {
                                int a = gencode((yyvsp[(1) - (3)].lexeme),"%", (yyvsp[(3) - (3)].lexeme));
                                char* tempVar = genTempVariable(a);
                                (yyval.lexeme)=tempVar;
                                tempVariable++;
                          ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 189 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 193 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(2) - (3)].lexeme);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 194 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 196 "cg2.y"
    {
        char* temp1 = genTempVariable(tempVariable++);
        char* temp2 = genTempVariable(tempVariable++);
        char* temp3 = genTempVariable(tempVariable++);
        char* temp4 = genTempVariable(tempVariable++);

        printf("%s = %s\n", temp1, (yyvsp[(3) - (4)].lexeme)); 
        int size=4;

        
        printf("%s = %d * %s\n", temp2, size, temp1); 
        printf("%s = &%s\n", temp3, (yyvsp[(1) - (4)].lexeme)); 
        printf("%s = %s + %s\n", temp4, temp2, temp3); 
        (yyval.lexeme)=temp4;
        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 211 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 213 "cg2.y"
    {
       char* temp1 = genTempVariable(tempVariable++);
        printf("%s = ! %s\n", temp1, (yyvsp[(2) - (2)].lexeme)); 
        (yyval.lexeme)=temp1;
        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 219 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 220 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 221 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 222 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 227 "cg2.y"
    {printf("if not %s goto L%d\n",(yyvsp[(2) - (3)].lexeme)  ,++label);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 230 "cg2.y"
    {printf("goto L%d\n", label+1);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 230 "cg2.y"
    {printf("L%d: \n",label);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 230 "cg2.y"
    {printf("L%d: \n", ++label);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 231 "cg2.y"
    {printf("L%d: \n",label);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 236 "cg2.y"
    {
        printf("L%d:\n", ++label);
        nestLabel[nesting]=label;

        
        printf("if not %s goto L%d\n", (yyvsp[(2) - (4)].lexeme), ++label);
        nestLabel[nesting+1]=label; 
     ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 245 "cg2.y"
    { 
        printf("goto L%d\n", nestLabel[nesting]);
        printf("L%d:\n", nestLabel[++nesting]); 
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 252 "cg2.y"
    {
                        printf("for_loop:\n");
                        printf("%s = %s\n", (yyvsp[(2) - (8)].lexeme), (yyvsp[(4) - (8)].lexeme));
                        printf("L%d:\n", ++label); 
                        nestLabel[nesting]=label;
                        printf("if %s < %s goto L%d\n", (yyvsp[(2) - (8)].lexeme), (yyvsp[(6) - (8)].lexeme), ++label); 
                        printf("goto L%d\n", ++label);
                        nestLabel[nesting+1]=label; 
                        printf("L%d:\n", label - 1); 
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 263 "cg2.y"
    {
                        printf("%s = %s + 1\n", (yyvsp[(2) - (10)].lexeme), (yyvsp[(2) - (10)].lexeme));
                        printf("goto L%d\n", nestLabel[nesting]); 
                        printf("L%d:\n", nestLabel[++nesting]);
                    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 270 "cg2.y"
    {
                        printf("for_loop:\n");
                        printf("%s = %s\n", (yyvsp[(2) - (8)].lexeme), (yyvsp[(4) - (8)].lexeme));
                        printf("L%d:\n", ++label); 
                        nestLabel[nesting]=label;
                        printf("if %s > %s goto L%d\n", (yyvsp[(2) - (8)].lexeme), (yyvsp[(6) - (8)].lexeme), ++label);
                        printf("goto L%d\n", ++label);
                        nestLabel[nesting+1]=label; 
                        printf("L%d:\n", label - 1); 
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 281 "cg2.y"
    {
                        printf("%s = %s - 1\n", (yyvsp[(2) - (10)].lexeme), (yyvsp[(2) - (10)].lexeme)); 
                        printf("goto L%d\n", nestLabel[nesting]); 
                        printf("L%d:\n", nestLabel[++nesting]);
                    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 289 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 290 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 291 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 292 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 293 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 294 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 295 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 296 "cg2.y"
    {(yyval.lexeme)=(yyvsp[(1) - (1)].lexeme);;}
    break;



/* Line 1455 of yacc.c  */
#line 1951 "cg2.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 300 "cg2.y"



void main(){

yyin=fopen("input.txt","r");

yyparse();
printf("parsed");


}




void yyerror(){
printf("Syntax error..\n");
exit(0);
}


