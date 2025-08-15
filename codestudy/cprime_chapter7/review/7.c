/*
7. 找出程序错误并修正
要点：检查程序中条件表达式写法错误、变量使用错误等问题，修正后让程序能正确统计小写字母、大写字母和其他字符数量。
知识点：getchar 用法、条件表达式正确写法、printf 格式使用。
*/
/**/
#include <stdio.h>
int main(void)
{
    char ch;
    int lc = 0; /* 统计小写字母 */
    int uc = 0; /* 统计大写字母 */
    int oc = 0; /* 统计其他字母 */

    while ((ch = getchar()) != '#')
    {
        // 原错误：'a' <= ch >= 'z' 这种连续比较写法错误，C语言中要拆成两个条件用逻辑与连接
        if ('a' <= ch && ch <= 'z') 
            lc++;
        // 原错误：!(ch < 'A') || !(ch > 'Z') 逻辑不对，应该是判断在'A'到'Z'之间，这里修正为 (ch >= 'A' && ch <= 'Z')
        else if (ch >= 'A' && ch <= 'Z') 
            uc++;
        else
            oc++;
    }
    // 原错误：printf 中最后一个变量写的是 pc，应该是 oc
    printf("%d lowercase, %d uppercase, %d other\n", lc, uc, oc);
    return 0;
}
// 主要错误在于条件表达式的写法不符合C语言语法，以及 printf 中变量名写错，修正后就能正确统计各类字符数量 
/*
wrwetweste
#
10 lowercase, 0 uppercase, 1 other
*/