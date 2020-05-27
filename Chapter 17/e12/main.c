#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void insert(struct node **head, int val) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        exit(EXIT_FAILURE);
    new_node->value = val;
    new_node->next = *head;
    *head = new_node;
}

void print(struct node *head) {
    printf("head->");
    while (head!=NULL) {
        printf("%d->", head->value);
        head=head->next;
    }
    printf("NULL\n");
}

struct node *find_last(struct node *list, int n) {
    int counter = 0;
    int location=0;
    struct node *x = NULL;
    while (list!= NULL) {
        if (list->value == n) {
            x = list;
            location = counter;
        }
        counter += 1;
        list=list->next;
    }
    if (x!=NULL)
        printf("Find node x at location: %d\n", location);
    else
        printf("No node has that value\n");
    return x;
}

int main()
{
    struct node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 100);
    insert(&head, 10);
    insert(&head, 10);
    print(head);
    find_last(head, 10);
    find_last(head, 30);
    find_last(head, 50);
    return 0;
}
