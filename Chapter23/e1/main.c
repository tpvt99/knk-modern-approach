#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double round_nearest(double x, int n) {
    double y = x * pow(10, n);
    y = (y < 0.0) ? ceil(y - 0.5) : floor(y + 0.5);
    return y / pow(10, n);
}

int main()
{
    printf("%f\n", round_nearest(-1.49999, 3));
    return 0;
}
