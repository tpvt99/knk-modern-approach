#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("The reversed number: ");
    do {
        printf("%d", a % 10);
        a = a / 10;
    } while (a !=0);
    return 0;
}
