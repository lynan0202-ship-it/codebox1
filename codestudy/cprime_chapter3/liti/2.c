#include <stdio.h>

int main(void) {
    // 第 6 题演示
    printf("常量 12          | 类型 int       | 输出: %d\n", 12);
    printf("常量 0X3         | 类型 int       | 十六进制输出: %#X | 十进制输出: %d\n", 0X3, 0X3);
    printf("常量 'C'         | 类型 char      | 输出: %c\n", 'C');
    printf("常量 2.34E07     | 类型 double    | 科学计数法: %e | 小数形式: %f\n", 2.34E07, 2.34E07);
    printf("常量 '\\040'     | 类型 char      | 字符输出: %c | 八进制值: %#o\n", '\040', '\040');
    printf("常量 7.0         | 类型 double    | 输出: %f\n", 7.0);
    printf("常量 6L          | 类型 long      | 输出: %ld\n", 6L);
    printf("常量 6.0f        | 类型 float     | 输出: %f\n", 6.0f);
    printf("常量 0x5.b6p12   | 类型 double    | 十六进制浮点: %a | 小数形式: %f\n", 0x5.b6p12, 0x5.b6p12);

    return 0;
}