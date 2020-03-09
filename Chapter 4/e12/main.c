#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    i = 5;
    j = ++i * 3 - 2;
    printf("%d %d\n", i, j);
    i = 5;
    j = 3 - 2 * i++;
    printf("%d %d\n", i, j);
    i = 7;
    j = 3 * i-- + 2;
    printf("%d %d\n", i, j);
    i = 7;
    j = 3 + --i * 2;
    printf("%d %d\n", i, j);
    int k;
    i = 5;
    k = (i+= 1);
    i = 5;
    j = (++i);
    printf("%d %d\n", k, j);
    return 0;
}
