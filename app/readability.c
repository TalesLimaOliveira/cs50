#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void count_text_elements(string text, int *letters, int *words, int *sentences);
void print_grade(int grade);

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0, words = 1, sentences = 0;
    count_text_elements(text, &letters, &words, &sentences);

    float L = ((float)letters / words) * 100; // letter per 100 words
    float S = ((float)sentences / words) * 100; // sentences per 100 words
    int grade = round(.0588 * L - 0.296 * S - 15.8);

    print_grade(grade);
    return 0;
}


void count_text_elements(string text, int *letters, int *words, int *sentences)
{
    for (int i = 0, text_size = strlen(text); i < text_size; i++){
        if (isalpha(text[i])){
            (*letters)++;
        }
        else if (text[i] == ' '){
            (*words)++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?'){
            (*sentences)++;
        }
    }
}


void print_grade(int grade)
{
    if(grade < 1){
        printf("Before Grade 1\n");
        return;
    }
    if (grade > 15){
        printf("Grade 16+\n");
        return;
    }

    printf("Grade %i\n", grade); 
}
