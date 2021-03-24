#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
     // ask for money
     float change;
     int changecents;
     int coins = 0;
     
     do
     {
         change = get_float("Change coins: ");
     }
     while (change <= 0);
     
     // round and change to cents
     
     changecents = round(change * 100);
     
     // coins coounter
     while (changecents >=20)
     {
         changecents = changecents - 25;
         coins++;
     }
     while (changecents >= 10)
     {
         changecents = changecents - 10;
         coins++;
     }
    
    while (changecents >= 5)
    {
        changecents = changecents - 5;
        coins++;
    }
    
    while (changecents >= 1)
    {
        changecents = changecents - 1;
        coins++;
    }
    
    // print the coins needed value
    
    {
        printf("Coins needed %d\n", coins);
    }
}