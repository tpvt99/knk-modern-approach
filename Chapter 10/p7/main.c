#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

const int segments[10][7] = {   {1, 1, 1, 1, 1, 1, 0},
                                 {0, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 0, 1, 1, 0, 1},
                                 {1, 1, 1, 1, 0, 0, 1},
                                 {0, 1, 1, 0, 0, 1, 1},
                                 {1, 0, 1, 1, 0, 1, 1},
                                 {1, 0, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 0, 1, 1}};

char digits[4][MAX_DIGITS*4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main()
{
    printf("Enter a number: ");
    char ch;
    int counter = 0;
    while (1) {
        ch = getchar();
        if (ch == '\n')
            break;
        else if (ch >= '0' && ch <= '9')
            process_digit(ch-'0', counter++);

        if (counter == MAX_DIGITS)
            break;
    }
    print_digits_array();
    return 0;
}

void clear_digits_array(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_DIGITS*4; j++)
            digits[i][j] = ' ';
    }
}

void process_digit(int digit, int position) {
    if (segments[digit][0])
        digits[0][position*4+1] = '_';
    if (segments[digit][1])
        digits[1][position*4+2] = '|';
    if (segments[digit][2])
        digits[2][position*4+2] = '|';
    if (segments[digit][3])
        digits[2][position*4+1] = '_';
    if (segments[digit][4])
        digits[2][position*4] = '|';
    if (segments[digit][5])
        digits[1][position*4] = '|';
    if (segments[digit][6])
        digits[1][position*4+1] = '_';

}

void print_digits_array(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j< MAX_DIGITS*4; j++)
            printf("%c", digits[i][j]);
        printf("\n");
    }
}
