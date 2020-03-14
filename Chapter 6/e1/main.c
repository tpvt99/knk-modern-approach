#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 1;
    while (i <= 128) {
        printf("%d ", i);
        i*= 2;
    }
    int j, z;
    j = 0, z = 10;
    for (int m =0, j = 1;m <= 5;m++) {
        printf("%d %d\n", m, j);
    }
    printf("%d\n", z);
    return 0;
}
