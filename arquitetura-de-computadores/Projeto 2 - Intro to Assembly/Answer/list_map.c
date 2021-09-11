#include <stdio.h>
#include <stdlib.h>

// Rascunho para o item 4 do Projeto 2
// List Map

struct Node {
    int value;
    struct Node *next;
};

struct Node* createNode (int value, struct Node *next) {
    
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;

    if (next) {
        node->next = next;
    }
    return node;
}

void map (struct Node *head, int (*f)(int)) {

    if (!head) {
        return;
    }

    head->value = f(head->value);
    map(head->next, f);
}

int square (int n) {
    return n*n;
}

int main () {

    struct Node *th1  = createNode(0, NULL);   
    struct Node *th2  = createNode(1,  th1);
    struct Node *th3  = createNode(2,  th2);
    struct Node *th4  = createNode(3,  th3);
    struct Node *th5  = createNode(4,  th4);
    struct Node *th6  = createNode(5,  th5);
    struct Node *th7  = createNode(6,  th6);
    struct Node *th8  = createNode(7,  th7);
    struct Node *th9  = createNode(8,  th8);
    struct Node *th10 = createNode(9,  th9);

    map(th10, square);

    struct Node *iterator = th10;
    while(iterator) {
        printf("  %d", iterator->value);
        iterator = iterator->next;
    }

    puts("");
}