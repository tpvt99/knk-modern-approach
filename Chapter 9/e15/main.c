#include <stdio.h>
#include <stdlib.h>

double median(double , double, double);

int main()
{
    printf("Median: %f!\n", median(1,2,3));
    printf("Median: %f!\n", median(1,2,1));
    printf("Median: %f!\n", median(1,4,2));
    return 0;
}

double median(double x, double y, double z) {
    double median;
    if (x <= y)
        if (y <= z) median = y;
        else if (x <= z) median = z;
        else median = x;
    else if (z <y ) median = y;
    else if (x <= z) median = x;
    else median = z;
    return median;
}
