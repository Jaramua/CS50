#include <cs50.h>
#include <stdio.h> 

int main(void)
{

    int minutes, bottles;
    printf("Minutes: ");
    minutes = get_int();
    bottles = minutes * 12;
   
    printf("Bottles: %d\n", bottles);
    return 0;
}
