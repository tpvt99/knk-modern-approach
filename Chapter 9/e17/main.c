#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n) {
    if (n == 0)
        return m;
    else
        return gcd(n, m%n);
}


int main()
{
    printf("GCD: %d\n", gcd(20, 4));
    printf("GCD: %d\n", gcd(20, 5));
    return 0;
}
