#include <stdio.h>

int main()
{
    int size = 70;
    _Bool arr0[size];
    _Bool arr1[size];
    int n = 0;
    int c = 0;
    int divres = 0;
    int x = 0;
    
    //init arr0 & arr1
    for(c = 0; c < size; c++)
    {
        arr0[c] = 0;
        arr1[c] = 0;
    }
    

    
    do{
        divres = n / 2;
    
        //copy BITSTRING0 to BS1
        for(x=0; x < 32; x++)
        {
            arr1[x] = arr0[x];
        }        
    
        //modify BS1
        arr1[divres] = 1;
        //LSHIFT BIT STRING 0 by 1
        
    
        //get BS1 into BS0
        for(x=0; x < n; x++)
        {
            arr0[n+1+x] = arr1[x];
        }

    
        n = 2*n + 1;
    }while( n < size/2 );
    
    for(c = 0; c < size; c++)
    {
        printf("%i", arr0[c]);
    }
    
}

//5. Ordnung RRLRRLLRRRLLRLLRRRLRRLLLRRLLRLL
//6. Ordnung RRLRRLLRRRLLRLLRRRLRRLLLRRLLRLLRRRLRRLLRRRLLRLLLRRLRRLLLRRLLRLLR
