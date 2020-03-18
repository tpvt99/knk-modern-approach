#include <stdio.h>
#include <stdlib.h>

int main()
{
    float e;
    printf("Enter e: ");
    scanf("%f", &e);
    float sum = 1.0f;
    float old_sum;
    int denom = 1;
    int i;
    for (i = 1; i <= 100; i++) {
        denom *= i;
        old_sum = sum;
        sum += 1.0f/denom;
        if (sum-old_sum <= e)
            break;
    }
    printf("Value of e: %.4f with iterations: %d", sum, i);
    return 0;
}
