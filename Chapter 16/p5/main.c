#include <stdio.h>
#include <stdlib.h>

struct time {
    int departure;
    int arrival;
};

void print_hour(int minutes) {
    int h = minutes / 60;
    int m = minutes - 60 * h;
    int convert_h = h;
    if (h >= 13 && h <= 23)
        convert_h = h - 12;
    printf("%d:%d", convert_h, m);
    if (h >= 0 && h<= 11)
        printf(" a.m.");
    else
        printf(" p.m.");
}

int main()
{
    struct time flight_time[8] = {{480,616},{583, 712},{679,811},{767,900},{840,968},{945,1075},{1140,1280},{1305,1438}};

    printf("Enter a 24-hour time: ");
    int h,m;
    scanf("%d:%d", &h, &m);
    int time = h*60 + m;
    int min_val = 24*60;
    int min_index;
    for (int i = 0; i < 8; i++) {
        int x = time - flight_time[i].departure;
        if (x < 0) {
            x = -x;
        }
        if (x < min_val) {
            min_val = x;
            min_index = i;
        }
    }
    printf("Closest departure time is: ");
    print_hour(flight_time[min_index].departure);
    printf(", arriving at: ");
    print_hour(flight_time[min_index].arrival);
    return 0;
}
