#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void split_date(int day_of_year, int year, int *month, int *day);
bool is_leap_year(int year);

int main()
{
    int day_of_year = 61;
    int year = 2020;
    int day, month;
    split_date(day_of_year, year, &month, &day);
    printf("Day: %d in month: %d", day, month);
    return 0;
}

void split_date(int day_of_year, int year, int *month, int *day) {
    int total_days = 0;
    int days_in_month = 0;
    for (int m = 1; m <= 12; m++) {
        switch(m) {
            case 1: case 5: case 3: case 7: case 8: case 10: case 12: days_in_month = 31; break;
            case 2: {
                if (is_leap_year(year))
                    days_in_month = 29;
                else
                    days_in_month = 28;
            } break;
            case 4: case 6: case 9: case 11: days_in_month = 30; break;
        }
        if ((day_of_year - total_days) <= days_in_month) {
            *month = m;
            *day = day_of_year - total_days;
            break;
        } else {
            total_days += days_in_month;
        }
    }
}

bool is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return true;
            else
                return false;
        } else
            return true;
    } else
        return false;
}
