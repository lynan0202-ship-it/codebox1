#include <stdio.h>

int main(void) {
    // 第 7 题演示（假设 int 为 16 位，范围 -32768 ~ 32767）
    printf("常量 012         | 类型 int       | 八进制输出: %#o | 十进制输出: %d\n", 012, 012);
    printf("常量 2.9e05L     | 类型 long double | 科学计数法: %Le | 小数形式: %Lf\n", 2.9e05L, 2.9e05L);
    printf("常量 's'         | 类型 char      | 输出: %c\n", 's');
    printf("常量 100000      | 类型 long      | 输出: %ld\n", 100000L); // 16 位 int 存不下，用 long
    printf("常量 '\\n'       | 类型 char      | 转义字符: %c（实际输出会换行，这里用描述）\n", '\n');
    printf("常量 20.0f       | 类型 float     | 输出: %f\n", 20.0f);
    printf("常量 0x44        | 类型 int       | 十六进制输出: %#X | 十进制输出: %d\n", 0x44, 0x44);
    printf("常量 -40         | 类型 int       | 输出: %d\n", -40);

    return 0;
}