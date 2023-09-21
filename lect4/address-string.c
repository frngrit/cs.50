#include <stdio.h>
// #include <cs50.h>

int main(void)
{
    // string s = "Hi!";

    // char *s = "Hi!";
    char s[] = {'H', 'i', '!'};

    char *addressOfArray = s;
    char *addressOfFirstEle = &s[0];

    printf("addressOfArray = %p\naddressOfFirstEle = %p\n", addressOfArray, addressOfFirstEle);

    for (int i = 0; s[i] != '\0'; i++)
    {
        char *b = &s[i];
        printf("from %s -> char: %c, address: %p\n", s, s[i], b);
    }

    // printf("%p\n", p);
}