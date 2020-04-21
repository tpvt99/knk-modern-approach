#include <stdio.h>
#include <stdlib.h>

void find_two_largest(int [], int, int *, int*);

int main()
{
    printf("This program find two largest integers in an array.\n");
    int a[5]= {12,-2,44,3,16};
    int largest, second_largest;
    find_two_largest(a, 5, &largest, &second_largest);
    printf("Largest is: %d, second largest is: %d\n", largest, second_largest);
    return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
    *largest = a[0];
    *second_largest = a[0];
    for (int i =1; i< n; i++) {
        if (a[i] > *largest)
            *largest = a[i];
        if (a[i] > (*second_largest) && a[i] < (*largest))
            *second_largest = a[i];
    }
}
