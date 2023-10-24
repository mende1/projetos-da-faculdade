%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

struct expr * parser_result = 0;

/* interface to the lexer */
 
extern int yylineno; /* from lexer */
int yylex();

void yyerror(char *s, ...)
{
    // fprintf(stderr,"%s\n",s);
}

%}

%union {
	struct expr *e;
	int value;
}

%type <e> expr term factor program

/* declare tokens */ 
%token <value> NUMBER
%token <e> ERROR
%token <e> EOL
%token <e> PLUS
%token <e> MINUS
%token <e> TIMES
%token <e> OPENP
%token <e> CLOSEP

%start program

%%
program
: expr EOL { parser_result = $1; return 0; }
;

expr
: expr PLUS term    { $$ = expr_create(EXPR_ADD,$1,$3); }
| expr MINUS term   { $$ = expr_create(EXPR_SUBTRACT,$1,$3); }
| term              { $$ = $1; }
;

term
: term TIMES factor { $$ = expr_create(EXPR_MULTIPLY,$1,$3); }
| factor            { $$ = $1; }
;

factor
: NUMBER                 { $$ = expr_create_value($1); }
| OPENP expr CLOSEP      { $$ = $2; }
;

%%

