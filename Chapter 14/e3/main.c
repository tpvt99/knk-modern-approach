#include <stdio.h>
#include <stdlib.h>

#define DOUBLE(x) (2*(x))

int main()
{
    printf("%d\n", DOUBLE(1+2));
    printf("%d\n", 4/DOUBLE(2));
    return 0;
}
