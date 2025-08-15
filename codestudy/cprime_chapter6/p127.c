/* for_cube .c __使用for循环创建一个立方体*/
#include <stdio.h>
int main (void)
{
    int num ;
    printf("n n cube\n");

    for (num=1; num<=6; num++)
    {
        printf("%5d %5d \n", num, num*num*num);
    }
    return 0;
}

/*
n n cube
    1     1 
    2     8 
    3    27 
    4    64 
    5   125 
    6   216 
*/