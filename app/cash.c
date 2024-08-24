#include <cs50.h>
#include <stdio.h>
#include <math.h>

float check_input();
int change(int cents);
int main(void)
{
    float x = check_input();
    int cents = round(x * 100); // Convert to cents to avoid floating point precision issue
    printf("%i\n", change(cents));
    return 0;
}


float check_input()
{
    float n;
    do{
        n = get_float("Change: ");
    } while (n <= 0.0);
    return n;  
}


int change(int cents)
{   
    int total = 0;
    while (cents >= 1){
        if(cents >= 25){
            total++;
            cents -= 25;
        }else if(cents >= 10){
            total++;
            cents -= 10;
        }else if(cents >= 5){
            total++;
            cents -= 5;
        }else{
            total++;
            cents -= 1;
        }
    }

    return total;
}