#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


int main(void)
{
    char *s = get_string("s: ");
    char *t = s; //it's like you assign pointer to be address of address that stored in s

    t[0] = toupper(t[0]);

    printf("s: %s @%p\n", s, s);
    printf("t: %s @%p\n", t, t);

}