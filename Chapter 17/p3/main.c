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
