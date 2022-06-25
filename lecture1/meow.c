#include <stdio.h>

//declare meow first
void meow(int n);



int main(void)
{
    const int LIMIT = 3;
    int i = 0;

    while (i < LIMIT)
    {
        meow();
        i += 1;
    }

    /*
    for (int j = i; i > 0; i--)
    {
        printf("meow!!\n");
    }
    */
}


//If you define your function after execute it, there will be error
void meow(void)
{
    printf("meow~\n");
}