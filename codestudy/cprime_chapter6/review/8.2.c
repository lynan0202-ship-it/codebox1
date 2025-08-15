#include <stdio.h>
int main(void)
{
    char ch;

    // 1. 读取第一个字符，存入 ch
    scanf("%c", &ch); 
    // 2. 当 ch 不等于 'g' 时持续循环
    while (ch != 'g') 
    {
        // 2.1 先将 ch 自增（ASCII 码 +1），再打印
        printf("%c", ++ch); 
        // 2.2 读取下一个字符，更新 ch
        scanf("%c", &ch); 
    }
    return 0;
}/*

执行流程（输入 Go west, young man! 时）：
每个字符会先 ++ch（ASCII 码加 1）再打印：
'G'→'H'、'o'→'p'、' '→'!'（因为 ' ' 的 ASCII 是 32，! 是 33 ）、'w'→'x'...
打印内容：Hp!xft!zpvO（遇到 'g' 时停止，'g' 及之后不处理 ）
*/
/*
Go west, young man!
Hp!xftu-!zpvo
*/