#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int top = 0;
char contents[STACK_SIZE];

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);


int main()
{
    char ch, pop_char;
    printf("Enter parentheses and/or braces: ");
    for (;;) {
        ch = getchar();
        if (ch == '(' || ch == '{') {
            push(ch);
        }
        else if (ch == ')' || ch == '}') {
            pop_char = pop();
            if ((pop_char == '{' && ch != '}') || (pop_char == '(' && ch != ')')) {
                printf("Not matching.");
                return 0;
            }
        }
        else if (ch == '\n')
            break;
    }
    if (is_empty())
        printf("Parenthesis/braces are nested properly\n");
    else
        printf("Not matching properly");
    return 0;
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(char c) {
    if (is_full())
        stack_overflow();
    else
        contents[top++] = c;
}

char pop(void) {
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void stack_overflow(void) {
    printf("Stack Overflow. Terminate\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Stack Underflow. Terminate\n");
    exit(EXIT_FAILURE);
}
