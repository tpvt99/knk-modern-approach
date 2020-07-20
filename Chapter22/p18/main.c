#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10000

int compare_function(const void *p, const void *q) {
    const int *p1 = p;
    const int *q1 = q;

    if (*p1 < *q1)
        return -1;
    else if (*p1 > *q1)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: main.c input\n");
        exit(EXIT_FAILURE);
    }

    FILE *src;

    if ((src = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int a[MAX_LENGTH];
    int d;
    int counter = 0;
    while(fscanf(src, "%d", &d) == 1) {
        a[counter++] = d;
    }

    qsort(a, counter, sizeof(int), compare_function);

    printf("Array after soring: ");
    for(int i = 0; i < counter; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Maximum number: %d\n", a[0]);
    printf("Minimum number: %d\n", a[counter-1]);
    if (counter % 2 == 0) {
        printf("Median numbers: %d\n", (a[counter/2-1] + a[counter/2]) /2);
    }
    else {
        printf("Median numbers: %d\n", a[counter/2]);
    }
    fclose(src);
    return 0;
}
