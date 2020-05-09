#include <stdio.h>
#include <stdlib.h>

#define NELEMS(a) ((int) sizeof(a) / sizeof(a[0]))

int main()
{
    int a[10] = {1,2,3};
    printf("size of a: %d", NELEMS(a));
    return 0;
}
