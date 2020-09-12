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
		printf("\n%i: ", currentaddress);
		if(loadflag == 1)
		{
			dataregister[destr] = memory[currentaddress];
			//nach erfolgreichem Laden, muessen die Flags/?Instruktionsregister zurueckgesetzt werden
			loadflag = 0;
		}
		else if(aluflag == 1)
		{
			dataregister[destr] = aluout;
			aluflag = 0;
		}
		else if(writeflag == 1)
		{
			memory[currentaddress] = dataregister[src0];
			writeflag = 0;
			prewriteflag = 0;
		}
		else //if there is no instruction to load or write anything...
		{
			//Instruktionsregister laden
			instructionregister0 = memory[currentaddress];
			src0 = 0;
			src1 = 0;
			destr = 0;
			for(n = 0; n < 16; n++)
		  {
		    insregb[n] = 0;
			}
			for(n = 0; instructionregister0 > 0; n++)
		  {
		    insregb[n] = instructionregister0 % 2;
		    instructionregister0 = instructionregister0 / 2;
		  }

			//src0 conversion bin to dec
		  for(n = 4; n < 8; n++)
		  {
		    src0 = src0 + (insregb[n] * powe(2, n-4));
		  }
			//src1 bin to dec
			for(n = 8; n < 12; n++)
		  {
		    src1 = src1 + (insregb[n] * powe(2, n-8));
		  }
			//dest bin to dec
			for(n = 12; n < 16; n++)
		  {
		    destr = destr + (insregb[n] * powe(2, n-12));
		  }

			//Instruction:
			binary[0] = insregb[0];
			binary[1] = insregb[1];
			binary[2] = insregb[2];
			binary[3] = insregb[3];
			//befehl verstehen/decoden (ins src0 src1 dest)
			/*
			ins: Instruktion
			src0: operator0; Instruktionsabhaengig
			src1: operator1; Instruktionsabhaengig
			dest: Zielregister
			*/

			if(! memcmp(binary, nop, m * sizeof(int)))
			{
				printf("nop executed!\n"); //nop
				//printf("DEBIG: %i %i %i\n", src0, src1, destr);
			}
			if(! memcmp(binary, load, m * sizeof(int)))
			{
				loadflag = 1;
				printf("load executed!\n"); //nop
			}
			if(! memcmp(binary, store, m * sizeof(int)))
			{
				printf("store executed!\n"); //nop
				prewriteflag = 1;
			}
			if(! memcmp(binary, jump, m * sizeof(int)))
			{
				printf("jump executed!\n"); //nop
				jumpflag = 1;
			}
			if(! memcmp(binary, nand, m * sizeof(int)))
			{
				printf("add executed!\n"); //nop
				int r = dataregister[src0] + dataregister[src1];
				aluout = r;
				aluflag = 1;
			}
			if(! memcmp(binary, hlt, m * sizeof(int)))
			{
				printf("halted!\n"); //nop
				haltflag = 1;
			}

			/*
			Another Instruction like CMPJMP
			*/

		}




		//naechste Adresse laden
		if(jumpflag == 1)
		{
			if(prewriteflag == 1)
			{
				writeflag = 1;
			}
			currentaddress = dataregister[15];
		}
		if(jumpflag == 0)
		{
			currentaddress = currentaddress + 1;
			if(prewriteflag == 1)
			{
				writeflag = 1;
			}
			if(currentaddress == 256)
			{
				haltflag = 1;
			}
		}
	}while(haltflag != 1);
}




#endif
