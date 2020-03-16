#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    printf("Enter two integers: ");
    scanf("%d%d", &n, &m);
    while (n != 0) {
        int re = m % n;
        m = n;
        n = re;
    }
    printf("Greatest common divisor: %d", m);
    return 0;
}
