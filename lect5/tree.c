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

    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    //point tree to n
    tree = n;

    //Add second number to the three
    n = malloc(sizeof(node));

    //check if n is allocated memory
    if (n == NULL)
    {
        //free(tree);
        return 1;
    }

    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    //point the parent left to the children
    tree->left = n;

    //Add second number to the three
    n = malloc(sizeof(node));

    //check if n is allocated memory
    if (n == NULL)
    {
        //free(tree);
        return 1;
    }

    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    //point the parent left to the children
    tree->right = n;

    print_tree(tree);

}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    //show left
    print_tree(root->left);
    //print parent
    printf("%i\n", root->number);
    //show right
    print_tree(root->right);
}