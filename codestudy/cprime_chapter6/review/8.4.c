#include <stdio.h>
int main(void)
{
    char ch;

    // 1. 读取第一个字符
    scanf("%c", &ch); 
    // 2. for 循环逻辑：
    //    - 初始化 ch='s'（覆盖了之前读的字符，这里要注意！）
    //    - 条件：ch != 'g'
    //    - 每次循环：读新字符到 ch
    for (ch = 's'; ch != 'g'; scanf("%c", &ch)) 
    {
        // 2.1 打印当前 ch 的值
        printf("%c", ch); 
    }
    return 0;
}
/*
执行逻辑问题：
for 循环初始化 ch='s'，会覆盖用户输入的第一个字符。
假设输入是 Go west...，实际程序里 ch 被强制设为 's'，然后判断 ch!='g' → 打印 's'，接着读下一个字符...
（题目里代码不完整，若按推测逻辑，重点是理解 for 循环的初始化会覆盖外部输入 ）
*/
/*
Go west, young man!
so west, youn
*/