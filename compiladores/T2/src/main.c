// main.c for T1 - Lexical Analysis for B-Lite

#include <stdio.h>
#include <stdlib.h>
#include "blite.tab.h"

/* interface to lexer */

extern int yylineno; /* from lexer */
extern char *yytext;
extern int yylex();
extern int yyparse();

int main(int argc, char **argv) {
if (!yyparse()) printf("no syntax error\n");
}

