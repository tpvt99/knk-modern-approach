#include <stdio.h>
#include <stdlib.h>

#define cube(x) ((x)*(x)*(x))
#define remainder(x) ((x)%4)
#define test(x, y) ((x)*(y)<100?1:0)

int main()
{
    int a = 2;
    int b = 10;
    printf("cube of a + 2 = %d\n", cube(a+2));
    printf("remainder of a + 3 = %d\n", remainder(a+3));
    printf("final value of (x+2)*(b+1): %d", test(a+2, b+100));
    return 0;
}
