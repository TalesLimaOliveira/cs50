#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string caesar_cipher(string text, int key);
int verify_arguments(int argc, string const argv[]);

int main(int argc, string const argv[])
{   
    int arg_error = verify_arguments(argc, argv);
    if(arg_error){
        return arg_error;
    }

    int key = atoi(argv[1]);
    string text = get_string("Plaintext : ");

    printf("Ciphertext: %s\n", caesar_cipher(text, key));
    return 0;
}


string caesar_cipher(string text, int key)
{
    for (int i = 0, n = strlen(text); i < n; i++){
        if(isalpha(text[i])){
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + key) % 26 + base;
        }
    }

    return text;
}

int verify_arguments(int argc, string const argv[])
{
    if(argc < 2){
        printf("Missing command line argument.\n");
        return 1;
    }
    else if (argc > 2){
        printf("Too many command line arguments.\n");
        return 2;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++){
        if (!isdigit(argv[1][i])) {
            printf("Invalid Argument. Just insert NUMBERS!!\n");
            return 3;
        }
    }
    return 0;
}