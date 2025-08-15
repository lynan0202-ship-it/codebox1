#include <stdio.h>
#define ender 103
int main(void)
{
    int n = 96;
    // n++ < TEN ：先判断再自增，循环执行时 n 从 0 开始，条件成立的 n 值是 0~9（共 10 次 ）
    while (n++ < ender)  
    {
        // 第一次循环 n 是 1（因为 n++ 先判断 0<10，再自增为 1 ），最后一次 n 是 10 时判断 10<10 不成立，实际循环里 n 输出 1~10 
        printf("%c", n);  
    }
    printf("\n");
    return 0;
}
/*
abcdefg
*/