#include <stdio.h>
#include <stdlib.h>

#define N 100

int main()
{
    printf("Enter a sentence: ");
    char sentences[N];
    char ch;

    char *ptr;
    for (ptr = sentences;;) {
        ch = getchar();
        *(ptr++) = ch;
        if (ch == '?' || ch == '.' || ch == '!')
            break;
    }


    getchar(); // Get the new-line character
    char terminate_char = *(--ptr);
    ptr--;
    printf("Reversal of sentence: ");
    char *ptr_en;
    while (ptr >= sentences) {
        ptr_en = ptr; // Mark the ending of each words
        while (*ptr != ' ') { //Loop to find the space before this word
            if (ptr == sentences)
                break;
            ptr--;
        } // Finish the loop, ptr points to the blank space
        char *ptr_print;
        if (ptr == sentences)
            ptr_print = ptr;
        else
            ptr_print = ptr+1;
        for (;ptr_print<=ptr_en;ptr_print++)
            printf("%c", *ptr_print);
        if (ptr!= sentences)
            printf(" ");
        ptr--;
    }
    printf("%c\n", terminate_char);

    return 0;
}
