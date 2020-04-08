#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n) {
    while (n != 0) {
        int re = m % n;
        m = n;
        n = re;
    }
    return m;
}

int main()
{
    printf("GCD is: %d", gcd(20, 28));
    return 0;
}
