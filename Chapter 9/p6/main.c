#include <stdio.h>
#include <stdlib.h>

int calculate_function(int x) {
    return 3 * x * x * x * x * x + 2 * x * x * x *x - 5 * x * x *x - x * x + 7 * x - 6;
}

int main()
{
    printf("This program calculates the function 3x^5 + 2x^4 - 5x^3 - x^2 +7x - 6\n");
    printf("Enter x: ");
    int x;
    scanf("%d", &x);
    int result = calculate_function(x);
    printf("Results is :%d", result);
    return 0;
}
