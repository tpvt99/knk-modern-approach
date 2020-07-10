#include <stdio.h>
#include <stdlib.h>

struct time {
    int departure;
    int arrival;
};

void print_hour(int minutes);



int main(int argc, char *argv[])
{

    if (argc != 2) {
        fprintf(stderr, "usage: main.c file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    struct time flight_time[8];
    int counter = 0;
    int h1, h2, h3, h4;
    char str[50];
    while(fgets(str, 50, fp) != NULL) {
        sscanf(str, "%d:%d %d:%d", &h1, &h2, &h3, &h4);
        flight_time[counter].departure = h1*60 + h2;
        flight_time[counter].arrival = h3*60 + h4;
        counter+=1;
    }

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
    fclose(fp);
    return 0;
}


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
