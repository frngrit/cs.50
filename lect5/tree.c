#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

void free_tree(node *root);
void print_tree(node *root);

int main(void)
{
    // initialize tree
    node *tree = NULL;

    // add the number to tree (first number)
    node *n = malloc(sizeof(node));

    //check if n is allocated memory
    if (n == NULL)
    {
        return 1;
    }

    n->number = 4;
    n->left = NULL;
    n->right = NULL;
    //point tree to n
    tree = n;

    //Add second number to the three
    n = malloc(sizeof(node));

    //check if n is allocated memory
    if (n == NULL)
    {
        free(tree);
        return 1;
    }

    n->number = 4;
    n->left = NULL;
    n->right = NULL;


}