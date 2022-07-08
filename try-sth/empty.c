#include <stdio.h>

int main(void)
{
    int candidate_count = 4;
    int pref[candidate_count];
    int round = (candidate_count - 1) / 2 * candidate_count;
    for (int i = 0; i < round; i++)
    {
        printf("at %i\n", i);
    }
}
