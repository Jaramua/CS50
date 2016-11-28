/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    
    if (n == 0)
    {
        return false;
    } 
    
  
    int mid = n/2;
    
    
    if(values[mid] == value)
    {
            return true;
    }
    
    else if(values[mid] < value)
    {
        return search(value, values + mid + 1, n - mid - 1);
    }
        
    else 
    {
        return search(value, values, mid);
    }
    
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
     for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            if (values[j] > values[j + 1])
            {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
    } 
    return;
}
