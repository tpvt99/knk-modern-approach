#include <stdio.h>
#include <stdlib.h>

enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};

int main()
{
    printf("Hello world!\n");
    const int piece_value[] = {200, 9, 5, 3, 3, 1};
    const int chess[] = {[KING] = 200, [QUEEN] = 9, [ROOK] = 5, [BISHOP] = 3, [KNIGHT] = 3, [PAWN] = 1};
    for (int i = 0; i < sizeof(chess) / sizeof(chess[0]);i++)
        printf("%d ", chess[i]);
    return 0;
}
