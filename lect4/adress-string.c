#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "Hi!";
    string *p = &s;

    printf("%s\n", s);


    for (int i = 0; s[i] != '\0'; i++)
    {
        char *c = &s[i];
        printf("char: %c, address: %p\n",s[i], c);
    }

    // printf("%p\n", p);
}