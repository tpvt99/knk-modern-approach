#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool test_extension(const char *file_name, const char *extension) {
    const char *f = file_name;
    const char *e;
    int extension_length = strlen(extension);
    bool has_extension = false;
    while (*f) {
        if ((strlen(f) >= extension_length) && (toupper(*f) == toupper(*extension))) {
            for(e = extension+1; *e; e++)
                if (toupper(*e) != toupper(*(f+(e-extension))))
                    break;
            if (!(*e))
                has_extension = true;
        }
        f++;
    }
    return has_extension;
}

int main()
{
    printf("%d", test_extension("memo.tat", "TaT"));
    return 0;
}
