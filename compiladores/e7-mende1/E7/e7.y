%{
#include <stdio.h>
#include <stdlib.h>

/* interface to the lexer */
 
extern int yylineno; /* from lexer */
int parser_result;
int yylex();

void yyerror(char *s, ...) {  }
%}

/* declare tokens */ 
%token NUMBER
%token ERROR
%token EOL
%token PLUS
%token MINUS
%token TIMES
%token OPENP
%token CLOSEP

%start program

%%
program
: expr EOL { parser_result = $1; return 0; }
;

expr
: expr PLUS term    { $$ = $1 + $3; }
| expr MINUS term   { $$ = $1 - $3; }
| term                   { $$ = $1; }
;

term
: term TIMES factor { $$ = $1 * $3; }
| factor                 { $$ = $1; }
;

factor
: NUMBER                 { $$ = $1; }
| OPENP expr CLOSEP      { $$ = $2; }
;

%%

