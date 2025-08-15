#include <stdio.h>
int main(void)
{
    int i = 0;
    while (++i < 4) // i 从 1 开始，条件为真时执行循环体
        printf("Hi! ");
    do
        printf("Bye! ");
    while (i++ < 8); // 先执行循环体，再判断条件
    return 0;
}
/*
Hi! Hi! Hi! Bye! Bye! Bye! Bye! Bye! 
*/