#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter first date (mm/dd/yy): ");
    int m1, d1, y1;
    scanf("%d/%d/%d", &m1, &d1, &y1);
    printf("Enter second date (mm/dd/yy): ");
    int m2, d2, y2;
    scanf("%d/%d/%d", &m2, &d2, &y2);
    int earlier = 0;
    if (y1 < y2) {
        earlier = 1;
    }
    else if (y2 < y1) {
        earlier = 2;
    } else {
        if (m1 < m2) {
            earlier = 1;
        }
        else if (m2 < m1) {
            earlier = 2;
        } else {
            if (d1 < d2) {
                earlier = 1;
            }
            else if (d2 < d1) {
                earlier = 2;
            } else {
                earlier = 0;
            }
        }
    }
    if (earlier == 1)
        printf("%d/%d/%d is earlier than %d/%d/%d", m1,d1,y1, m2,d2,y2);
    else if (earlier == 2)
        printf("%d/%d/%d is earlier than %d/%d/%d", m2,d2,y2, m1,d1,y1);
    else
        printf("Two dates are equal");

    return 0;
}
