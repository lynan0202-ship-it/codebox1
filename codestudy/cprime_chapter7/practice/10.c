/*
编程练习 1（统计字符问题 ）
问题要点：读取输入直到遇到 # 字符停止，统计其中空格数、换行符数和其他字符数量。
涉及知识点：循环结构（while ）、分支结构（if-else ）、字符输入与判断
*/
#include <stdio.h>

int main() {
    char ch;
    int spaceCount = 0, newlineCount = 0, otherCount = 0;

    printf("请输入字符，遇到 # 停止：\n");
    while ((ch = getchar()) != '#') {  // 读取字符直到 #
        if (ch == ' ') {
            spaceCount++;  // 统计空格
        } 
        else if (ch == '\n') {
            newlineCount++;  // 统计换行符
        } 
        else {
            otherCount++;  // 统计其他字符
        }
    }

    printf("空格数：%d\n", spaceCount);
    printf("换行符数：%d\n", newlineCount);
    printf("其他字符数：%d\n", otherCount);

    return 0;
}