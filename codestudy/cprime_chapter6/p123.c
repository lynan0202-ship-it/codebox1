/* * t_and _f.c -- 中的真值和假值*/
#include <stdio.h>
int main (void )
{
    int ture_val,false_val;

    ture_val=(10>2);
    false_val=(10==2);
    printf("The number of(10>2) is %d and the number of (10==2) is %d", ture_val,false_val);

    return 0;

}
/*
The number of(10>2) is 1 and the number of (10==2) is 0
*/