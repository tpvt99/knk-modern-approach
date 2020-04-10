#include <stdio.h>
#include <stdlib.h>

int fact(int n) {
    int result = 1;
    for (int i =2; i<=n;i++)
        result *= i;
    return result;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
