#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hash(const char *word);

char word[LENGTH +1] ;
int count = 0;

typedef struct node 
{
    char *word;
    struct node *next;
}   node;
#define HASHTABLE 50
node *hashtable[HASHTABLE];

/*
 * Returns true if word is in dictionary else false.
 */

bool check(const char *word)
{
    char temp_word[LENGTH +1] = {};
     node *checker;

    int len = strlen(word);

    for(int i = 0; i < len; i++) 
    {
        temp_word[i] = tolower(word[i]);
    }

    temp_word[len] = '\0';
		    
    int bucket = hash(word);
    checker = hashtable[bucket];
    if (!checker )
    {
        return false;
    }    

    while( checker )
    {
        if (!strcmp(word,temp_word))
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
  
    for (int i = 0; i<HASHTABLE; i++)
    {
         hashtable[i] = NULL;
    }

    if (!(dictionary_file = fopen(dictionary, "r"))) 
    {
        return false;
    }
 
  while (fscanf(dictionary_file,"%s\n",word) != EOF)
  {
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
    { 
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
  for (int i = 0; i<HASHTABLE; i++)
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
    int len = strlen(word);
    int index = 0;

    for(int i = 0; i < len; i++) 
    {
          index += word[i];
    }
    return index % HASHTABLE;
}
