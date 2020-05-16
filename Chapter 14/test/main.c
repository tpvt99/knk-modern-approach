#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int main()
{
    printf("Hello world!\n");
    #ifdef DEBUG
    printf("Debug\n");
    #endif // DEBUG
    return 0;
}
