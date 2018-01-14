#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main (void)
{
    int nCoins = 0;
    float coins [] = {25,10,5,1};

    float money;
    do
    {
        money = get_float("Insert money: ");
    }
    while(money < 0.0);

    int cents = (int)(round(money * 100));

    while (cents > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            if ((cents - coins[i]) >= 0)
            {
                cents -= coins[i];
                nCoins++;
                break;
            }
        }
    }

    printf ("%i\n", nCoins);
}