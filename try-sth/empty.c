#include <stdio.h>

int main(void)
{
    int pref[3];

    int j;
    for (int i = 0; i < 6; i++)
    {
        j = i % 3;
        pref[j] += 1;
        printf("at %i: %i\n", i, pref[j]);
    }
}
