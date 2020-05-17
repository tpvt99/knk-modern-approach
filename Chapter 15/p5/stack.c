#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int top;
char contents[STACK_SIZE];

void stack_overflow(void);
void stack_underflow(void);

void make_empty(void) {
    top = 0;
}

void push(char ch) {
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

char pop(void) {
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

int is_full(void) {
    return top == STACK_SIZE;
}

int is_empty(void) {
    return top == 0;
}

void stack_overflow(void) {
    printf("Program too complex.");
    exit(1);
}

void stack_underflow(void) {
    printf("Not enough operands.");
    exit(1);
}
