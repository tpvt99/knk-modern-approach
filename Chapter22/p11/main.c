#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: main date\n");
        exit(EXIT_FAILURE);
    }

    int month, day, year;
    int r = sscanf(argv[1], "%d%*[-/]%d%*[-/]%d", &month, &day, &year);
    if (r == 3) {
        switch(month) {
            case 1: printf("January ");break;
            case 2: printf("February ");break;
            case 3: printf("March ");break;
            case 4: printf("April ");break;
            case 5: printf("May ");break;
            case 6: printf("June ");break;
            case 7: printf("July ");break;
            case 8: printf("August ");break;
            case 9: printf("September ");break;
            case 10: printf("October ");break;
            case 11: printf("November ");break;
            case 12: printf("December ");break;
        }
        fprintf(stdout, "%d, %d\n", day, year);

    } else {
        printf("Error while reading. Exit.\n");
    }

    return 0;
}
