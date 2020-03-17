#include <stdio.h>
#include <stdlib.h>

int main()
{
    int days, start;
    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start);
    for (int t = 1; t < start; t++) {
        printf("   ");
    }
    for (int i =1; i<= days; i++) {
        printf("%3d", i);
        if ((i + start -1) % 7==0)
            printf("\n");
    }
    return 0;
}
