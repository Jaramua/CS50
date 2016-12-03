#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hash(const char *word);

char word[LENGTH +1] ;
int count = 0;

<<<<<<< HEAD
// define node structure
=======
>>>>>>> origin/master
typedef struct node 
{
    char *word;
    struct node *next;
}   node;
<<<<<<< HEAD
#define HASHTABLE_SIZE 50
node *hashtable[HASHTABLE_SIZE];
=======
#define HASHTABLE 50
node *hashtable[HASHTABLE];
>>>>>>> origin/master

/*
 * Returns true if word is in dictionary else false.
 */

bool check(const char *word)
{
<<<<<<< HEAD
  
    node *checker;
	
	// detecting in which bucket the word is 	    
=======
    char temp_word[LENGTH +1] = {};
     node *checker;

    int len = strlen(word);

    for(int i = 0; i < len; i++) 
    {
        temp_word[i] = tolower(word[i]);
    }

    temp_word[len] = '\0';
		    
>>>>>>> origin/master
    int bucket = hash(word);
    checker = hashtable[bucket];
    if (!checker )
    {
        return false;
    }    

    while( checker )
    {
<<<<<<< HEAD
        // searching in that linked list comparing strings  
        if (strcasecmp(checker->word, word) == 0)
=======
        if (!strcmp(word,temp_word))
>>>>>>> origin/master
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
<<<<<<< HEAD

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



=======

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

>>>>>>> origin/master
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

/*
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

bool unload(void)
{
<<<<<<< HEAD

  node *nextcursor,*cursor;
  // free nodes for each bucket
  for (int i = 0; i<HASHTABLE_SIZE; i++)
=======
  node *nextcursor,*cursor;
  for (int i = 0; i<HASHTABLE; i++)
>>>>>>> origin/master
  {
      cursor = hashtable[i];
      while (cursor) 
      {
<<<<<<< HEAD
	        free(cursor->word);
    	    nextcursor  = cursor->next;
    	    free(cursor);
	        cursor = nextcursor;
=======
	    free(cursor->word);
    	    nextcursor  = cursor->next;
    	    free(cursor);
	    cursor = nextcursor;
>>>>>>> origin/master
      }
       
    hashtable[i] = NULL;
  }
  return true;
}


int hash(const char *word) 
{
<<<<<<< HEAD
    // the hash function indicates to which bucket the word belongs to
=======
    int len = strlen(word);
>>>>>>> origin/master
    int index = 0;

    for(int i = 0; i < len; i++) 
    {
<<<<<<< HEAD
        index += tolower(word[i]);
    }    
    return index % HASHTABLE_SIZE;
}
=======
          index += word[i];
    }
    return index % HASHTABLE;
}
>>>>>>> origin/master
