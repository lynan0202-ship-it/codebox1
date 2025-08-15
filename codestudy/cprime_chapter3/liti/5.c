#include <stdio.h>

int main() {
    char ch1, ch2, ch3, ch4;
    
    // 使用转义序列赋值
    ch1 = '\n';
    
    // 使用十进制 ASCII 值赋值
    ch2 = 10;
    
    // 使用八进制字符常量赋值
    ch3 = '\12';
    
    // 使用十六进制字符常量赋值
    ch4 = '\xa';
    
    // 输出每个变量的十进制值
    printf("ch1 的十进制值: %c\n", ch1);
    printf("ch2 的十进制值: %c\n", ch2);
    printf("ch3 的十进制值: %c\n", ch3);
    printf("ch4 的十进制值: %c\n", ch4);
    
    // 比较它们是否相等
    if (ch1 == ch2 && ch2 == ch3 && ch3 == ch4) {
        printf("所有变量的值都相等\n");
    } else {
        printf("变量的值存在不相等的情况\n");
    }
    
    return 0;
}