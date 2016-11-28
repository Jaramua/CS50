#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    int coin_count = 0;
    
    printf("O hai! How much change is owed?: \n");
    
    do
    {
        change = get_float();
        if(change == 0||change <= 0)
        printf("Error\n");
    }
    while (change<=0);
    
    
    int change_cents = roundf(change * 100);
    while (change_cents > 0) 
    {
        if ((change_cents - 25) >= 0) 
        { 
            change_cents = change_cents - 25; 
            coin_count++;
        }
        else if ((change_cents - 10) >= 0)
        { 
            change_cents = change_cents - 10;
            coin_count++;
        }
        else if ((change_cents - 5) >= 0)
        { 
            change_cents = change_cents - 5; 
            coin_count++;
        }
        else if ((change_cents - 1) >= 0)
        { 
            change_cents = change_cents - 1; 
            coin_count++; 
            
        }
    }
    
    
    printf("%d\n", coin_count);
}


