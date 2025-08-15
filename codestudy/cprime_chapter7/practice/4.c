/*
1. 题目问题：编写程序用 if - else 读取输入直到#停止，用感叹号替换句号，用两个感叹号替换原来的感叹号，最后报告替换次数。
2. 问题要点与知识点：通过循环逐字符读取，依据条件判断进行标点替换并统计次数，涉及输入、循环、条件判断、字符替换知识点。
*/

#include <stdio.h>

int main() {
    char ch;
    int replaceCount = 0;
    printf("输入内容（遇到 # 停止）：\n");
    while ((ch = getchar()) != '#') {
        if (ch == ',') {  // 逗号替换为 !
            putchar('!');
            replaceCount++;
        } else if (ch == '!') {  // 感叹号替换为 !!
            putchar('!');
            putchar('!');
            replaceCount++;
        } else {  // 其他字符原样输出
            putchar(ch);
        }
    }
    printf("\n替换次数：%d\n", replaceCount);
    return 0;
}