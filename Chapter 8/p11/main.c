#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter phone number: ");
    int i;
    char original_forms[15];
    char numeric_forms[15];
    for(int i = 0; i < 15; i++) {
        scanf("%c", &original_forms[i]);
        if (original_forms[i] == '\n')
            break;
    }
    for (i = 0; i < 15; i++) {
        if (original_forms[i] != '\n') {
            switch (original_forms[i]) {
                case 'A': case 'B': case 'C': numeric_forms[i] = '2';break;
                case 'D': case 'E': case 'F': numeric_forms[i] = '3';break;
                case 'G': case 'H': case 'I': numeric_forms[i] = '4';break;
                case 'J': case 'K': case 'L': numeric_forms[i] = '5';break;
                case 'M': case 'N': case 'O': numeric_forms[i] = '6';break;
                case 'P': case 'R': case 'S': numeric_forms[i] = '7';break;
                case 'T': case 'U': case 'V': numeric_forms[i] = '8';break;
                case 'W': case 'X': case 'Y': numeric_forms[i] = '9';break;
                default: numeric_forms[i] = original_forms[i];break;
            }
        } else
            numeric_forms[i] = '\n';
    }
    for (i = 0; i< 15; i++) {
        if (numeric_forms[i] != '\n')
            printf("%c", numeric_forms[i]);
    }

    return 0;
}
