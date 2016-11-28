#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
                        
int main(int argc, string argv[])
{
    string key;
    
      if(argc != 2)
        {
            printf("oops :( \n");
            return 1;
        }
        else
        {
            key = argv[1];
        }
        
        for (int i = 0, n = strlen(key); i < n; i++)
        
        if (!isalpha(key[i]))
            { 
           
               printf("Alphabet only, sir!\n");
                return 1;
            } 
            
            
    printf("plaintext: ");
    string s = get_string();
    printf("ciphertext: ");
     for (int i = 0, j = 0, n = strlen(s); i < n; i++, j++)
        {
            if (j > strlen(key) - 1)
            {
                j = 0;
            }
                int formula = 0;
               
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    formula = (((s[i] - 'A') + (tolower(key[j]) - 'a'))%26) + 'A';
                    printf("%c", (char)formula);
                }
                else if (s[i] >= 'a' && s[i] <= 'z')
                {
                    formula = (((s[i] - 'a') + (tolower(key[j]) - 'a'))%26) + 'a';
                    printf("%c", (char)formula);
                }
                else
                {
                    printf("%c", s[i]);
                    j--;
                }
            }                             
    printf("\n");
    return 0;  
}