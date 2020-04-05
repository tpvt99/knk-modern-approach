#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5][5];
    int score_sum[5] = {0};
    int quiz_sum[5] = {0};
    int quiz_high[5] = {0};
    int quiz_low[5] = {0};

    for (int i = 0; i <= 4; i++) {
        printf("Enter 5 grades of student %d: ", i+1);
        for (int j = 0; j<=4; j++) {
            scanf("%d", &a[i][j]);
            score_sum[i] += a[i][j];
            quiz_sum[j] += a[i][j];
            if (i == 0) { // First student to be initializer for high/low score
                quiz_high[j] = a[i][j];
                quiz_low[j] = a[i][j];
            } else {
                if (a[i][j] >= quiz_high[j])
                    quiz_high[j] = a[i][j];
                if (a[i][j] <= quiz_low[j])
                    quiz_low[j] = a[i][j];
            }
        }
    }

    for (int i = 0; i <= 4; i++) {
        printf("Student %d, Total Score: %d, Average Score: %.2f\n", i+1, score_sum[i], score_sum[i] / 5.0f);
    }

    for (int i = 0; i <= 4; i++) {
        printf("Quiz %d, Average: %.2f, High: %d, Low: %d\n", i+1, quiz_sum[i]/5.0f, quiz_high[i], quiz_low[i]);
    }

    return 0;
}
