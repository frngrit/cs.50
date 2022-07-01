#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before:  ");
    printf("Output: ");

    int b;
    for (int i = 0; s[i] != '\0'; i++)
    {
        b = (int) s[i];
        if (b > 96)
        {
            b -= 32;
        }
        printf("%c",(char) b);
    }
    printf("\n");
}