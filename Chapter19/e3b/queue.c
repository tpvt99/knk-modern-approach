#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


struct contents {
    int value;
    struct contents *next;
};

static struct contents *first = NULL;
static struct contents *last = NULL;

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}


bool is_empty(void) {
    return first == NULL;
}

int first_item(void) {
    if (is_empty()) {
        printf("Empty queue.\n");
        return -1;
    }

    return first->value;
}

int last_item(void) {
    if (is_empty()) {
        printf("Empty queue.\n");
        return -1;
    }

    return last->value;
}

void push(int i) {
    struct contents *new_node = malloc(sizeof(struct contents));
    if (new_node == NULL)
        terminate("No space for allocation\n");
    new_node->value = i;
    new_node->next = NULL;

    if (first == NULL && last == NULL) {
        first = new_node;
        last = new_node;
    } else {
        last->next = new_node;
        last = new_node;
    }
}


int pop(void) {
    if (is_empty()) {
        printf("Empty Queue.\n");
        return -1;
    }
    int i;
    struct contents *old_first = first;
    i = old_first->value;
    first = first->next;
    free(old_first);
    if (first == NULL)
        last = NULL;
    return i;
}

