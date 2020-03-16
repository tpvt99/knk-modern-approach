#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int test = 2; test <= 25; test++) {
        int d;
        for (d = 2; d < test; d++) {
            if ((d*d > test) || ((test % d) == 0))
                break;
        }
        if (d*d > test)
            printf("%d is a prime number\n", test);
        else
            printf("%d is not a prime number. divisible by %d\n", test, d);
    }
    return 0;
}
