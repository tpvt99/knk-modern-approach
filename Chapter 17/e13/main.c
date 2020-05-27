#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node* insert(struct node *list, struct node *new_node) {
    struct node *curr = list, *prev = NULL;
    while ( (curr != NULL) && (curr->value < new_node->value)) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) {
        list = new_node;
        new_node->next = curr;
    } else {
        prev->next = new_node;
        new_node->next = curr;
    }
    return list;
}

void print(struct node *head) {
    printf("head->");
    while (head!=NULL) {
        printf("%d->", head->value);
        head=head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    head = insert(head, &(struct node){10});
    head = insert(head, &(struct node){20});
    head = insert(head, &(struct node){5});
    insert(head, &(struct node){15});
    insert(head, &(struct node){25});
    head=insert(head, &(struct node){2});
    print(head);
    return 0;
}
