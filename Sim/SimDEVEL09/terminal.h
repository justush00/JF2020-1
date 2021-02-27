#ifndef TERMINAL_H
#define TERMINAL_H

int termcount = 0;

void printt()
{
    //newline
    if(tmemory == 255)
    {
        printf("\n");
    }
    else
    {
        printf("%c", tmemory);
    }
    tmemory = 0;
    //terminating character ^C is int(3) char(^C)
}

#endif
