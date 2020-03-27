#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Enter a positive number: ");
    double x,y, new_y;
    scanf("%lf", &x);
    y = 1.0;
    new_y = x;
    double div, avg;
    while (fabs(new_y - y) >= 1e-10) {
        y = new_y;
        div = x /y;
        avg = (y + div)/2;
        new_y = avg;
        printf("y: %f, div: %f, avg: %f, new_y: %f\n", y, div, avg, new_y);
    }
    printf("Square root: %f", new_y);
    return 0;
}
