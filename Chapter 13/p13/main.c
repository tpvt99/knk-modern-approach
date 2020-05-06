#include <stdio.h>
#include <stdlib.h>

void encrypt(char *message, int shift);
int read_line(char [], int);

int main()
{
    printf("Enter the message: ");
    char str[200];
    read_line(str, 200);
    printf("Enter shift amount (1-25): ");
    int n;
    scanf("%d", &n);
    encrypt(str, n);
    printf("Encrypted message: %s", str);
    return 0;
}

void encrypt(char *message, int shift) {
    while(*message) {
        if (*message >= 'a' && *message <= 'z')
            *message = (((*message-'a') + shift) % 26) + 'a';
        else if (*message >= 'A' && *message <= 'Z')
            *message = (((*message-'A') + shift) % 26) + 'A';
        message++;
    }
}

int read_line(char str[], int n) {
    int i = 0;
    char ch;
    while((ch=getchar())!='\n') {
        if (i<n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
