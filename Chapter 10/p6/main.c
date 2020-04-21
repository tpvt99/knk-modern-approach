#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int top;
char contents[STACK_SIZE];

char pop(void);
void push(char);
void stack_overflow(void);
void stack_underflow(void);
bool is_full(void);
bool is_empty(void);

int main()
{
    char ch;
    int first_operand, second_operand, result;
    while (true) {
        printf("Enter an RPN expression: ");
        while ((ch = getchar()) != '\n') {
            if (ch >= '0' && ch <= '9')
                push(ch-'0');
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                first_operand = pop();
                second_operand = pop();
                switch (ch) {
                    case '+': result = first_operand + second_operand; break;
                    case '-': result = second_operand - first_operand; break;
                    case '*': result = second_operand * first_operand; break;
                    case '/': result = second_operand / first_operand; break;
                }
                push(result);
            }
            else if (ch == ' ')
                ;
            else if (ch == '=')
                printf("Value of expression: %d\n", pop());
            else if (ch == 'g')
                return 0;
        }
    }
    return 0;
}

void push(char ch) {
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

char pop(void) {
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

bool is_full(void) {
    return top == STACK_SIZE;
}

bool is_empty(void) {
    return top == 0;
}

void stack_overflow() {
    printf("Program too complex.");
    exit(EXIT_FAILURE);
}

void stack_underflow() {
    printf("Not enough operands.");
    exit(EXIT_FAILURE);
}
