#include <stdio.h>

meow(void)


int main(void)
{
    const int LIMIT = 3;
    int i = 0;

    while (i < LIMIT)
    {
        printf("meow~\n");
        i += 1;
    }


    for (int j = i; i > 0; i--)
    {
        printf("meow!!\n");
    }
}