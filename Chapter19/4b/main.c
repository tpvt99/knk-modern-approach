#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void pushStack();
void popStack();
void emptyStack();
void isFullStack();

Stack s1;

int main()
{
    char command;
    for (;;) {
        printf("Enter a command: ");
        command = getchar();
        getchar();
        switch (command) {
            case 'i': pushStack();break;
            case 'd': popStack();break;
            case 'e': emptyStack();break;
            case 'f': isFullStack();break;

        }
    }
    return 0;
}

void pushStack(void) {
    printf("Enter number: ");
    int n;
    scanf("%d", &n);
    getchar();
    push(&s1, n);
}

void popStack(void) {
    int n = pop(&s1);
    printf("Pop item: %d\n", n);
}

void emptyStack(void) {
    make_empty(&s1);
}

void isFullStack(void) {
    bool b = is_full(s1);
    if (b)
        printf("Full.\n");
    else
        printf("Not Full.\n");
}

