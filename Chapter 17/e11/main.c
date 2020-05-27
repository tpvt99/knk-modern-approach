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

int count_occurences(struct node *list, int n) {
    int counter = 0;
    while (list!= NULL) {
        if (list->value == n)
            counter += 1;
        list=list->next;
    }
    return counter;
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
    printf("Occurence of 10: %d\n", count_occurences(head, 10));
    printf("Occurence of 30: %d\n", count_occurences(head, 30));
    printf("Occurence of 50: %d\n", count_occurences(head, 50));
    return 0;
}
