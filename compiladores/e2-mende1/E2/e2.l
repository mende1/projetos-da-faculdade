/* recognize tokens for the calculator */ 

%option noyywrap nodefault yylineno
%{
#include "e2.tab.h"

void yyerror(char *s, ...);
%}

%%

"+" 	{ return PLUS; }
"-" 	{ return MINUS; }
"*" 	{ return TIMES; }
"/" 	{ return DIV; }
"(" 	{ return OPENP; } 
")" 	{ return CLOSEP; } 

[0-9]+ 	{ return NUMBER; } 
[ \t] 	{ /* ignore white space */ }
\n      { return EOL; }
.   	{ return ERROR; }
%%

