#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main(void)
{
    //prompt for user's string
    string s = get_string("Text: ");
    //count for letter
    int i = 0, letters = 0, sentences = 0, words = ;
    while (s[i] != '\0')
    {
        words += 1;
        sentences += 1;
        if (isalpha(s[i])
        {
            letters += 1;
        }
        if (s[i] == ' ')
        {
            words += 1;
        }
        if (
    }
}