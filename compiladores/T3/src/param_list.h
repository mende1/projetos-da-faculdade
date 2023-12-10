
#ifndef PARAM_LIST_H
#define PARAM_LIST_H

#include "type.h"
#include <stdio.h>

struct expr;

struct param_list {
	char *name;
	struct type *type;
	struct param_list *next;
};

struct param_list * param_list_create(char *name, 
    struct type *type, struct param_list *next );

struct param_list * param_create(char *name, 
    struct type *type);

struct param_list * insert_param(struct param_list *head,
    struct param_list *elem);

void print_params(struct param_list *pl);

#endif
