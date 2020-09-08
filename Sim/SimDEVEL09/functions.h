//02.07.2020
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void initialize()
{
	currentaddress = 0;
	haltflag = 0; //halt cpu
	loadflag = 0; //load data from mem
	writeflag = 0; //write data to mem
	returnflag = 0; //data return from alu
	jumpflag = 0; //jump
	aluflag = 0; // maybe compare... coming later
	loadmem();
}

int running()
{
	do{
		//1. Daten / ALU laden, wenn vorheriger Befehl dies verlangt (Flag)
		if(loadflag == 1)
		{
			dataregister[operator0] = memory[currentaddress];
			//nach erfolgreichem Laden, muessen die Flags/?Instruktionsregister zurueckgesetzt werden
		}
		loadflag == 0;

		//Instruktionsregister laden
		instructionregister0 = memory[currentaddress];
		for(n = 0; n < 16; n++)
	  {
	    insregb[n] = 0;
		}
		for(n = 0; instructionregister0 > 0; n++)
	  {
	    insregb[n] = instructionregister0 % 2;
	    instructionregister0 = instructionregister0 / 2;
	  }

		//Instruction:
		binary[0] = insregb[0];
		binary[1] = insregb[1];
		binary[2] = insregb[2];
		binary[3] = insregb[3];
		//befehl verstehen/decoden (ins op0 op1 dest)
		/*
		ins: Instruktion
		op0: operator0; Instruktionsabhaengig
		op1: operator1; Instruktionsabhaengig
		dest: Zielregister
		*/

		if(! memcmp(binary, nop, m * sizeof(int)))
		{
			printf("nop executed!\n"); //nop
		}
		if(! memcmp(binary, load, m * sizeof(int)))
		{
			printf("load executed!\n"); //nop
		}
		if(! memcmp(binary, store, m * sizeof(int)))
		{
			printf("store executed!\n"); //nop
			writeflag = 1;
		}
		if(! memcmp(binary, jump, m * sizeof(int)))
		{
			printf("jump executed!\n"); //nop
			jumpflag = 1;
		}
		if(! memcmp(binary, nand, m * sizeof(int)))
		{
			printf("nand executed!\n"); //nop
			aluflag = 1;
		}
		if(! memcmp(binary, hlt, m * sizeof(int)))
		{
			printf("halted!\n"); //nop
			haltflag = 1;
		}
		//naechste Adresse laden
		if(jumpflag == 1)
		{
			currentaddress = dataregister[15];
		}
		if(jumpflag == 0)
		{
			currentaddress = currentaddress + 1;
		}
	}while(haltflag != 1);
}




#endif
