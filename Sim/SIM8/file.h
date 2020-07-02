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
  initialize();
  savemem();
}
#endif