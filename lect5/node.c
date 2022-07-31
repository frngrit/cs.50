#include <stdio.h>

typedef struct node //<-- node is telling the complier
{
    int number;
    struct node *next;
}
node;