#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct stack_type {
    Item *contents;
    int top;
    int size;
};

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(int size) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: stack could not be created.");
    s->contents = malloc(size * sizeof(Item));
    if (s->contents == NULL) {
        free(s);
        terminate("Error in create: stack could not be created.");
    }
    s->top = 0;
    s->size = size;
    return s;
}

void destroy(Stack s) {
    free(s->contents);
    free(s);
}

void make_empty(Stack s) {
    s->top = 0;
}

bool is_empty(Stack s) {
    return s->top == 0;
}

bool is_full(Stack s) {
    return s->top == s->size;
}

void push(Stack s, Item i) {
    if (is_full(s)) {
        Item *new_item = malloc(sizeof(Item) * 2 * (s->size));
        s->size = (s->size) * 2;
        for (int temp = 0; temp < s->top; temp++)
            new_item[temp] = s->contents[temp];
        free(s->contents);
        s->contents = new_item;
    }
    s->contents[s->top++] = i;
}

Item pop(Stack s) {
    if (is_empty(s))
        terminate("Error in pop: stack is empty.");
    return s->contents[--s->top];
}

Item peek(Stack s) {
    if (is_empty(s))
        terminate("Error in peek: stack is empty.");
    return s->contents[s->top-1];
}
