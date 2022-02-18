#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char LETTER[]= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z'};
int total_score;
char lower;

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    
    // TODO: Print the winner
    if (score1 > score2)
        {
            printf("Player 1 wins!\n");
        }
    else if(score2 > score1)
        {
            printf("Player 2 wins!\n");
        }
    else 
        {
            printf("Tie!\n");
        }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    total_score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
        {
        lower = tolower(word[i]);
        // printf("%c", lower);
        for (int j = 0; j <26; j++)
            {
            if (lower == LETTER[j])
                {
                // printf("%i", POINTS[j]);
                total_score = total_score + POINTS[j];
                }
            }
        }
    // printf("\n");
    // printf("total_score: %i\n", total_score);
    return total_score;
}