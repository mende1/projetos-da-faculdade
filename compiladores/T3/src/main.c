/* main.c */

#include <stdio.h>
#include <stdlib.h>

#include "decl.h"
#include "blite.tab.h"

extern int yyparse();
extern struct decl *parser_result;

int main(int argc, char **argv) {

    extern FILE *yyin;
    extern FILE *yyout;

    if (argc > 2) {
        if(!(yyin = fopen(argv[1], "r"))) {
            fprintf(stderr,"Erro na abertura do arquivo de entrada %s\n",argv[1]);
            return (1);
        }
        if(!(yyout = fopen(argv[2], "w"))) {
            fprintf(stderr,"Erro na criacao do arquivo de saida %s\n",argv[2]);
            return (1);
        }
    }
    else {
        fprintf(stderr,"Erro no número de argumentos passados para blite-minus\n");
        return (1);
    }

    if (!yyparse()) {
        fprintf(stderr,"no syntax errors\n");
        printAST(parser_result);
	fclose(yyout);
    }
}
