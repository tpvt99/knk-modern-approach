#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACKS 10

int *top_ptr;
int a[MAX_STACKS];

void push(int i);
void pop(void);
void stack_overflow(void);
void stack_underflow(void);
bool is_full(void);
bool is_empty(void);
void make_empty(void);

int main()
{
    printf("Hello world!\n");
    return 0;
}

void push(int i ) {
    if (is_full())
        stack_overflow();
    else
        *top_ptr++ = i;
}

void pop(void) {
    if (is_empty())
        stack_underflow();
    else
        return *--top_ptr;
}

void make_empty(void) {
    top_ptr = &a[0];
}

bool is_full(void) {
    return top_ptr == &a[MAX_STACKS];
}

bool is_empty(void) {
    return top_ptr == &a[0];
}

void stack_overflow(void) {
    return ;
}

void stack_underflow(void) {
    return ;
}
