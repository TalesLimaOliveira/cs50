#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int const POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
void print_winner(int score1, int score2);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    print_winner(score1, score2);
    return 0;
}

int compute_score(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++){
        if (isalpha(word[i])){
            score += POINTS[tolower(word[i]) - 'a'];
        }
    }
    return score;
}

void print_winner(int score1, int score2)
{
    printf("P1: %i vs %i :P2\n", score1, score2);
    if (score1 > score2){
        printf("Player 1 Wins!\n");
        return;
    }
    else if(score1 < score2){
        printf("Player 2 Wins!\n");
        return;
    }
    printf("It's a tie!\n");
}