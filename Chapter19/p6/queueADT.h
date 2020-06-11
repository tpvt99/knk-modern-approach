#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

void insert_queue(Queue q, Item number);
Item remove_queue(Queue q);
Item first_element(Queue q);
Item last_element(Queue q);
bool is_empty(Queue q);
Queue create(int size);
void destroy(Queue q);

#endif // QUEUEADT_H


