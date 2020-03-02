#include <stdio.h>
#define VOLUME_FRACTION 4.f / 3.f
#define PI 3.14f

int main()
{
    int r;
    printf("Enter the radius of the sphere: ");
    scanf("%d", &r);
    printf("Volume of sphere: %.2f\n", VOLUME_FRACTION * PI * r * r *r);
    return 0;
}
