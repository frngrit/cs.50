#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (argv[1] < 0)
    {
        printf("Input must be non-negative integer\n");
        return 1;
    }
    
}