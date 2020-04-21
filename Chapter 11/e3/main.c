#include <stdio.h>
#include <stdlib.h>

void avg_sum(double [], int, double *, double *);

int main()
{
    double a[] = {1,2,3,4,6};
    double sum, avg;
    avg_sum(a, 5, &avg, &sum);
    printf("Sum is: %f. Average is: %f", sum, avg);
    return 0;
}

void avg_sum(double a[], int n, double *avg, double *sum) {
    int i;
    *sum = 0;
    for (i = 0; i<n;i++)
        *sum += a[i];
    *avg = *sum / n;
}
