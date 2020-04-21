#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main()
{
    int i = 10;
    int j = 12;
    printf("Number before swap: i: %d, j: %d\n", i, j);
    swap(&i, &j);
    printf("Number after swap: i %d, j: %d\n", i, j);
    return 0;
}

void swap(int *i, int *j) {
    int temp;
    temp = *j;
    *j = *i;
    *i = temp;
}
