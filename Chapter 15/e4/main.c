#include <stdio.h>
#include <stdlib.h>

#include "debug.h"



int main()
{
    int i= 1, j= 2, k = 3;

    #ifdef DEBUG
    printf("OUTPUT if DEBUG is defined\n");
    #else
    printf("OUTPUT if DEBUG is not defined:\n");
    #endif // DEBUG

    PRINT_DEBUG(i);
    PRINT_DEBUG(j);
    PRINT_DEBUG(k);
    PRINT_DEBUG(i+j);
    PRINT_DEBUG(2*i+j-k);
    return 0;
}
