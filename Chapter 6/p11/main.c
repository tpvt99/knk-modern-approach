#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int denom = 1;
    float sum=1.0f;
    for (int i = 1; i<=n; i++) {
        denom *= i;
        sum += 1.0f/denom;
    }
    printf("Approximate for e: %.4f", sum);
    return 0;
}
