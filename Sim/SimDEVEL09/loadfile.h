#ifndef EXTERNAL_IN_FILE_H
#define EXTERNAL_IN_FILE_H

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

    printf("%s\n", string);

  	fclose(file0);
}

#endif