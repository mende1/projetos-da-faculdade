/* recognize tokens for the calculator */ 

%option noyywrap nodefault yylineno
%{
#include "e8.tab.h"
#include "ast.h"

void yyerror(char *s, ...);
%}

%%

"+" 	{ return PLUS; }
"-" 	{ return MINUS; }
"*" 	{ return TIMES; }
"(" 	{ return OPENP; } 
")" 	{ return CLOSEP; } 

[0-9]+ 	{ 
  yylval.e = expr_create_value(atoi(yytext));
  return NUMBER; 
}

[ \t] 	{ /* ignore white space */ }
\n      { return EOL; }
.   	  { return ERROR; }
%%

