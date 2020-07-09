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

void print(struct part *inventory, int num_parts);
void dump(struct part *inventory, int num_parts, FILE *fp);
void restore(FILE *fp, struct part *, int *);
int concat_inventory(struct part **dest, struct part *s1, int n1, struct part *s2, int n2);

int compare_parts(const void *p, const void *q) {
    const struct part *p1 = p;
    const struct part *q1 = q;
    if (p1->number < q1->number)
        return -1;
    else if (p1->number == q1->number)
        return 0;
    else
        return 1;
}

int merge_inventories(struct part **merged, struct part *inv, int n);

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "usage: merged file1 file2 output_file\n");
        exit(EXIT_FAILURE);
    }

    FILE *f1, *f2, *output_file;

    if((f1 = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if((f2 = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if((output_file = fopen(argv[3], "wb")) == NULL) {
        fprintf(stderr, "Cannot open file %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    struct part inventory1[MAX_PARTS];
    struct part inventory2[MAX_PARTS];
    int n1;
    int n2;
    restore(f1, inventory1, &n1);
    printf("Contents from file %s: \n", argv[1]);
    print(inventory1, n1);
    restore(f2, inventory2, &n2);
    printf("Contents from file %s: \n", argv[2]);
    print(inventory2, n2);
    struct part *concat_inv;
    concat_inventory(&concat_inv, inventory1, n1, inventory2, n2);
    qsort(concat_inv, n1+n2, sizeof(struct part), compare_parts);
    printf("After concatenating: \n");
    print(concat_inv, n1+n2);
    struct part *merged_inv;
    int out = merge_inventories(&merged_inv, concat_inv, n1+n2);
    printf("After merging: \n");

    print(merged_inv, out);
    printf("Dumping the merged data...\n");
    dump(merged_inv, out, output_file);
}

int merge_inventories(struct part **merged, struct part *inv, int n) {
    int current_number = inv->number;
    int current_on_hand = inv->on_hand;
    char current_name[NAME_LEN+1];
    strcpy(current_name, inv->name);
    int total_items = 0;

    *merged = malloc(sizeof(struct part) * n);

    for (int i = 1; i <n;i++) {
        if ((inv+i)->number == current_number) {
            if (strcmp((inv+i)->name, current_name) != 0) {
                fprintf(stderr, "Item has same number: %d but different name: %s vs. %s\n", current_number, (inv+i)->name, current_name);
            } else {
                current_on_hand += (inv+i)->on_hand;
            }
        } else {
            (*merged + total_items)->number = current_number;
            (*merged + total_items)->on_hand = current_on_hand;
            strcpy((*merged + total_items)->name, current_name);
            total_items+=1;
            current_number = (inv+i)->number;
            current_on_hand = (inv+i)->on_hand;
            strcpy(current_name, (inv+i)->name);
        }
    }
    (*merged + total_items)->number = current_number;
    (*merged + total_items)->on_hand = current_on_hand;
    strcpy((*merged + total_items)->name, current_name);
    total_items+=1;
    return total_items;
}

int concat_inventory(struct part **dest, struct part *s1, int n1, struct part *s2, int n2) {
    *dest = malloc(sizeof(struct part) * (n1 + n2));

    if (*dest == NULL) {
        fprintf(stderr, "Cannot allocate for merging function\n");
        exit(EXIT_FAILURE);
    }
    int i;
    for (i = 0; i < n1; i++) {
        (*dest+i)->number = (s1+i)->number;
        (*dest+i)->on_hand = (s1+i)->on_hand;
        strcpy((*dest+i)->name, (s1+i)->name);
    }
    for (;i<n1+n2;i++) {
        (*dest+i)->number = (s2+i-n1)->number;
        (*dest+i)->on_hand = (s2+i-n1)->on_hand;
        strcpy((*dest+i)->name, (s2+i-n1)->name);
    }
    return n1+n2;
}


void print(struct part *inventory, int num_parts) {
    int i;
    printf("Part Number    Part Name                "
           "Quantity on Hand\n");
    for (i = 0; i <num_parts;i++)
        printf("%7d         %-25s%11d\n", (inventory+i)->number, (inventory+i)->name, (inventory+i)->on_hand);
}

void dump(struct part *inventory, int num_parts, FILE *fp) {

    int no_items_written = fwrite(inventory, sizeof(struct part), num_parts, fp);
    if (no_items_written < num_parts) {
        fprintf(stderr, "Dumping error.\n");
    } else
        fprintf(stdout, "Dumping successfully\n");

    fclose(fp);
    return;
}

void restore(FILE *fp, struct part *inventory, int *x) {
    printf("Enter number of items to read: ");
    int n;
    scanf("%d", &n);

//    inventory = malloc(sizeof(struct part) * n);
//    if (inventory == NULL) {
//        fprintf(stderr, "Cannot allocate memory for inventory\n");
//        return;
//    }

    int no_items_read;
    for (int i = 0; i< n; i++) {
        int m = fread(inventory+i, sizeof(struct part), 1, fp);
        no_items_read += m;
    }

    if (no_items_read < n) {
        if (feof(fp)) {
            fprintf(stderr, "Reading End of file while reading %d elements from file\n", n);
            *x = no_items_read;
        }
        else if (ferror(fp))
            fprintf(stderr, "Reading Error from file\n");
    } else {
        fprintf(stdout, "Reading successfully\n");
        *x = n;
    }
}
