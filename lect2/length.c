#include <cs50.h>
#include <stdio.h>

int string_length(name);

int main(void)
{
    string name = get_string("Name: ");

    int length = strlen(name);

    printf("%i\n", length);

    // int i = 0;

    // while (name[i] != '\0')
    // {
    //     printf("%c\n",name[i]);
    //     i++;
    // }
    // printf("%c\n",name[i]);
    // printf("%i\n",i);
}

int string_length(name)
{
    int i = 0;

    while (name[i] != '\0')
    {
        printf("%c\n", name[i]);
        i++;
    }
    return i;
}