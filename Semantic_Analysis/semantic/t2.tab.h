
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 198 "t2.y"

 struct{
  char *type;
  union{
  	int ival;
  	float fval;
  	char cval;
  	char* sval;
  }v;
 }t;



/* Line 1676 of yacc.c  */
#line 123 "t2.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


