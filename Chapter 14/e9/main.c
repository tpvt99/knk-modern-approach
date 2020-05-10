#include <stdio.h>
#include <stdlib.h>

#define CHECK(x,y,n) ((0<=(x)&&(x)<=(n-1)&&0<=(y)&&(y)<=(n-1))?1:0)
#define MEDIAN(x,y,z) ((((x)+(y)+(z))/3))
#define POLYNOMIAL(x) ((3*(x)*(x)*(x)*(x)*(x)+2*(x)*(x)*(x)*(x)-5*(x)*(x)*(x)-(x)*(x)+7*(x)-6))

int main()
{
    printf("%d\n", CHECK(10,20,30));
    printf("%d\n", CHECK(10,20,15));
    printf("%d\n", MEDIAN(10,20,25));
    printf("%f\n", 100/(float) POLYNOMIAL(2));
    return 0;
}
