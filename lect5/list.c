#include <stdio.h>

int main(void)
{
    int *list = malloc(sizeof(int) * 3);

    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //Time passes
    list = malloc(4 * sizeof(int));
    list[3] = 4;
}