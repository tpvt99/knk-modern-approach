#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"


struct queue_type {
    Item *contents;
    int first;
    int last;
    int num_elements;
    int size;
};

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(int size) {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: stack could not be create.\n");
    q->contents = malloc(size * sizeof(Item));
    if (q->contents == NULL)
        terminate("Error in create: stack could not be created.\n");
    q->first = 0;
    q->last = 0;
    q->num_elements = 0;
    q->size = size;
    return q;
}

void destroy(Queue q) {
    free(q->contents);
    free(q);
}

void make_empty(Queue q) {
    q->first = 0;
    q->last = 0;
    q->num_elements = 0;
}

bool is_empty(Queue q) {
    return q->num_elements == 0;
}

bool is_full(Queue q) {
    return q->num_elements == q->size;
}

void push(Queue q, Item i) {
    if (is_full(q))
        terminate("Error in push: stack is full.");

    if (q->last >= q->size)
        q->last = q->size % q->size;
    q->num_elements++;
    q->contents[q->last++] = i;
}

Item pop(Queue q) {
    if (is_empty(q))
        terminate("Error in pop: stack is empty.");
    if (q->first >= q->size)
        q->first = q->first % q->size;
    q->num_elements--;
    return q->contents[q->first++];
}


