//01.07.2020
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void initialize()
{
	printf("DEBUG0\n");
	currentaddress = 0;
	for(int a = 0; a < 255; a++)
	{
		printf("DEBUG1: %i\n", a);
		memory[a] = 0;
	}
	loadflag = 0;
	writeflag = 0;
	returnflag = 0;
	jumpflag = 0;
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
		if(loadflag == 1)
		{
			//datloadrequest
			datloadrequest = 1;
			dataregister[operator0] = memory[currentaddress]; //only 4 bits of operator 0 used
			//printf("Data Loaded!\n");
			loadflag = 0;
			datloadrequest = 0;
		}
		else if(loadflag == 0)
		{
			if(memory[currentaddress] != instructionregister0)
			{
				insloadrequest = 1;
				instructionregister0 = memory[currentaddress];
				insloadrequest = 0;
			}
			//convert insreg to binary to decode flags etc.
			//binary conversion
			operator0 = instructionregister0;
			//printf("DEBUG0: %i DEBUG1: %i\n", operator0, instructionregister0);
			for(i = 0; operator0 > 0; i++)
			{
				binary[i] = operator0 % 2;
				operator0 = operator0 / 2;
				//printf("%i: %i\n", i, binary[i]);
			}
			//let the instruction decoding begin!!!
			//convert binary[3] - binary[7] back to decimal for ease of operator checking
			//^ can be changed later... for now just to keep it simple(ish) 
			operator0 =  binary[3] * 1 + binary[4] * 2 + binary[5] * 4 + binary[6] * 8 + binary[7] * 16;  
			//sleep(2);
			if(binary[2] == 0 && binary[1] == 0 && binary[0] == 0)//nop 0
			{
				//printf("doing nothing!\n");
				//adrloadrequest
			}
			if(binary[2] == 0 && binary[1] == 0 && binary[0] == 1)//load 1
			{
				//check operators
				//which register should be loaded to?
				//activate loadflag, takes two CPU cycles -> don't refresh INSREG
				loadflag = 1;
				if(operator0 == 0)//error detection... otherwise results in core dump
				{
					haltflag = 0;
				}
				//adrloadrequest
			}
			if(binary[2] == 0 && binary[1] == 1 && binary[0] == 0)//store 2
			{
				//check operators
				//which register should be loaded from?
				//activate writeflag, takes two CPU cycles -> don't refresh INSREG

			}
			if(binary[2] == 0 && binary[1] == 1 && binary[0] == 1)//jmp 3
			{
				//check operators
				//activate jumpflag
				jumpflag = 1;
			}
			if(binary[2] == 1 && binary[1] == 0 && binary[0] == 0)//alu  4
			{
				//check operators for specific ALU instructions
				returnflag = 1;
			}
			if(binary[2] == 1 && binary[1] == 1 && binary[0] == 1)//no further operations 7
			{
				//halts the cpu
				haltflag = 0;
			}
		}	
		//Current Processing of Memory is finished, jump/change to next one 
		//adrloadrequest
		if(insloadrequest == 0 || datloadrequest == 0)
		{
			interfacerunning();
			printf("Stepping Mode active, press 1 and enter to continue program execution... ");
			int cont = 0;
			do{
				scanf("%i", &cont);
			}while(cont == 0);
			//sleep(1);
				if(haltflag == 1)
				{
					if(jumpflag == 1)
					{
						currentaddress = dataregister[15];
					}
					if(jumpflag == 0)
					{
						currentaddress = currentaddress + 1;
					}
				}

		}
	}while(haltflag != 0);
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