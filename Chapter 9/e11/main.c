#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float compute_GPA(char [], int );

int main()
{
    printf("GPA is: %.2f", compute_GPA( (char []){'A', 'A', 'B', 'A'}, 4));
    return 0;
}

float compute_GPA(char grade[], int n) {
    int sum = 0;
    for (int i = 0; i< n; i++) {
        if (toupper(grade[i]) == 'A')
            sum += 4;
        else if (toupper(grade[i])=='B')
            sum += 3;
        else if (toupper(grade[i])=='C')
            sum += 2;
        else if (toupper(grade[i])=='D')
            sum += 1;
        else if (toupper(grade[i])=='F')
            sum += 0;
    }
    return sum / (float) n;
}
