#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define DICE 6

int roll_dice(void);
bool play_game(void);

int main()
{
    int win = 0, loose = 0;
    srand((unsigned) time(NULL));
    char ch;
    while (1) {
        if (play_game())
            win += 1;
        else
            loose += 1;
        printf("Play again? ");
        scanf(" ");
        scanf("%c", &ch);
        ch = tolower(ch);
        if (ch == 'n')
            break;
        // scanf(" "); not putting this at the end because space correspondings to infinite space/non-char
        printf("ch is %c\n", ch);
    }
    printf("Wins: %d Losses: %d\n", win, loose);
    return 0;
}

int roll_dice(void) {
    int dice1 = rand() % DICE;
    int dice2 = rand() % DICE;
    return dice1 + dice2;
}

bool play_game(void) {
    int first_sum, subsequent_sum;
        first_sum = roll_dice();
        printf("You rolled: %d\n", first_sum);
        printf("Your point is: %d\n", first_sum);
        if (first_sum == 7 || first_sum == 11) {
            printf("You win!\n");
            return true;
        }
        else if (first_sum == 2 || first_sum == 3 || first_sum == 12) {
            printf("You loose!\n");
            return false;
        }
        else {
            for(;;) {
                subsequent_sum = roll_dice();
                printf("You rolled: %d\n", subsequent_sum);
                if (subsequent_sum == first_sum) {
                    printf("You win!\n");
                    return true;
                } else if (subsequent_sum == 7) {
                    printf("You loose!\n");
                    return false;
                }
            }
        }
}
