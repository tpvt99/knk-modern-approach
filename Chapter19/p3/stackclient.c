#include <stdio.h>
#include "stackADT.h"

int main(void) {
    Stack s1, s2;
    int n;

    s1 = create();
    s2 = create();

    push(s1, 1);
    printf("Size of s1: %d\n", length(s1));
    push(s1, 2);
    printf("Size of s1: %d\n", length(s1));

    n = pop(s1);

    printf("Popped %d from s1\n", n);
    printf("Size of s1: %d\n", length(s1));
    push(s2, n);
    printf("Size of s2: %d\n", length(s2));
    n = pop(s1);

    printf("Popped %d from s1\n", n);
    printf("Size of s1: %d\n", length(s1));
    push(s2, n);
    printf("Size of s2: %d\n", length(s2));

    destroy(s1);
    while (!is_empty(s2))
        printf("Popped %d from s2\n", pop(s2));

    push(s2, 3);
    printf("Size of s2: %d\n", length(s2));
    make_empty(s2);
    if (is_empty(s2))
        printf("S2 is empty\n");
    else
        printf("S2 is not empty\n");
    destroy(s2);
    return 0;
}


