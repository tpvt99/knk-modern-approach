#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter a value: ");
    float x;
    scanf("%f", &x);
    printf("Value of polynomial: 3x^5+2x^4-5x^3-x^2+7x-6: %.0f", 3*x*x*x*x*x+
           2*x*x*x*x - 5*x*x*x - x*x + 7*x -6);
    return 0;
}
