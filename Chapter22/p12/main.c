#include <stdio.h>
#include <stdlib.h>

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

    char str[100];
    int item, m,d,y;
    float price;
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    while(fgets(str, 100, fp) != NULL) {
        int x = sscanf(str, "%d,%f,%d/%d/%d", &item, &price, &m, &d, &y);
        if (x == 5)
            printf("%d\t\t$%7.2f\t%d/%d/%d\n", item, price, m,d,y);
    };

    return 0;
}
