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
    for (int i = 0; i < candidate_count; i++)
    {
        //using strcmp (string compare) to check for a match between name on vote and candidate's name
        if (strcmp(candidates[i].name, name) == 0)
        {
            //adding 1 vote everytime the condition is matched
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}


// Print the winner (or winners) of the election
void print_winner(void)
{
    //creating an int variable that will store the highest number of votes across all candidates
    int winner_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > winner_votes)
        {
            //setting winner_votes with the highest number of votes received t
            winner_votes = candidates[i].votes;
        }
    }
    //additional for loop that compates the votes of each candidates againt the winner_votes variable and selects all those that match
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == winner_votes)
        {
            printf("%s\n", candidates[j].name);
        }
    }
    return;
}