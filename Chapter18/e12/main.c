#include <stdio.h>
#include <stdlib.h>

float inner_func(long x) {
    printf("inner function with %d\n", x);
    return 3.14;
}

int glob_func(double x) {
    printf("Inside globe func with x: %f\n", x);
    return 10;
}

int *ff(int m) {
    static int x = 10;
    return &x;
}

int (*f(float (*q)(long), char *c))(double) {
    (*q)(10);
    printf("c: %c\n", *c);
    int (*x)(double) = glob_func;
    return x;
}

int main()
{
    char c = 't';
    int (*result_f)(double) = f(inner_func, &c);
    (*result_f)(10.4);

    // TESTING PURPOSE between (pointer to func) and (func return pointers)
    int *g(int); // cannot assign
    int *(*m)(int) = ff; // able to assign

    //g = ff; cannot assign
    m = ff; // able to assign
    printf("%d: ", *(*m)(10));


    //f = outer_func;
    return 0;
}
