#include <stdio.h>
#include <cs50.h>

void draw(int n, int level);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}


void draw(int n, int level)
{
    if (n == level)
    {
        printf("*");
    }
}