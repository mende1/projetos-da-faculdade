%option noyywrap yylineno nodefault
%{
#include "blite.tab.h"
#include "expr.h"
%}

%%

[ \t\n\r]+    { /* ignore whitespace */ }
"//".*      { /* ignore comments */ }

[0-9]+      { 
  yylval.d = atoi(yytext);
  return INTEGER_CONST; 
}

"boolean"   { return BOOLEAN; }
"else"      { return ELSE; }
"function"  { return FUNCTION; }
"if"        { return IF; }
"integer"   { return INTEGER; }
"print"     { return PRINT; }
"return"    { return RETURN; }
"while"     { return WHILE; }
"void"      { return VOID; }
"false"     { return BOOLEAN_CONST_FALSE; }
"true"      { return BOOLEAN_CONST_TRUE; }

"<="       { return LEQ; }
">="       { return GEQ; }
"=="       { return EQ; }
"!="       { return NEQ; }

"+"        { return PLUS; }
"-"        { return MINUS; }
"*"        { return TIMES; }
"/"        { return DIVIDE; }
"<"        { return LT; }
">"        { return GT; }
"="        { return ASSIGN; }
":"        { return COLON; }
";"        { return SEMICOLON; }
","        { return COMMA; }
"\("       { return LPAREN; }
"\)"       { return RPAREN; }
"\{"       { return LBRACE; }
"\}"       { return RBRACE; }

[a-zA-Z][a-zA-Z0-9_]* {
  yylval.name = strdup(yytext);

  if (yyleng > 256) return ERROR; 
  else return ID; 
}

. { return ERROR; }

%%

