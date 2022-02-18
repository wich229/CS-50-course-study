#include <cs50.h>
#include <stdio.h>

int main(void)
{

//get number from user;
//h=hight;

    int h;

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

// print the brick pattern out;


    for (int i = 0; i < h; i++)
    {
        int dot = h - i;
        for (int j = 1; j < dot ; j++)
        {
            printf(" ");
        }

        for (int k = 0; k <= i ; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}

//     for (int i = 0; i < h; i++)
//     {
//         int dot = h - i;
//         for (int j = 1; j < dot ; j++)
//         {
//             // printf("j%i",j);
//             printf(" ");
//         }

//         for (int k = 0; k <= i ; k++)
//         {
//             // printf("k%i",k);
//             printf("#");
//         }

//         for (int l = 0 ; l < 2 ; l++)

//         {
//             // printf("l%i",l);
//             printf(" ");
//         }

//         for (int l = 0 ; l <= i ; l++)

//         {
//             printf("#");
//         }

//         printf("\n");
//     }
// }