#include <stdio.h>

int main(void) {
    // a. 字段宽度6、最少4位的十进制整数 → %6d（宽度6，不足补空格；本身4位以上自动适配）
    int a = 1234;
    printf("a: %6d\n", a);

    // b. 动态字段宽度的八进制 → %*o（* 由参数传宽度，这里演示固定宽4）
    int b = 0123; // 八进制数
    printf("b: %4o\n", b);

    // c. 字段宽度2的字符 → %2c
    char c = 'A';
    printf("c: %2c\n", c);

    // d. 字段宽度等于字符数的浮点数 → %.f（自动匹配宽度，这里演示 %.3f 保留3位小数）
    float d = 3.13;
    printf("d: %g\n", d); // %g 自动去掉无意义的0，接近“宽度等于字符数”

    // e. 字段宽度7、左对齐的前5字符 → %-7.5s
    char e[] = "HelloWorld";
    printf("e: %-7.5s\n", e);

    return 0;
}
/*
a:   1234
b:  123
c:  A
d: 3.13
e: Hello  
*/