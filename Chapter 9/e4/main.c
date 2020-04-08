#include <stdio.h>
#include <stdlib.h>

int day_of_year(int month, int day, int year) {
    int total_days = 0;
    for (int i = 1; i < month; i++) {
        switch (i) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: total_days += 31; break;
            case 4: case 6: case 9: case 11: total_days += 30; break;
            case 2: {
                if (year % 4 == 0) {
                    if (year % 100 == 0) {
                        if (year % 400 == 0)
                            total_days += 29;
                        else
                            total_days += 28;
                    } else
                        total_days += 29;
                } else
                    total_days += 28;
                break;
            }
            default: ;
        }
        printf("Days: %d\n", total_days);
    }
    total_days += day;
    return total_days;
}

int main()
{
    printf("Day of year: %d\n", day_of_year(3,3,2021));
    return 0;
}
