#include <stdlib.h>
#include "ast.h"

struct expr * expr_create(expr_t kind, struct expr *left, struct expr *right ) {
  struct expr *e = malloc(sizeof(*e));
  e->kind = kind;
  e->value = 0;
  e->left = left;
  e->right = right;
  return e;
}

struct expr * expr_create_value( int value ) {
  struct expr *e = expr_create(EXPR_VALUE,0,0);
  e->value = value;
  return e;
}