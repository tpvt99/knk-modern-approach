#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int p, r, t;
    printf("Enter original amount: ");
    scanf("%d", &p);
    printf("Enter interest rate: ");
    scanf("%d", &r);
    printf("Enter number of years: ");
    scanf("%d", &t);
    printf("Value: %.2f\n", p * exp((r/100.0f) * t));
    return 0;
}
