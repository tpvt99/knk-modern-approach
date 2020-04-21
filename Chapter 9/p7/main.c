#include <stdio.h>
#include <stdlib.h>

int power(int , int);

int main()
{
    printf("Power of 5^2 : %d", power(3, 7));
    return 0;
}

int power(int x, int n) {
    if (n == 0)
        return 1;
    else if ((n % 2) == 0) {
        int inner_power = power(x, n/2);
        return inner_power * inner_power;
    }
    else if ((n%2) == 1) {
        return x * power(x, n-1);
    }

    return 0;
}
