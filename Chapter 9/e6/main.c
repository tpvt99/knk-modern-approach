#include <stdio.h>
#include <stdlib.h>

int digit(int n, int k) {
    int i = 1;
    while (n >0) {
        if (i == k)
            return n % 10;
        i++;
        n /= 10;
    }
    return 0;
}

int main()
{
    printf("The digit: %d\n", digit(829,1));
    printf("The digit: %d\n", digit(829,2));
    printf("The digit: %d\n", digit(829,3));
    printf("The digit: %d\n", digit(829,4));
    return 0;
}
