#include <stdio.h>
#include <stdlib.h>

struct date {
    int day;
    int month;
    int year;
};

int day_of_year(struct date d) {
    int total_days = 0;
    for (int i = 1; i < d.month; i++) {
        switch (i) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: total_days += 31; break;
            case 4: case 6: case 9: case 11: total_days += 30; break;
            case 2: {
                if (d.year % 4 == 0) {
                    if (d.year % 100 == 0) {
                        if (d.year % 400 == 0)
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
    }
    total_days += d.day;
    return total_days;
}

int compare_dates(struct date d1, struct date d2) {
    int earlier;
    if (d1.year < d2.year) {
        earlier = -1;
    }
    else if (d2.year < d1.year) {
        earlier = 1;
    } else {
        if (d1.month < d2.month) {
            earlier = -1;
        }
        else if (d2.month < d1.month) {
            earlier = 1;
        } else {
            if (d1.day < d2.day) {
                earlier = -1;
            }
            else if (d2.day < d1.day) {
                earlier = 1;
            } else {
                earlier = 0;
            }
        }
    }
    return earlier;
}

int main()
{
    struct date d1 = {.day = 16, .month = 5, .year = 2019};
    struct date d2 = {.day = 15, .month = 5, .year = 2019};
    printf("Day of year of d1: %d\n", day_of_year(d1));
    printf("Comparision: %d", compare_dates(d1, d2));
    return 0;
}
