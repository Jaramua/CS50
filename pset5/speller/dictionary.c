#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

int hash(const char *word);

char word[LENGTH +1] ;
int count = 0;

// define node structure
typedef struct node 
{
    char *word;
    struct node *next;
}   node;
#define HASHTABLE_SIZE 50
node *hashtable[HASHTABLE_SIZE];

/*
 * Returns true if word is in dictionary else false.
 */

bool check(const char *word)
{
  
    node *checker;
	
	// detecting in which bucket the word is 	    
    int bucket = hash(word);
    checker = hashtable[bucket];
    if (!checker )
    {
        return false;
    }    

    while (checker != NULL)
    {
        // searching in that linked list comparing strings  
        if (strcasecmp(checker->word, word) == 0)
        {
            return true;
        }    
        checker = checker->next;
    }
  return false;
}


/*
 * Loads dictionary into memory.  Returns true if successful else false.
 */

bool load(const char *dictionary)
{
    FILE *dictionary_file = NULL;
    int bucket;
    
    // initializing hash table
    for (int i = 0; i<HASHTABLE_SIZE; i++)
    {
         hashtable[i] = NULL;
    }
    
    // opening the dictionnary file for reading 
    if (!(dictionary_file = fopen(dictionary, "r"))) 
    {
        return false;
    }
  
   // iterate through the dictionnary
  while (fscanf(dictionary_file,"%s\n",word) != EOF)
  {
      
    // inserting word into a node
    node *new = malloc(sizeof(node));
    new->word = malloc(strlen(word) +1);
    strcpy(new->word,word);
    
    bucket = hash(word);

    count ++;
    if (hashtable[bucket] == NULL)
    { 
	    hashtable[bucket] = new;
	    new->next = NULL;
    }
    else
    {   // inserting 'new' into the hash table 
	    new->next = hashtable[bucket];
	    hashtable[bucket] = new;
    }
  }

 
  return true;

}



/*
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */

unsigned int size(void)
{
    int countResult = count;
    if (countResult != 0)
    {
        return countResult;
    }
    return 0;    
}


/*
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

bool unload(void)
{

  node *nextcursor,*cursor;
  // free nodes for each bucket
  for (int i = 0; i<HASHTABLE_SIZE; i++)
  {
      cursor = hashtable[i];
      while (cursor) 
      {
	    free(cursor->word);
    	    nextcursor  = cursor->next;
    	    free(cursor);
	    cursor = nextcursor;
      }
       
    hashtable[i] = NULL;
  }
  return true;
}


int hash(const char *word) 
{
    // the hash function indicates to which bucket the word belongs to
    int index = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index += tolower(word[i]);
    }    
    return index % HASHTABLE_SIZE;
}
