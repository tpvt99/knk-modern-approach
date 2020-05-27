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
};


void print_part(struct part *inventory) {
    printf("Number: %d, Name: %s, on_hand: %d\n", inventory->number, inventory->name, inventory->on_hand);
}

void print_part2(struct part inventory) {
    printf("Number: %d, Name: %s, on_hand: %d\n", (&inventory)->number, (&inventory)->name, (&inventory)->on_hand);
}

int main()
{
    struct part inventory = {10, "Love me", 100};
    print_part(&inventory);
    print_part2(inventory);
}
