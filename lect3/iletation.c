#include <stdio.h>
#include <cs50.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}


void draw(int n)
{
    printf("%i\n", n);
   if (n == 1)
   {
    printf("end\n");
   }
   else
   {
    draw(n-1);
   }
}