#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p = 10;
    char *a = &p;
    printf("%p - %p", a, a+1);

    return 0;
}
