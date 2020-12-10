#ifndef FILE_H
#define FILE_H

void external_in_file()
{
  	//char *line = getenv("LINECOUNT");
  	//int lc = strtol(line, &null,10) * 7;
 	//printf("%i\n", lc);
  	//char *pathtoin = getenv("INTXT");
  	char string[1001];
  	FILE *file0;
  	//FILE *file1;
  	file0 = fopen("/home/justus/MEGAsync/Projects/JF2020-1/Sim/hallo", "r"); //edit this to your develop-directory/in.txt
  	//file1 = fopen("/home/dev/Projects/smlCPUsimulator/out.txt", "w");

 	fscanf(file0, "%s", string);  // %c: einzelnes Zeichen %s: Zeichenkette
 	printf("File scanned!\n");
    // String muss mit Nullbyte abgeschlossen sein

    string[1000] = '\0';

    printf("%s\n", &string);
    sleep(5);
  	fclose(file0);
}

void datain(bool returrn[64])
{
  bool string[65];
  FILE *file0;
  file0 = fopen("/home/justus/MEGAsync/Projects/JF2020-1/Sim/datain", "r"); //edit this to your develop-directory/in.txt

 	fscanf(file0, "%s", string);  // %c: einzelnes Zeichen %s: Zeichenkette
 	printf("File scanned!\n");
    // String muss mit Nullbyte abgeschlossen sein
 	printf("%s\nDEBUG:\n", &string);
    string[64] = '\0';
 	for(int a = 0; a < 64; a++)
 	{
 		printf("%c", &string[a]);
 	}
 	sleep(5);
  	fclose(file0);
}

void savemem()
{
  printf("Please enter a name (.mem): ");
  char name[20];
  scanf("%s\0", name); 
  FILE *out;
  out = fopen(name, "w+" );
  if (out == NULL)
  {
      printf("Sorry, file does not exist.\n");
      exit(EXIT_FAILURE);
  }
  for(int i=0; i < 255; i++)
  {
    fprintf(out, "%i\n", memory[i]); 
  }
  fclose(out);
}

void loadmem()
{
  printf("Please enter a name (.mem): ");
  char name[20];
  char arr[255];
  scanf("%s\0", name); 
  FILE *in;
  in = fopen(name, "r" );
  if (in == NULL)
  {
      printf("Sorry, file does not exist.\n");
      exit(EXIT_FAILURE);
  }
  for(int i=0; i < 255; i++)
  {
    fscanf(in, "%s\n", &arr[i]);
    memory[i] = atoi(&arr[i]);
  }
  fclose(in);  
}

void initmem()
{
  for(int a = 0; a < 255; a++)
  {
    printf("DEBUG1: %i\n", a);
    memory[a] = 0;
  }
  savemem();
}

void assemble()
{
  FILE* in;
  FILE* out;

  char* INS = malloc(3);
  char* OP0 = malloc(1);
  char* OP1 = malloc(1);

  printf("Please enter the name of the source (.asm): ");
  char source[20];
  scanf("%s\0", source);

  printf("Please enter the name of the target (.mem): ");
  char target[20];
  scanf("%s\0", target);

  in = fopen(source, "r");
  out = fopen(target, "w+");

  if (in == NULL)
  {
      printf("Sorry, sourcefile does not exist.\n");
      exit(EXIT_FAILURE);
  }

  int op0;
  int op1;

  for(int c = 0; c < 255; c++)
  {
    //INS = 0;
    //OP0 = 0;
    //OP1 = 0;
    fscanf(in, "%s %s %s\n", INS, OP0, OP1);
    printf("%s %s %s\n", INS, OP0, OP1);
    if(strcmp(INS, "nop") == 0)
        {
          fprintf(out, "0\n");
          continue;
        }
    if(strcmp(INS, "loa") == 0) //op0 sind hier die zu ladenden daten
        {
          fprintf(out, "1\n");//op0 is stored in adress c+1
          op0 = atoi(OP0);
          fprintf(out, "%i\n", op0);
          c = c+1;
          continue;
        }
    if(strcmp(INS, "str") == 0)
        {
          fprintf(out, "2\n");
          continue;
        }
    if(strcmp(INS, "jmp") == 0)
        {
          fprintf(out, "3\n"); //op0
          continue;
        }
    if(strcmp(INS, "alu") == 0)
        {
          fprintf(out, "6\n");
          op0 = atoi(OP1);
          fprintf(out, "%i\n", op0);
          fprintf(out, "7\n");
          op1 = atoi(OP0);
          fprintf(out, "%i\n", op1);
          fprintf(out, "4\n");
          c = c + 4;
          continue;
        }
    if(strcmp(INS, "cmp") == 0)
        {
          fprintf(out, "5\n");
          continue;
        }
    if(strcmp(INS, "o0l") == 0) //laedt operatorregister; operatorregister != operator
        {
          fprintf(out, "6\n"); //load op0
          op0 = atoi(OP0);
          if(op0 > 15)
          {
            printf("Operator is invalid! 0-15\n");
            break;
          }
          fprintf(out, "%i\n", op0);
          c = c+1;
          continue;
        }
    if(strcmp(INS, "o1l") == 0)
        {
          fprintf(out, "7\n"); //op1
          op0 = atoi(OP0);
          if(op0 > 15)
          {
            printf("Operator is invalid! 0-15\n");
          }
          fprintf(out, "%i\n", op0);
          c = c+1;
          continue;
        }
    if(strcmp(INS, "hlt") == 0)
        {
          fprintf(out, "255\n");
          continue;
        }
  }
  fclose(in);
  fclose(out);
}
#endif