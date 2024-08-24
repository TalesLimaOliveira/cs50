#include <stdio.h>
#include <cs50.h>

void print_stair(int n);
int check_input();
int main(void)
{
    int n = check_input();
    print_stair(n);
    return 0;
}


int check_input()
{
    int n = -1;
    while (n < 1 || n > 8){
        n = get_int("Stair height: ");
    }
    return n;  
}


void print_stair(int n)
{
    for (int i = 1; i <= n; i++){
        for (int j = n-i; j > 0; j--){
            printf(" "); // (n-i) spaces are needed to right-align the steps
        }
        for (int j = 0; j < i; j++){
            printf("$"); // The number of '$' is equal to the current row number (i)
        }
        printf("  "); //The Gap
        for (int j = 0; j < i; j++){
            printf("$"); // The number of '$' is equal to the current row number (i)
        }
        printf("\n");
    } 
}
