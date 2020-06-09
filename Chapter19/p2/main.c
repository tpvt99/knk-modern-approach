#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT.h"

int main()
{
    char ch;
    int first_operand, second_operand, result;
    Stack s = create(100);
    while (true) {
        printf("Enter an RPN expression: ");
        while ((ch = getchar()) != '\n') {
            if (ch >= '0' && ch <= '9')
                push(s, ch-'0');
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                first_operand = pop(s);
                second_operand = pop(s);
                switch (ch) {
                    case '+': result = first_operand + second_operand; break;
                    case '-': result = second_operand - first_operand; break;
                    case '*': result = second_operand * first_operand; break;
                    case '/': result = second_operand / first_operand; break;
                }
                push(s, result);
            }
            else if (ch == ' ')
                ;
            else if (ch == '=')
                printf("Value of expression: %d\n", pop(s));
            else if (ch == 'g')
                return 0;
        }
    }
    return 0;
}
