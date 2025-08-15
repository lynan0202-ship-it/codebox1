/* squares.c -- 计算1~20的平方 */
#include <stdio.h>
int main (void)
{
    int num = 1;

    while (num<21)
    {
        printf("%4d %6d\n",num,num*num);
        num=num+1;
    }
    return 0;

}
/*
   1      1
   2      4
   3      9
   4     16
   5     25
   6     36
   7     49
   8     64
   9     81
  10    100
  11    121
  12    144
  13    169
  14    196
  15    225
  16    256
  17    289
  18    324
  19    361
  20    400
*/