#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include <string.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;


struct part * find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);

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
            case 'e': erase();
                        break;
            case 'r': restore();
                        break;
            case 'd': dump();
                        break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }

}

struct part * find_part(int number) {
    struct part *p = inventory;
    while (p != NULL) {
        if (p->number > number)
            break;
        p = p->next;
    }
    if (p != NULL && p->number == number)
        return p;
    return NULL;
}

void insert(void) {
    struct part *p = malloc(sizeof(struct part));
    if (p == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &p->number);

    struct part *curr = inventory, *prev = NULL;
    for(;curr!=NULL;prev=curr, curr=curr->next) {
        if (curr->number > p->number)
            break;
    }
    if (curr != NULL && curr->number == p->number) {
        printf("Part exists.\n");
        return;
    }

    if (prev == NULL) {
        p->next = inventory;
        inventory = p;
    } else {
        p->next = curr;
        prev->next = p;
    }

    printf("Enter part name: ");
    readline(p->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &p->on_hand);
}

void search(void) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);
    struct part *p = find_part(number);

    if (p!=NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else
        printf("Part not found.\n");
}

void update(void) {
    int number, change;
    printf("Enter part number: ");
    scanf("%d", &number);
    struct part *p = find_part(number);
    if (p!=NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else
        printf("Part not found\n");
}

void print(void) {
    printf("Part Number    Part Name                "
           "Quantity on Hand\n");
    for (struct part *p = inventory; p!=NULL;p=p->next)
        printf("%7d         %-25s%11d\n", p->number, p->name, p->on_hand);
}

void erase(void) {
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);

    struct part *curr = inventory, *prev = NULL;
    for(;curr!=NULL;prev=curr, curr=curr->next) {
        if (curr->number >= number)
            break;
    }
    if (curr != NULL && curr->number == number) {
        if (prev == NULL)
            inventory = curr->next;
        else
            prev->next = curr->next;
        free(curr);
    }
}

void dump(void) {
    FILE *fp;
    printf("Enter the name of file to dump: ");
    char file_name[50];
    readline(file_name, 50);

    if((fp=fopen(file_name, "wb")) == NULL) {
        fprintf(stderr, "Cannot open the file %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    int item_write=0;
    struct part *top = inventory;
    while (top != NULL) {
        item_write+= fwrite(&(top->number), sizeof(int), 1, fp);
        item_write+= fwrite(top->name, sizeof(char) * (NAME_LEN+1), 1, fp);
        item_write+= fwrite(&(top->on_hand), sizeof(int), 1, fp);
        if (item_write != 3) {
            fprintf(stderr, "Write error\n");
        } else
            fprintf(stdout, "Dumping one item successfully\n");
        item_write = 0;
        top = top->next;
    }
    printf("Dump susscessfully\n");
    fclose(fp);

}

void restore(void) {
    FILE *fp;
    printf("Enter the name of file to restore: ");
    char file_name[50];
    readline(file_name, 50);

    if((fp=fopen(file_name, "rb")) == NULL) {
        fprintf(stderr, "Cannot open the file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    struct part *new_node = malloc(sizeof(struct part));

    int number_read;
    int on_hand_read;
    int name_read;
    number_read = fread(&(new_node->number), sizeof(int), 1, fp);
    name_read = fread(new_node->name, sizeof(char) * (NAME_LEN+1), 1, fp);
    on_hand_read = fread(&(new_node->on_hand), sizeof(int), 1, fp);
    struct part *last = inventory;

    while (number_read == 1 && name_read == 1 && on_hand_read == 1) {
        new_node->next = NULL;
        if (inventory == NULL) {
            inventory = new_node;
        }
        else
            last->next = new_node;
        last = new_node;
        new_node = malloc(sizeof(struct part));
        number_read = fread(&(new_node->number), sizeof(int), 1, fp);
        name_read = fread(new_node->name, sizeof(char) * (NAME_LEN+1), 1, fp);
        on_hand_read = fread(&(new_node->on_hand), sizeof(int), 1, fp);
    }
    fclose(fp);

}

