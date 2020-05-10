#include <stdio.h>
#include <stdlib.h>

#define ERROR(x, index) fprintf(stderr, x, index)

int main()
{
    int index=10;
    ERROR("Range error: index = %d\n", index);
    return 0;
}
