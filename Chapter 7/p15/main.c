#include <stdio.h>
#include <stdlib.h>

int main()
{
    float d, fac;
    printf("Enter a positive integer: ");
    scanf(" %f", &d);
    fac = 1;
    for (int i = 1; i <= d; i++) {
        fac *= i;
    }
    printf("Factorial of %f: %f", d, fac);
    return 0;
}
