#ifndef TERMINAL_H
#define TERMINAL_H

int termcount = 0;


void printt()
{
    //newline
    if(tmemory[0] == 255) //real newline here
    {
        printf("\n");
    }
    else
    {
        printf("%c", tmemory[0]);
    }
    tmemory[0] = 0;
    //terminating character ^C is int(3) char(^C)
}

void scant()
{
    //printf("debug1");
    //flush input and rework this ugly piece down here
    //scanf("%c", &tmemory[0]);
    scanf("%c", &tmemory[0]);
    dataregister[destr] = tmemory[termcount];
    for(termcount; termcount < 8; termcount++)
    {
        tmemory[termcount] = tmemory[termcount + 1];
    }
    termcount = 0;
}

#endif
