//01.07.2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "vars.h"
#include "graphical.h"
#include "file.h"
#include "functions.h"

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

			/*printf("DR0:%i\n", dataregister[0]);
			printf("DR1:%i\n", dataregister[1]);
			printf("DR2:%i\n", dataregister[2]);
			printf("DR3:%i\n", dataregister[3]);
			printf("DR4:%i\n", dataregister[4]);
			printf("DR5:%i\n", dataregister[5]);
			printf("DR6:%i\n", dataregister[6]);
			printf("DR7:%i\n", dataregister[7]);
			printf("DR8:%i\n", dataregister[8]);
			printf("DR9:%i\n", dataregister[9]);
			printf("DR10:%i\n", dataregister[10]);
			printf("DR11:%i\n", dataregister[11]);
			printf("DR12:%i\n", dataregister[12]);
			printf("DR13:%i\n", dataregister[13]);
			printf("DR14:%i\n", dataregister[14]);
			printf("DR15:%i\n", dataregister[15]);
			scanf("%i", &i);
			*///initmem();
		}
		if(globala == 3) //readout regs
		{
			printf("DR0:%i\n", dataregister[0]);
			printf("DR1:%i\n", dataregister[1]);
			printf("DR2:%i\n", dataregister[2]);
			printf("DR3:%i\n", dataregister[3]);
			printf("DR4:%i\n", dataregister[4]);
			printf("DR5:%i\n", dataregister[5]);
			printf("DR6:%i\n", dataregister[6]);
			printf("DR7:%i\n", dataregister[7]);
			printf("DR8:%i\n", dataregister[8]);
			printf("DR9:%i\n", dataregister[9]);
			printf("DR10:%i\n", dataregister[10]);
			printf("DR11:%i\n", dataregister[11]);
			printf("DR12:%i\n", dataregister[12]);
			printf("DR13:%i\n", dataregister[13]);
			printf("DR14:%i\n", dataregister[14]);
			printf("DR15:%i\n", dataregister[15]);
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
			loadmem();
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
