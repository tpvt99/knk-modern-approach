#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 100

struct queue_type {
    int contents[QUEUE_SIZE];
    int first;
    int last;
    int num_elements;
};

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void) {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: stack could not be create.");
    q->first = 0;
    q->last = 0;
    q->num_elements = 0;
    return q;
}

void destroy(Queue q) {
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
    return q->num_elements == QUEUE_SIZE;
}

void push(Queue q, int i) {
    if (is_full(q))
        terminate("Error in push: stack is full.");

    if (q->last >= QUEUE_SIZE)
        q->last = q->last % QUEUE_SIZE;
    q->num_elements++;
    q->contents[q->last++] = i;
}

int pop(Queue q) {
    if (is_empty(q))
        terminate("Error in pop: stack is empty.");
    if (q->first >= QUEUE_SIZE)
        q->first = q->first % QUEUE_SIZE;
    q->num_elements--;
    return q->contents[q->first++];
}

