#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int *x = malloc(3 * sizeof(int)); //return an array of three ints or address of first array of three ints
    printf("%i\n", x[0]); //output is zero (such a fasinating!! ><)
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
    for (i = 0; i < 3; i++)
    {
        printf("\n");
    }
}