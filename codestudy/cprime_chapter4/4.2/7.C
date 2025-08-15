#include <stdio.h>

int main(void) {
    // a. 字段宽度15的 unsigned long → %15lu
    unsigned long a = 1234567890UL;
    printf("a: %15lu\n", a);

    // b. 形如 0x8A、字段宽度4的十六进制 → %#4x（小写 0x，宽度4）
    int b = 0x8A;
    printf("b: %#4x\n", b);

    // c. 形如 2.33E+02、字段宽度12、左对齐 → %-12.2E（- 左对齐，.2 保留2位小数）
    float c = 2.33e2;
    printf("c: %-12.2E\n", c);

    // d. 形如 +232.346、字段宽度10的浮点数 → %+10.3f（+ 强制显正负号）
    float d = 232.346;
    printf("d: %+10.3f\n", d);

    // e. 字段宽度8的字符串前8个字符 → %.8s（.8 截取前8个字符）
    char e[] = "HelloWorld";
    printf("e: %.8s\n", e);

    return 0;
}
/*
a:      1234567890
b: 0x8a
c: 2.33E+002   
d:   +232.346
e: HelloWor
*/