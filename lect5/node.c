#include <stdio.h>

typedef struct node //<-- node is telling the complier
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    node *list = NULL;
    node *n = malloc(sizeof(node));

    if (n != NULL) //malloc able to allocate memory
    {
        // (*n).number = 1;
        // (*n).next = NULL;
        // too cryptic do the following instead

        n -> number = 1;
        n -> next = NULL;
    }
    list = n;
    
}