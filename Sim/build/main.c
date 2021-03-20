//01.07.2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "vars.h"   //variables for running the program
#include "graphical.h" //displaying the menu and other screens that are not needed
#include "file.h"   //file I/O
#include "terminal.h"   //terminal I/O of CPU/Computer
#include "controller.h" //memory controller for CPU
#include "functions.h"  //core of CPU and other functions needed for working CPU

int main()
{
	globala = 0;
	do{
		globala = 0;
		//----------------------------------
		//insert readout of dataregister
		//----------------------------------
		if(globala == 0)
		{
			menu();
			//printf("a is %i\n", globala);
		}
		if(globala == 1) //init program
		{
			initialize();
		}
		if(globala == 2) //readout mem
		{
			printf("which adress?: ");
			int in, value;
			scanf("%i", &in);
			if(in > 254)
			{
				printf("Adress does not exist! 0 - 254\n");
				sleep (2);
				break;
			}
			printf("%i\n", memory[in]);
		}
		if(globala == 3) //readout regs
		{
			printregs();
			scanf("%i", &i);
		/*	printf("which adress?: ");
			int in, value;
			scanf("%i", &in);
			if(in > 254)
			{
				printf("Adress does not exist! 0 - 254\n");
				sleep (2);
				break;
			}
			printf("which value?: ");
			scanf("%i", &value);
			memory[in] = value;*/
		}
		if(globala == 4) //save memory state
		{
			savemem();
		}
		if(globala == 5)
		{
			enabledebugrunning();
			/*for(int i=0; i < 20; i++)
  			{
    			printf("%i\n", memory[i]);
  			}*/
  			//running();
		}
		if(globala == 6)
		{
			int start, end;
			printf("start: ");
			scanf("%i", &start);
			printf("\nend: ");
			scanf("%i", &end);
			printf("\n");
			for(int i=start; i < end; i++)
  			{
    			printf("%i\n", memory[i]);
  			}
		}
		if(globala == 7)
		{
			assemble();
		}
		if(globala == 8)
		{
			running();
		}
	}while(globala != 9);

	if(globala == 9)
	{
		currentaddress = 0;
		haltflag = 0;
		main();
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
