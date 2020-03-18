#include <stdio.h>
#include <stdlib.h>

int main()
{
    int soon_m, soon_d, soon_y;
    int earlier;
    printf("Enter a date (mm/dd/yy): ");
    int m, d, y;
    scanf("%d/%d/%d", &m, &d, &y);
    soon_m = m; soon_d = d; soon_y = y;
    while ((m !=0) && (d!=0) && (y!=0)) {
        earlier = 0;
        if (y < soon_y) {
            earlier = 1;
        } else if (y == soon_y) {
            if (m < soon_m) {
                earlier = 1;
            } else if (m == soon_m) {
                if (d < soon_d) {
                    earlier = 1;
                } else {
                    earlier = 0;
                }
            }
        }
        if (earlier == 1) {
            soon_y = y;
            soon_m = m;
            soon_d = d;
        }
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &m, &d, &y);
    }
    printf("%d/%d/%d is the earliest date\n", soon_m, soon_d, soon_y);


    return 0;
}
