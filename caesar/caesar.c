#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Input must be non-negative integer\n");
            return 1;
        }
    }
    int increment = (long) argv[1] % 26;
    //printf("%li", (long) argv[1]);
    string plain = get_string("plaintext:  ");

    printf("ciphertext: ");
    int i = 0;
    while (plain[i] != '\0')
    {
        printf("%c",plain[i] + increment);
        i++;
    }
    printf("\n");
}