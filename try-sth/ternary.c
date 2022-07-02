#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    do
    {
        int player1 = get_int("Enter attack damage: ");
        int player2 = get_int("Enter attack damage: ");
    }
    while (isnumeric(player1) && isnumeric(player2))
    string answer = player1 > player 2 ? "Player1 wins\n" : player2 > player1 ? "Player2 wins\n" : "Tie\n";

    printf("%s\n", answer);
}