#include <stdio.h>
#include <stdlib.h>

#define NUM_RATES (int) (sizeof(value) / sizeof(value[0]))
#define INITIAL_BALANCE 100.00
#define ACCUMULATIVE_MONTH 12

int main()
{
    int i, low_rate, num_years, year;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for(i=0; i< NUM_RATES;i++) {
        printf("%6d%%", low_rate+i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years;year++) {
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++) {
            for (int m_acc = 1; m_acc <= ACCUMULATIVE_MONTH; m_acc++) {
                value[i] *= (1 + (low_rate+i)/ ((float) (12*100)));
            }
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}
