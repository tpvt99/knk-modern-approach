#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void insertQueue();
void deleteQueue();
void printQueue();
void firstQueue();
void lastQueue();

int main()
{
    char command;
    for (;;) {
        printf("Enter a command: ");
        command = getchar();
        getchar();
        switch (command) {
            case 'i': insertQueue();break;
            case 'd': deleteQueue();break;
            case 'f': firstQueue();break;
            case 'l': lastQueue();break;

        }
    }
    return 0;
}

void insertQueue(void) {
    printf("Enter number: ");
    int n;
    scanf("%d", &n);
    getchar();
    push(n);
}

void deleteQueue(void) {
    int n = pop();
    printf("Pop item: %d\n", n);
}

void firstQueue(void) {
    int n = first_item();
    printf("First item: %d\n", n);
}

void lastQueue(void) {
    int n = last_item();
    printf("First item: %d\n", n);
}

