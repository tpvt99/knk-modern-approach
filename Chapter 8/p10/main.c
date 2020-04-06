#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter a 24-hour time: ");
    int h,m;
    scanf("%d: %d", &h, &m);
    int depart[8] = {8*60, 9*60+ 43, 11*60+19,12*60+47,14*60,3*60+45,19*60,21*60+45};
    int x = h * 60 + m;
    int closest = 0;
    for (int i = 0; i < 7; i++) {
        if (x <= depart[0]) {
            closest = 0;
            break;
        } else if (x >= depart[7]) {
            closest = 7;
            break;
        }
        if ((depart[i] <= x ) && (x <= depart[i+1])) {
            if ((x - depart[i]) <= (depart[i+1]-x))
                closest = i;
            else
                closest = i+1;
            break;
        }
    }
    switch (closest) {
        case 0: printf("Closest departure time is 8:00 a.m, arriving at 10:16 a.m\n");break;
        case 1: printf("Closest departure time is 9:43 a.m, arriving at 11:52 a.m\n");break;
        case 2: printf("Closest departure time is 11:19 a.m, arriving at 1:31 p.m\n");break;
        case 3: printf("Closest departure time is 12:47 p.m, arriving at 3:00 p.m\n");break;
        case 4: printf("Closest departure time is 2:00 pm, arriving at 4:08 p.m\n");break;
        case 5: printf("Closest departure time is 3:45 p.m, arriving at 5:55 p.m\n");break;
        case 6: printf("Closest departure time is 7:00 p.m, arriving at 9.20 p.m\n");break;
        case 7: printf("Closest departure time is 9.45 p.m, arriving at 11:58 p.m\n");break;
    }
    return 0;
}
