
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

/* Line 1676 of yacc.c  */
#line 39 "cg2.y"

char* lexeme;
char* arrtype;



/* Line 1676 of yacc.c  */
#line 116 "cg2.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


