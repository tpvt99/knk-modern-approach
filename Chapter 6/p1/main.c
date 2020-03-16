#include <stdio.h>
#include <stdlib.h>

int main()
{

    float x, largest = 0;
    printf("Enter a number: ");
    scanf("%f", &x);
    largest = x;
    while (x > 0) {
        if (x > largest)
            largest = x;
        printf("Enter a number: ");
        scanf("%f", &x);
    }
    if (largest >= 0)
        printf("The largest number entered was %f\n", largest);
    else
        printf("The largest number entered was 0\n");


    return 0;
}
