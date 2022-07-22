#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>


int main(void)
{
    char *s = get_string("s: ");
    printf("\n");

    // char *t = s; //it's like you assign pointer to be address of address that stored in s

    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    {
        // t[i] = s[i];
        t[i] = *(s+i);
    }
    //or use this ------> strcpy(t, s);

    t[0] = toupper(t[0]);

    printf("s: %s @%p\n", s, s);
    printf("t: %s @%p\n", t, t);

    free(t);
}