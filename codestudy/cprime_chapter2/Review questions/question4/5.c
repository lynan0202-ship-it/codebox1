#include <stdio.h>

void br (void);
void rc (void);

int main(void) 
{
    br(); 
    printf(",");
    rc();
    printf("\n");
    rc();
    printf("\n");
    br();

    return 0;
}

void br (void)
{
    printf("Brazil,Russia");
}


void rc (void)
{
    printf("India,China");
   
}