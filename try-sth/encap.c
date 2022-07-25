#include <stdio.h>

typedef struct
{
    int x;
    int y;
}
corres;

int main(void)
{
    corres array[6];

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 2; j++)
        {
            array[i].x = i;
            array[i].y = j;
        }
    }
}