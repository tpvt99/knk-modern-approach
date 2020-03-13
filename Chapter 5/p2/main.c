#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h, m;
    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &h, &m);
    int convert_h = h;
    if (h >= 13 && h <= 23)
        convert_h = h - 12;
    printf("Equivalent 12-hour time: %d:%d", convert_h, m);
    if (h >= 0 && h<= 11)
        printf(" AM\n");
    else
        printf(" PM\n");
    return 0;
}
