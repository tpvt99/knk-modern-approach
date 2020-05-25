#include <stdio.h>
#include <stdlib.h>

struct date {
    int day;
    int month;
    int year;
};

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
    printf("Enter first date (mm/dd/yy): ");
    struct date day1;
    scanf("%d/%d/%d", &day1.month, &day1.day, &day1.year);
    printf("Enter second date (mm/dd/yy): ");
    struct date day2;
    scanf("%d/%d/%d", &day2.month, &day2.day, &day2.year);
    int earlier = compare_dates(day1, day2);
    if (earlier == -1)
        printf("%d/%d/%d is earlier than %d/%d/%d", day1.month, day1.day, day1.year, day2.month, day2.day, day2.year);
    else if (earlier == 1)
        printf("%d/%d/%d is earlier than %d/%d/%d", day2.month, day2.day, day2.year, day1.month, day1.day, day1.year);
    else
        printf("Two dates are equal");
    return 0;
}
