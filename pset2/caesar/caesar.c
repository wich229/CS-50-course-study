#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// get Key; useage: ./caesar Key
//argv[1][i] == 0 non digit 
// argv[1][i] !=0 digit


int alph_index[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


int main(int argc, string argv[])
{
    int k;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    if (argc == 2)
    {
        
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                break;
            }
            else if (i == n - 1)
            {
                // printf("Success\n");
                k = atoi(argv[1]);
                
                string plaintext = get_string("plaintext: ");
                // printf("plaintext:%s\n",plaintext);
                printf("ciphertext:");
                for (int j = 0, l = strlen(plaintext); j < l; j++)
                {
                    if (isalpha(plaintext[j]) == 0)
                    {
                        char non_text = plaintext[j];
                        printf("%c", non_text);
                    }
                    else if (isupper(plaintext[j]))
                    {
                        int new_index1 = plaintext[j] - 65;
                        int upper_encipher = (new_index1 + k) % 26;
                        char ci_up_text = alph_index[upper_encipher];
                        printf("%c", ci_up_text);
                    }
                    else
                    {
                        int new_index2 = plaintext[j] - 97;
                        int lower_encipher = (new_index2 + k) % 26;
                        char ci_low_text = alph_index[lower_encipher];
                        printf("%c", tolower(ci_low_text));
                    }
            
                }
                printf("\n");
            }
        }
    }
}

