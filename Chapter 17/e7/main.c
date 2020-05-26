#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void add_to_list(struct node **head, int n) {
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *head;
    *head = new_node;
};

void print_list(struct node *head) {
    printf("head->");
    while (head != NULL) {
        printf("%d->", head->value);
        head = head->next;
    }
    printf("NULL");
}

void delete_list(struct node **head) {
    struct node *p = *head;
    for (;p!= NULL;) {
        struct node *curr = p;
        p = p->next;
        free(curr);
    }
    *head = p;
}

int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int temp;
    struct node *list = NULL;
    for (int i = 0; i<n;i++) {
        printf("Enter value: ");
        scanf("%d", &temp);
        add_to_list(&list, temp);
    }
    print_list(list);
    printf("\nDelete the linked list...\n");
    delete_list(&list);
    print_list(list);
    return 0;
}
