#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DISP(f, x) printf(#f " (%g) = %g\n", (x), sqrt(x))
#define DISP2(f, x, y) printf(#f " (%g, %g) = %g\n", (x), (y), f(x,y))

int main()
{
    float x = 3.0f;
    DISP(sqrt, x);
    DISP2(pow, 2.0, 3.0);
    return 0;
}
