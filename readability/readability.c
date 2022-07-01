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
    int i = 0, letters = 0, sentences = 0, words = 0;
    while (s[i] != '\0')
    {
        words += 1;
        if (isalpha(s[i]))
        {
            letters += 1;
        }
        if (s[i] == ' ')
        {
            words += 1;
        }
        if (s[i] == ',' || s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentences += 1;
        }

        float index = 0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8;

        printf("Grade %i\n", (int) round(index));
    }
}