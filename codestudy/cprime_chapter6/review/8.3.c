#include <stdio.h>
int main(void)
{
    char ch;

    // 1. do-while 循环：先执行循环体，再判断条件
    do 
    {
        // 1.1 读取字符并存入 ch
        scanf("%c", &ch); 
        // 1.2 打印当前字符
        printf("%c", ch); 
    // 2. 条件：ch 不等于 'g' 时继续循环
    } while (ch != 'g'); 
    return 0;
}/*
执行流程（输入 Go west, young man! 时）：
do-while 特点是先执行一次循环体，所以哪怕第一个字符是 'g' 也会先处理。
实际输入时：
先读 'G' 并打印，再判断 ch!='g' → 继续循环
最终打印内容：Go west, young man（遇到 'g' 时，会先打印 'g' 再结束循环 ）
*/

/*
Go west, young man!
Go west, young
*/