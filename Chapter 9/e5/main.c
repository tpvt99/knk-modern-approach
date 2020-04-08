#include <stdio.h>
#include <stdlib.h>

int num_digits(int n) {
    int num = 0;
    while ((n/=10) > 0)
        num += 1;
    num += 1;
    return num;
}

int main()
{
    printf("Number of digit: %d!\n", num_digits(20));
    printf("Number of digit: %d!\n", num_digits(1));
    printf("Number of digit: %d!\n", num_digits(245));
    printf("Number of digit: %d!\n", num_digits(34564));
    printf("Number of digit: %d!\n", num_digits(0));
    return 0;
}
