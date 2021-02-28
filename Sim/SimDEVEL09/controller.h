#ifndef CONTROLLER_H
#define CONTROLLER_H

bool ram = 0; // ram = 0 pram, ram = 1 tram
//int tmemcount = 0;

void toggle()
{
    ram = !ram;
}

void memwrite()
{
    if(ram == 0)
    {
        memory[currentaddress] = dataregister[src0];
    }
    if(ram == 1)
    {
        tmemory[0] = dataregister[src0];
       /* if(tmemcount >= 254)
        {
            tmemcount = 0;
        }
        else
        {
            tmemcount++;
        }*/
    }
}

void memread()
{
    if(ram == 0)
    {
        dataregister[destr] = memory[currentaddress];
    }
    if(ram == 1)
    {
        scant();
    }
}

#endif
