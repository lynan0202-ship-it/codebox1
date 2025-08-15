/*
1. 题目问题：用 switch 语句重写练习 4 的程序，实现相同的标点替换及统计替换次数功能。
2. 问题要点与知识点：将条件判断改为 switch 分支结构，处理字符替换和次数统计，涉及 switch 语法、字符处理、循环知识点。
*/

#include <stdio.h>

int main() {
    char ch;
    int replaceCount = 0;
    printf("输入内容（遇到 # 停止）：\n");
    while ((ch = getchar()) != '#') {
        switch (ch) {
            case ',':  // 逗号替换为 !
                putchar('!');
                replaceCount++;
                break;
            case '!':  // 感叹号替换为 !!
                putchar('!');
                putchar('!');
                replaceCount++;
                break;
            default:  // 其他字符原样输出
                putchar(ch);
                break;
        }
    }
    printf("\n替换次数：%d\n", replaceCount);
    return 0;
}