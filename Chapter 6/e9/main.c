#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 10;
    while (i>=1) {
        printf("%d ",i++);
        i/=2;
    }
    return 0;
}
