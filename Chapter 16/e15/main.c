#include <stdio.h>
#include <stdlib.h>

typedef enum days {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
} DAYS;

int main()
{
    DAYS d = MONDAY;
    d = 100;
    printf("%d\n", d);
    return 0;
}
