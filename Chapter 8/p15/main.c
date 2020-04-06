#include <stdio.h>
#include <stdlib.h>
#define N 80
int main()
{
    char sentences[N];
    int n;
    printf("Enter message to be encrypted: ");
    int i = 0;
    for (i = 0; i<N; i++) {
        scanf("%c", &sentences[i]);
        if (sentences[i] == '\n')
            break;
    }
    printf("Enter shift amount (1-25): ");
    scanf("%d", &n);
    printf("Encrypted message: ");
    for (i = 0; i<N; i++) {
        if (sentences[i] != '\n') {
            if (sentences[i] >= 'a' && sentences[i] <= 'z')
                printf("%c", (((sentences[i] - 'a') + n)%26) + 'a');
            else if (sentences[i] >= 'A' && sentences[i] <= 'Z')
                printf("%c", (((sentences[i] - 'A') + n)%26) + 'A');
            else
                printf("%c", sentences[i]);
        } else
            break;
    }
    return 0;
}
