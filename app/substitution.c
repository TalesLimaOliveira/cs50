#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Prototypes
string substitute_cipher(string text, string key);
int verify_arguments(int argc, const string argv[]);

int main(int argc, const string argv[])
{   
    // Validate command-line arguments
    int arg_error = verify_arguments(argc, argv);
    if(arg_error){
        return arg_error;
    }

    string key = argv[1];
    string text = get_string("Plaintext : ");

    // Encrypt and print ciphertext
    text = substitute_cipher(text, key);
    printf("Ciphertext: %s\n", text);

    return 0;
}

/**
 * @brief Function to perform substitution cipher
 * @return string incryped
 */
string substitute_cipher(string text, string key)
{
    for (int i = 0, n = strlen(text); i < n; i++){
        if(isalpha(text[i])){
            // Convert character to uppercase index ('A' = 0, ..., 'Z' = 25)
            int index = toupper(text[i]) - 'A'; 
            if (islower(text[i])) {
                text[i] = tolower(key[index]);
            } else {
                text[i] = toupper(key[index]);
            }
        }
    }

    return text;
}

/**
 * @brief Function to validate command-line arguments
 * @return 0 if its ok else throw a erro
 */
int verify_arguments(int argc, const string argv[])
{
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1; // Incorrect number of arguments
    }

    int key_length = strlen(argv[1]);
    if (key_length != 26) {
        printf("Key must contain exactly 26 characters.\n");
        return 2; // Invalid key length
    }

    // Check for non-alphabetic characters and duplicates
    bool seen[26] = {false}; // Array to track seen characters ('A' to 'Z')
    for (int i = 0; i < key_length; i++) {
        if (!isalpha(argv[1][i])) {
            printf("Key must only contain alphabetic characters.\n");
            return 3; // Non-alphabetic character found
        }

        // Convert character to uppercase index ('A' = 0, ..., 'Z' = 25)
        int index = toupper(argv[1][i]) - 'A';

        if (seen[index]) {
            printf("Key must not contain duplicate characters.\n");
            return 4; // Duplicate character found
        }

        seen[index] = true;
    }

    return 0; // All checks passed
}