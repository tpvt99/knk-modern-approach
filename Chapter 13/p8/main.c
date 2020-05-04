#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compute_scrabble_value(const char *word);

int main()
{
    printf("Enter a word: ");
    char ch[20];
    scanf("%s", ch);
    int sum = compute_scrabble_value(ch);
    printf("Scrabble value: %d", sum);
}

int compute_scrabble_value(const char *word) {
    int sum = 0;
    char ch;
    while(*word) {
        ch = toupper(*(word++));
        if (ch == 'A' || ch =='E' || ch =='I' || ch == 'L' || ch =='N' || ch == 'O' || ch == 'R' || ch == 'S' || ch == 'T' || ch == 'U')
            sum += 1;
        else if (ch == 'D' || ch =='G')
            sum += 2;
        else if (ch == 'B' || ch =='C' || ch == 'M' || ch =='P')
            sum += 3;
        else if (ch == 'F' || ch == 'H' || ch == 'V' || ch =='W' || ch == 'Y')
            sum += 4;
        else if (ch == 'K')
            sum += 5;
        else if (ch == 'J' || ch == 'X')
            sum += 8;
        else if (ch == 'Q' || ch =='Z')
            sum += 10;
    }
    return sum;
}
