//01.07.2020
#ifndef VARS_H
#define VARS_H
//#define bandwidth 8 //channel width

//bin2dec running()
int src0;
int src1;
int destr;

//assemble
int ins[4];
int srcz[4];
int srco[4];
int dest[4];

//decoding
size_t m = 4;
int nop[4] = {0,0,0,0};
int load[4] = {1,0,0,0};
int store[4] = {0,1,0,0};
int jump[4] = {1,1,0,0};
int nand[4] = {0,0,1,0};
int hlt[4] = {1,1,1,1};

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
int binary[4] = {0,0,0,0};
int insregb[16];


int aluout;
//Memory Vars
//bool memory64[64][255]; //255 adresses of 64bit memory
//bool memory32[32][255];
//bool memory16[16][255];
int memory[255];
//bool memory4[4][255];

//Register
int instructionregister0;
int dataregister[16]; //0 alulin0
/*bool dataregister0[64]; //aluin0
bool dataregister1[64];
bool dataregister2[64];
bool dataregister3[64];
bool dataregister4[64];
bool dataregister5[64];
bool dataregister6[64];
bool dataregister7[64];
bool dataregister8[64];
bool dataregister9[64];
bool dataregister10[64];
bool dataregister11[64];
bool dataregister12[64];
bool dataregister13[64];
bool dataregister14[64];
bool dataregister15[64]; //adressreturn
*/
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

//Busystates
//bool alubusystate; //alu is busy //not useful: alu cannot be "looked into"
//bool dataregisterbusystate; //loading data// not useful: additional circuitry slows down complete machine
//bool insregisterbusystate; //refreshing instruction register
//bool decoderbusystate; //decoding instruction



#endif
