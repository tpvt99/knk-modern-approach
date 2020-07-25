#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

double try_math_fcn(double (*)(double), double, char *);


#define TRY_MATH_FCN(fp, x) try_math_fcn(fp, x, "Error in call of " #fp)


int main()
{
    double in = -9.7;
    //double x = try_math_fcn(sqrt, in, "sqrt error haha");
    //double y = try_math_fcn(exp, 1000, "Error in call of sqrt");
    double x = TRY_MATH_FCN(sqrt, in);
    printf("Sqrt of %f is %f\n", in, 1);
    return 0;
}

double try_math_fcn(double (*pf)(double), double x, char *c) {
    errno = 0;
    double results = pf(x);
    if (errno != 0) {
        perror(c);
        exit(EXIT_FAILURE);
    }
    return results;
}
