#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN+1];
    int price;
    int on_hand;
};

int find_part(int number, int num_parts, struct part *inventory);
void insert(struct part *inventory, int *num_parts);
void search(struct part *inventory, int num_parts);
void update(struct part *inventory, int num_parts);
void print(struct part *inventory, int num_parts);
void update_price(struct part *inventory, int num_parts);

int main()
{
    struct part inventory[MAX_PARTS];

    int num_parts = 0;

    char code;
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n')
            ;
        switch (code) {
            case 'i': insert(inventory, &num_parts);
                        break;
            case 's': search(inventory, num_parts);
                        break;
            case 'u': update(inventory, num_parts);
                        break;
            case 'x': update_price(inventory, num_parts);
                        break;
            case 'p': print(inventory, num_parts);
                        break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }

}

int find_part(int number, int num_parts, struct part *inventory) {
    for (int i = 0; i< num_parts;i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

void insert(struct part *inventory, int *num_parts) {
    int part_number;
    if (*num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number, *num_parts, inventory) >= 0) {
        printf("Part already exists.\n");
        return;
    }
    inventory[*num_parts].number = part_number;
    printf("Enter part name: ");
    readline(inventory[*num_parts].name, NAME_LEN);
    printf("Enter price: ");
    scanf("%d", &inventory[*num_parts].price);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);
    (*num_parts)++;
}

void search(struct part *inventory, int num_parts) {
    int i, number;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);
    if (i>=0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Price: %d\n", inventory[i].price);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    } else
        printf("Part not found.\n");
}

void update(struct part *inventory, int num_parts) {
    int i, number, change;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);
    if (i>=0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else
        printf("Part not found\n");
}

void update_price(struct part *inventory, int num_parts) {
    int i, number, change;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);
    if (i>=0) {
        printf("Enter a new price: ");
        scanf("%d", &change);
        inventory[i].price = change;
    } else
        printf("Part not found\n");
}

void print(struct part *inventory, int num_parts) {
    int i;
    printf("Part Number    Part Name                "
           "Price    Quantity on Hand\n");
    for (i = 0; i <num_parts;i++)
        printf("%7d         %-25s%2d%11d\n", inventory[i].number, inventory[i].name, inventory[i].price, inventory[i].on_hand);
}
