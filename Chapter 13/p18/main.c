#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Enter a date (mm/dd/yyyy): ");
    int m, d,y;
    scanf("%d/%d/%d", &m, &d, &y);
    printf("You entered the date %s %d, %d", months[m-1], d, y);
    return 0;
}
