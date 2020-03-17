#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no_months;
    float loan, rate, monthly_payment;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);
    printf("Enter number of months: ");
    scanf("%d", &no_months);
    for (int i = 1; i<= no_months; i++) {
        loan = loan*(1 + rate / 1200) - monthly_payment;
        printf("Balance remaining after %d payment: %.2f\n", i, loan);
    }

    return 0;
}
