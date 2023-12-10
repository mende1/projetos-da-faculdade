/* type.h
 * Adaptação de partes do código do livro de Compiladores
 * de Douglas Thain para a disciplina MATA61-UFBA
 * Christina von Flach (github: christinaflach)
 * 2020
 */

#ifndef TYPE_H
#define TYPE_H

#include "param_list.h"

typedef enum {
	TYPE_VOID,
	TYPE_BOOLEAN,
	TYPE_INTEGER,
	TYPE_FUNCTION,
} type_t;

struct type {
	type_t kind;
	struct type *subtype;
	struct param_list *params;
};

struct type * type_create(type_t kind, 
    struct type *subtype, struct param_list *params );

void print_type( struct type *t );

#endif

