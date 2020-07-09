#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

int main()
{
    char code;
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
            case 'd': dump();
                        break;
            case 'r': restore();
                        break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }

}

int find_part(int number) {
    for (int i = 0; i< num_parts;i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

void insert(void) {
    int part_number;
    if (num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }
    int i, z;
    for (i = 0; i < num_parts;i++) {
        if (inventory[i].number > part_number)
            break;
    }
    for (z=num_parts+1;z>i;z--) {
        inventory[z].number = inventory[z-1].number;
        strcpy(inventory[z].name, inventory[z-1].name);
        inventory[z].on_hand = inventory[z-1].on_hand;
    }
    inventory[i].number = part_number;
    printf("Enter part name: ");
    readline(inventory[i].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[i].on_hand);
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
    for (i = 0; i <num_parts;i++)
        printf("%7d         %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}

void dump(void) {
    printf("Enter name of output file: ");
    char file_name[50];
    readline(file_name, 50);

    FILE *fp;
    if ((fp = fopen(file_name, "wb")) == NULL) {
        fprintf(stderr, "Cannot open the file %s\n", file_name);
        return;
    }

    int no_items_written = fwrite(&inventory, sizeof(struct part), num_parts, fp);
    if (no_items_written < num_parts) {
        fprintf(stderr, "Dumping error.\n");
    } else
        fprintf(stdout, "Dumping successfully\n");

    fclose(fp);
    return;
}

void restore(void) {
    printf("Enter name of output file: ");
    char file_name[50];
    readline(file_name, 50);

    FILE *fp;
    if ((fp = fopen(file_name, "rb")) == NULL) {
        fprintf(stderr, "Cannot open the file %s\n", file_name);
        return;
    }

    printf("Enter number of items to read: ");
    int n;
    scanf("%d", &n);

    int no_items_read = fread(&inventory, sizeof(struct part), n, fp);
    if (no_items_read < n) {
        if (feof(fp))
            fprintf(stderr, "Reading End of file while reading %d elements from file %s\n", n, file_name);
        else if (ferror(fp))
            fprintf(stderr, "Reading Error from file %s\n", file_name);
    } else {
        fprintf(stdout, "Reading successfully\n");
        num_parts = n;
    }
}
