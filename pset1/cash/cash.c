#include <math.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{

//get number from user;
// n = cash number;
    float n;

    do
    {
        n = get_float("change owed: ");

    }
    while (n < 0);

//covert the dollars to cents;

    int cents = round(n * 100);
    printf("%i\n", cents);

// qn = quarter number, dn = dime number, nn = nickel number, pn = penny number;
  
    int qn = cents / 25;
    // printf("%i\n",qn);
      
    int dn = (cents % 25) / 10;
    //printf("%i\n",dn);
     
    int nn = (cents % 25 % 10) / 5;
    //printf("%i\n",nn);
    
    int pn = cents - qn * 25 - dn * 10 - nn * 5;
    //printf("%i\n",pn);
    
  
    //print out the number of the coins;
    
    int coins = qn + dn + nn + pn;
    printf("%i\n", coins);
}
  
//     int qn, dn, nn, pn, r, coins;
  
//     qn=0;
//     dn=0;
//     nn=0;
//     pn=0;
//   r=0;
 
 

//   qn=cents/25;
//   r = cents%25;
//   // printf("qn: %i\n", qn);
//   // printf("r: %i\n", r);
  
//   if(r > 0)
//   {
//     dn=r/10;
//     r=r%10;
//     // printf("dn: %i\n", dn);
//     // printf("r2: %i\n", r);
//   }
//   if(r > 0)
//   {
//     nn=r/5;
//     r=r%5;
//     // printf("nn: %i\n",nn);
//     // printf("r3: %i\n", r);
//   }
//   if(r > 0)
//   {
//     pn=r;
//     // printf("pn: %i\n",pn);
//     // printf("r4: %i\n", r);
//   }

//   coins = qn+dn+nn+pn;
//   printf("%i\n",coins);
// }

