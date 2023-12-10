%{
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
%}

%union {
   int d;
   char *name;
   int integer;
   struct type *type;
   struct expr *expr;
   struct stmt *stmt;
   struct decl *decl;
   struct param_list *param_list;
}

%token <name> ID
%token <integer> INTEGER
%token <integer> BOOLEAN
%token <type> VOID
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
%token INTEGER_CONST
%token BOOLEAN_CONST_TRUE
%token BOOLEAN_CONST_FALSE
%token ERROR

%left PLUS MINUS
%left TIMES DIVIDE
%nonassoc LT LEQ GT GEQ EQ NEQ

%type <expr> expr expr_add_minus expr_mult_div expr_relational expr_primary function_call_arguments function_call print_arguments
%type <stmt> statements statement block assignment_statement return_statement if_statement while_statement print_statement
%type <type> type
%type <decl> declaration declarations var_declaration func_declaration program local_declarations
%type <param_list> param_list params param

%%

program
: declarations
   { parser_result = $1; return 0;}
;

declarations
: declarations declaration
   {
      if ($2 != NULL) {
         struct decl *current = $1;
         while (current->next != NULL) {
            current = current->next;
         }
         current->next = $2;
         $$ = $1;  // Result is the head of the list
      } else {
         $$ = $1;  // No new declaration, result is the same as before
      }
   
   }
| declaration { $$ = $1; }
;

declaration
: var_declaration SEMICOLON { $$ = $1;  }
| func_declaration { $$ = $1; }
;

type
: INTEGER
   { $$ = type_create(TYPE_INTEGER, NULL, NULL); }
| BOOLEAN
   { $$ = type_create(TYPE_BOOLEAN, NULL, NULL); }
| VOID
   { $$ = type_create(TYPE_VOID, NULL, NULL); }
;

func_declaration
: ID COLON FUNCTION type LPAREN params RPAREN ASSIGN block
   { $$ = func_decl_create($1, $4, $6, $9); }
;

params
: /* empty */ 
   {$$ = NULL;}
| param_list
;

param_list
: param_list COMMA param 
   { 
      if ($3 != NULL) {
         struct param_list *current = $1;
         while (current->next != NULL) {
            current = current->next;
         }
         current->next = $3;
         $$ = $1;  // Result is the head of the list
      } else {
         $$ = $1;  // No new param, result is the same as before
      }
   }
| param 
   {$$ = $1;}
;

param
: ID COLON type 
   {$$ = param_create($1, $3); }
;

var_declaration
: ID COLON type                  
   { $$ = var_decl_create($1, $3, NULL); }
| ID COLON type ASSIGN expr     
   { $$ = var_decl_create($1, $3, $5); }
;

block
: LBRACE statements RBRACE 
   { $$ = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, $2, NULL, NULL); }
| LBRACE local_declarations SEMICOLON statements RBRACE 
   { $$ = stmt_create(STMT_BLOCK, $2, NULL, NULL, NULL, $4, NULL, NULL); }
;

statements
: statements statement
   { 
      if ($2 != NULL) {
         struct stmt *current = $1;
         while (current->next != NULL) {
            current = current->next;
         }
         current->next = $2;
         $$ = $1;  // Result is the head of the list
      } else {
         $$ = $1;  // No new statement, result is the same as before
      }
   }
| statement
;

local_declarations
: local_declarations SEMICOLON var_declaration 
   { 
      if ($3 != NULL) {
         struct decl *current = $1;
         while (current->next != NULL) {
            current = current->next;
         }
         current->next = $3;
         $$ = $1;  // Result is the head of the list
      } else {
         $$ = $1;  // No new declaration, result is the same as before
      }
   }
| var_declaration
   { $$ = $1; }
;

statement
: block
| assignment_statement SEMICOLON
| return_statement SEMICOLON
| if_statement
| while_statement
| print_statement SEMICOLON
| function_call SEMICOLON { $$ = stmt_create(STMT_EXPR, NULL, NULL, $1, NULL, NULL, NULL, NULL);  }
;

assignment_statement
: ID ASSIGN expr 
   {
      struct expr *left = expr_create_var($1);
      struct expr *right = $3;
      struct expr *assignment_expr = expr_create(EXPR_ASSIGN, left, right);
      $$ = stmt_create(STMT_EXPR, NULL, NULL, assignment_expr, NULL, NULL, NULL, NULL);
   }
;

return_statement
: RETURN expr 
   { $$ = stmt_create(STMT_RETURN, NULL, NULL, $2, NULL, NULL, NULL, NULL); }
| RETURN 
   { $$ = stmt_create(STMT_RETURN, NULL, NULL, NULL, NULL, NULL, NULL, NULL); }
;

if_statement
: IF LPAREN expr RPAREN statement 
   { $$ = if_create($3, $5); }
| IF LPAREN expr RPAREN statement ELSE statement 
   { $$ = if_else_create($3, $5, $7); }
;

while_statement
: WHILE LPAREN expr RPAREN statement 
   { $$ = while_create($3, $5); }
;

print_statement
: PRINT print_arguments
   {$$ = print_stmt_create($2);}
;

print_arguments
: expr 
   { $$ = $1; }
| print_arguments COMMA expr
   {  $$ = expr_create_arg($3, $1); }
;

expr
: expr_add_minus
   { $$ = $1; }
| expr_relational
   { $$ = $1; }
;

expr_add_minus
: expr_add_minus PLUS expr_mult_div
   { $$ = expr_create(EXPR_ADD, $1, $3); }
| expr_add_minus MINUS expr_mult_div
   { $$ = expr_create(EXPR_SUB, $1, $3);}
| expr_mult_div
   { $$ = $1; }
;

expr_mult_div
: expr_mult_div TIMES expr_primary
   { $$ = expr_create(EXPR_MUL, $1, $3); }
| expr_mult_div DIVIDE expr_primary
   { $$ = expr_create(EXPR_DIV, $1, $3); }
| expr_primary
   { $$ = $1; }
;

expr_relational
: expr_primary LT expr_primary
   { $$ = expr_create(EXPR_LT, $1, $3);  }
| expr_primary LEQ expr_primary
   { $$ = expr_create(EXPR_LTEQ, $1, $3); }
| expr_primary GT expr_primary
   { $$ = expr_create(EXPR_GT, $1, $3); }
| expr_primary GEQ expr_primary
   { $$ = expr_create(EXPR_GTEQ, $1, $3); }
| expr_primary EQ expr_primary
   { $$ = expr_create(EXPR_EQ, $1, $3); }
| expr_primary NEQ expr_primary
   { $$ = expr_create(EXPR_NEQ, $1, $3); }
;

expr_primary
: ID                    
   { $$ = expr_create_var($1); }
| INTEGER_CONST         
   { $$ = create_integer_literal(atoi(yytext)); }
| BOOLEAN_CONST_FALSE         
   { $$ = create_boolean_literal(0); }
| BOOLEAN_CONST_TRUE         
   { $$ = create_boolean_literal(1); }
| LPAREN expr RPAREN          
   { $$ = $2; }
| function_call
;

function_call
: ID LPAREN RPAREN
   { $$ = expr_create_call($1, NULL); }
| ID LPAREN function_call_arguments RPAREN
   { $$ = expr_create_call($1, $3); }
;

function_call_arguments
: expr
   { $$ = expr_create_arg($1, NULL);}
| function_call_arguments COMMA expr
   { $$ = expr_create_arg($3, $1); }
;

%%

void yyerror(const char *s) {
   fprintf(stdout, "%s\n", s);
}