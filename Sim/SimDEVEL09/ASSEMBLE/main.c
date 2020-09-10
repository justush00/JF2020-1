#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

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
  FILE* in;
  FILE* out;

  char* INS = malloc(3);
  char* SRC0 = malloc(1);
  char* SRC1 = malloc(1);
  char* DEST = malloc(1);

  //printf("Please enter the name of the source (.asm): ");
  char source[20];
  //scanf("%s\0", source);

  //printf("Please enter the name of the target (.mem): ");
  char target[20];
  //scanf("%s\0", target);

  in = fopen("test.asm", "r");
  out = fopen("./test.mem", "w+");

  if (in == NULL)
  {
      printf("Sorry, sourcefile does not exist.\n");
      exit(EXIT_FAILURE);
  }

  int ins;
  int src0;
  int src1;
  int dest;

  int dec;
  int insb[4];
  int src0b[4];
  int src1b[4];
  int destb[4];
  int full[16];
  int n;

  for(int c = 0; c < 255; c++)
  {
    //INS = 0;
    //OP0 = 0;
    //OP1 = 0;
    fscanf(in, "%s %s %s %s\n", INS, SRC0, SRC1, DEST);
    //printf("%s %s %s %s\n", INS, SRC0, SRC1, DEST);

    if(strcmp(INS, "nop") == 0)
        {
          ins = 0;
        }
    if(strcmp(INS, "loa") == 0) //op0 sind hier die zu ladenden daten
        {
          ins = 1;
        }
    if(strcmp(INS, "str") == 0)
        {
          ins = 2;
          //not finished yet
        }
    if(strcmp(INS, "jmp") == 0)
        {
          ins = 3;
        }
    if(strcmp(INS, "alu") == 0)
        {
          //bitwise adding
          ins = 4;
        }
    if(strcmp(INS, "cmp") == 0)
        {
          ins = 5;
        }

    if(strcmp(INS, "hlt") == 0)
        {
          ins = 15;
          printf("DBG");
        }

    src0 = atoi(SRC0);
    src1 = atoi(SRC1);
    dest = atoi(DEST);

    //initialize arrays
    for(n = 0; n < 4; n++)
    {
      insb[n] = 0;
      src0b[n] = 0;
      src1b[n] = 0;
      destb[n] = 0;
    }

    //conversion dec to bin
    for(n = 0; ins > 0; n++)
    {
      insb[n] = ins % 2;
      ins = ins / 2;
    }
    for(n = 0; src0 > 0; n++)
    {
      src0b[n] = src0 % 2;
      src0 = src0 / 2;
    }
    for(n = 0; src1 > 0; n++)
    {
      src1b[n] = src1 % 2;
      src1 = src1 / 2;
    }
    for(n = 0; dest > 0; n++)
    {
      destb[n] = dest % 2;
      dest = dest / 2;
    }
    full[0] = insb[0];
    full[1] = insb[1];
    full[2] = insb[2];
    full[3] = insb[3];
    full[4] = src0b[0];
    full[5] = src0b[1];
    full[6] = src0b[2];
    full[7] = src0b[3];
    full[8] = src1b[0];
    full[9] = src1b[1];
    full[10] = src1b[2];
    full[11] = src1b[3];
    full[12] = destb[0];
    full[13] = destb[1];
    full[14] = destb[2];
    full[15] = destb[3];

    dec = 0;

    for(n = 0; n < 16; n++)
    {
      //printf("%i + (%i * %i)\n", dec, full[n], powe(2, n));
      dec = dec + (full[n] * powe(2, n));
    }

    fprintf(out, "%i\n", dec);

  }
  fclose(in);
  fclose(out);
}