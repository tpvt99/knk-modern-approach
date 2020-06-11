#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"


struct queue_element {
    Item contents;
    struct queue_element *next;
};

struct queue_type {
    struct queue_element *first;
    int num_elements;
    struct queue_element *last;
};

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create() {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: stack could not be create.\n");
    q->first = NULL;
    q->last = NULL;
    q->num_elements = 0;
    return q;
}

void destroy(Queue q) {
    make_empty(q);
    free(q);
}

void make_empty(Queue q) {
    while(!is_empty(q))
        pop(q);
}

bool is_empty(Queue q) {
    return q->num_elements == 0;
}

bool is_full(Queue q) {
    return false;
}

void push(Queue q, Item i) {
    if (is_full(q))
        terminate("Error in push: queue is full.");

    struct queue_element *node = malloc(sizeof(struct queue_element));
    if (node == NULL)
        terminate("Error in push: cannot allocate memory for new element.");
    node->contents = i;
    q->num_elements++;
    if (q->last == NULL && q->first == NULL) {
        node->next = NULL;
        q->last = node;
        q->first = node;
    } else {
        node->next = q->last->next;
        q->last->next = node;
        q->last = node;
    }

}

Item pop(Queue q) {
    if (is_empty(q))
        terminate("Error in pop: queue is empty.");

    q->num_elements--;
    struct queue_element *node = q->first;
    q->first = q->first->next;
    if (q->first == NULL)
        q->last = NULL;
    Item i = node->contents;
    free(node);
    return i;
}

Item first_element(Queue q) {
    if (is_empty(q))
        terminate("Error in first element: queue is empty.");
    return q->first->contents;
}

Item last_element(Queue q) {
    if (is_empty(q))
        terminate("Error in last element: queue is empty.");
    return q->last->contents;
}


