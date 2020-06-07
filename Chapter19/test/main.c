#include <stdio.h>
#include <stdlib.h>

typedef struct items {
    int value;
    float f;
} *Item;

int main()
{
    Item i1 = malloc(sizeof(Item));
    i1->value = 10;
    i1->f = 10.23;
    printf("Size of struct items: %d and size of Item: %d\n", sizeof(struct items), sizeof(Item));
    printf("value: %d and f-value: %f\n", (*i1).value, (*i1).f);
    printf("Hello world!\n");
    return 0;
}
