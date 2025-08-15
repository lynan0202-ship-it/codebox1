// when.c -- 何时推出循环
#include <stdio.h>
int main (void)
{
    int n = 5;

    while (n <7)
    {
        printf("n = %d\n",n);
        n++;
        printf("Now loop has finished.\n");

    }
    printf("The loop has finished .\n");

    return 0;

    
}
/*
n = 5
Now loop has finished.
n = 6
Now loop has finished.
The loop has finished .
*/