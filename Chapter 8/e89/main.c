#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temperature_readings[30][24] = {0};
    for (int i = 0; i< 30; i++) {
        for (int j = 0; j< 24; j++){
            temperature_readings[i][j] = i+j;
        }
    }
    for (int i = 0; i< 30; i++) {
        for (int j = 0; j< 24; j++){
            printf("%d ", temperature_readings[i][j]);
        }
        printf("\n");
    }
    float sum_of_days = 0;
    for (int i = 0; i<30; i++){
        int sum_of_hours = 0;
        for (int j = 0; j < 24; j++){
            sum_of_hours += temperature_readings[i][j];
        }
        sum_of_days += (float) sum_of_hours / 24;
    }
    printf("Average temperature: %.2f", sum_of_days / 30);
    return 0;
}
