#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d;
    printf("Enter four integer numbers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int largest1, largest2;
    int smallest1, smallest2;
    int max, min;
    if (a > b) {
        largest1 = a;
        smallest1 = b;
    } else {
        largest1 = b;
        smallest1 = a;
    }
    if (c > d) {
        largest2 = c;
        smallest2 = d;
    } else {
        largest2 = d;
        smallest2 = c;
    }

    if (largest1 > largest2) {
        max = largest1;
    } else {
        max = largest2;
    }

    if (smallest1 < smallest2)
        min = smallest1;
    else
        min = smallest2;

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);
    return 0;
}
