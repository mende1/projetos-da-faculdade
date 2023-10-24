#include <stdio.h> 
#include <stdlib.h> 
#include "e8.tab.h"
#include "ast.h"

/* parser */

int yyparse();
extern struct expr * parser_result;

int expr_evaluate( struct expr *e ) {
    if(!e) return 0;
    int l = expr_evaluate(e->left);
    int r = expr_evaluate(e->right);

    switch(e->kind) {
			case EXPR_VALUE:    return e->value;
			case EXPR_ADD:      return l+r;
			case EXPR_SUBTRACT: return l-r;
			case EXPR_MULTIPLY: return l*r;
    }
    return 0; 
}

int main() {
  if (yyparse()) 
		fprintf(stdout, "syntax error\n");
  else
		fprintf(stdout,"%d\n", expr_evaluate(parser_result));
     
  exit(0);
}
