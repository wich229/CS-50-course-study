#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
//isupper() islower() return a boolean; toupper() tolower() convert it to a character.
//a-z:97-122; A-Z:65-90;
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int alph[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int compute_score(string word);

int main(void)
{
// Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

// Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // printf("%i\n", score1);
    // printf("%i\n", score2);

// TODO: Print the winner
    if (score1 > score2)
    {
        printf("%s", "Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("%s", "Player 2 wins!");
    }
    else
    {
        printf("%s", "Tie!");
    }

}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int sum = 0;
    // string word = get_string("Input: ");
    // printf("Output: ");
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // printf("%i\n", toupper(word[i])); //print out the uppercase;
        //check input is alphabetical.
        if (isalpha(word[i]))
        {
            // printf("Your input is alphabetical.\n");
            int point_index = toupper(word[i]) - alph[0];
            // printf("%i",POINTS[point_index]);
            sum = sum + POINTS[point_index];
        }
        else
        {
            // printf("Your input is not alphabetical.\n");
            sum = sum + 0;
        }
    }
    printf("%i\n", sum);
    return sum;
}