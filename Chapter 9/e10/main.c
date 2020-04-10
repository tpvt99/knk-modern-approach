#include <stdio.h>
#include <stdlib.h>
#define N 10

int largest_element(int , int [*]);
float average_array(int n, int a[n]);
int positive_numbers(int , int []);

int main()
{
    int a[N] = {-1, -3, 9, 10, 20, 1, 3, 4, 5};
    printf("Largest element: %d\n", largest_element(N, a));
    printf("Average of arrays: %.3f\n", average_array(N, a));
    printf("Number of positive numbers: %d\n", positive_numbers(N, a));
    return 0;
}

int largest_element(int n, int a[n]) {
    int largest = 0;
    for (int i = 0; i < n; i++) {
        if (i==0)
            largest = a[i];
        else
            if (a[i] >= largest)
                largest = a[i];
    }
    return largest;
}

float average_array(int n, int a[100]) {
    int sum = 0;
    for (int i = 0; i < n; i ++)
        sum += a[i];
    return sum / (float) n;
}

int positive_numbers(int n, int a[1]) {
    int x  = 0;
    for (int i = 0; i<n;i++)
        if (a[i] > 0)
            x += 1;
    return x;
}
