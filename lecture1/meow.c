#include <stdio.h>

void meow(void)
{
    printf("meow\n");
}


int main(void)
{
    const int LIMIT = 3;
    int i = 0;

    while (i < LIMIT)
    {
        meow();
        i += 1;
    }


    for (int j = i; i > 0; i--)
    {
        printf("meow!!\n");
    }
}