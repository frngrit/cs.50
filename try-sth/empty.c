#include <stdio.h>

int main(void)
{
    int candidate_count = 4;
    int round = (candidate_count - 1) * candidate_count / 2;
    printf("%i\n", round);
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%i and %i\n", i,j);
            count++;
        }
    }

}
