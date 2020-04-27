#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3] = {10, 11, 12};
    int b[3][2]= {{1,2},{4,5},{6,7}};
    int (*ptr)[3] = &a;
    int *p = a;
//    printf("ptr address: %p\n", ptr);
//    printf("ptr address + 1: %p\n", ptr+1);
//    printf("p address: %p\n", p);
//    printf("p address + 1: %p\n", p+1);
//    int *q = *ptr;
//    printf("%d:\n", *q);
//    printf("%d:\n", q[2]);
//    printf("%d:\n", (*ptr)[0]);
//    printf("%d:\n", *(*ptr+1));
//    printf("%d\n", **b);

    printf("%d\n", sizeof(p));
    printf("%d\n", sizeof(ptr));
    return 0;
}
