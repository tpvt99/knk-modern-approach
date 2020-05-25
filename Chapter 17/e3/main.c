#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value) {
    int *p = malloc(n * sizeof(int));
    if (p == NULL)
        return NULL;
    int *a = p;
    for (;a<p+n;a++)
        *a = initial_value;
    return p;
}

int main()
{
    int *p = create_array(10, 20);
    for (int i = 0; i < 10;i++)
        printf("%d ", *p);
    return 0;
}
