#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("This program creates a magic square of a specified size.\nThe size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    int n;
    scanf("%d", &n);
    int square[n][n];
    for (int i = 0; i< n; i++) {
        for (int j = 0; j<n; j++)
            square[i][j] = 0;
    }
    int current_row = 0, current_column = n/2;
    for (int i = 1; i <= n*n; i++) {
        if (i == 1)
            square[current_row][current_column] = i;
        else {
            if (square[((current_row -1) + n)% n][((current_column+1)+n)%n] == 0){
                current_row = ((current_row -1) + n)% n;
                current_column = ((current_column+1)+n)%n;
            }
            else {
                current_row = ((current_row +1) + n)% n;
                current_column = current_column;
            }
            printf("val: %d row: %d, column: %d\n", i, current_row, current_column);
            square[current_row][current_column] = i;
        }
    }
    for (int i = 0; i< n; i++) {
        for (int j = 0; j<n; j++) {
            printf("%5d", square[i][j]);
        }
        printf("\n");
    }
    return 0;
}
