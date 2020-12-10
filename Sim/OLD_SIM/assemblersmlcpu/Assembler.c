//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

  FILE* in;
  FILE* out;
  FILE* DAT0in;
  FILE* DAT1in;
  out = fopen("INScompile.t", "w+");
  char* INS = malloc(3);
  char* DATbuff0 = malloc(1);
  char* DATbuff1 = malloc(1);
  int a = 0;
  in = fopen("INScompile.u", "r");
  DAT0in = fopen("DAT0.raw", "r");
  DAT1in = fopen("DAT1.raw", "r");
  //
    for(int c=1; c < 15; c++)
    {
      fscanf(DAT0in, "%c\n", DATbuff0);
      //fscanf(DAT0in, "%c\n", DATbuff01);
      //fscanf(DAT0in, "%c", DATbuff10);
      fscanf(DAT1in, "%c\n", DATbuff1);
      fscanf(in, "%s", INS);
      printf("%i: \n", c);
      printf("%s\n", INS);
      //printf("hello: %s", DATbuff0);

      if(strcmp(INS, "loa") == 0)
        {
          fprintf(out, "%x080000%s\n", c, DATbuff0);
          continue;
        }
      if(strcmp(INS, "jmp") == 0)
        {
          fprintf(out, "1\n");
          continue;
        }
      if(strcmp(INS, "add") == 0)
        {
          fprintf(out, "%x094%s00%s\n", c, DATbuff0, DATbuff1);
          continue;
        }
      if(strcmp(INS, "sub") == 0)
        {
          fprintf(out, "%x09c%s00%s\n", c, DATbuff0, DATbuff1);
          continue;
        }
      if(strcmp(INS, "mul") == 0)
        {
          a = c - 2;
          //int b = c - 1;

          //printf("a: %d\n", a);
          fprintf(out, "%x0d4%s00%s\n\n", a, DATbuff0, DATbuff1);
          continue;
        }
      if(strcmp(INS, "div") == 0)
        {
          a = c - 2;
          fprintf(out, "%x0dc%s00%s\n\n", a, DATbuff0, DATbuff1);
          continue;
        }
      if(strcmp(INS, "not") == 0)
        {
          fprintf(out, "%x0d0%s00%s\n", c, DATbuff0, DATbuff1);
          continue;
        }
      if(strcmp(INS, "and") == 0)
        {
          fprintf(out, "%x0d1%s00%s\n", c, DATbuff0, DATbuff1);
          continue;
        }
      if(strcmp(INS, "or") == 0)
        {
          fprintf(out, "%x0d2%s00%s\n", c, DATbuff0, DATbuff1);
          continue;
        }
      if(strcmp(INS, "xor") == 0)
        {
          fprintf(out, "%x0d3%s00%s\n", c, DATbuff0, DATbuff1);
          continue;
        }
      if(strcmp(INS, "mov") == 0)
        {
          fprintf(out, "%x095%s00%s\n", c, DATbuff0, DATbuff1);
          continue;
        }
      /*if(strcmp(INS, "in") == 0)
        {
          fprintf(out, "b\n");
          continue;
        }*/
      if(strcmp(INS, "out") == 0)
        {
          fprintf(out, "%x080%s00%s\n", c, DATbuff0, DATbuff1);
          continue;
        }
      if(strcmp(INS, "hlt") == 0)
        {
          fprintf(out, "00000000\n");
          break;
        }

    }

  //
  fclose(in);
  fclose(out);
  return 0;
}
