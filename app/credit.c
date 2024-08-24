#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Function prototypes
long check_input();
bool check_card(long card, int limit);

int main(void)
{
    bool valid = false; // Track if the card is valid
    long first_digits; // Store the first digits of the card

    long card = check_input(); // Get the card number from the user

    // AMEX - 15 digits [34, 37]
    if ((first_digits = card / (long)pow(10, 13)) == 34 || first_digits == 37){
        if(check_card(card, 15)){
            valid = true;
            printf("AMEX\n");
        }
    }

    // MASTERCARD - 16 digits [51-55]
    else if ((first_digits = card / (long)pow(10, 14)) >= 51 && first_digits <= 55){   
        if(check_card(card, 16)){
            valid = true;
            printf("MASTERCARD\n");
        }
    }

    // VISA - 13 digits [4]
    else if (card / (long)pow(10, 12) == 4){
        if(check_card(card, 13)){
            valid = true;
            printf("VISA\n");
        }
    }

    // VISA - 16 digits [4]
    else if (card / (long)pow(10, 15) == 4){
        if(check_card(card, 16)){
            valid = true;
            printf("VISA\n");
        }
    }

    // If no valid card type was found
    if(!valid){
        printf("INVALID\n");
    }
    return 0;
}


/**
 * @brief Function to validate the card number using Luhn's algorithm
 * 
 * @param card card number give from the user
 * @param limit how many digits the card have
 * @return true if the card is valid, else
 * @return false
 */
bool check_card(long card, int limit)
{
    int total = 0; // Variable to store the sum of the digits

    // Loop through each digit of the card number
    for (int i = 0; i < limit; i++)
    {
        int x = card / (long)pow(10, i) % 10; // Extract the digit at position i
        if (i % 2 == 1) // If the position is odd (from the right, 0-based index)
        {
            x *= 2; // Multiply the digit by 2
            if (x > 9){
                x = x % 10 + x / 10; // If the result is a two-digit, sum the digits
            }
        }
        total += x; // Add the result to the total sum
    }

    // If the total sum is divisible by 10, the card is valid
    return (total % 10 == 0);
}


long check_input()
{
    long card = 0;
    while (card < 4000000000000 || card > 9999999999999999) {
        card = get_long("Number: ");
    }
    return card;
}
