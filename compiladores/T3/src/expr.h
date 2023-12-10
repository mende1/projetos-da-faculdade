#ifndef EXPR_H
#define EXPR_H

typedef enum {
	EXPR_ASSIGN,
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_EQ,
   	EXPR_NEQ,
  	EXPR_LT,
   	EXPR_GT,
   	EXPR_LTEQ,
   	EXPR_GTEQ,
   	EXPR_VAR,
	EXPR_FUN,
    	EXPR_CALL,
    	EXPR_ARG,
    	EXPR_NAME,
    	EXPR_INTEGER_LITERAL,
    	EXPR_BOOLEAN_LITERAL,
} expr_t;

struct expr {
	/* used by all kinds of exprs */
	expr_t kind;
	struct expr *left;
	struct expr *right;

	/* used by various leaf exprs */
	char *name;
	int integer_value;
};

struct expr * expression_create(expr_t kind,
    struct expr *, struct expr *, char *, int);

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right );

struct expr * expr_create_name(char *name);
struct expr * create_integer_literal(int i);
struct expr * create_boolean_literal(int b);
struct expr * expr_create_var(char *name);
struct expr * expr_create_call(char *name, struct expr *expr);
struct expr * expr_create_arg(struct expr *, struct expr *);

void print_bexpr(char *c, struct expr *l, struct expr *r);
void print_expr(struct expr *e);
void print_name(char *name);
#endif

