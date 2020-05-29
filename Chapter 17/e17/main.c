#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare_func(const void *p, const void *q) {

    if ( *((const int *)p) < *((const int *)q))
        return -1;
    else if (p == q)
        return 0;
    else return 1;
}

int main()
{
    int a[100] = {0};
    time_t t;
    /* Intializes random number generator */
   srand((unsigned) time(&t));

    for (int i =0; i < 100;i++) {
        a[i] = rand() % 100;
    }

    qsort(a+50, 50, sizeof(a[0]), compare_func);
    for (int i =0; i < 100;i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
