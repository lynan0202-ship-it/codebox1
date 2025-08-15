#include <stdio.h>

void br (void);
void rc (void);

int main(void) 
{    int i;
    char ch;

    for (i=0,ch='A'; i<4; i++,ch+=2*i)
    {
        printf("%c",ch);
    }
    
    return 0;
}
/*
ACGM
*/