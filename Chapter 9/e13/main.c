#include <stdio.h>
#include <stdlib.h>

int evaluate_position(char board[8][8]);

int main()
{

    return 0;
}


int evaluate_position(char board[8][8]) {
    int white_sum = 0, black_sum = 0;
    for (int i =0; i<8;i++) {
        for (int j=0; j<8;j++) {
            if (board[i][j] == 'Q')
                white_sum += 9;
            else if (board[i][j] == 'R')
                white_sum += 5;
            else if (board[i][j] == 'B')
                white_sum += 3;
            else if (board[i][j] == 'N')
                white_sum += 3;
            else if (board[i][j] == 'P')
                white_sum += 1;
            if (board[i][j] == 'q')
                black_sum += 9;
            else if (board[i][j] == 'r')
                black_sum += 5;
            else if (board[i][j] == 'b')
                black_sum += 3;
            else if (board[i][j] == 'n')
                black_sum += 3;
            else if (board[i][j] == 'p')
                black_sum += 1;
        }
    }
    return white_sum - black_sum;
}
