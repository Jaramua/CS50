#include <cs50.h>
#include <stdio.h> 

int main(void)
{
    int height;
    
    do
    {
         printf("Height: ");
         height = get_int();
    }
    while (height < 0 || height > 23);
    
    
    for (int r = 1, s, h; r <= height; r++) 
    {
        for (s = (height - r); s > 0; s--)
        {
            printf(" "); 
        }
 
        for (h = 1; h <= (r + 1); h++)
        {   
            printf("#"); 
        }
 
        printf("\n");
    }
    return 0;
}
