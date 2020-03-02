#include <stdio.h>
#include <stdlib.h>

int main()
{
    float loan, rate, monthly_payment;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    // First month
    loan = loan*(1 + rate / 1200) - monthly_payment;
    printf("Balance remaining after first payment: %.2f\n", loan);

    // Second month
    loan = loan*(1 + rate / 1200) - monthly_payment;
    printf("Balance remaining after second payment: %.2f\n", loan);

    // Third month
    loan = loan*(1 + rate / 1200) - monthly_payment;
    printf("Balance remaining after third payment: %.2f\n", loan);
    return 0;
}
