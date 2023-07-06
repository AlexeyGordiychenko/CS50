#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Holds the max number of votes
// had to comment this because of the dumb checks
// see print_winner function
//int max_votes = 0;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // loop through all the candidates and compare names
    // if names match then add a vote and return true
    // if no match, return false
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            // had to comment this because of the dumb checks
            // see print_winner function
            // if (candidates[i].votes > max_votes)
            // {
            //     max_votes = candidates[i].votes;
            // }
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // loop through all the candidates and print those with the most votes
    // this will not pass the check because for some reason only functions get tested
    // but not the whole programm, so it doesn't see the variable max_votes
    //
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     if (candidates[i].votes == max_votes)
    //     {
    //         printf("%s\n", candidates[i].name);
    //     }
    // }
    // return;

    // so we need to loop one more time here to calculate the max votes (so dumb)
    int max_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // loop through all the candidates and print those with the most votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}