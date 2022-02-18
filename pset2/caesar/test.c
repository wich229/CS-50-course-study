#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int k=3;
int alph_index[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(void)
{
    string plaintext = get_string("Input: ");
    printf("plaintext:%s\n",plaintext);
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if(isalpha(plaintext[i])==0)
        {
            char non_text = plaintext[i];
            printf("%c",non_text);
        }
        else
        {
            if(isupper(plaintext[i]))
            {
                int new_index1 = plaintext[i]-65;
                int upper_encipher = (new_index1+k) % 26;
                char ci_up_text = alph_index[upper_encipher];
                printf("%c",ci_up_text);
            }
            else
            {
                int new_index2 = plaintext[i]-97;
                int lower_encipher = (new_index2+k) % 26;
                char ci_low_text = alph_index[lower_encipher];
                printf("%c",tolower(ci_low_text));
            }
            
        }
    }
    //A-Z:65-90; a-z:97-122;
    // encipher  ci = (pi + k) % 26;
}