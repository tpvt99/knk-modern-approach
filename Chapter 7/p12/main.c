#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter an expression: ");
    float a, result;
    char ch;
    scanf("%f", &a);
    result = a;
    while (1) {
        scanf("%c", &ch);
        if (ch == '\n')
            break;
        scanf("%f", &a);
        if (ch == '+')
            result += a;
        else if (ch == '-')
            result -= a;
        else if (ch == '*')
            result *= a;
        else if (ch == '/')
            result /= a;
    }
    printf("Value of an expression: %.3f", result);
    return 0;
}
