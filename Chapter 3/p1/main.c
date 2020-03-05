#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d,m,y;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d / %d / %d", &m, &d, &y);
    printf("You entered the date %.4d%.2d%.2d\n", y,m,d);
    return 0;
}
