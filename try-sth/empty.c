#include <stdio.h>

int main(void)
{
    int candidate_count = 4;
    int round = (candidate_count - 1) * candidate_count / 2;
    printf("%i\n", round);
    for (int i = 0; i < round; i++)
    {
        printf("at %i\n", i);
    }
}
