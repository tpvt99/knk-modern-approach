#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

static bool is_full(Queue *q) {
    return q->num_elements == QUEUE_SIZE;
}

bool is_empty(Queue *q) {
    return q->num_elements == 0;
}

int first_item(Queue *q) {
    if (is_empty(q)) {
        printf("Empty queue.\n");
        return -1;
    }

    return q->contents[q->first];
}

int last_item(Queue *q) {
    if (is_empty(q)) {
        printf("Empty queue.\n");
        return -1;
    }

    return q->contents[q->last-1];
}

void push(Queue *q, int i) {
    if (is_full(q)) {
        printf("Full Queue.\n");
        return ;
    }
    if (q->last >= QUEUE_SIZE)
        q->last = q->last % QUEUE_SIZE;
    q->num_elements++;
    q->contents[q->last++] = i;
}


int pop(Queue *q) {
    if (is_empty(q)) {
        printf("Empty Queue.\n");
        return -1;
    }
    if (q->first >= QUEUE_SIZE)
        q->first = q->first % QUEUE_SIZE;
    q->num_elements--;
    return q->contents[q->first++];
}

