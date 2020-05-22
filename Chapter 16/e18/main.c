#include <stdio.h>
#include <stdlib.h>

enum Piece {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
    EMPTY,
};

enum Color {
    BLACK,
    WHITE,
};

struct Square {
    enum Piece piece;
    enum Color color;
};

void initializer(struct Square (*board)[8]) {
    struct Square (*row)[8] = board;
    for (; row < board + 8; row++) {
        if ((row - board == 0) || (row-board == 7)) {
            struct Square *element = *row;
            (*element).piece = ROOK;
            (*(element+1)).piece = KNIGHT;
            (*(element+2)).piece = BISHOP;
            (*(element+3)).piece = KING;
            (*(element+4)).piece = QUEEN;
            (*(element+5)).piece = BISHOP;
            (*(element+6)).piece = KNIGHT;
            (*(element+7)).color = ROOK;
            for (;element < *row + 8; element++) {
                if ((row-board) == 0)
                    (*element).color = BLACK;
                else
                    (*element).color = WHITE;
            }
        } else if ((row - board == 1) || (row-board == 6)) {
            for (struct Square *element = *row; element < *row + 8; element++) {
                (*element).piece = PAWN;
                if ((row-board) == 1)
                    (*element).color = BLACK;
                else
                    (*element).color = WHITE;
            }
        } else {
            for (struct Square *element = *row; element < *row + 8; element++) {
                (*element).piece = EMPTY;
                (*element).color = BLACK;
            }
        }
    }
}

int main()
{
    struct Square board[8][8] = {0};
    initializer(board);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d%d ", board[i][j].piece, board[i][j].color);
        }
        printf("\n");
    }
    return 0;
}
