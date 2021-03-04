#ifndef CONTROLLER_H
#define CONTROLLER_H

bool ram = 0; // ram = 0 pram, ram = 1 tram

void toggle()
{
    ram = !ram;
}

void memwrite()
{
    if(ram == 0)
    {
        //expand for nonlinear storing of cpu data -> store with jump
        //more modes for storing
        memory[dataregister[15]] = dataregister[src0];
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
        //more modes for loading whether from current adress or from absolute memory address
        dataregister[destr] = memory[currentaddress];
        //dataregister[destr] = memory[dataregister[15]];
    }
    if(ram == 1)
    {
        scant();
    }
}

#endif
