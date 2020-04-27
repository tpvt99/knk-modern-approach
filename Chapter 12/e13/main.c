#include <stdio.h>
#include <stdlib.h>

#define N 5

int main()
{
    printf("Hello world!\n");
    int ident[N][N];
    int *p, counter;
    for (p=ident[0], counter=0; p <= &ident[N-1][N-1]; p++) { // p++ increase by size of each elements in array ident
        printf("Address of p: %p\n", p);
        if (counter==0) {
            *p = 1;
            counter++;
        } else if (counter == N) {
            counter = 0;
            *p = 0;
        } else if (counter < N) {
            *p = 0;
            counter++;
        }
    }

    int (*q)[N];
    for (q = ident; q < ident + N; q++) {// q++ increase by size of each row in array ident
        printf("Address of q: %p\n", q);
    }
     for (q = ident; q < ident + N; q++) {
        for (counter = 0; counter < N; counter++)
            printf("%d ", (*q)[counter]);
        printf("\n");
    }

    return 0;
}
