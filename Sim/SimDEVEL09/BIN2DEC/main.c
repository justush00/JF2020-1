//create a useful function to decode 16bit decimal to instruction, operators 0 and 1, destination register

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int powe( int a, int b)
{
  int c = 1;
  while(b != 0)
  {
    c = c * a;
    b--;
  }
  return c;
}

int main()
{
  int dec;
  int bin[16];
  int turn[16];
  int m = 0;
  int n;

  //initialize array
  for(n = 0; n < 16; n++)
  {
    bin[n] = 0;
    turn[n] = 0;
  }

  printf("enter a Number: ");
  scanf("%d", &dec);
  printf("your number in decimal: %d\n", dec);

  //conversion dec to bin
  for(n = 0; dec > 0; n++)
  {
    bin[n] = dec % 2;
    dec = dec / 2;
  }

  //output
  printf("your number in binary: ");
  for(n = 15 ; n >= 0; n--)
  {
    printf("%d", bin[n]);
  }
  printf("\n");

  //turn the array "around"
  /*turn[0] = bin[15];
  turn[1] = bin[14];
  turn[2] = bin[13];
  turn[3] = bin[12];
  turn[4] = bin[11];
  turn[5] = bin[10];
  turn[6] = bin[9];
  turn[7] = bin[8];
  turn[8] = bin[7];
  turn[9] = bin[6];
  turn[10] = bin[5];
  turn[11] = bin[4];
  turn[12] = bin[3];
  turn[13] = bin[2];
  turn[14] = bin[1];
  turn[15] = bin[0];

  bin[0] = turn[0];
  bin[1] = turn[1];
  bin[2] = turn[2];
  bin[3] = turn[3];
  bin[4] = turn[4];
  bin[5] = turn[5];
  bin[6] = turn[6];
  bin[7] = turn[7];
  bin[8] = turn[8];
  bin[9] = turn[9];
  bin[10] = turn[10];
  bin[11] = turn[11];
  bin[12] = turn[12];
  bin[13] = turn[13];
  bin[14] = turn[14];
  bin[15] = turn[15];*/

  printf("your number in binary(2nd time): ");
  for(n = 15 ; n >= 0; n--)
  {
    printf("%d", bin[n]);
  }
  printf("\n");

  //conversion bin to dec
  for(n = 0; n < 16; n++)
  {
    printf("%i + (%i * %i)\n", dec, bin[n], powe(2, n));
    dec = dec + (bin[n] * powe(2, n));
  }
  printf("your number in decimal(2nd time): %d\n", dec);
}
