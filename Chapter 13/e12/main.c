#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_extension(const char *file_name, char *extension);

int main()
{
    char c[20] ="br1_file.txt";
    char extension[20];
    get_extension(c, extension);
    printf("Extension: %s", extension);
    return 0;
}

void get_extension(const char *file_name, char *extension) {
    const char *ptr = file_name;
    while ((*(ptr) != '.') && (*(ptr) != '\0')) {
        ptr++;
    }
    if (*ptr == '.')
        ptr++;

    strcpy(extension, ptr);
}
