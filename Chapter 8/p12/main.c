#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int scrabble[26] = {0};
    char ch = 'A';
    while(ch <= 'Z') {
        if (ch == 'A' || ch =='E' || ch =='I' || ch == 'L' || ch =='N' || ch == 'O' || ch == 'R' || ch == 'S' || ch == 'T' || ch == 'U')
            scrabble[ch - 'A'] = 1;
        else if (ch == 'D' || ch =='G')
            scrabble[ch - 'A'] = 2;
        else if (ch == 'B' || ch =='C' || ch == 'M' || ch =='P')
            scrabble[ch - 'A'] = 3;
        else if (ch == 'F' || ch == 'H' || ch == 'V' || ch =='W' || ch == 'Y')
            scrabble[ch - 'A'] = 4;
        else if (ch == 'K')
            scrabble[ch - 'A'] = 5;
        else if (ch == 'J' || ch == 'X')
            scrabble[ch - 'A'] = 8;
        else if (ch == 'Q' || ch =='Z')
            scrabble[ch - 'A'] = 10;
        ch++;
    }
    int sum=0;
    printf("Enter a word: ");
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);
        sum += scrabble[ch - 'A'];
    }
    printf("Scrabble value: %d", sum);
    return 0;
}
