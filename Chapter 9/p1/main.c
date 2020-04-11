#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY 100

void selection_sort(int, int [*]);

int main()
{
    int integers[MAX_ARRAY];
    printf("Enter a series of integers (0 to stop): \n");
    int x;
    int i = 0;
    for (i = 0; i<MAX_ARRAY; i++) {
        scanf("%d", &x);
        if (x != 0)
            integers[i] = x;
        else
            break;
    }
    int length = i;
    printf("Integer lists before sorting: ");
    for (int i = 0; i<length; i++){
        printf("%d ", integers[i]);
    }
    printf("\n");
    selection_sort(i, integers);
    printf("Integer lists after sorting: ");
    for (int i = 0; i<length; i++){
        printf("%d ", integers[i]);
    }
    return 0;
}

void selection_sort(int n, int a[n]) {
    if (n == 1)
        return;
    int largest = a[0];
    int index = 0;
    for (int i = 1; i<n; i++) {
        if (a[i] > largest) {
            largest = a[i];
            index = i;
        }
    }
    int temp = a[n-1];
    a[n-1] = largest;
    a[index] = temp;
    selection_sort(n-1, a);
}
