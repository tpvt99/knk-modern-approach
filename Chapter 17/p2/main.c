#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include <string.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} *inventory;

int num_parts = 0;
int MAX_PARTS = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int compare_part(const void *p, const void *q);

int main()
{
    char code;
    inventory = malloc(2 * sizeof(struct part));
    if (inventory == NULL) {
        printf("Cannot allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    MAX_PARTS += 2;
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n')
            ;
        switch (code) {
            case 'i': insert();
                        break;
            case 's': search();
                        break;
            case 'u': update();
                        break;
            case 'p': print();
                        break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }

}

int find_part(int number) {
    for (int i = 0; i< num_parts;i++)
        if ((inventory+i)->number == number)
            return i;
    return -1;
}

void insert(void) {
    int part_number;
    if (num_parts == MAX_PARTS) {
        printf("Database is full. Reallocating memory\n");
        struct part *temp = realloc(inventory, 2 * num_parts * (sizeof(struct part)));
        if (temp == NULL) {
            printf("Cannot expanding the database.\n");
        } else {
            inventory = temp;
            MAX_PARTS += 2;
        }
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    readline(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &((inventory+num_parts)->on_hand));
    num_parts++;
}

void search(void) {
    int i, number;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i>=0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    } else
        printf("Part not found.\n");
}

void update(void) {
    int i, number, change;
    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i>=0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else
        printf("Part not found\n");
}

void print(void) {
    int i;
    printf("Part Number    Part Name                "
           "Quantity on Hand\n");
    qsort(inventory, num_parts, sizeof(struct part), compare_part);
    for (i = 0; i <num_parts;i++)
        printf("%7d         %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}

int compare_part(const void *p, const void *q) {
    const struct part *p1 = p;
    const struct part *p2 = q;
    if (p1->number < p2->number)
        return -1;
    else if (p1->number == p2->number)
        return 0;
    else
        return 1;
}
