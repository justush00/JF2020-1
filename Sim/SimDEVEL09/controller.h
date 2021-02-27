#ifndef CONTROLLER_H
#define CONTROLLER_H

bool ram = 0; // ram = 0 pram, ram = 1 tram
int tmemcount = 0;

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
        tmemory = dataregister[src0];
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

#endif
