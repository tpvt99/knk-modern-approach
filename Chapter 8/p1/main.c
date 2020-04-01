#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int digit_counts[10] = {0};
    int digit;
    long int n;
    bool digit_seen = false;
    printf("Enter a number: ");
    scanf("%ld", &n);
    while (n > 0) {
        digit = n % 10;
        if (digit_counts[digit])
            digit_seen = true;
        digit_counts[digit] += 1;
        n /= 10;
    }
    if (digit_seen) {
        printf("Repeated digit(s): ");
        for (int i = 0; i < 10; i++)
            if (digit_counts[i] >= 2)
                printf("%d ", i);
    }
    else
        printf("No repeated digit\n");
    return 0;
}
