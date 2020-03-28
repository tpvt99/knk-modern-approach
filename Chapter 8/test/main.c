#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1
#include <stdbool.h>

int main()
{
    int i;
    bool a[10] = {0};
    for (i = 0; i< (int) (sizeof(a) / sizeof(a[0])) ;i++)
        printf("a[%d]: %d\n", i, a[i]);

    return 0;
}
