#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main()
{
    char ch;
    int first_operand, second_operand, result;
    while (1) {
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

