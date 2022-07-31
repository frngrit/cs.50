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

    if (n == NULL) //malloc able to allocate memory
    {
        printf("Not enough memory\n");
        return 1;
    }

    // (*n).number = 1;
    // (*n).next = NULL;
    // too cryptic do the following instead

    n -> number = 1;
    n -> next = NULL;

    list = n;

    //add number to list
    n = malloc(sizeof(node));

    if (n == NULL)
    {
        printf("Not enough memory\n");
        free(list);
        return 1;
    }

    n -> number = 2;
    n -> next = NULL;
    list -> next = n;

    //add new number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list -> next); //free second node
        free(list); //free first node
        
        return 1;
    }
    n -> number = 3;
    n -> next = NULL;
    list -> next -> next = n;

}