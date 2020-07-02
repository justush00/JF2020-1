//21.06.2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "vars.h"
#include "functions.h"
#include "graphical.h"
#include "file.h"

int main()
{ 
	globala = 0;
	do{
		globala = 0;
		if(globala == 0)
		{
			menu();
			//printf("a is %i\n", globala);
		}
		if(globala == 1)
		{
			bool test[64];
			datain(&test[0]);
			printf("%d", &test[2]);
			/*for(int a = 0; a < 64; a++)
 			{
 				printf("%d", &test[0]);
 			}*/
 			int a;
 			scanf("%i", a);
		}
		if(globala == 2)
		{
			initmem();
		}
		if(globala == 3)
		{
			initialize();
		}
		if(globala == 4)
		{
			interfacerunning();
			sleep(2);
		}
	}while(globala != 5);

	if(globala == 5)
	{
		goodbye();
	}

}

/*{
	addressregister[] = //0 im simulator nur 8 bit Speicherbandweite
	memory64[][];
	/*Ablauf:
		1. Adresse wird geladen
		2. pre/post insreg: insloadrequest ! except data handling: pre post datreg:datloadrequest !
		(3. insregbusystate bzw dataregisterbusystate
		(4. decoderbusystate
		(5. ALU - Befehl : alubusystate dataregisterbusystate
		(6. alle states abgearbeitet: adrloadrequest
		3. Clockcycle/trigger
		4. ADRLOADREQUEST

	


	*/


/*
	bool mem[64];
	for(int a = 0; a < 64; a++)
	{
		mem[a] = 1;
	}
	printf("Entry is: %d %d %d %d\n", mem[0], mem[1], mem[2], mem[3]);
	int ar[8];
	b2h64(&mem[0], &ar[0]);
	printf("HEXCODE is: %X%X%X%X%X%X%X%X\n", ar[0], ar[1], ar[2], ar[3], ar[4], ar[5], ar[6], ar[7]);
*/

