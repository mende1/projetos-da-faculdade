#include <stdio.h> 
#include <stdlib.h> 
#include "e7.tab.h"

/* parser */

int yyparse();
extern int parser_result;  /* definir e atribuir valor em e7.y */

int main()
{
    if (!yyparse()) 
	fprintf(stdout,"%d\n", parser_result);
    else 
	fprintf(stdout, "syntax error\n");
    exit(0);
}
