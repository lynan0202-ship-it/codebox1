/* shoes1.c -- 把鞋码的尺寸转换为英寸*/
#include <stdio.h>
#define ADJUST 7.31
int main (void)
{
    const double SCALE = 0.333;//const bianliang
    double shoe, foot;

    shoe=9.0;
    foot =SCALE*shoe+ADJUST;
    printf("Shoe size (men's)    foot length\n");
    printf("%10.1f %15.2f inches\n",shoe,foot);

    return 0;

}
/*
Shoe size (men's)    foot length
       9.0           10.31 inches
*/