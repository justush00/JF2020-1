//02.07.2020
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void initialize()
{
	currentaddress = 0;
	haltflag = 0;
	loadflag = 0;
	writeflag = 0;
	returnflag = 0;
	jumpflag = 0;
	aluflag = 0;
	loadmem();
}

int running()
{
	//1. Daten / ALU laden, wenn vorheriger Befehl dies verlangt (Flag)
	if(loadflag == 1)
	{
		dataregister[operator0] = memory[currentaddress];
		//nach erfolgreichem Laden, muessen die Flags/?Instruktionsregister zurueckgesetzt werden
		loadflag == 0;
	}

	//Instruktionsregister laden
	instructionregister0 = memory[currentaddress];

	//befehl verstehen/decoden (ins op0 op1 dest)
	/*
	ins: Instruktion
	op0: operator0; Instruktionsabhaengig
	op1: operator1; Instruktionsabhaengig
	dest: Zielregister
	*/
	size_t n = 4;
	int nop[4] = {0,0,0,0};
	int load[4] = {0,0,0,1};
	int store[4] = {0,0,1,0};
	int jump[4] = {0,0,1,1};
	int nand[4] = {0,1,0,0};
	if(! memcmp(binary, nop, n * sizeof(int)))
	{
		printf("nop executed!\n"); //nop
		scanf("%i", &i);
	}
	if(! memcmp(binary, load, n * sizeof(int)))
	{
		printf("load executed!\n"); //nop
		scanf("%i", &i);
	}
	if(! memcmp(binary, store, n * sizeof(int)))
	{
		printf("store executed!\n"); //nop
		scanf("%i", &i);
	}
	if(! memcmp(binary, jump, n * sizeof(int)))
	{
		printf("jump executed!\n"); //nop
		scanf("%i", &i);
	}
	if(! memcmp(binary, nand, n * sizeof(int)))
	{
		printf("nand executed!\n"); //nop
		scanf("%i", &i);
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
}



#endif
