#include <stdio.h>
#include "stackADT.h"

int main(void) {
    Stack s1, s2;
    char *p;

    s1 = create();
    s2 = create();

    push(s1, "I love you");
    push(s1, "I like you");

    p = pop(s1);
    printf("Popped \"%s\" from s1\n", p);
    push(s2, "more than this");
    p = pop(s1);
    printf("Popped \"%s\" from s1\n", p);
    push(s2, "Hello you");


    destroy(s1);
    while (!is_empty(s2))
        printf("Popped \"%s\" from s2\n", pop(s2));

    push(s2, "Alo");
    make_empty(s2);
    if (is_empty(s2))
        printf("S2 is empty\n");
    else
        printf("S2 is not empty\n");
    destroy(s2);
    return 0;
}


