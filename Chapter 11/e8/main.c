#include <stdio.h>
#include <stdlib.h>

int *find_largest(int, int [*]);

int main()
{
    int a[5] = {43,-2,32,52,1};
    int *largest = find_largest(5, a);
    printf("Largest number is: %d", *largest);
    return 0;
}

int *find_largest(int n, int a[n]) {
    int largest_index = 0;
    for (int i = 1; i< n; i++) {
        if (a[i] > a[largest_index])
            largest_index = i;
    }
    return &a[largest_index];
}
