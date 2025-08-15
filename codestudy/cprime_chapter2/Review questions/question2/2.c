#include <stdio.h>

int main(void) 
{
    // 题目 4 的逻辑：打印一年有多少周
    int s;
    s = 56;
    printf("There are %d weeks in a year.\n", s);

    // 题目 5 的逻辑：各种 printf 输出示例
    // a
    printf("Baa Baa Black Sheep. ");
    printf("Have you any wool?\n");

    // b
    printf("Begone! %creature of lard!\n");

    // c
    printf("What?\nNo fish?\n");

    // d（变量名统一，这里用 num 更直观，也可以保留 nm ，看需求）
    int num;
    num = 2;
    printf("%d + %d = %d\n", num, num, num + num);

    return 0;
}