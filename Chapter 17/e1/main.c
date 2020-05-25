#include <stdio.h>
#include <stdlib.h>

void * my_malloc(int size) {
    void *p;
    if ((p = malloc(size))== NULL) {
        printf("Not enough space.\n");
        exit(EXIT_FAILURE);
    }
    printf("%p\n",p);
    return p;
}

int main()
{
    int *p = my_malloc(4 * sizeof(int));

    for (int i = 0 ; i < 4;i++)
        *(p+i) = i;
    for (int i = 0 ; i < 4;i++)
        printf("%d ",*(p+i));
    return 0;
}
