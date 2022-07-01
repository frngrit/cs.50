#include <cs50.h>
#include <stdio.h>
#include <string.h>

string encrypt(char c, string key);

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

    string s = get_string("plaintext:  "); //prompt user for plain text

    // char c;
    // for (int i = 0, n = strlen(s); i < n; i++)
    // {
    //     //encrypt each character
    //     c = encrypt(s[i], argv[1]);
    //     //print each charater

    // }


}


string encrypt(char c, string key)
{
    int index;
    if (c >= 'a' && c <= 'z')
    {
        return tolower(key[c - 97]);
    }
    if (c >= 'A' && c <= 'Z')
    {
        return toupper(key[c - 65]);
    }
    return c;

}