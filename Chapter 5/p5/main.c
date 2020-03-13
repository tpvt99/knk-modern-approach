#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the amount of taxable income: ");
    float income;
    scanf("%f", &income);
    float tax;
    if (income < 750)
        tax = .01f * income;
    else if (income >= 750 && income < 2250)
        tax = 7.50f + .02f * (income - 750);
    else if (income >= 2250 && income < 3750)
        tax = 37.50f + .03f * (income - 2250);
    else if (income >= 3750 && income < 5250)
        tax = 82.50f + .04f * (income - 3750);
    else if (income >= 5250 && income < 7000)
        tax = 142.50f + .05f * (income - 5250);
    else
        tax = 230.00f + .06 * (income - 7000);
    printf("Tax: %.2f", tax);
    return 0;
}
