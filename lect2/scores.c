#include <stdio.h>

int main(void)
{
    /*
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;
    */

   //use array instead
   int scores[3];

   scores[0] = 72;
   scores[1] = 73;
   scores[2] = 33;


    printf("average score is %f\n",(scores[0] + scores[1] + scores[2])/3.0);
}