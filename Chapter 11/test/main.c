#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 10;
    int j = 5;
    int *p, *q;
    p = i;
    q = j;
    &p = 10;

    //*p = &i;
    printf("Address of i: %d\n", i);

    return 0;
}
