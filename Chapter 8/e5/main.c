#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fib_numbers[40] = {0, 1};
    for (int i = 2; i< 40; i++) {
        fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];
    }
    for (int i = 0; i< 40; i++) {
        printf("fibs[%d]: %d\n", i+1, fib_numbers[i]);
    }
    return 0;
}
