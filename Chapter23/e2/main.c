#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double evaluate_polynomial(double a[], int n, double x) {
    int results = a[0];
    for (int i = 1; i <= n; i++) {
        results = fma(results, x, a[i]);
    }
    return results;
}

int main()
{
    double a[] = {1,2,3,4};
    printf("Results: %f\n", evaluate_polynomial(a, 3, 9));
    return 0;
}
