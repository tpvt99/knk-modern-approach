#include <stdio.h>
#include <stdlib.h>

#define N 100

void f(void);

int main()
{
    printf("N is %d\n", N);
    f();
    #ifdef N
    #undef N
    #endif // N
    return 0;
}

void f(void) {
    #if defined(N)
        printf("N is %d\n", N);
    #else
        printf("N is undefined\n");
    #endif // defined
}
