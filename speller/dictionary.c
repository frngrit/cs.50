// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dictionary = fopen(dictionary, "r"); //open dictionary file

    if (dictionary == NULL) //check if file exist
    {
        return false;
    }

    char temp[];
    while (fread(temp, sizeof(char), 1, dictionary))
    {
        if (temp == '\n') //when start new word check where to go
        {
            unsigned int pos = hash(temp);
        }


    }


    return true;

}


void add_element(node *bucket, char *word)
{
    node *new = malloc(sizeof(node));
    new->word = word;
    new->next = NULL;

    if (bucket->next == NULL)
    {
        bucket->next = new;
        return;
    }
    add_element(bucket->next, word);

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
