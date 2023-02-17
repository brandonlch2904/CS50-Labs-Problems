// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

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

// Word count variable
int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Use hash function
    int hashIndex = hash(word);

    // Create a pointer variable
    node *ptr = table[hashIndex];

    // Loop until end of list
    while (ptr != NULL)
    {
        // Check if word is same
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
        else
        {
            ptr = ptr->next;
        }
    }

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
    // Open dictionary file
    FILE *dictfile = fopen(dictionary, "r");

    // Check if return value is NULL
    if (dictfile == NULL)
    {
        return false;
    }

    // Read strings from file
    char word[LENGTH + 1];
    while (fscanf(dictfile, "%s", word) != EOF)
    {
        // Create a new node
        node *n = malloc(sizeof(node));

        // Check if value is NULL
        if (n == NULL)
        {
            return false;
        }

        // Copy word into node using strcpy
        strcpy(n->word, word);

        // Use hash function
        int hashIndex = hash(word);

        // Check whether head is pointing to NULL
        if (table[hashIndex] == NULL)
        {
            // If yes, n points to NULL
            n->next = NULL;
        }
        else
        {
            // Otherwise points n to the first node of the linked list
            n->next = table[hashIndex];
        }

        // Point header to n
        table[hashIndex] = n;

        count += 1;
    }
    // Close file
    fclose(dictfile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Free each node in the list
void freeList(node *n)
{
    //Recursively calling freeList until points NULL
    if (n->next != NULL)
    {
        freeList(n->next);
    }
    free(n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Loop through the hash table
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            freeList(table[i]);
        }
    }
    return true;
}
