#include <stdio.h>

int main(void) {
    // 错误：sizeof(double) 是 size_t 类型，%z 匹配 size_t
    // 修复：用 %zu 输出 size_t 类型（C99+ 标准）
    printf("The double type is %zu bytes.\n", sizeof(double));

    return 0;
}
/*
The double type is 8 bytes.
*/