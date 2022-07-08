#include <stdio.h>

int main(void)
{
    int candidate_count = 4;
    int round = (candidate_count - 1) * candidate_count / 2;
    //printf("%i\n", round);
    int count = 1;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            printf("count: %i\n%i and %i\n", count, i, j);
            count++;
        }
    }

}
