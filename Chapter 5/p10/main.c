#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter numerical grade: ");
    int grade;
    scanf("%d", &grade);
    if (grade > 100 || grade < 0) {
        printf("Grade out of range.\n");
        return 0;
    }
    int t;
    t = grade/10;
    switch(t) {
        case 10: case 9: printf("Letter grade: A\n"); break;
        case 8: printf("Letter grade: B\n"); break;
        case 7: printf("Letter grade: C\n"); break;
        case 6: printf("Letter grade: D\n"); break;
        default: printf("Letter grade: F"); break;
    }
    return 0;
}
