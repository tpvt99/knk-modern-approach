#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no_items, d, m, y;
    float price;
    printf("Enter item number: ");
    scanf("%d", &no_items);
    printf("Enter unit price: ");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d / %d / %d", &m, &d, &y);
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%7.2f\t%d/%d/%d", no_items, price, m,d,y);
    return 0;
}
