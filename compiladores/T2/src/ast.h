#ifndef EXPR_H
#define EXPR_H

typedef enum {
  EXPR_ADD,
  EXPR_SUBTRACT,
  EXPR_MULTIPLY,
  EXPR_VALUE
} expr_t;

struct expr {
  expr_t kind;
  struct expr *left;
  struct expr *right;
  int value;
};

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );
struct expr * expr_create_value( int value );

#endif