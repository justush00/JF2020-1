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

double pow(double x, double y)
{
	//printf("DEBUG: %i|%i\n", x,y);
	long double b = 2;
	for(int a=2; a <= y; a++)
	{
		b = b*x;
	}
	if(y == 0)
	{
		return 1;
	}
	if(y == 1)
	{
		return x;
	}
	else{
		//printf("DEBUG: %i|%i|%G\n", x,y,b);
		return b;
	}
}

int b2h4(bool h[4])
{
	int x = 0;
	for(int a = 0; a < 4; a++)
	{
		x = x + (pow(2,a) * h[a]);
	}
	return x;
}

long double b2h64(bool h[64], int array[8])  //super ugly but functional
{
	bool arr[4];
	int y = 0;
	int z = 0;
	int c;
	do{
		//printf("DEBUG1: %i\n",y);
		for(int b = 0; b < 4; b++)
		{
			arr[b] = h[z+b];
			c = z+b;
		}
		array[y] = b2h4(&arr[0]);

		y = y+1;
		z = z + 4;
	}while(z < 64);
}

int running()
{
	cls();
	do{
		for(i = 0; i < 8; i++) //reset binary array
			{
				binary[i] = 0;
			}
		//is current operation a load data operation?
		if(returnflag == 1  && loadflag == 1)
		{
			printf("ERROR! Trying to load from ALU and RAM.\n");
			break;
			}
		else if(returnflag == 1)
		{
			dataregister[operator0] = aluout;//result of alu operation
			returnflag = 0;
		}
		if(loadflag == 1)
		{
			/*
			else{*/
			//datloadrequest
			datloadrequest = 1;
			dataregister[operator0] = memory[currentaddress]; //only 4 bits of operator 0 used
			//printf("Data Loaded!\n");
			datloadrequest = 0;
			loadflag = 0;

		}
		else if(loadflag == 0)
		{
			if(op0loadflag == 1 && op1loadflag == 1)
			{
				printf("ERROR! Trying to load two operators at once.\n");
				break;
			}
			else if(op0loadflag == 1)
			{
				operator0 = memory[currentaddress];
				printf("operator0 ist geladen\n");
				op0loadflag = 0;
			}
			else if(op1loadflag == 1)
			{
				operator1 = memory[currentaddress];
				printf("operator1 ist geladen\n");
				op1loadflag = 0;
			}
			else{
				if(memory[currentaddress] != instructionregister0)
				{
					insloadrequest = 1;
					instructionregister0 = memory[currentaddress];
					insloadrequest = 0;
				}
				//convert insreg to binary to decode flags etc.
				//binary conversion
				n = instructionregister0;
				//printf("DEBUG0: %i DEBUG1: %i\n", n, instructionregister0);
				for(i = 0; n > 0; i++)
				{
					binary[i] = n % 2;
					n = n / 2;
					//printf("DEBUG: %i\n", binary[i]);
				}
				//let the instruction decoding begin!!!
				//sleep(2);
				//nop
				if(binary[7] == 0 && binary[6] == 0 && binary[5] == 0 && binary[4] == 0 && binary[3] == 0 && binary[2] == 0 && binary[1] == 0 && binary[0] == 0)//nop 0
				{
					//adrloadrequest
				}
				//load
				else if(binary[7] == 0 && binary[6] == 0 && binary[5] == 0 && binary[4] == 0  && binary[3] == 0 && binary[2] == 0 && binary[1] == 0 && binary[0] == 1)//load 1
				{
					//check operators
					//which register should be loaded to?
					//activate loadflag, takes two CPU cycles -> don't refresh INSREG
					loadflag = 1;
					//adrloadrequest
				}
				//store
				else if(binary[7] == 0 && binary[6] == 0 && binary[5] == 0 && binary[4] == 0 && binary[3] == 0 && binary[2] == 0 && binary[1] == 1 && binary[0] == 0)//store 2
				{
					//check operators
					//which register should be loaded from?
					//activate writeflag, takes two CPU cycles -> don't refresh INSREG

				}
				//jump
				else if(binary[7] == 0 && binary[6] == 0 && binary[5] == 0 && binary[4] == 0 && binary[3] == 0 && binary[2] == 0 && binary[1] == 1 && binary[0] == 1)//jmp 3
				{
					//check operators
					//activate jumpflag
					jumpflag = 1;
				}
				//NAND
				else if(binary[7] == 0 && binary[6] == 0 && binary[5] == 0 && binary[4] == 0 && binary[3] == 0 && binary[2] == 1 && binary[1] == 0 && binary[0] == 0)//alu  4
				{
					int a = dataregister[0];
					bool ba[8]; //binary a
					for(i = 0; i<8; i++)
					{
						ba[i] = 0;
					}
					for(i = 0; a > 0; i++)
					{
						ba[i] = a % 2;
						a = a / 2;
					}
					for(i = 7; i >= 0; i--)
					{
						printf("%i", ba[i]);
					}
					printf("\n");
					int b = dataregister[operator1];
					bool bb[8]; //binary b
					for(i = 0; i<8; i++)
					{
						bb[i] = 0;
					}
					for(i = 0; b > 0; i++)
					{
						bb[i] = b % 2;
						b = b / 2;
						}
					for(i = 7; i >= 0; i--)
					{
						printf("%i", bb[i]);
					}
					printf("\n_________\n");
					bool br[8]; // binary result
					for(i = 0; i < 8; i++)
					{
						br[i] = (!ba[i]) && (!bb[i]);
					}
					for(i = 7; i >= 0; i--)
					{
						printf("%i", br[i]);
					}
					printf("\n");
					int r = 1 * br[0] + 2 * br[1] + 4 * br[2] + 8 * br[3] + 16 * br[4] + 32 * br[5] + 64 * br[6] + 128 * br[7];
					printf("%i\n",r);
					aluout = r;
					//check operators for specific ALU instructions
					returnflag = 1;
				}
				//cmp
				else if(binary[7] == 0 && binary[6] == 0 && binary[5] == 0 && binary[4] == 0 && binary[3] == 0 && binary[2] == 1 && binary[1] == 0 && binary[0] == 1)//cmp  5
				{
					//check operators for specific ALU instructions
					if(dataregister[0] == dataregister[operator0])//aluin0 = aluin1
					{
						aluflag = 1;
					}
				}
				//load zielregister fuer: alu, load
				else if(binary[7] == 0 && binary[6] == 0 && binary[5] == 0 && binary[4] == 0 && binary[3] == 0 && binary[2] == 1 && binary[1] == 1 && binary[0] == 0)//load op0 6
				{
					op0loadflag = 1; //zielregister
				}
				//load quellregister fuer: alu, store, jmp
				else if(binary[7] == 0 && binary[6] == 0 && binary[5] == 0 && binary[4] == 0 && binary[3] == 0 && binary[2] == 1 && binary[1] == 1 && binary[0] == 1)//load op1 7
				{
					op1loadflag = 1; //quellregister
				}
				//halt
				else if(binary[7] == 1 && binary[6] == 1 && binary[5] == 1 && binary[4] == 1 && binary[3] == 1 && binary[2] == 1 && binary[1] == 1 && binary[0] == 1)//no further operations 255
				{
					//halts the cpu
					haltflag = 1;
				}
			}
		}


		//if(aluflag)
		//Current Processing of Memory is finished, jump/change to next one
		//adrloadrequest
		if(insloadrequest == 0 || datloadrequest == 0)
		{
			/*printf("Adressinhalt: %i\n", memory[currentaddress]);
			printf("Register0: %i, Register1: %i, Register2: %i\n", dataregister[0], dataregister[1], dataregister[2]);
			printf("HALT: %i LOAD: %i OP0: %i OP1: %i\n", haltflag, loadflag, op0loadflag, op1loadflag);
			printf("operator0: %i operator1: %i \n\n", operator0, operator1);
			*/
			interfacerunning();
			if(SMA == 1)
			{
				printf("Stepping Mode active, press 1 and enter to continue program execution... ");
				int cont = 0;
				if(cont != 1)
				{
					scanf("%i", &cont);
				}
				else if(cont == 1)
				{
					haltflag = 1;
				}
			}
			if(SMA == 2)
			{
				sleep(1);
			}

				if(haltflag == 0)
				{
					if(jumpflag == 1 || aluflag == 1)
					{
						currentaddress = dataregister[15];
						aluflag = 0;
					}
					else if(jumpflag == 0 && aluflag == 0)
					{
						currentaddress = currentaddress + 1;
					}
				}

		}
	}while(haltflag != 1);
	cls();
	printf("EXECUTION FINISHED!\n");
	printf("press any key and enter to return to menu...");
	scanf("%i", &haltflag);

}


#endif

/*



int b2h8(bool h[8])
{
	int x = 0;
	for(int a = 0; a < 8; a++)
	{
		x = x + (pow(2,a) * h[a]);
	}
	return x;
}

int b2h16(bool h[16])
{
	int x = 0;
	for(int a = 0; a < 16; a++)
	{
		x = x + (pow(2,a) * h[a]);
	}
	return x;
}

int b2h32(bool h[32])
{
	int x = 0;
	for(int a = 0; a < 32; a++)
	{
		x = x + (pow(2,a) * h[a]);
	}
	return x;
}
*/
