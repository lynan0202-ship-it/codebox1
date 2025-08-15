#include <stdio.h>
int main (void)
{
    int num = 1;
    int total=0;
    while (num <= 100)
    {
        total=total+num;
        num=num+1;
        /* code */
    }
    printf("total= %d\n",total);
    return 0 ;

}
/*
total= 5050
*/