#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int j=3;
int alph_index[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int cipher(string plaintext,int k);

int main(void)
{
    string plaintext = get_string("plaintext: ");
    int cipher_text2 = cipher(plaintext, j);
    printf("ciphertext: %c",cipher_text2);
    printf("\n");
}


int cipher(string plaintext,int k)
{
    char cipher_text;
    // get plaintext
    // encipher  i = (pi + k) % 26

    // printf("plaintext:%s\n",plaintext);
    // printf("ciphertext:");
    // plaintext = get_string("Input: ");
    // printf("plaintext:%s\n",plaintext);
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if(isalpha(plaintext[i])==0)
        {
            cipher_text = plaintext[i];
            // printf("%c",non_text);
        }
        else if(isupper(plaintext[i]))
        {
            int new_index1 = plaintext[i]-65;
            int upper_encipher = (new_index1+k) % 26;
            cipher_text = alph_index[upper_encipher];
            // printf("%c",ci_up_text);
        }
        else
        {
            int new_index2 = plaintext[i]-97;
            int lower_encipher = (new_index2+k) % 26;
            cipher_text = tolower(alph_index[lower_encipher]);
            // printf("%c",tolower(ci_low_text));
        }
    }
    return cipher_text;
}