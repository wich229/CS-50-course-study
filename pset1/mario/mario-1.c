#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int h, h_minus, extra, extra_plus;

  do
  {
   h = get_int("Height: ");
  }
  while(h<1 || h>8);

  h_minus = h;
  extra = h;
  extra_plus = h;

  for (int i = 0; i < h; i++)
  {
    h_minus = h-i;
    // printf("%i", h_minus);
    for (int k = 1; k < h_minus; k++)
      {
        printf(" ");
      }
    for (int j = 0; j <= i; j++)
    {
      printf("#");
    }
  printf("\n");
  }
}