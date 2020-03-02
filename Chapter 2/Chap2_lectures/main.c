#include <stdio.h>

int main(void)
{
    /* Lectures */
    printf("To C, or not to C: ");
    printf("that is the question.\n");

    // Section 2.2
    printf("Parkison's Law:\nWork expands so as to ");
    printf("fill the time\n");
    printf("available for its completion.\n");

    // Section 2.4
    int height = 8, length = 12, width = 10, volume;
    volume = height * length * width;
    printf("Dimensions: %dx%dx%d\n", length, height, width);
    printf("Volume (cubic inched): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", (volume + 165)/ 166);

    printf("I like this"
           "baby");

    return 0;
}
