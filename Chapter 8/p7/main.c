#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5][5];
    int row_sums[5] = {0};
    int column_sums[5] = {0};

    for (int i = 0; i <= 4; i++) {
        printf("Enter row %d: ", i+1);
        for (int j = 0; j<=4; j++) {
            scanf("%d", &a[i][j]);
            row_sums[i] += a[i][j];
            column_sums[j] += a[i][j];
        }
    }

    printf("Row totals: ");
    for (int i = 0; i <= 4; i++) {
        printf("%d ", row_sums[i]);
    }

    printf("\nColumn totals: ");
    for (int i = 0; i <= 4; i++) {
        printf("%d ", column_sums[i]);
    }

    return 0;
}
