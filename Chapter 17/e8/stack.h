#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

void make_empty(void);
bool is_empty(void);
bool push(int i);
struct contents * pop(void);

struct contents {
    int value;
    struct contents *next;
};

extern struct contents *top;

#endif // STACK_H
