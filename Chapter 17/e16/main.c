#include <stdio.h>
#include <stdlib.h>

int sum(int (*f)(int), int start, int end);
int func(int );

int main()
{
    printf("Answer: %d\n", sum(func, 1, 5));
    return 0;
}

int sum(int (*f)(int), int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += (*f)(i);
    }
    return sum;
}

int func(int n) {
    return n*n;
}
