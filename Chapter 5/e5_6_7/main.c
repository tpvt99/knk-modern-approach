#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    n = -100;
    if (n >= 1 <= 10)
        printf("n is between 1 and 10\n");
    n = 0;
    if (n >= 1 <= 10)
        printf("n is between 1 and 10\n");
    n = 5;
    if (n >= 1 <= 10)
        printf("n is between 1 and 10\n");
    n = 11;
    if (n >= 1 <= 10)
        printf("n is between 1 and 10\n");

    n = 5;
    if (n == 1-10)
        printf("n is between 1 and 10\n");
    n = 17;
    printf("%d\n", n >= 0 ? n : -n);
    n = -17;
    printf("%d\n", n >= 0 ? n : -n);
    return 0;
}
