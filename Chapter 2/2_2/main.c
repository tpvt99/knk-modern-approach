#include <stdio.h>
#define VOLUME_FRACTION 4.f / 3.f
#define PI 3.14f

int main()
{
    int r = 10;
    printf("Volume of sphere: %.2f\n", VOLUME_FRACTION * PI * r * r *r);
    return 0;
}
