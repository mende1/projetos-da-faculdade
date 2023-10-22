// main.c for T1 - Lexical Analysis for B-Lite

#include <stdio.h>
#include <stdlib.h>
#include "blite.tab.h"

/* interface to lexer */

extern int yylineno; /* from lexer */
extern char *yytext;
extern int yylex();

int main(int argc, char **argv) {
    int token;

    extern FILE *yyin; 
    FILE *fout; 

    if (argc > 2) {
        if(!(yyin = fopen(argv[1], "r"))) {
            printf("erro na abertura do arquivo de entrada %s\n",argv[1]);
            return (1); 
        }
    	if(!(fout = fopen(argv[2], "w"))) {
            printf("erro na criacao do arquivo de saida %s\n",argv[2]);
            return (1);
        }
    }
    else {
        printf("erro no número de argumentos de entrada\n");
        return (1);
    }
    while ((token = yylex())) {
        switch (token) {
         case ERROR:
            fprintf(fout, "(%d,ERROR,\"%s\")\n", yylineno, yytext);
            break;
         case NUM: 
            fprintf(fout, "(%d,NUM,\"%s\")\n", yylineno, yytext);
            break; 
         case ID: 
            fprintf(fout, "(%d,ID,\"%s\")\n", yylineno, yytext);
            break;
         case KEY:
            fprintf(fout, "(%d,KEY,\"%s\")\n", yylineno, yytext);
            break;
         case SYM: 
            fprintf(fout, "(%d,SYM,\"%s\")\n", yylineno, yytext);
            break;
         case SYMC: 
            fprintf(fout, "(%d,SYMC,\"%s\")\n", yylineno, yytext);
            break;
	 case STRING:
            fprintf(fout, "(%d,STR,\"%s\")\n", yylineno, yytext);
            break;
        }
    }
    fclose(fout);
}

void yyerror(char *s) {
   fprintf(stdout, "%s\n", s);
}


