/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 128 "blite.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

