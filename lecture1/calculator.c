#include <cs50.h>
#include <stdio.h>

int main(void){

    //Prompt user for x
    int x = get_int("x: ");
    //Prompt user for y
    int y = get_int("y: ");
    // Perform addition
    printf("x+y = %i\n",x+y);
}