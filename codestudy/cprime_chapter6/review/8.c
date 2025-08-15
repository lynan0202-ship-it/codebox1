#include <stdio.h>
int main(void)
{
    char ch;

    // 1. 读取第一个字符，存入 ch
    scanf("%c", &ch);
    // 2. 当 ch 不等于 'g' 时持续循环
    while (ch != 'g') 
    {
        // 2.1 打印当前字符
        printf("%c", ch); 
        // 2.2 读取下一个字符，更新 ch
        scanf("%c", &ch); 
    }
    return 0;
}
/*
执行流程（输入 Go west, young man! 时）：
输入字符依次是 'G' 'o' ' ' 'w' 'e' 's' 't' ',' ' ' 'y' 'o' 'u' 'n' 'g'...
循环逻辑：只要 ch 不是 'g'，就打印并读下一个字符。
打印内容：Gowest, youn（遇到 'g' 时停止，所以不包含 'g' 及之后内容 ）
*/
/*
Go west, young man！
Go west, youn
*/