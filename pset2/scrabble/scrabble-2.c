#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int alph[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int compute_score(string word);

int main(void)
{

//find common elements;

//     int b[] = {1,3};
//     int a[] = {1,2,3,4};
//     int i,j;

//   for(i = 0; i < 4 ;i++)
//   {
//         for(j = 0; j < 2 ;j++)
//         {

//             if(b[i] == a[j])
//             {
//                 printf("\n Common elements is %i", b[i]);
//             }
//         }
//   }

// return the char to point;
    string word = get_string("Input: ");
    // printf("Score: ");
    int l, j, sum = 0;


    for (int i = 0,n = strlen(word); i < n; i++)
    {
        // printf("%i\n", toupper(word[i]));

        for(l = 0; l < 26; l++)
        {
            if(toupper(word[i]) == alph[l])
            {
                 sum = sum + POINTS[l];
                 printf("%i",sum);
            }


        }

    }
}
    //check input is alphabetical.
    // char c = get_char("Input: ");
    // if (isalpha(c))
    // {
    //     printf("Your input is alphabetical.\n");
    // }
    // else
    // {
    //     printf("Your input is not alphabetical.\n");
    // }

    //A=>point to the point

    // for(j = 0; j < 26; j++)
    // {
    //     alph[j]=POINTS[j];
    //     // printf("%i",alph[j]);
    // }






