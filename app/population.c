#include <stdio.h>
#include <cs50.h>

int check_input1();
int check_input2(int start);
int population(int start, int end);

int main(void)
{
    int start = check_input1();
    int end   = check_input2(start);
    printf("Years: %i\n", population(start, end));
    return 0;
}

int check_input1()
{
    int input = 0;
    while (input < 9){
        input = get_int("Start: ");
    }
    return input;
}

int check_input2(int start)
{
    int end = 0;
    while (end <= start){
        end = get_int("End: ");
    }
    return end;
}

int population(int start, int end)
{
    int years = 0;
    while (start < end){
        start = start + (start/3) - (start/4);
        years++;
    }
    return years;
}