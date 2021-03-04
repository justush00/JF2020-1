//01.07.2020
#ifndef VARS_H
#define VARS_H

//bin2dec running()
int src0;
int src1;
int destr;

//assemble
int ins[5];
int srcz[4];
int srco[4];
int dest[4];

//decoding
size_t m = 5; //2^5/32 Ops possible
int nop[5] = {0,0,0,0,0};
int load[5] = {1,0,0,0,0};
int store[5] = {0,1,0,0,0};
int jump[5] = {1,1,0,0,0};
int add[5] = {0,0,1,0,0};
int shft[5] = {1,0,1,0,0};
int nand[5] = {0,1,1,0,0};
int not[5] = {1,1,1,0,0};
int xor[5] = {0,0,0,1,0};
int jeq[5] = {1,0,0,1,0};
int jle[5] = {0,1,0,1,0};
int jge[5] = {1,1,0,1,0};
int mtgl[5] = {0,0,1,1,0};
int hlt[5] = {1,1,1,1,1};

//switch case var
int SMA=1; //Stepping Mode
char option = 0;
int globala = 0;

int i = 0;

int n = 0; //placeholder for instructionregister

int operator0 = 0;
int operator1 = 0;

//currentaddress
int currentaddress;
int binary[5] = {0,0,0,0,0};
int insregb[20];


int aluout;
//Memory Vars
int memory[65535]; //memory interface for cpu
//int pmemory[255]; //program memory for controller
int tmemory[10]; //terminal memory for controller


//Register
int instructionregister0;
int dataregister[16]; //0 aluin0

//Flags
bool loadflag; //1: load from memory
bool prewriteflag; //prebuffer to writeflag... refer to quicktest10092020withTMU
bool writeflag; //1: write to memory
bool returnflag; //return from ALU
bool jumpflag; //flag for memoryjumps
bool aluflag; //flag for loops utilizes A=B Output from 74181
bool op0loadflag; //1: load operator0 from memory -> makes full 8 Bit instructions/operators possible
bool op1loadflag;
bool haltflag = 0; //halts CPU, almost like clock in real CPU

//Requests
bool insloadrequest; //request for refreshing instructionregister
bool datloadrequest; //request for loading dataregister
bool adrloadrequest; //

#endif
