#include <stdio.h>
// 用于 strlen 函数
#include <string.h>  

int main(void) {
    char first[20], last[20];
    printf("请输入名：");
    scanf("%s", first);
    printf("请输入姓：");
    scanf("%s", last);

    // 计算字母数
    int len_first = strlen(first);
    int len_last = strlen(last);

    // 字母数与名、姓结尾对齐
    printf("%s %s\n", first, last);
    printf("%*d %*d\n", len_first, len_first, len_last, len_last);

    // 字母数与名、姓开头对齐
    printf("\n");
    printf("%s %s\n", first, last);
    printf("%-*d %-*d\n", len_first, len_first, len_last, len_last);

    return 0;
}
/*
请输入名：LIU
请输入姓：NIANNIAN
LIU NIANNIAN
  3        8

LIU NIANNIAN
3   8
*/