#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct contents *top = NULL;

bool push(int val) {
    struct contents *new_node;
    new_node = malloc(sizeof(struct contents));
    if (new_node == NULL)
        return false;
    new_node->value = val;
    new_node->next = top;
    top = new_node;
    return true;
}

struct contents *pop(void) {
    if (is_empty())
        return NULL;
    struct contents *curr = top;
    top = top->next;
    curr->next = NULL;
    return curr;
};

bool is_empty(void) {
    return (top == NULL);
}

void make_empty(void) {
    struct contents *curr;
    for (;top!= NULL;) {
        curr = top;
        top=top->next;
        free(curr);
    }
    return;
}
