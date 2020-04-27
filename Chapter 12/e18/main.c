#include <stdio.h>
#include <stdlib.h>

int evaluate_position(char board[8][8]);

int main()
{
    char board[8][8] = {{'Q',' '}, {'r'}};
    int x = evaluate_position(board);
    printf("Evaluation: %d", x);
    return 0;
}


int evaluate_position(char board[8][8]) {
    int white_sum = 0, black_sum = 0;
    char *p = *board;
    for(;p<*board+8*8;p++) {
        switch (*p) {
            case 'Q': white_sum += 9; break;
            case 'R': white_sum += 5;break;
            case 'B': white_sum += 3;break;
            case 'N': white_sum += 3;break;
            case 'P': white_sum += 1;break;
            case 'q': black_sum += 9;break;
            case 'r': black_sum += 5;break;
            case 'b': black_sum += 3;break;
            case 'n': black_sum += 3;break;
            case 'p': black_sum += 1;break;
        }
    }
    return white_sum - black_sum;
}
