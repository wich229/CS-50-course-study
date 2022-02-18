#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //Getting User Input
    string text = get_string("text: ");

    //Letters
    int n = strlen(text);
    int letters_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters_sum ++;
        }
        else
        {
            // printf("Your input is not alphabetical.\n");
            letters_sum = letters_sum + 0;
        }
    }
    printf("letters:");
    printf("%i\n",letters_sum);

    //words
    int words_sum = 0;

    for (int l = 0; l < n; l++)
    {
        if (text[l] == 32)
        {
            words_sum ++;
        }
        else
        {
            words_sum = words_sum + 0;
        }

    }
    words_sum = words_sum + 1;
    printf("words:");
    printf("%i\n",words_sum);

    //Sentences

    int sentences_sum = 0;

    for (int j = 0; j < n; j++)
    {
        if (text[j] == 33 || text[j] == 46 || text[j] == 63)
        {
            sentences_sum ++;
        }
        else
        {
            sentences_sum = sentences_sum + 0;
        }
    }

    printf("sentences:");
    printf("%i\n",sentences_sum);

    //Putting it into Coleman-Liau index: index = 0.0588 * L - 0.296 * S - 15.8
    //L is the average number of letters per 100 words in the text;  L=letters/words*100;
    //S is the average number of sentences per 100 words in the text.  S=sentences/words*100;
    //grad X; the number will be round (四捨五入);

    float L = (float) letters_sum / (float) words_sum * 100;
    float S = (float) sentences_sum / (float) words_sum * 100;
    float grade = 0.0588 * L - 0.296 * S - 15.8;

    //lower than 1="Before Grade 1"; higher than 16="Grade 16+"

    if ((int)round(grade) < 0)
    {
        printf("Before Grade 1\n");
    }
    else if ((int)round(grade) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(grade));
    }

}