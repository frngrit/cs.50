#include <stdio.h>
// #include <cs50.h>

int main(void)
{
    // string s = "Hi!";

    // char *s = "Hi!";
    char s[] = {'H', 'i', '!'};

    for (int i = 0; s[i] != '\0'; i++)
    {
        char *b = &s[i];
        printf("from %s -> char: %c, address: %p\n", s, s[i], b);
    }

    // printf("%p\n", p);
}