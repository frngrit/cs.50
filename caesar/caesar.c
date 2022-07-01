#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    long key = 0;
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Input must be non-negative integer\n");
            return 1;
        }
        int str_to_number = (int) argv[1][i] - 48;
        key += str_to_number * pow(10,n-i-1);
    }
    //printf("%li", key);
    string plain = get_string("plaintext:  ");

    printf("ciphertext: ");
    int i = 0;
    char c;
    while (plain[i] != '\0')
    {
        c = plain[i];
        c = (c + key) % 26;
        if (isupper(c))
        {
            c = c + 65;
        }
        else
        {
            c = c + 97;
        }
        printf("%c", c);
        i++;
    }
    printf("\n");
}