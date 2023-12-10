
#ifndef STMT_H
#define STMT_H

#include "decl.h"

typedef enum {
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_WHILE,
	STMT_PRINT,
	STMT_RETURN,
	STMT_BLOCK
} stmt_t;

struct stmt {
	stmt_t kind;
	struct decl *decl;
	struct expr *init_expr;
	struct expr *expr;
	struct expr *next_expr;
	struct stmt *body;
	struct stmt *else_body;
	struct stmt *next;
};

struct stmt * stmt_create(stmt_t kind, 
    struct decl *decl, struct expr *init_expr, 
    struct expr *expr, struct expr *next_expr, 
    struct stmt *body, struct stmt *else_body, 
    struct stmt *next);

struct stmt * insert_stmt(struct stmt *head, struct stmt *elem);

struct stmt * compound_stmt_create(stmt_t kind,
    struct decl *localdecl, struct stmt *body);

struct stmt * if_create(struct expr *expr, struct stmt *body);

struct stmt * if_else_create(struct expr *expr,
    struct stmt *body, struct stmt *else_body);

struct stmt * while_create(struct expr *expr, struct stmt *body);

struct stmt * print_stmt_create(struct expr *expr);

void print_stmt(struct stmt *s);

#endif
