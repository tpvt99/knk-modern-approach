#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no_shares;
    float commission, commission_rival, price, value;
    printf("Enter the number of shares: ");
    scanf("%d", &no_shares);
    printf("Enter the price per share: ");
    scanf("%f", &price);
    value = no_shares * price;

    if (value < 2500.0f)
        commission = 30.0f + .017f * value;
    else if (value < 6250.0f)
        commission = 56.0f + .0066f * value;
    else if (value < 20000.0f)
        commission = 76.0f + 0.0034f * value;
    else if (value < 50000.0f)
        commission = 100.0f + .0022f * value;
    else if (value < 500000.0f)
        commission = 155.0f + .0011f * value;
    else
        commission = 255.0f + .0009f * value;

    if (commission < 39.0f)
        commission = 39.0f;

    if (value < 2000.0f)
        commission_rival = 33.0f + .03 * no_shares;
    else
        commission_rival = 33.0f + .02 * no_shares;

    printf("Commission: $%.2f\n", commission);
    printf("Commission Rival: $%.2f\n", commission_rival);


    return 0;
}
