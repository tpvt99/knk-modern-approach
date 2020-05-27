#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void insertStack(void);
void popStack(void);
void deleteStack(void);
void printStack(void);

int main()
{
    char commands;
    for (;;) {
        printf("Enter a command: i(insert), d(pop), m(delete), p(print), q(quit): ");
        scanf("%c", &commands);
        //printf("commands: %d\n", commands);
        getchar();
        switch(commands) {
            case 'i': insertStack();break;
            case 'd': popStack();break;
            case 'm': deleteStack();break;
            case 'p': printStack();break;
            case 'q': exit(EXIT_SUCCESS);
            default: printf("Wrong commands");break;
        }
        printf("\n");
    }
    return 0;
}

void insertStack(void) {
    int val;
    printf("Enter number to insert: ");
    scanf("%d", &val);
    getchar();
    if(!push(val)) {
        printf("Not enough space to insert.\n");
    }
}

void popStack(void) {
    struct contents *popElement = pop();
    if (popElement!=NULL)
        printf("Elements pop: %d", popElement->value);
}

void deleteStack(void) {
    make_empty();
}

void printStack(void) {
    printf("head->");
    struct contents *h = top;
    while (h!=NULL) {
        printf("%d->", h->value);
        h=h->next;
    }
    printf("NULL");
}
