#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

void push(Queue q, Item number);
Item pop(Queue q);
Item first_element(Queue q);
Item last_element(Queue q);
bool is_empty(Queue q);
Queue create();
void destroy(Queue q);
void make_empty(Queue q);

#endif // QUEUEADT_H



