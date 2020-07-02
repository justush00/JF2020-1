
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main(void)
{
	bool returrn[64];
  	bool string[64];
  	FILE *file0;
  	//FILE *file1;
  	file0 = fopen("/home/justus/MEGAsync/Projects/JF2020-1/Sim/datain", "r"); //edit this to your develop-directory/in.txt
  	//file1 = fopen("/home/dev/Projects/smlCPUsimulator/out.txt", "w");

 	fscanf(file0, "%c", &string);  // %c: einzelnes Zeichen %s: Zeichenkette
 	printf("File scanned!\n");
    // String muss mit Nullbyte abgeschlossen sein
 	printf("%c\nDEBUG:\n", &string[0]);
    //string[64] = '\0';
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
 	printf("%c\nDEBUG:\n", string[2]);
    //string[64] = '\0';
 	//[] = string [];
 	//printf("%d", &returrn);

 	sleep(5);
  	fclose(file0);
}