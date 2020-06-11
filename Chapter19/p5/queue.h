#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct queue_type *Queue;

void insert_queue(Queue q, int number);
int remove_queue(Queue q);
int first_element(Queue q);
int last_element(Queue q);
bool is_empty(Queue q);
Queue create();
void destroy(Queue q);

#endif // QUEUE_H

