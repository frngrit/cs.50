#include <stdio.h>
#include <cs50.h>
#include <string.h>

int string_to_int(string input);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./greedy [number]\n");
        return 1;
    }

    string input = argv[1];

}



int string_to_int(string input)
{
    for(int i = 0, n = strlen(input); i < n; i++)
    {
        
    }
}