#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 5, j = i-1; i>0, j>0; --i, j=i-1)
        printf("%d ", i);
    return 0;
}
