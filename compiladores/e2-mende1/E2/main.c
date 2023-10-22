#include <stdio.h> 
#include <stdlib.h> 
#include "e2.tab.h"

/* parser */

int yyparse();

void yyerror(char *s, ...)
{
    printf("%s\n", s); 
}

int main()
{
    int result = yyparse(); 
    exit(0);
}
