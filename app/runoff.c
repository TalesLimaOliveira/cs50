#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// Structure to represent a candidate
typedef struct {
    string name;     // Candidate's name
    int votes;       // Number of votes received
    bool eliminated; // Elimination status
} Candidate;

// Global variables
Candidate candidates[MAX_CANDIDATES];
int votes[MAX_VOTERS][MAX_CANDIDATES]; // Stores ranks for each voter - v[i][j] is number of voters who prefer i over j

int voter_count;      // Number of voters
int candidate_count;  // Number of candidates

// Function prototypes
void verify_arguments(int argc);
void set_candidates(const string argv[]);
void make_votes(void);
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, const string argv[]) {
    // Validate command-line arguments
    verify_arguments(argc);

    // Initialize the array of candidates
    candidate_count = argc - 1;
    set_candidates(argv);

    // Get vote preferences from voters
    make_votes();

    // Keep holding runoffs until a winner exists
    while (true) {
        // Calculate votes for the remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won) {
            break;
        }

        // Eliminate candidates with the fewest votes
        int min = find_min();
        bool tie = is_tie(min);

        // If there is a tie, everyone wins
        if (tie) {
            printf("Tie:\n");
            for (int i = 0; i < candidate_count; i++) {
                if (!candidates[i].eliminated) {
                    printf("    %s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with the minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++) {
            candidates[i].votes = 0;
        }
    }

    return 0;
}

// Verify command-line arguments
void verify_arguments(int argc) {
    if (argc <= 2 || argc > MAX_CANDIDATES + 1) {
        printf("Please inform MIN=2 and MAX=%i catidades\n", MAX_CANDIDATES);
        exit(1);
    }
}

// Initialize candidates with names from command-line arguments
void set_candidates(const string argv[]) {
    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
}

// Collect votes from voters
void make_votes(void) {
    // Check number of voters
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS) {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        exit(2);
    }

    // Query each voter for their preferences
    for (int i = 0; i < voter_count; i++) {
        printf("--- Voter %i ---\n", i + 1);
        for (int j = 0; j < candidate_count; j++) {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name)) {
                printf("Invalid vote! Try again..\n");
                j--;
            }
        }
        printf("\n");
    }
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name) {
    // Check if the candidate name is valid
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            // Check if the candidate has already been ranked by the voter
            for (int j = 0; j < rank; j++) {
                if (votes[voter][j] == i) {
                    return false; // Candidate already ranked, invalid vote
                }
            }

            // Record the valid vote
            votes[voter][rank] = i; // Store the candidate index
            return true;
        }
    }
    return false; // Candidate name not found, invalid vote
}


// Tabulate votes for non-eliminated candidates
void tabulate(void) {
    // Reset the vote counts for each candidate
    for (int i = 0; i < candidate_count; i++) {
        candidates[i].votes = 0;
    }

    // Iterate over each voter
    for (int i = 0; i < voter_count; i++) {
        // Iterate over each voter's preferences
        for (int j = 0; j < candidate_count; j++) {
            int candidate_index = votes[i][j];
            
            // If the candidate is not eliminated, count the vote
            if (!candidates[candidate_index].eliminated) {
                candidates[candidate_index].votes++;
                break; // Stop checking preferences for this voter
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void) {
    int majority = voter_count / 2;

    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > majority) {
            printf("Winner: %s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void) {
    int min_votes = voter_count;
    for (int i = 0; i < candidate_count; i++) {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes) {
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min) {
    for (int i = 0; i < candidate_count; i++) {
        if (!candidates[i].eliminated && candidates[i].votes != min) {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min) {
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes == min) {
            candidates[i].eliminated = true;
        }
    }
}
