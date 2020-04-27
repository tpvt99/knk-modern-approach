#include <stdio.h>
#include <stdlib.h>

double inner_product(const double *a, const double *b, int n) {
    double *p = a, *q = b;
    double product = 0;
    while (p < a + n)
        product += *p++ * *q++;
    return product;
}

int main()
{
    double a[3] = {1,2,3};
    double b[3] = {6,7,8};
    double product = inner_product(a, b, 3);
    printf("Inner product: %f", product);
    return 0;
}
