// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Number of Words in dictionary
unsigned int Words = 0;

// declaring the hash code for the word
unsigned int HashCode = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    HashCode = hash(word);
    node *cursor = table[HashCode];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hash += tolower(word[i]);
        hash = (tolower(word[i]) * hash) % N;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    FILE *dic = fopen(dictionary, "r");
    unsigned int hashed = 0;
    if (dic != NULL)
    {
        while (fscanf(dic, "%s", word) != EOF)
        {
            node *n = malloc(sizeof(node));

            if (n != NULL)
            {
                hashed = hash(word);
                strcpy(n->word, word);
                n->next = table[hashed];
                table[hashed] = n;
                Words ++;
            }

        }
        fclose(dic);
    }
    else
    {
        return false;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return Words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *cursor;
    node *tmp;
    for (int i = 0; i < N; i++)
    {

        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
