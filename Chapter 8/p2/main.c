#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int digit_counts[10] = {0};
    int digit;
    long int n;
    printf("Enter a number: ");
    scanf("%ld", &n);
    while (n > 0) {
        digit = n % 10;
        digit_counts[digit] += 1;
        n /= 10;
    }
    printf("Digit:\t\t");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", i);
    }
    printf("\nOccurrences\t");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", digit_counts[i]);
    }

    return 0;
}
