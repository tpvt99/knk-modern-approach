#include <stdio.h>
#include <stdlib.h>


void print_haha(int , int a[*]);

int main()
{
    int x = 10;
    int a[x];
    print_haha(x, a);
    printf("Hello world!\n");
    return 0;
}

void print_haha(int n, int a[n]) {
    printf("n is %d\n", n);
    printf("length of a is %d\n", sizeof(a) / sizeof(a[0]));
    return ;
}
