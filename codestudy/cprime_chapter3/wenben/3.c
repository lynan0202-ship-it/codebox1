/* bases.c -- 以十进制、八进制、十六进制打印十进制数 100 */
#include <stdio.h>
int main(void)
{
    int x = 100;

    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);/*printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);可以显示数据类型标识前缀*/


    return 0;
}