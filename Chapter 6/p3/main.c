#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter a fraction: ");
    int m, n;
    scanf("%d/%d", &m, &n);
    int a = m, b = n;
    while (n != 0) {
        int re = m % n;
        m = n;
        n = re;
    }
    printf("In lowest terms: %d/%d", a/m, b/m2);
    return 0;
}
