#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

#define QUEUE_SIZE 5

typedef struct queue_type {
    int last;
    int first;
    int num_elements;
    int contents[QUEUE_SIZE];
} Queue;

void push(Queue *q, int i);
int pop(Queue *q);
int first_item(Queue *q);
int last_item(Queue *q);
bool is_empty(Queue *q);

#endif // QUEUE_H

