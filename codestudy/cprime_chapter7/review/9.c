/*
9. 分析输入对应的程序输出
要点：根据输入字符 q、c、h、b，结合 continue、break、goto 等语句对流程的影响，确定程序打印内容。
知识点：while 循环、getchar 输入、continue（跳过本次循环剩余部分 ）、
break（跳出循环 ）、goto（跳转到指定标签 ）的用法。
*/
#include <stdio.h>
int main(void)
{
    char ch;
    while ((ch = getchar()) != '#')
    {
        if (ch == '\n')
            continue;
        printf("Step 1\n");
        if (ch == 'c')
            continue;
        if (ch == 'b')
            break;
        else if (ch == 'h')
            goto laststep;
        printf("Step 2\n");
    laststep: printf("Step 3\n");
    }
    printf("Done\n");
    return 0;
}
// 输入字符分析（输入为 q、c、h、b 依次输入，实际输入时注意换行等情况，这里简化分析）：
// 输入 'q'：不会触发 continue、break、goto，输出 Step 1、Step 2、Step 3 
// 输入 'c'：触发 continue，跳过后面打印 Step 2 等，输出 Step 1、Step 3 
// 输入 'h'：触发 goto，跳转到 laststep，输出 Step 1、Step 3 
// 输入 'b'：触发 break，跳出循环，输出 Step 1 后循环结束，最后输出 Done 
// 可按照这个逻辑，详细推导每一步输入对应的输出

/*
awfaawffa
Step 1
Step 2
Step 3
Step 1
Step 2
Step 3
Step 1
Step 2
Step 3
Step 1
Step 2
Step 3
Step 1
Step 2
Step 3
Step 1
Step 2
Step 3
Step 1
Step 2
Step 3
Step 1
Step 2
Step 3
Step 1
Step 2
Step 3
*/