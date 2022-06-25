#include <cs50.h>
#include <stdio.h>

float discount(float reg_price, int sale_pct);


int main(void)
{
    float regular = get_float("Regular price: ");
    int sale_pct = get_int("Percent off: ");
    float discounted = discount(regular,sale_pct);
    //float sale = regular * 0.85;

    printf("Sale Price: %.2f\n",discounted);
}

float discount(float reg_price, int sale_pct)
{
    return reg_price * (1-sale_pct/100);
}