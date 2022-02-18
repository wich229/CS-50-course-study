// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <ctype.h>
#include <stdio.h>
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

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1)  * 'z';

//words_counter
int words_counter = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash word to obtain a hash value
    // Access linked list at that index in the hash table
    // Traverse linked list, looking for the word with strcasecmp function (strcasecmp compares two string case insensitive, it is declared in strings.h)
    // Create a new node *cursor and set it to the first element in the linked list
    // Then Check until Cursor is not NULL(if the cursor is not pointing to anything)
    int index = hash(word); 
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //143000 words in dicitionary
    //Maximum length for a word is 45
    int key = 0;
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        key += tolower(word[i]);
    }
    
    int hash_value = key % N;
    
    return hash_value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Opening a dictionary file
    FILE *dictionary_file;
    dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    
    // Reading Strings from file one at a time
    char dictionary_word[LENGTH + 1];
    while (fscanf(dictionary_file, "%s", dictionary_word) != EOF)
    {
        // Allocate memory for a node, n
        // Creating a node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // strcpy(destination, source);
        strcpy(n -> word, dictionary_word);
        n -> next = NULL;
        // Hashing word to Obtain a hash value
        // int index = hash(dictionary_word);
        int index = hash(n -> word);
        // Insert node into the hash table at that location
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else //table[index] != NULL
        {
            node *head = table[index];
            n->next = table[index];
            head = n;
        }
        words_counter ++;
    }
    fclose(dictionary_file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0 ; i < N ; i++)
    {
        node *head = table[i];
        node *cursor = table[i];
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(head);
            head = cursor;
        }
    }

    return true;
}
