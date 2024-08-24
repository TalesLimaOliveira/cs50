#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9 

// Candidates have name and vote count
typedef struct{
    string name;
    int votes;
} Candidate;

// Global Vars
int candidate_count;
Candidate candidates[MAX];

// Prototypes
int verify_arguments(int argc);
void set_caditades(string const argv[]);
void make_votes(void);
bool vote(string name);
void print_winner(void);

int main(int argc, const string argv[])
{
    // Validate command-line arguments
    int arg_error = verify_arguments(argc);
    if(arg_error){
        return arg_error;
    }

    // Populate array of candidates
    candidate_count = argc-1;
    set_caditades(argv);

    // Count votes and find the winner
    make_votes();
    print_winner();
    
    return 0;
}


int verify_arguments(int argc)
{
    if(argc <= 2 || argc > MAX+1){
        printf("Please inform MIN=2 and MAX=%i catidades\n", MAX);
        return 1;
    }

    return 0;
}

void set_caditades(string const argv[])
{
    for (int i = 0; i < candidate_count; i++){
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
    }
}

void make_votes(void)
{
    int voter_count = get_int("Number of voters: ");
    string name;

    for (int i = 0; i < voter_count; i++){
        name = get_string("Vote %i: ", i+1);
        if(!vote(name)){
            printf("Invalid vote.\n");
            i--;
        }
    }
}

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++){
        if (strcmp(candidates[i].name, name) == 0){
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int max_votes = 0, winner_index;
    for (int i = 0; i < candidate_count; i++){
        if(candidates[i].votes > max_votes){
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    printf("Winner: %s\n", candidates[winner_index].name);
}