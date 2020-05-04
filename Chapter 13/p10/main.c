#include <stdio.h>
#include <stdlib.h>

#define STR_LENGTH 100

int read_line(char str[], int n);
void reverse_name(char *name);

int main()
{
    printf("Enter a first and last name: ");
    char str[STR_LENGTH+1];
    read_line(str, STR_LENGTH+1);
    reverse_name(str);
    printf("Name after modified: %s", str);
    return 0;
}

void reverse_name(char *name) {
    char *ptr = name;
    char *pointer_to_name = name;
    while (*ptr == ' ')
        ptr++;

    char fname = *ptr; // First initial of first name
    while (*ptr != ' ')
        ptr++;

    while (*ptr == ' ')
        ptr++;

    while ((*ptr != ' ') && (*ptr != '\0')) {
        *pointer_to_name = *ptr;
        ptr++;
        pointer_to_name++;
    }
    *pointer_to_name++ = ',';
    *pointer_to_name++ = ' ';
    *pointer_to_name++ = fname;
    *pointer_to_name++ ='.';
    *pointer_to_name='\0';

}

int read_line(char str[], int n) {
    char ch;
    int i=0;
    while((ch=getchar())!='\n')
        if (i<n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
