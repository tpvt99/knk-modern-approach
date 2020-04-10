#include <stdio.h>
#include <stdlib.h>

void pb(int n) {
    if (n!=0) {
        pb(n/2);
        putchar('0' + n%2);
    }
}

int main()
{
    pb(100);
    return 0;
}
