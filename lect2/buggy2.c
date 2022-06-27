#include <cs50.h>
#include <stdio.h>

int get_negative_int(void);

int main(void)
{
    int i = get_negative_int();
    printf("number is %i\n",i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Input negative number: ");
    }
    while (n < 0); //Bug is in this line
    return n;
}