// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 20063;
unsigned int TOTAL = 0;

// Hash table
node *table[N];

bool free_node(node *node);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int word_hash = hash(word);
    node *tmp = table[word_hash];
    while (tmp != NULL)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    free(tmp);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hashval = 0;
    unsigned int len = 0;

    for (hashval = 0; *word != '\0'; word++)
    {
        hashval += tolower(*word);
        len++;
    }

    return hashval * len % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    char buffer[LENGTH + 1];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        //printf("%s", buffer);
        unsigned int word_hash = hash(buffer);
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        strcpy(new_node->word, buffer);

        new_node->next = table[word_hash];
        table[word_hash] = new_node;
        TOTAL += 1;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return TOTAL;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            if (!free_node(table[i]))
            {
                return false;
            }
        }
    }

    return true;
}

bool free_node(node *node)
{
    if (node->next == NULL)
    {
        free(node);
        return true;
    }

    free_node(node->next);

    free(node);

    return true;

}
