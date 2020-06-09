#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT.h"


int main()
{
    char ch, pop_char;
    Stack s = create();
    printf("Enter parentheses and/or braces: ");
    for (;;) {
        ch = getchar();
        if (ch == '(' || ch == '{') {
            push(s, ch);
        }
        else if (ch == ')' || ch == '}') {
            pop_char = pop(s);
            if ((pop_char == '{' && ch != '}') || (pop_char == '(' && ch != ')')) {
                printf("Not matching.");
                return 0;
            }
        }
        else if (ch == '\n')
            break;
    }
    if (is_empty(s))
        printf("Parenthesis/braces are nested properly\n");
    else
        printf("Not matching properly");
    return 0;
}
