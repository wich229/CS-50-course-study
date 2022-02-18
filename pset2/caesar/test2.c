#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int j=3;
int alph_index[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int cipher(char plaintext,int k);

int main(void)
{
    string plaintext = get_string("plaintext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int cipher_text2 = cipher(plaintext[i], j);
        printf("%c",cipher_text2);
    }
    printf("\n");
}


int cipher(char plaintext,int k)
{
    char cipher_text;
    // get plaintext
    // encipher  i = (pi + k) % 26

    // printf("plaintext:%s\n",plaintext);
    // printf("ciphertext:");

    if(isalpha(plaintext)==0)
    {
        cipher_text = plaintext;
        // printf("%c",non_text);
    }
    else if(isupper(plaintext))
    {
        int new_index1 = plaintext-65;
        int upper_cipher = (new_index1+k) % 26;
        cipher_text = alph_index[upper_cipher];
        // char ci_up_text = alph_index[upper_cipher];
        // printf("%c",ci_up_text);
    }
    else
    {
        int new_index2 = plaintext-97;
        int lower_cipher = (new_index2+k) % 26;
        cipher_text =  tolower(alph_index[lower_cipher]);
        // char ci_low_text = alph_index[lower_cipher];
        // printf("%c",tolower(ci_low_text));
    }
    return cipher_text;
}