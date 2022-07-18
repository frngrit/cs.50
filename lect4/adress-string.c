#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "Hi!";
    string *p = &s;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char *b = &s[i];
        printf("char: %c, address: %p\n",s[i], b);
    }

    // printf("%p\n", p);
}