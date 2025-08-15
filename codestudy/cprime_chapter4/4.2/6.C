#include <stdio.h>

int main(void) {
    // a. 字段宽度与位数相同的十进制整数 → %d（或 %*d 动态宽度，这里默认匹配）
    int a = 123;
    printf("a: %d\n", a);

    // b. 形如 8A、字段宽度为4的十六进制 → %#4X（# 显示 0X 前缀，4 固定宽度）
    int b = 0x8A;
    printf("b: %#4X\n", b);

    // c. 形如 232.346、字段宽度为10的浮点数 → %10.3f（10 是宽度，.3 保留3位小数）
    float c = 232.346;
    printf("c: %10.3f\n", c);

    // d. 形如 2.33e+002、字段宽度为12的浮点数 → %12.2e（12 是宽度，.2 保留2位小数）
    float d = 2.33e2;
    printf("d: %12.2e\n", d);

    // e. 字段宽度为30、左对齐的字符串 → %-30s（- 表示左对齐）
    char e[] = "Hello";
    printf("e: %-30s\n", e);

    return 0;
}
/*
a: 123
b: 0X8A
c:    232.346
d:    2.33e+002
e: Hello
*/