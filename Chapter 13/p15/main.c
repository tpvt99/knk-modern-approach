#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define STACK_SIZE 100

int top=0;

char pop(char *contents);
void push(char *contents, char ch);
void stack_overflow(void);
void stack_underflow(void);
bool is_full(void);
bool is_empty(void);
int read_line(char [], int );
int evaluate(const char *expression);

int main()
{
    char rpn_expression[STACK_SIZE];
    while (1) {
        printf("Enter an RPN expression: ");
        read_line(rpn_expression, STACK_SIZE);
        int rpn_value = evaluate(rpn_expression);
        printf("Value of RPN expression: %d\n", rpn_value);
    }

    return 0;
}

int evaluate(const char *expression) {
    char contents[STACK_SIZE];
    top = 0;
    int first_operand, second_operand, result;
    while (*expression) {
            if (*expression >= '0' && *expression <= '9')
                push(contents, *expression-'0');
            else if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/') {
                first_operand = pop(contents);
                second_operand = pop(contents);
                switch (*expression) {
                    case '+': result = first_operand + second_operand; break;
                    case '-': result = second_operand - first_operand; break;
                    case '*': result = second_operand * first_operand; break;
                    case '/': result = second_operand / first_operand; break;
                }
                push(contents, result);
            }
            else if (*expression == ' ')
                ;
            else if (*expression == '=')
                return pop(contents);
            else if (*expression == 'g')
                exit(EXIT_SUCCESS);
        expression++;
    }
}

int read_line(char str[], int n) {
    int i = 0;
    char ch;
    while((ch=getchar())!='\n') {
        if (i<n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

void push(char *contents, char ch) {
    if (is_full())
        stack_overflow();
    else {
        *(contents+top) = ch;
        top+=1;
    }
}

char pop(char *contents) {
    if (is_empty())
        stack_underflow();
    else {
        top-=1;
        return *(contents+top);
    }
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
