#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"
#define HASHTABLE 50
static unsigned int count = 0;
int hash(const char* word);


typedef struct node
{
    char *word;
    struct node* next;
} node;



char word[LENGTH + 1];
node *hashtable[HASHTABLE];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    
    node* checker = malloc(sizeof(node));
    int bucket = hash(word);
    checker = hashtable[bucket];

    while (checker != NULL)
    {
        if (strcasecmp(checker->word, word) == 0)
        {
            return true;
        }    
        checker = checker->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    FILE* dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL)
        return false;

    while (fscanf(dictionary_file, "%s\n", word) != EOF)
    {
        
        node *new = malloc(sizeof(node));
        new->word = malloc(strlen(word) + 1);
        strcpy(new->word, word);
        int hashed = hash(word);

        if (hashtable[hashed] == NULL)
        {
            hashtable[hashed] = new;
            new->next = NULL;
        }

        else
        {
            new->next = hashtable[hashed];
            hashtable[hashed] = new;
        }
        count++;
    }
    fclose(dictionary_file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    int countResult = count;
    if (countResult != 0){
        return countResult;
    }
    return 0;
}


bool unload(void)
{
    // TODO

    for (int i = 0; i < HASHTABLE; i++)
    {
       
        node *cursor;
        cursor = hashtable[i];

        while (cursor)
        {
            node* tmp = cursor;
            cursor = cursor->next;
            free(tmp);
            return true;
        }
        hashtable[i] = NULL;
    }
    return false;
}

int hash(const char* word)
{
    int index = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index += tolower(word[i]);
    }
    return index % HASHTABLE;
}