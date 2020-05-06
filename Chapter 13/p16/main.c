#include <stdio.h>
#include <stdlib.h>

int read_line(int, char str[*]);
void reverse(char *message);

int main()
{
    char str[200];
    printf("Enter a message: ");
    read_line(200, str);
    reverse(str);
    printf("Reversed message: %s", str);
    return 0;
}

void reverse(char *message) {
    char *ptr_end = message;
    char *ptr_beg = message;
    char temp;
    while(*(ptr_end++))
        ;
    ptr_end-=2;
    while(ptr_end > ptr_beg) {
        temp = *ptr_end;
        *ptr_end = *ptr_beg;
        *ptr_beg = temp;
        ptr_end--;
        ptr_beg++;
    }

}

int read_line(int n, char str[n]) {
    char ch;
    int i=0;
    while((ch=getchar())!='\n') {
        if (i<n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
