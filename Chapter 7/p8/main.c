#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    printf("Enter a 12-hour time: ");
    int h, m;
    scanf("%d: %d", &h, &m);
    char c;
    scanf(" %c", &c);
    c = toupper(c);
    if (c == 'P') {
        if (h != 12)
            h += 12;
    }
    int t1 = 8*60, t2 = 9*60 + 43, t3 = 11*60+19, t4 = 12*60+47,
    t5 = 14*60, t6 = 3*60+45, t7 = 19*60, t8 = 21*60+45;
    int x = h * 60 + m;
    int closest = 0;
    if (x <= t1)
        closest = 1;
    if ( (t1 <= x ) && (x <= t2)) {
        if ((x - t1) <= (t2 - x))
            closest = 1;
        else
            closest = 2;
    }
    else if (t2 <= x && x <= t3) {
        if (x - t2 <= t3 - x)
            closest = 2;
        else
            closest = 3;
    }
    else if (t3 <= x && x <= t4) {
        if (x - t3 <= t4 - x)
            closest = 3;
        else
            closest = 4;
    }
    else if (t4 <= x && x <= t5) {
        if (x - t4 <= t5 - x)
            closest = 4;
        else
            closest = 5;
    }
    else if (t5 <= x && x <= t6) {
        if (x - t5 <= t6 - x)
            closest = 5;
        else
            closest = 6;
    }
    else if (t6 <= x && x <= t7) {
        if (x - t6 <= t7 - x)
            closest = 6;
        else
            closest = 7;
    }
    else if (t7 <= x && x <= t8) {
        if (x - t7 <= t8 - x)
            closest = 7;
        else
            closest = 8;
    }
    else if (x >= t8)
        closest = 8;
    switch (closest) {
        case 1: printf("Closest departure time is 8:00 a.m, arriving at 10:16 a.m\n");break;
        case 2: printf("Closest departure time is 9:43 a.m, arriving at 11:52 a.m\n");break;
        case 3: printf("Closest departure time is 11:19 a.m, arriving at 1:31 p.m\n");break;
        case 4: printf("Closest departure time is 12:47 p.m, arriving at 3:00 p.m\n");break;
        case 5: printf("Closest departure time is 2:00 pm, arriving at 4:08 p.m\n");break;
        case 6: printf("Closest departure time is 3:45 p.m, arriving at 5:55 p.m\n");break;
        case 7: printf("Closest departure time is 7:00 p.m, arriving at 9.20 p.m\n");break;
        case 8: printf("Closest departure time is 9.45 p.m, arriving at 11:58 p.m\n");break;
    }
    return 0;
}
