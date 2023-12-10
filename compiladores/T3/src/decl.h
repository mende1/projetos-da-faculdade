/* decl.h
 * Adaptação de partes do código do livro de Compiladores
 * de Douglas Thain para a disciplina MATA61-UFBA
 * Christina von Flach (github: christinaflach)
 * 2020
 */

#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"
#include <stdio.h>

struct decl {
	struct type *type;
	char *name;
	struct expr *expr;
	struct stmt *code;
	struct decl *next;
};

struct decl * decl_create(char *name, 
   struct type *type, struct expr *expr, 
   struct stmt *code, struct decl *next );

struct decl * insert_decl(struct decl *head, 
		          struct decl *elem);

struct decl * var_decl_create(char *name, struct type *type, struct expr *init);
	
struct decl * func_decl_create(char *, struct type *,
    struct param_list *pl, struct stmt *body);

void print_decl(struct decl *d);
void print_var(struct decl *var);
void print_func(struct decl *f);

void printAST(struct decl *program);
#endif


