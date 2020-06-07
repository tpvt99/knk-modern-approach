#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5
static int last = 0;
static int first = 0;
static int num_elements = 0;

static int contents[QUEUE_SIZE];

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

static bool is_full(void) {
    return num_elements == QUEUE_SIZE;
}

bool is_empty(void) {
    return num_elements == 0;
}

int first_item(void) {
    if (is_empty()) {
        printf("Empty queue.\n");
        return -1;
    }

    return contents[first];
}

int last_item(void) {
    if (is_empty()) {
        printf("Empty queue.\n");
        return -1;
    }

    return contents[last-1];
}

void push(int i) {
    if (is_full()) {
        printf("Full Queue.\n");
        return ;
    }
    if (last >= QUEUE_SIZE)
        last = last % QUEUE_SIZE;
    num_elements++;
    contents[last++] = i;
}


int pop(void) {
    if (is_empty()) {
        printf("Empty Queue.\n");
        return -1;
    }
    if (first >= QUEUE_SIZE)
        first = first % QUEUE_SIZE;
    num_elements--;
    return contents[first++];
}
