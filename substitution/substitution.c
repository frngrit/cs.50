#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        //hadle when user input incorrectly
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        //handle when user input string length not 26 chars
        printf("Key must contain 26 characters.\n");
        return 2;
    }

    s = get_string("plaintext:  "); //prompt user for plain text

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        
    }


}