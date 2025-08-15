/*
#include <stdio.h>
int main(void)
{
    int i, j, list(10); // 错误：数组声明语法错误，应该是 list[10]
    for (i = 1, i <= 10, i++) // 错误：for 循环条件分隔符错误，应该是 ;
    {
        list[i] = 2*i + 3;
        for (j = 1, j >= i, j++) // 错误：for 循环条件分隔符错误，应该是 ;
            printf("%d", list[j]);
        printf("\n");
    }
}
*/