#include <stdio.h>
#include <stdlib.h>

double inner_product(double [], double [], int);

int main()
{
    printf("Hello world %f \n", inner_product((double[]){1,2,3}, (double[]) {1,2,3}, 3));
    return 0;
}

double inner_product(double a[], double b[], int n) {
    double re = 0;
    for (int i = 0; i<n;i++) {
        re += (a[i] * b[i]);
    }
    return re;
}
