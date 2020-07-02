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
  	//char *line = getenv("LINECOUNT");
  	//int lc = strtol(line, &null,10) * 7;
 	//printf("%i\n", lc);
  	//char *pathtoin = getenv("INTXT");
  	bool string[64];
  	FILE *file0;
  	//FILE *file1;
  	file0 = fopen("/home/justus/MEGAsync/Projects/JF2020-1/Sim/datain", "r"); //edit this to your develop-directory/in.txt
  	//file1 = fopen("/home/dev/Projects/smlCPUsimulator/out.txt", "w");

 	fscanf(file0, "%s", string);  // %c: einzelnes Zeichen %s: Zeichenkette
 	printf("File scanned!\n");
    // String muss mit Nullbyte abgeschlossen sein
 	printf("%s\nDEBUG:\n", &string);
    //string[64] = '\0';
 	for(int a = 0; a < 64; a++)
 	{
 		returrn[a] = string[a];
 		printf("%d", &returrn[a]);
 	}
 	sleep(5);
  	fclose(file0);
}

void initmem()
{
	FILE *file;
	file = fopen("/home/justus/MEGAsync/Projects/JF2020-1/Sim/one.mem", "w");
	if (file == NULL)
	{
    	printf("Sorry, file does not exist.\n");
    	exit(EXIT_FAILURE);
	}	
	printf("File open");
	for(int i=0; i < 16320; i++)
	{
		fprintf(file, "0");	
	}	
	fclose(file);
	printf("Memory File Initialized!\n");
	sleep(5);
}

#endif