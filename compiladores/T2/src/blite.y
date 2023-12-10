%{
#include <stdio.h>
#include <stdlib.h>

/* interface to lexer */
 
extern int yylineno; /* from lexer */
void yyerror(const char *);
int yydebug = 1;
int yylex();
%}

%token BLANK
%token NEWLINE
%token TAB
%token COMMENT
%token ID
%token INTEGER
%token BOOLEAN
%token PLUS
%token MINUS
%token TIMES
%token DIVIDE
%token LT
%token LEQ
%token GT
%token GEQ
%token EQ
%token NEQ
%token ASSIGN
%token COLON
%token SEMICOLON
%token LPAREN
%token RPAREN
%token LBRACE
%token RBRACE
%token FUNCTION
%token IF
%token ELSE
%token WHILE
%token RETURN
%token PRINT
%token COMMA
%token ERROR
%token STR
%token TRUE
%token FALSE
%token VOID
%token INTEGER_CONST
%token BOOLEAN_CONST
%token NUMBER

%left PLUS MINUS
%left TIMES DIVIDE
%nonassoc LT LEQ GT GEQ EQ NEQ

%%

program
: declarations
;

declarations
: declarations declaration
| declaration
;

declaration
: var_declaration SEMICOLON
| func_declaration
;

type
: INTEGER
| BOOLEAN
;

func_declaration
: ID COLON FUNCTION type LPAREN params RPAREN ASSIGN block
| ID COLON FUNCTION VOID LPAREN params RPAREN ASSIGN block
;

params
: /* empty */
| param_list
;

param_list
: param_list COMMA param
| param
;

param
: ID COLON type
;

var_declaration
: ID COLON type
| ID COLON type ASSIGN expr
;

block
: LBRACE statements RBRACE
;

statements
: var_declaration_and_statements statements
| statement
;

var_declaration_and_statements
: var_declaration SEMICOLON
| statement
;

statement
: block
| assignment_statement SEMICOLON
| return_statement SEMICOLON
| if_statement
| while_statement
| print_statement SEMICOLON
;

assignment_statement
: ID ASSIGN expr
;

return_statement
: RETURN expr
| RETURN
;

if_statement
: IF LPAREN expr RPAREN statement
| IF LPAREN expr RPAREN statement ELSE statement
;

while_statement
: WHILE LPAREN expr RPAREN statement
;

print_statement
: PRINT print_arguments
;

print_arguments
: expr
| print_arguments COMMA expr
;

expr
: expr_add
| expr_relational
;

expr_add
: expr_add PLUS expr_mult
| expr_mult
;

expr_mult
: expr_mult TIMES expr_divide
| expr_divide
;

expr_divide
: expr_divide DIVIDE expr_minus
| expr_minus
;

expr_minus
: expr_minus MINUS expr_primary
| expr_primary
;

expr_relational
: expr_primary LT expr_primary
| expr_primary LEQ expr_primary
| expr_primary GT expr_primary
| expr_primary GEQ expr_primary
| expr_primary EQ expr_primary
| expr_primary NEQ expr_primary
;

expr_primary
: ID
| INTEGER_CONST
| BOOLEAN_CONST
| LPAREN expr RPAREN
| function_call
;

function_call
: ID LPAREN RPAREN
| ID LPAREN function_call_arguments RPAREN
;

function_call_arguments
: expr
| function_call_arguments COMMA expr
;

%%

void yyerror(const char *s) {
   fprintf(stdout, "%s\n", s);
}