//21.06.2020
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void initialize()
{
	int a = bandwidth - 1;
	for(a;  a>= 0; a--)
	{
		currentaddress[a] = 0;
	}
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



#endif

/*
int running()
{
	for(int a = 0; a < 64; a++)
	{
		currentaddress[a] = 0;
	}
	currentaddress[] = []
}


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