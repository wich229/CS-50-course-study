#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    //stn means start number; edn means end number
    // stn/3 are new born; stn/4 pass away

    int stn, edn, n, i;

    do
    {
        stn = get_int("Positive Integer: ");
    }
    while (stn < 9);

  
    // if(stn>=9)
    // {
    //   printf("start size: %i\n ",stn);
    // }
    // else
    // {
    //   stn = get_int("Positive Integer: ");
    // }

    // TODO: Prompt for end size

    do
    {
        edn = get_int("Positive Integer and larger than start size: ");
    }
    while (edn < stn);

    // TODO: Calculate number of years until we reach threshold
    // edn = stn+(stn/3)-(stn/4);
    // i= year

    n = stn;
    i = 0;

    while (edn >= n)
    {
        if (stn == edn)
        {
            break;
        }
        else
        {
            n = n + (n / 3) - (n / 4);
        }
        
        if (n >= edn)
        {
            i++;
            break;
        }
        else
        {
            i++;
        }
    }


    // TODO: Print number of years
    printf("Years: %i", i);
}