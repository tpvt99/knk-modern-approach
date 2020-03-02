#include <stdio.h>
#include <stdlib.h>

int main()
{
    float money;
    printf("Enter an amount: ");
    scanf("%f", &money);
    printf("With tax added: $%.2f", money*1.05);
    return 0;
}
