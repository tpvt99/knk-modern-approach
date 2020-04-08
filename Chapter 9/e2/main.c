#include <stdio.h>
#include <stdlib.h>

int check (int x, int y, int n) {
    if (0 <= x && x <= n-1 && 0 <= y && y <= n-1)
        return 1;
    return 0;
}

int main()
{
    printf("%d\n", check(1,2,3));
    printf("%d\n", check(1,2,1));
    printf("%d\n", check(1,2,5));
    return 0;
}
