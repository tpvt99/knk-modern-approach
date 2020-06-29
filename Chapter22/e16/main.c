#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[] = "love 123 #123";
    char s2[] = "x#24,675 just youandme";
    char s3[] = "babe#24,675,154just youandme";
    char s4[] = "babe#a24,675,154just youandme";

    char code_s1[100], code_s2[100], code_s3[100], code_s4[100];
    int c;

    char pattern[] = "%*[^#] %*[#] %[,0123456789]";


    c = sscanf(s1, pattern , code_s1);
    printf("Reading code: %d\n", c);
    if (c == 1)
        printf("Successfully read s1 with code: %s\n", code_s1);
    else
        printf("Unsuccessfully read s1 \n");

    c = sscanf(s2, pattern, code_s2);
    printf("Reading code: %d\n", c);
    if (c == 1)
        printf("Successfully read s2 with code: %s\n", code_s2);
    else
        printf("Unsuccessfully read s2 \n");

    c = sscanf(s3, pattern, code_s3);
    printf("Reading code: %d\n", c);
    if (c == 1)
        printf("Successfully read s3 with code: %s\n", code_s3);
    else
        printf("Unsuccessfully read s3 \n");

    c = sscanf(s4, pattern, code_s4);
    printf("Reading code: %d\n", c);
    if (c == 1)
        printf("Successfully read s4 with code: %s\n", code_s4);
    else
        printf("Unsuccessfully read s4 \n");

    return 0;
}
