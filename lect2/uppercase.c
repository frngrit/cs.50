#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("Output: ");

    // int b;
    // for (int i = 0; s[i] != '\0'; i++)
    // {
    //     b = (int) s[i];
    //     if (b > 96 && b < 123)
    //     {
    //         b -= 32;
    //     }
    //     printf("%c",(char) b);
    // }
    // printf("\n");

    for (int i =0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");

}