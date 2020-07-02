//01.07.2020
#ifndef VARS_H
#define VARS_H
#define bandwidth 8 //channel width

//switch case var
char option = 0;
int globala = 0;

int i = 0;

int operator0 = 0;

//currentaddress
int currentaddress;
bool binary[8];

//Memory Vars
//bool memory64[64][255]; //255 adresses of 64bit memory
//bool memory32[32][255];
//bool memory16[16][255];
int memory[255];
//bool memory4[4][255];

//Register
int instructionregister0;
int dataregister[16];
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
bool writeflag; //1: write to memory
bool returnflag; //return from ALU
bool jumpflag; //flag for memoryjumps
bool haltflag = 1; //halts CPU, almost like clock in real CPU

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