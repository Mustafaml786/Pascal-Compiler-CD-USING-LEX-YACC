
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
#line 1 "t1.y"

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#define HASH_TABLE_SIZE 1000
#define ARRAY_SIZE 1000

extern int yylex();
extern int yyparse(void);
void display_stable(); // Assuming this is declared somewhere in your project
void yyerror(const char *s);
extern FILE *yyin;



typedef struct
{
	char* name;
	int start_idx;
	int end_idx;
	union{
	  	int ival;
	  	float fval;
	  	char cval;
	  	char* sval;
	  	int intArray[ARRAY_SIZE];  
		float floatArray[ARRAY_SIZE]; 
		char charArray[ARRAY_SIZE]; 
		char* booleanArray[ARRAY_SIZE]; 
	}vi;
	int init;
	char* arr_tp;
	char* tp;
}T;

int token_ct = 0;
T symbol_table[HASH_TABLE_SIZE];

char *varnames[100];
char *arrtypes[100];
int arrvals[100];
int var_idx=0;

int execute = 1;

int search_table(char *lexeme){
	for(int i=0;i<token_ct;i++){
		if(strcmp(symbol_table[i].name,lexeme)==0)return i;
	}
	return -1;
}

void assign_type_to_var(char *typ){
	for(int i=0;i<var_idx;i++){
		if(search_table(varnames[i])!=-1) printf("ERROR : multiple declarations of a variable '%s'.\n",varnames[i]);
		else{
			symbol_table[token_ct].name = strdup(varnames[i]);
			symbol_table[token_ct].tp = strdup(typ);
			
			//default values
			if(strcmp(typ,"integer")==0)symbol_table[token_ct].vi.ival = 0;
	       		else if(strcmp(typ,"real")==0)symbol_table[token_ct].vi.fval = 0;
	       		else if(strcmp(typ,"boolean")==0)symbol_table[token_ct].vi.sval = strdup("false");
	       		else if(strcmp(typ,"char")==0)symbol_table[token_ct].vi.cval = '\0';
	       		
	       		symbol_table[token_ct].init = 0;  //init = 0 : not initialised
	       		
	       		token_ct++;	
       		}
	}
	var_idx=0;
}

void assign_array_to_var(char* typ,int sind,int eind){
	for(int i=0;i<var_idx;i++){
		if(search_table(varnames[i])!=-1) printf("ERROR : multiple declarations of a variable '%s'.\n",varnames[i]);
		else{
			symbol_table[token_ct].name = strdup(varnames[i]);
			symbol_table[token_ct].tp = strdup("array");
			symbol_table[token_ct].arr_tp = strdup(typ);
			symbol_table[token_ct].start_idx = sind;
			symbol_table[token_ct].end_idx = eind;
			
			//default values
			/*if(strcmp(typ,"integer")==0)symbol_table[token_ct].vi.ival = 0;
	       		else if(strcmp(typ,"real")==0)symbol_table[token_ct].vi.fval = 0;
	       		else if(strcmp(typ,"boolean")==0)symbol_table[token_ct].vi.sval = strdup("false");
	       		else if(strcmp(typ,"char")==0)symbol_table[token_ct].vi.cval = '\0';
	       		*/
	       		
	       		token_ct++;;	
       		}
	}
	var_idx=0;
}

//if type checked it return the index of the varible in the symbo_table
int typecheck(char *var_name,char* tp2){
	int idx = search_table(var_name);
	if(idx==-1){
		printf("ERROR : undeclared variable '%s' .\n",var_name);
		return -1;
	}
	else{
		char *tp1 = symbol_table[idx].tp;
		if(strcmp(tp1,"real")==0 && strcmp(tp2,"integer")==0)return idx; //handling int assigned to real
		if(strcmp(tp1,tp2)!=0){
			printf("ERROR : a '%s' value assigned to '%s' variable .\n",tp2,tp1);
			return -1;
		}
		return idx;
	}
}

int array_check_var_int_bound(char* var_name,char* term_type,int arr_ind){
	int idx = search_table(var_name);
	if(idx==-1){
		printf("ERROR : undeclared variable '%s'.\n",var_name);
		return -1;
	}
	else{
		if(strcmp(term_type,"integer")==0){
			int s = symbol_table[idx].start_idx;
			int e = symbol_table[idx].end_idx;
			if(arr_ind>=s && arr_ind<=e){
				return idx;
			}
			else{
				printf("ERROR : index '%d' out of bound.\n",arr_ind);
				return -1;
			}
		
		}
		else{
			printf("ERROR : not found 'integer' inside '[..]'.\n");
			return -1;
		}
	}
}


int is_any_bool_char(char *tp1,char *tp2){
	if(strcmp(tp1,"char")==0 || strcmp(tp2,"char")==0){printf("ERROR : Trying to perform arithematic operation on 'char'.\n");return 1;}
	if(strcmp(tp1,"boolean")==0 || strcmp(tp2,"boolean")==0){printf("ERROR : Trying to perform arithematic operation on 'boolean'.\n");return 1;}
	
	return 0;
}

void wfunc(char *str1,char *str2){
	if(strcmp(str1,"boolean")==0){
		if(strcmp(str2,"false")==0);
	}
	else{
		printf("ERROR : condition inside 'while' is not 'boolean'.\n");
		//exit(0);
	}
}

void is_int(char *str1){
	if(strcmp(str1,"integer")!=0){
		printf("ERROR : condition inside 'for' is not 'arithematic expression'.\n");	
	}
}


void ifunc(char *str1,char *str2){
	if(strcmp(str1,"boolean")==0){
		if(strcmp(str2,"false")==0)execute = 0;
	}
	else{
		printf("ERROR : condition inside 'if' is not 'boolean'.\n");
		//exit(0);
	}
}

void display_stable()
{
    printf("\n====================================================\n");
    printf(" %-20s %-20s %-20s\n","lexeme_name","value","data_type");
    printf("====================================================\n");

	for(int i=0; i < token_ct; i++){
		if(strcmp(symbol_table[i].tp,"integer")==0)printf(" %-20s %-20d %-20s \n", symbol_table[i].name, symbol_table[i].vi.ival, symbol_table[i].tp);
       		else if(strcmp(symbol_table[i].tp,"real")==0)printf(" %-20s %-20lf %-20s \n", symbol_table[i].name, symbol_table[i].vi.fval, symbol_table[i].tp);
       		else if(strcmp(symbol_table[i].tp,"boolean")==0)printf(" %-20s %-20s %-20s \n", symbol_table[i].name, symbol_table[i].vi.sval, symbol_table[i].tp);
       		else if(strcmp(symbol_table[i].tp,"char")==0)printf(" %-20s %-20c %-20s \n", symbol_table[i].name, symbol_table[i].vi.cval, symbol_table[i].tp);
       		else if(strcmp(symbol_table[i].tp,"array")==0){
       			printf(" %-20s %-20s %-20s \n", symbol_table[i].name, symbol_table[i].arr_tp, symbol_table[i].tp);
       			for(int j=0 ;j<=symbol_table[i].end_idx;j++){
       				printf("%d ",symbol_table[i].vi.intArray[j]);
       			}
       			printf("\n");
       		}
       		
		
	}
    	printf("====================================================\n");

}





/* Line 189 of yacc.c  */
#line 280 "t1.tab.c"

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
     PROGRAM = 264,
     INT = 265,
     REAL = 266,
     BOOLEAN = 267,
     CHAR = 268,
     VAR = 269,
     FOR = 270,
     DO = 271,
     WHILE = 272,
     ARRAY = 273,
     AND = 274,
     OR = 275,
     PROG_BEGIN = 276,
     END = 277,
     READ = 278,
     WRITE = 279,
     IF = 280,
     ELSE = 281,
     ELSEIF = 282,
     THEN = 283,
     TO = 284,
     DOWNTO = 285,
     PERIOD = 286,
     TXT = 287,
     LCPAREN = 288,
     RCPAREN = 289,
     IDENTIFIER = 290,
     INTVAL = 291,
     REALVAL = 292,
     BOOLVAL = 293,
     CHARVAL = 294,
     EQ = 295,
     NEQ = 296,
     LT = 297,
     GT = 298,
     LTE = 299,
     GTE = 300,
     ASSIGN = 301,
     COMMA = 302,
     COLON = 303,
     SEMICOLON = 304,
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
#line 215 "t1.y"

 struct{
  char *type;
  union{
  	int ival;
  	float fval;
  	char cval;
  	char* sval;
  }v;
 }t;



/* Line 214 of yacc.c  */
#line 387 "t1.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 399 "t1.tab.c"

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
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  157

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
       0,     0,     3,     5,    14,    17,    18,    25,    26,    41,
      42,    43,    48,    50,    52,    54,    56,    58,    62,    63,
      65,    67,    69,    71,    73,    75,    80,    85,    86,    94,
      99,   104,   106,   108,   110,   114,   118,   125,   127,   131,
     135,   139,   143,   147,   151,   155,   159,   163,   167,   168,
     172,   176,   180,   182,   186,   188,   193,   195,   198,   200,
     202,   204,   206,   207,   214,   215,   219,   220,   221,   229,
     230,   242,   243
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,     9,    35,    49,    61,    21,
      68,    22,    31,    -1,    14,    62,    -1,    -1,    65,    48,
      67,    63,    49,    62,    -1,    -1,    65,    48,    18,    52,
      36,    31,    31,    36,    53,    57,    67,    49,    64,    62,
      -1,    -1,    -1,    35,    66,    47,    65,    -1,    35,    -1,
      10,    -1,    11,    -1,    12,    -1,    13,    -1,    69,    49,
      68,    -1,    -1,    76,    -1,    70,    -1,    73,    -1,    81,
      -1,    85,    -1,    75,    -1,    23,    50,    65,    51,    -1,
      23,    50,    71,    51,    -1,    -1,    35,    52,    78,    53,
      72,    47,    71,    -1,    35,    52,    78,    53,    -1,    24,
      50,    74,    51,    -1,    32,    -1,    65,    -1,    71,    -1,
      21,    68,    22,    -1,    35,    46,    77,    -1,    35,    52,
      78,    53,    46,    77,    -1,    78,    -1,    77,    40,    78,
      -1,    77,    41,    78,    -1,    77,    42,    78,    -1,    77,
      43,    78,    -1,    77,    44,    78,    -1,    77,    45,    78,
      -1,    77,    20,    78,    -1,    77,    19,    78,    -1,    77,
       4,    78,    -1,    77,     3,    78,    -1,    -1,    78,     7,
      79,    -1,    78,     6,    79,    -1,    78,     5,    79,    -1,
      79,    -1,    50,    77,    51,    -1,    35,    -1,    35,    52,
      78,    53,    -1,    80,    -1,     8,    79,    -1,    36,    -1,
      37,    -1,    38,    -1,    39,    -1,    -1,    25,    77,    82,
      28,    75,    83,    -1,    -1,    26,    84,    75,    -1,    -1,
      -1,    17,    77,    86,    16,    21,    68,    22,    -1,    -1,
      15,    35,    46,    77,    87,    29,    77,    16,    21,    68,
      22,    -1,    -1,    15,    35,    46,    77,    88,    30,    77,
      16,    21,    68,    22,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   229,   229,   231,   235,   238,   238,   239,   239,   240,
     243,   243,   244,   247,   248,   249,   250,   253,   254,   259,
     260,   261,   262,   263,   264,   268,   309,   346,   346,   347,
     351,   355,   364,   380,   393,   397,   410,   427,   434,   456,
     478,   500,   522,   544,   566,   575,   584,   604,   624,   628,
     651,   660,   671,   680,   687,   704,   717,   724,   734,   735,
     736,   737,   745,   745,   748,   748,   749,   752,   752,   753,
     753,   754,   754
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MINUS", "PLUS", "MOD", "DIV", "MULT",
  "NOT", "PROGRAM", "INT", "REAL", "BOOLEAN", "CHAR", "VAR", "FOR", "DO",
  "WHILE", "ARRAY", "AND", "OR", "PROG_BEGIN", "END", "READ", "WRITE",
  "IF", "ELSE", "ELSEIF", "THEN", "TO", "DOWNTO", "PERIOD", "TXT",
  "LCPAREN", "RCPAREN", "IDENTIFIER", "INTVAL", "REALVAL", "BOOLVAL",
  "CHARVAL", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "ASSIGN", "COMMA",
  "COLON", "SEMICOLON", "LPAREN", "RPAREN", "LSPAREN", "RSPAREN",
  "UNDERSCORE", "SQUOTE", "DQUOTE", "OF", "$accept", "s", "program",
  "var_decl_section", "var_decl_list", "$@1", "$@2", "var_list", "$@3",
  "type", "statement_list", "statement", "read_stmt", "arr_list", "$@4",
  "write_stmt", "write_list", "block_stmt", "assignment_stmt", "expr",
  "term", "factor", "const", "conditional_stmt", "$@5", "if_st", "$@6",
  "loop", "$@7", "$@8", "$@9", 0
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
       0,    58,    59,    60,    61,    63,    62,    64,    62,    62,
      66,    65,    65,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    70,    70,    72,    71,    71,
      73,    74,    74,    74,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      78,    78,    78,    79,    79,    79,    79,    79,    80,    80,
      80,    80,    82,    81,    84,    83,    83,    86,    85,    87,
      85,    88,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     8,     2,     0,     6,     0,    14,     0,
       0,     4,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     1,     4,     4,     0,     7,     4,
       4,     1,     1,     1,     3,     3,     6,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     0,     3,
       3,     3,     1,     3,     1,     4,     1,     2,     1,     1,
       1,     1,     0,     6,     0,     3,     0,     0,     7,     0,
      11,     0,    11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     9,     0,    12,
       4,     0,    18,     0,     0,     0,    48,    18,     0,     0,
      48,     0,     0,     0,    20,    21,    24,    19,    22,    23,
       0,    13,    14,    15,    16,     0,     5,     0,     0,    54,
      58,    59,    60,    61,    48,    67,    37,    52,    56,     0,
       0,     0,    62,    48,     0,     0,    18,    11,     0,     0,
      48,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    10,
       0,     0,    31,    32,    33,     0,     0,    35,     0,     3,
      17,     0,     9,    69,     0,    53,    47,    46,    45,    44,
      38,    39,    40,    41,    42,    43,     0,    51,    50,    49,
       0,    25,    26,    30,     0,     0,     0,     6,     0,     0,
      55,    18,     0,    66,    48,     0,    48,    48,     0,    27,
      64,    63,    36,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,    65,     0,    18,    18,     0,    28,     0,
       0,     0,     7,    70,    72,     9,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    10,    59,   155,    11,    13,    36,
      22,    23,    24,    81,   137,    25,    85,    26,    27,    45,
      46,    47,    48,    28,    86,   131,   138,    29,    74,   118,
     119
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -102
static const yytype_int16 yypact[] =
{
      15,    19,    59,  -102,    -7,  -102,    43,    36,    56,    31,
    -102,    32,   150,    34,    88,    53,   122,   150,    39,    40,
     122,    -8,    69,    45,  -102,  -102,  -102,  -102,  -102,  -102,
      36,  -102,  -102,  -102,  -102,    62,  -102,    46,   122,    64,
    -102,  -102,  -102,  -102,   122,   107,    58,  -102,  -102,    73,
      82,     8,   107,   122,   122,    89,   150,  -102,    85,    74,
     122,  -102,   122,     7,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   106,   122,   122,   122,  -102,   -43,
      80,    81,  -102,  -102,  -102,    94,    96,   107,     0,  -102,
    -102,   115,    36,    42,    23,  -102,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,   104,  -102,  -102,  -102,
     122,  -102,  -102,  -102,   132,   108,   124,  -102,   127,   133,
    -102,   150,    26,   136,   122,   128,   122,   122,   144,   117,
    -102,  -102,   107,   116,    93,    99,  -102,   123,   132,   119,
     156,   157,   145,  -102,    57,   150,   150,   129,  -102,   130,
     160,   161,  -102,  -102,  -102,    36,  -102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -102,  -102,  -102,  -102,   -89,  -102,  -102,     5,  -102,    44,
     -17,  -102,  -102,   -49,  -102,  -102,  -102,  -101,  -102,   -19,
     -50,    -2,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -72
static const yytype_int16 yytable[] =
{
      49,    52,    84,   117,    88,    75,    76,    77,   -12,   110,
      64,    65,    94,   123,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     1,    63,    66,    67,    75,    76,
      77,    75,    76,    77,    87,    57,    61,   143,    53,    90,
      82,    93,     6,    79,    54,    64,    65,    68,    69,    70,
      71,    72,    73,   115,     4,    80,    83,     7,    95,     5,
     122,    66,    67,    75,    76,    77,   156,    31,    32,    33,
      34,     9,   -71,   107,   108,   109,   120,    12,   -10,   129,
      14,    30,    68,    69,    70,    71,    72,    73,    37,    50,
      51,    55,    60,   148,    56,    78,    64,    65,    31,    32,
      33,    34,    64,    65,   128,   132,    35,   134,   135,   140,
      64,    65,    66,    67,    58,   141,    62,    79,    66,    67,
      89,    91,   106,    92,   114,   121,    66,    67,   150,   151,
      38,   111,   112,    68,    69,    70,    71,    72,    73,    68,
      69,    70,    71,    72,    73,   113,   116,    68,    69,    70,
      71,    72,    73,    17,   124,   125,   126,    39,    40,    41,
      42,    43,   130,   127,   133,    15,   136,    16,   -29,   139,
     142,    17,    44,    18,    19,    20,   144,   145,   146,   152,
     147,   110,   153,   154,     0,    21,     0,     0,   149
};

static const yytype_int16 yycheck[] =
{
      17,    20,    51,    92,    54,     5,     6,     7,    51,    52,
       3,     4,    62,   114,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     9,    44,    19,    20,     5,     6,
       7,     5,     6,     7,    53,    30,    38,   138,    46,    56,
      32,    60,    49,    35,    52,     3,     4,    40,    41,    42,
      43,    44,    45,    53,    35,    50,    51,    14,    51,     0,
     110,    19,    20,     5,     6,     7,   155,    10,    11,    12,
      13,    35,    30,    75,    76,    77,    53,    21,    47,    53,
      48,    47,    40,    41,    42,    43,    44,    45,    35,    50,
      50,    22,    46,   142,    49,    22,     3,     4,    10,    11,
      12,    13,     3,     4,   121,   124,    18,   126,   127,    16,
       3,     4,    19,    20,    52,    16,    52,    35,    19,    20,
      31,    36,    16,    49,    28,    21,    19,    20,   145,   146,
       8,    51,    51,    40,    41,    42,    43,    44,    45,    40,
      41,    42,    43,    44,    45,    51,    31,    40,    41,    42,
      43,    44,    45,    21,    46,    31,    29,    35,    36,    37,
      38,    39,    26,    30,    36,    15,    22,    17,    51,    53,
      47,    21,    50,    23,    24,    25,    57,    21,    21,    49,
      35,    52,    22,    22,    -1,    35,    -1,    -1,   144
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    59,    60,    35,     0,    49,    14,    61,    35,
      62,    65,    21,    66,    48,    15,    17,    21,    23,    24,
      25,    35,    68,    69,    70,    73,    75,    76,    81,    85,
      47,    10,    11,    12,    13,    18,    67,    35,     8,    35,
      36,    37,    38,    39,    50,    77,    78,    79,    80,    68,
      50,    50,    77,    46,    52,    22,    49,    65,    52,    63,
      46,    79,    52,    77,     3,     4,    19,    20,    40,    41,
      42,    43,    44,    45,    86,     5,     6,     7,    22,    35,
      65,    71,    32,    65,    71,    74,    82,    77,    78,    31,
      68,    36,    49,    77,    78,    51,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    16,    79,    79,    79,
      52,    51,    51,    51,    28,    53,    31,    62,    87,    88,
      53,    21,    78,    75,    46,    31,    29,    30,    68,    53,
      26,    83,    77,    36,    77,    77,    22,    72,    84,    53,
      16,    16,    47,    75,    57,    21,    21,    35,    71,    67,
      68,    68,    49,    22,    22,    64,    62
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
#line 229 "t1.y"
    {return 0;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 238 "t1.y"
    {assign_type_to_var((yyvsp[(3) - (3)].t.type));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 239 "t1.y"
    {assign_array_to_var((yyvsp[(11) - (12)].t.type),(yyvsp[(5) - (12)].t.v.ival),(yyvsp[(8) - (12)].t.v.ival));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 243 "t1.y"
    {varnames[var_idx]=(yyvsp[(1) - (1)].t.type);var_idx++;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 244 "t1.y"
    {varnames[var_idx]=(yyvsp[(1) - (1)].t.type);var_idx++;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 247 "t1.y"
    {(yyval.t.type)=(yyvsp[(1) - (1)].t.type);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 248 "t1.y"
    {(yyval.t.type)=(yyvsp[(1) - (1)].t.type);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 249 "t1.y"
    {(yyval.t.type)=(yyvsp[(1) - (1)].t.type);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 250 "t1.y"
    {(yyval.t.type)=(yyvsp[(1) - (1)].t.type);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 268 "t1.y"
    {
		for(int i=0;i<var_idx;i++){
			int idx = search_table(varnames[i]);
			if(idx==-1){
				printf("ERROR : undeclared variable '%s'.\n",varnames[i]);
			}
			else{
				if(strcmp(symbol_table[idx].tp,"integer")==0){
					if(scanf("%d",&symbol_table[idx].vi.ival)!=1){
						printf("ERROR : input is not 'integer' type\n");
					}
					else symbol_table[idx].init=1;			
				}
				else if(strcmp(symbol_table[idx].tp,"real")==0){
					if(scanf("%f",&symbol_table[idx].vi.fval)!=1){
						printf("ERROR : input is not 'real' type\n");
					}
					else symbol_table[idx].init=1;
				}
				else if(strcmp(symbol_table[idx].tp,"char")==0){
					if(scanf("%c",&symbol_table[idx].vi.cval)!=1){
						printf("ERROR : input is not 'char' type\n");
					}
					else symbol_table[idx].init=1;
				}
				else if(strcmp(symbol_table[idx].tp,"boolean")==0){
					char str[100];
					if(scanf("%s",str)==1){
						if(strcmp(str,"true")==0 || strcmp(str,"false")==0){ symbol_table[idx].vi.sval = strdup(str);symbol_table[idx].init=1;}
						else printf("ERROR : input is not 'boolean' type\n");
					}
					else{
						printf("ERROR : input is not 'boolean' type\n");
					}
				}
			}
		}
		var_idx=0;
		printf("\n");

	;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 309 "t1.y"
    {
		for(int i=0;i<var_idx;i++){
			int ind = array_check_var_int_bound(varnames[i],arrtypes[i],arrvals[i]);
			if(ind!=-1){
				int arr_ind = arrvals[i];
				if(strcmp(symbol_table[ind].arr_tp,"integer")==0){
					if(scanf("%d",&symbol_table[ind].vi.intArray[arr_ind])!=1){
						printf("ERROR : input is not 'integer' type\n");
					}				
				}
				else if(strcmp(symbol_table[ind].arr_tp,"real")==0){
					if(scanf("%f",&symbol_table[ind].vi.floatArray[arr_ind])!=1){
						printf("ERROR : input is not 'real' type\n");
					}
				}
				else if(strcmp(symbol_table[ind].arr_tp,"char")==0){
					if(scanf("%c",&symbol_table[ind].vi.charArray[arr_ind])!=1){
						printf("ERROR : input is not 'char' type\n");
					}
				}
				else if(strcmp(symbol_table[ind].arr_tp,"boolean")==0){
					char str[100];
					if(scanf("%s",str)==1){
						if(strcmp(str,"true")==0 || strcmp(str,"false")==0) symbol_table[ind].vi.booleanArray[arr_ind] = strdup(str);	
						else printf("ERROR : input is not 'boolean' type\n");
					}
					else{
						printf("ERROR : input is not 'boolean' type\n");
					}
				}
			}
		}
		var_idx=0;
	;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 346 "t1.y"
    {varnames[var_idx]=(yyvsp[(1) - (4)].t.type);arrtypes[var_idx]=(yyvsp[(3) - (4)].t.type);arrvals[var_idx]=(yyvsp[(3) - (4)].t.v.ival);var_idx++;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 347 "t1.y"
    {varnames[var_idx]=(yyvsp[(1) - (4)].t.type);arrtypes[var_idx]=(yyvsp[(3) - (4)].t.type);arrvals[var_idx]=(yyvsp[(3) - (4)].t.v.ival);var_idx++;;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 355 "t1.y"
    {
		char* str = strdup((yyvsp[(1) - (1)].t.v.sval));
		int length = strlen(str);
		
		char result[length-1];
		strncpy(result,str+1,length-2);
		result[length-2]='\0';
		printf("%s\n",result);
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 364 "t1.y"
    {
		for(int i=0;i<var_idx;i++){
			int idx = search_table(varnames[i]);
			if(idx==-1){
				printf("ERROR : undeclared variable '%s'.\n",varnames[i]);
			}
			else{
				if(strcmp(symbol_table[idx].tp,"integer")==0)printf("%d ",symbol_table[idx].vi.ival);
				else if(strcmp(symbol_table[idx].tp,"real")==0)printf("%f ",symbol_table[idx].vi.fval);
				else if(strcmp(symbol_table[idx].tp,"char")==0)printf("%c ",symbol_table[idx].vi.cval);
				else if(strcmp(symbol_table[idx].tp,"boolean")==0)printf("%s ",symbol_table[idx].vi.sval);
			}
		}
		var_idx=0;
		printf("\n");
	;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 380 "t1.y"
    {
		for(int i=0;i<var_idx;i++){
			int ind = array_check_var_int_bound(varnames[i],arrtypes[i],arrvals[i]);
			int arr_ind = arrvals[i];
			if(strcmp(symbol_table[ind].arr_tp,"integer")==0)printf("%d ",symbol_table[ind].vi.intArray[arr_ind]);
			else if(strcmp(symbol_table[ind].arr_tp,"real")==0)printf("%f ",symbol_table[ind].vi.floatArray[arr_ind]);
			else if(strcmp(symbol_table[ind].arr_tp,"char")==0)printf("%c ",symbol_table[ind].vi.charArray[arr_ind]);
			else if(strcmp(symbol_table[ind].arr_tp,"boolean")==0)printf("%s ",symbol_table[ind].vi.booleanArray[arr_ind]);
		}
		var_idx=0;
	;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 397 "t1.y"
    {
		int idx = typecheck((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type));
		if(idx!=-1 && execute==1){
			symbol_table[idx].init=1;
			if(strcmp((yyvsp[(3) - (3)].t.type),"integer")==0){
				if(strcmp(symbol_table[idx].tp,"real")==0)symbol_table[idx].vi.fval = (yyvsp[(3) - (3)].t.v.ival);
				else symbol_table[idx].vi.ival = (yyvsp[(3) - (3)].t.v.ival);
			}
	       		else if(strcmp((yyvsp[(3) - (3)].t.type),"real")==0)symbol_table[idx].vi.fval = (yyvsp[(3) - (3)].t.v.fval);
	       		else if(strcmp((yyvsp[(3) - (3)].t.type),"boolean")==0)symbol_table[idx].vi.sval = (yyvsp[(3) - (3)].t.v.sval);
	       		else if(strcmp((yyvsp[(3) - (3)].t.type),"char")==0)symbol_table[idx].vi.cval = (yyvsp[(3) - (3)].t.v.cval);
		}	
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 410 "t1.y"
    {
		int idx = array_check_var_int_bound((yyvsp[(1) - (6)].t.type),(yyvsp[(3) - (6)].t.type),(yyvsp[(3) - (6)].t.v.ival));
		int arr_ind = (yyvsp[(3) - (6)].t.v.ival);
		if(strcmp(symbol_table[idx].arr_tp,(yyvsp[(6) - (6)].t.type))==0){
			if(strcmp(symbol_table[idx].arr_tp,"integer")==0)symbol_table[idx].vi.intArray[arr_ind] = (yyvsp[(6) - (6)].t.v.ival);
			else if(strcmp(symbol_table[idx].arr_tp,"real")==0)symbol_table[idx].vi.floatArray[arr_ind] = (yyvsp[(6) - (6)].t.v.fval);
			else if(strcmp(symbol_table[idx].arr_tp,"char")==0)symbol_table[idx].vi.intArray[arr_ind] = (yyvsp[(6) - (6)].t.v.cval);
			else if(strcmp(symbol_table[idx].arr_tp,"boolean")==0)symbol_table[idx].vi.booleanArray[arr_ind] = strdup((yyvsp[(6) - (6)].t.v.sval));
		}
		else{
			printf("ERROR : trying to assign '%s' to '%s' .\n",(yyvsp[(6) - (6)].t.type),symbol_table[idx].arr_tp);
			//exit(0);
		}
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 427 "t1.y"
    {
       		(yyval.t.type)=strdup((yyvsp[(1) - (1)].t.type));
       		if(strcmp((yyvsp[(1) - (1)].t.type),"integer")==0)(yyval.t.v.ival)=(yyvsp[(1) - (1)].t.v.ival);
       		else if(strcmp((yyvsp[(1) - (1)].t.type),"real")==0)(yyval.t.v.fval)=(yyvsp[(1) - (1)].t.v.fval);
       		else if(strcmp((yyvsp[(1) - (1)].t.type),"boolean")==0)(yyval.t.v.sval)=(yyvsp[(1) - (1)].t.v.sval);
       		else if(strcmp((yyvsp[(1) - (1)].t.type),"char")==0)(yyval.t.v.cval)=(yyvsp[(1) - (1)].t.v.cval);			
     ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 434 "t1.y"
    {
     		(yyval.t.type)=strdup("boolean");
     		if(strcmp((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
     			if(strcmp((yyvsp[(1) - (3)].t.type),"boolean")!=0){
     				//$<t.type>$=strdup("boolean");
	     			if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0){
	     				if((yyvsp[(1) - (3)].t.v.ival)==(yyvsp[(3) - (3)].t.v.ival))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
	     			}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0){
		       			if((yyvsp[(1) - (3)].t.v.fval)==(yyvsp[(3) - (3)].t.v.fval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"char")==0){
		       			if((yyvsp[(1) - (3)].t.v.cval)==(yyvsp[(3) - (3)].t.v.cval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
     			}
     			else {printf("ERROR : cannot perform '=' on 'boolean'.\n");}  	
     		}
     		else {printf("ERROR : type mismatch for '=' relop.\n");}   
     ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 456 "t1.y"
    {
     		(yyval.t.type)=strdup("boolean");
     		if(strcmp((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
     			if(strcmp((yyvsp[(1) - (3)].t.type),"boolean")!=0){
     				//$<t.type>$=strdup("boolean");
	     			if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0){
	     				if((yyvsp[(1) - (3)].t.v.ival) != (yyvsp[(3) - (3)].t.v.ival))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
	     			}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0){
		       			if((yyvsp[(1) - (3)].t.v.fval) != (yyvsp[(3) - (3)].t.v.fval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"char")==0){
		       			if((yyvsp[(1) - (3)].t.v.cval) != (yyvsp[(3) - (3)].t.v.cval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
     			}
     			else {printf("ERROR : cannot perform '<>' on 'boolean'.\n");}  	
     		}
     		else {printf("ERROR : type mismatch for '<>' relop.\n");}   
     ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 478 "t1.y"
    {
     		(yyval.t.type)=strdup("boolean");
     		if(strcmp((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
     			if(strcmp((yyvsp[(1) - (3)].t.type),"boolean")!=0){
     				//$<t.type>$=strdup("boolean");
	     			if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0){
	     				if((yyvsp[(1) - (3)].t.v.ival) < (yyvsp[(3) - (3)].t.v.ival))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
	     			}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0){
		       			if((yyvsp[(1) - (3)].t.v.fval) < (yyvsp[(3) - (3)].t.v.fval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"char")==0){
		       			if((yyvsp[(1) - (3)].t.v.cval) < (yyvsp[(3) - (3)].t.v.cval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
     			}
     			else {printf("ERROR : cannot perform '<' on 'boolean'.\n");}  	
     		}
     		else {printf("ERROR : type mismatch for '<' relop.\n");}   
     ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 500 "t1.y"
    {
     		(yyval.t.type)=strdup("boolean");
     		if(strcmp((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
     			if(strcmp((yyvsp[(1) - (3)].t.type),"boolean")!=0){
     				//$<t.type>$=strdup("boolean");
	     			if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0){
	     				if((yyvsp[(1) - (3)].t.v.ival) > (yyvsp[(3) - (3)].t.v.ival))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
	     			}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0){
		       			if((yyvsp[(1) - (3)].t.v.fval) > (yyvsp[(3) - (3)].t.v.fval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"char")==0){
		       			if((yyvsp[(1) - (3)].t.v.cval) > (yyvsp[(3) - (3)].t.v.cval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
     			}
     			else {printf("ERROR : cannot perform '>' on 'boolean'.\n");}  	
     		}
     		else {printf("ERROR : type mismatch for '>' relop.\n");}  
     ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 522 "t1.y"
    {
     		(yyval.t.type)=strdup("boolean");
     		if(strcmp((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
     			if(strcmp((yyvsp[(1) - (3)].t.type),"boolean")!=0){
     				//$<t.type>$=strdup("boolean");
	     			if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0){
	     				if((yyvsp[(1) - (3)].t.v.ival) <= (yyvsp[(3) - (3)].t.v.ival))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
	     			}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0){
		       			if((yyvsp[(1) - (3)].t.v.fval) <= (yyvsp[(3) - (3)].t.v.fval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"char")==0){
		       			if((yyvsp[(1) - (3)].t.v.cval) <= (yyvsp[(3) - (3)].t.v.cval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
     			}
     			else {printf("ERROR : cannot perform '<=' on 'boolean'.\n");}  	
     		}
     		else {printf("ERROR : type mismatch for '<=' relop.\n");}//$<t.v.sval>$=strdup("true");}   
     ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 544 "t1.y"
    {
     		(yyval.t.type)=strdup("boolean");
     		if(strcmp((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
     			if(strcmp((yyvsp[(1) - (3)].t.type),"boolean")!=0){
     				//$<t.type>$=strdup("boolean");
	     			if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0){
	     				if((yyvsp[(1) - (3)].t.v.ival) >= (yyvsp[(3) - (3)].t.v.ival))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
	     			}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0){
		       			if((yyvsp[(1) - (3)].t.v.fval) >= (yyvsp[(3) - (3)].t.v.fval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
		       		else if(strcmp((yyvsp[(1) - (3)].t.type),"char")==0){
		       			if((yyvsp[(1) - (3)].t.v.cval) >= (yyvsp[(3) - (3)].t.v.cval))(yyval.t.v.sval) = strdup("true");
	     				else (yyval.t.v.sval) = strdup("false");
		       		}
     			}
     			else {printf("ERROR : cannot perform '>=' on 'boolean'.\n");}  	
     		}
     		else {printf("ERROR : type mismatch for '>=' relop.\n");}   
     ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 566 "t1.y"
    {
     		(yyval.t.type)=strdup("boolean");
     		if(strcmp((yyvsp[(1) - (3)].t.type),"boolean")==0 && strcmp((yyvsp[(3) - (3)].t.type),"boolean")==0){
     			//$<t.type>$=strdup("boolean");
     			if(strcmp((yyvsp[(1) - (3)].t.v.sval),"true")==0 || strcmp((yyvsp[(3) - (3)].t.v.sval),"true")==0)(yyval.t.v.sval) = strdup("true");
     			else (yyval.t.v.sval) = strdup("false");
     		}
     		else {printf("ERROR : type mismatch for 'OR' relop.\n");}
     ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 575 "t1.y"
    {
     		(yyval.t.type)=strdup("boolean");
     		if(strcmp((yyvsp[(1) - (3)].t.type),"boolean")==0 && strcmp((yyvsp[(3) - (3)].t.type),"boolean")==0){
     			//$<t.type>$=strdup("boolean");
     			if(strcmp((yyvsp[(1) - (3)].t.v.sval),"true")==0 && strcmp((yyvsp[(3) - (3)].t.v.sval),"true")==0)(yyval.t.v.sval) = strdup("true");
     			else (yyval.t.v.sval) = strdup("false");
     		}
     		else {printf("ERROR : type mismatch for 'OR' relop.\n");}
     ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 584 "t1.y"
    {
    		if(is_any_bool_char((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
			if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0 && strcmp((yyvsp[(3) - (3)].t.type),"real")==0){
				(yyval.t.type) = strdup("real");
				(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.fval) + (yyvsp[(3) - (3)].t.v.fval);
			}
			else if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0 && strcmp((yyvsp[(3) - (3)].t.type),"integer")==0){
				(yyval.t.type) = strdup("real");
				(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.fval) + (yyvsp[(3) - (3)].t.v.ival);
			}
			else if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0 && strcmp((yyvsp[(3) - (3)].t.type),"real")==0){
				(yyval.t.type) = strdup("real");
				(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.ival) + (yyvsp[(3) - (3)].t.v.fval);
			}
			else if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0 && strcmp((yyvsp[(3) - (3)].t.type),"integer")==0){
				(yyval.t.type) = strdup("integer");
				(yyval.t.v.ival) = (yyvsp[(1) - (3)].t.v.ival) + (yyvsp[(3) - (3)].t.v.ival);
			} 
		}
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 604 "t1.y"
    {
    		if(is_any_bool_char((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
			if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0 && strcmp((yyvsp[(3) - (3)].t.type),"real")==0){
				(yyval.t.type) = strdup("real");
				(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.fval) - (yyvsp[(3) - (3)].t.v.fval);
			}
			else if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0 && strcmp((yyvsp[(3) - (3)].t.type),"integer")==0){
				(yyval.t.type) = strdup("real");
				(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.fval) - (yyvsp[(3) - (3)].t.v.ival);
			}
			else if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0 && strcmp((yyvsp[(3) - (3)].t.type),"real")==0){
				(yyval.t.type) = strdup("real");
				(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.ival) - (yyvsp[(3) - (3)].t.v.fval);
			}
			else if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0 && strcmp((yyvsp[(3) - (3)].t.type),"integer")==0){
				(yyval.t.type) = strdup("integer");
				(yyval.t.v.ival) = (yyvsp[(1) - (3)].t.v.ival) - (yyvsp[(3) - (3)].t.v.ival);
			} 
		}
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 628 "t1.y"
    {
		if(is_any_bool_char((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
			if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0 && strcmp((yyvsp[(3) - (3)].t.type),"real")==0){
				(yyval.t.type) = strdup("real");
				(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.fval) * (yyvsp[(3) - (3)].t.v.fval);
			}
			else if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0 && strcmp((yyvsp[(3) - (3)].t.type),"integer")==0){
				(yyval.t.type) = strdup("real");
				(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.fval) * (yyvsp[(3) - (3)].t.v.ival);
			}
			else if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0 && strcmp((yyvsp[(3) - (3)].t.type),"real")==0){
				(yyval.t.type) = strdup("real");
				(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.ival) * (yyvsp[(3) - (3)].t.v.fval);
			}
			else if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0 && strcmp((yyvsp[(3) - (3)].t.type),"integer")==0){
				(yyval.t.type) = strdup("integer");
				(yyval.t.v.ival) = (yyvsp[(1) - (3)].t.v.ival) * (yyvsp[(3) - (3)].t.v.ival);
			} 
		}
		//else $<t.type>$ = strdup($<t.type>3);
		//else not written

	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 651 "t1.y"
    {
    		if(is_any_bool_char((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
    			(yyval.t.type) = strdup("real");
			if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0 && strcmp((yyvsp[(3) - (3)].t.type),"real")==0)(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.fval) / (yyvsp[(3) - (3)].t.v.fval);
			else if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0 && strcmp((yyvsp[(3) - (3)].t.type),"integer")==0)(yyval.t.v.fval) = (yyvsp[(1) - (3)].t.v.fval) / (float)(yyvsp[(3) - (3)].t.v.ival);
			else if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0 && strcmp((yyvsp[(3) - (3)].t.type),"real")==0)(yyval.t.v.fval) = (float)(yyvsp[(1) - (3)].t.v.ival) / (yyvsp[(3) - (3)].t.v.fval);
			else if(strcmp((yyvsp[(1) - (3)].t.type),"integer")==0 && strcmp((yyvsp[(3) - (3)].t.type),"integer")==0)(yyval.t.v.fval) = (float)(yyvsp[(1) - (3)].t.v.ival) / (float)(yyvsp[(3) - (3)].t.v.ival);
		}	
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 660 "t1.y"
    {
    		if(is_any_bool_char((yyvsp[(1) - (3)].t.type),(yyvsp[(3) - (3)].t.type))==0){
    			if(strcmp((yyvsp[(1) - (3)].t.type),"real")==0 || strcmp((yyvsp[(3) - (3)].t.type),"real")==0){
    				printf("ERROR : cannot perform modulo '%%' operation on 'real' datatype.\n");
    			}
    			else{
    				(yyval.t.type) = strdup("integer");
    				(yyval.t.v.ival) = (yyvsp[(1) - (3)].t.v.ival) % (yyvsp[(3) - (3)].t.v.ival);
    			}
    		}
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 671 "t1.y"
    {
       		(yyval.t.type)=strdup((yyvsp[(1) - (1)].t.type));
       		if(strcmp((yyvsp[(1) - (1)].t.type),"integer")==0)(yyval.t.v.ival)=(yyvsp[(1) - (1)].t.v.ival);
       		else if(strcmp((yyvsp[(1) - (1)].t.type),"real")==0)(yyval.t.v.fval)=(yyvsp[(1) - (1)].t.v.fval);
       		else if(strcmp((yyvsp[(1) - (1)].t.type),"boolean")==0)(yyval.t.v.sval)=(yyvsp[(1) - (1)].t.v.sval);
       		else if(strcmp((yyvsp[(1) - (1)].t.type),"char")==0)(yyval.t.v.cval)=(yyvsp[(1) - (1)].t.v.cval);	
       ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 680 "t1.y"
    {
		(yyval.t.type)=strdup((yyvsp[(2) - (3)].t.type));
       		if(strcmp((yyvsp[(2) - (3)].t.type),"integer")==0)(yyval.t.v.ival)=(yyvsp[(2) - (3)].t.v.ival);
       		else if(strcmp((yyvsp[(2) - (3)].t.type),"real")==0)(yyval.t.v.fval)=(yyvsp[(2) - (3)].t.v.fval);
       		else if(strcmp((yyvsp[(2) - (3)].t.type),"boolean")==0)(yyval.t.v.sval)=(yyvsp[(2) - (3)].t.v.sval);
       		else if(strcmp((yyvsp[(2) - (3)].t.type),"char")==0)(yyval.t.v.cval)=(yyvsp[(2) - (3)].t.v.cval);	
	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 687 "t1.y"
    {
       		int ind = search_table((yyvsp[(1) - (1)].t.type));
       		if(ind==-1) printf("ERROR : undeclared variable '%s' .\n",(yyvsp[(1) - (1)].t.type));
       		else{
       			(yyval.t.type)=strdup(symbol_table[ind].tp);
       			if(symbol_table[ind].init==1){
	       			(yyval.t.type)=strdup(symbol_table[ind].tp);
	       			if(strcmp((yyval.t.type),"integer")==0)(yyval.t.v.ival)=symbol_table[ind].vi.ival;
		       		else if(strcmp((yyval.t.type),"real")==0)(yyval.t.v.fval)=symbol_table[ind].vi.fval;
		       		else if(strcmp((yyval.t.type),"boolean")==0)(yyval.t.v.sval)=symbol_table[ind].vi.sval;
		       		else if(strcmp((yyval.t.type),"char")==0)(yyval.t.v.cval)=symbol_table[ind].vi.cval;	
	       		}
	       		else{
	       			printf("ERROR : using the variable '%s' before a value is set.\n",(yyvsp[(1) - (1)].t.type));
	       		}
	       	}
       	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 704 "t1.y"
    {
       		int ind = array_check_var_int_bound((yyvsp[(1) - (4)].t.type),(yyvsp[(3) - (4)].t.type),(yyvsp[(3) - (4)].t.v.ival));
       		if(ind!=-1){
       			int arr_ind = (yyvsp[(3) - (4)].t.v.ival);
			(yyval.t.type)=strdup(symbol_table[ind].arr_tp);
			if(strcmp((yyval.t.type),"integer")==0)(yyval.t.v.ival) = symbol_table[ind].vi.intArray[arr_ind];
			else if(strcmp((yyval.t.type),"real")==0)(yyval.t.v.fval) = symbol_table[ind].vi.floatArray[arr_ind];
			else if(strcmp((yyval.t.type),"char")==0)(yyval.t.v.cval) = symbol_table[ind].vi.intArray[arr_ind];
			else if(strcmp((yyval.t.type),"boolean")==0)(yyval.t.v.sval) = strdup(symbol_table[ind].vi.booleanArray[arr_ind]);
       		}
		
       		    
       ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 717 "t1.y"
    {
       		(yyval.t.type)=strdup((yyvsp[(1) - (1)].t.type));
       		if(strcmp((yyvsp[(1) - (1)].t.type),"integer")==0)(yyval.t.v.ival)=(yyvsp[(1) - (1)].t.v.ival);
       		else if(strcmp((yyvsp[(1) - (1)].t.type),"real")==0)(yyval.t.v.fval)=(yyvsp[(1) - (1)].t.v.fval);
       		else if(strcmp((yyvsp[(1) - (1)].t.type),"boolean")==0)(yyval.t.v.sval)=(yyvsp[(1) - (1)].t.v.sval);
       		else if(strcmp((yyvsp[(1) - (1)].t.type),"char")==0)(yyval.t.v.cval)=(yyvsp[(1) - (1)].t.v.cval);	
       ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 724 "t1.y"
    {
       		(yyval.t.type)=strdup("boolean");
       		if(strcmp((yyvsp[(2) - (2)].t.type),"boolean")==0){
     			//$<t.type>$=strdup("boolean");
     			if(strcmp((yyvsp[(2) - (2)].t.v.sval),"true")==0)(yyval.t.v.sval) = strdup("false");
     			else (yyval.t.v.sval) = strdup("true");
     		}
     		else {printf("ERROR : type mismatch for 'NOT' relop.\n");}
       ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 734 "t1.y"
    {(yyval.t.type)=(yyvsp[(1) - (1)].t.type);(yyval.t.v.ival)=(yyvsp[(1) - (1)].t.v.ival);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 735 "t1.y"
    {(yyval.t.type)=(yyvsp[(1) - (1)].t.type);(yyval.t.v.fval)=(yyvsp[(1) - (1)].t.v.fval);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 736 "t1.y"
    {(yyval.t.type)=(yyvsp[(1) - (1)].t.type);(yyval.t.v.sval)=(yyvsp[(1) - (1)].t.v.sval);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 737 "t1.y"
    {(yyval.t.type)=(yyvsp[(1) - (1)].t.type);(yyval.t.v.cval)=(yyvsp[(1) - (1)].t.v.cval);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 745 "t1.y"
    {ifunc((yyvsp[(2) - (2)].t.type),(yyvsp[(2) - (2)].t.v.sval));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 748 "t1.y"
    {if(execute==0)execute=1;else execute=0;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 748 "t1.y"
    {execute=1;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 749 "t1.y"
    {execute=1;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 752 "t1.y"
    {wfunc((yyvsp[(2) - (2)].t.type),(yyvsp[(2) - (2)].t.v.sval));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 753 "t1.y"
    {is_int((yyvsp[(4) - (4)].t.type));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 754 "t1.y"
    {is_int((yyvsp[(4) - (4)].t.type));;}
    break;



/* Line 1455 of yacc.c  */
#line 2492 "t1.tab.c"
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
#line 757 "t1.y"



void display_input_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    // Display the contents of the file
    char ch;
    printf("Displaying contents of file %s:\n\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
    printf("\n\nStarting compilation...\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: No input file provided. Usage: ./parser <filename>\n");
        exit(1);
    }

    // Display the input Pascal file
    display_input_file(argv[1]);

    // Open the file for parsing
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Error: Could not open input file %s\n", argv[1]);
        exit(1);
    }

    // Call the parser
    yyparse();

    // After parsing, display symbol table (or any other table)
    display_stable();

    fclose(yyin);
    return 0;
}

void yyerror(const char *s) {
    printf("Syntax error: %s\n", s);
    exit(1);
}


