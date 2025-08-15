/*
1. 题目问题：编写程序读取输入直到#停止，报告“ei”出现的次数，需记录前一个字符和当前字符。
2. 问题要点与知识点：循环读取字符，通过记录前一个字符和当前字符判断“ei”组合，涉及输入、循环、条件判断、字符组合判断知识点。
*/

#include <stdio.h>

int main() {
    char ch, prev = 0;  // prev 存储前一个字符，初始为 0
    int eiCount = 0;
    printf("输入内容（遇到 # 停止）：\n");
    while ((ch = getchar()) != '#') {
        if (prev == 'e' && ch == 'i') {  // 判断是否是 ei 组合
            eiCount++;
        }
        prev = ch;  // 更新前一个字符
    }
    printf("ei 出现次数：%d\n", eiCount);
    return 0;
}