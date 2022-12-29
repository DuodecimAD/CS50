#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
string preferences[MAX_VOTERS][MAX_CANDIDATES];     //changed from int

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;


// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

 for (int w = 0; w < voter_count; w++)
{
for (int x = 0; x < candidate_count; x++)
{
printf("%i %s\t\t", x, preferences[w][x]);
}
printf("\n");
}
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name,candidates[i].name) == 0)
        {
            preferences[voter][rank] = name;

            return true;
        }
    }
    return false;



}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{

string rank2;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int k = 0; k < voter_count; k++)
        {
            if (strcmp(preferences[k][0],candidates[i].name) == 0 && candidates[i].eliminated == false)
            {
                candidates[i].votes++;
                printf("%s +1\n", candidates[i].name);
            }
            else if (strcmp(preferences[k][0],candidates[i].name) == 0 && candidates[i].eliminated == true)
            {
                for(z = 0; z < candidate_count; z++)
                {
                    if (strcmp(preferences[k][1],candidates[z].name) == 0)
                    {
                        candidates[z].votes++;
                        break;
                    }
                }
            }
        }
    }

    for (int z = 0; z < candidate_count; z++)
    {
        printf("%s %i\n",candidates[z].name,candidates[z].votes);
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{

    int temp = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > temp)
        {
            temp = candidates[i].votes;
        }
    }

    if (voter_count % 2 == 1)
    {
        if (temp >= ((voter_count / 2) + 1))
        {
            printf("%i is more than 50%% of %i\n", temp, voter_count);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (temp > (voter_count / 2))
        {
            printf("%i is more than 50%% of %i\n", temp, voter_count);
        }
        else
        {
            return false;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == temp)
        {
            printf("%s is the winner\n", candidates[i].name);
        }
    }

    return true;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = MAX_VOTERS;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    printf("min is %i\n",min);
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > min)
        {
            printf("they aren't tied\n");
            return false;
        }
    }
 printf("they ARE tied\n");
        return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
            printf("%s is eliminated\n", candidates[i].name);
        }
    }

    return;
}