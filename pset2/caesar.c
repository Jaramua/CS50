#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
                        
int main(int argc, string argv[])
{
    int key = 0;
    if(argc != 2)
        {
            printf("oops :( \n");
            return 1;
        }
        else
        {
            key = atoi(argv[1]);
        }
        
    printf("plaintext: ");
    string s = get_string();
    
    printf("ciphertext: ");
    
    for(int i = 0; i < strlen(s); i++)
    {
       if(isalpha(s[i]))
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
             printf("%c", 'A' + (s[i] - 'A' + key) % 26);
            }
             
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
            printf("%c", 'a' + (s[i] - 'a' + key) % 26);
            }
            
        }
        else
        {
        
        printf("%c", s[i]);
        }
    }
    
    printf("\n");
    return 0;  
}