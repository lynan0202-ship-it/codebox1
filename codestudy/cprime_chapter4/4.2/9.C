#include <stdio.h>

int main(void) {
    // a. 输入 101 → 读整数
    int a;
    printf("a: ");
    scanf("%d", &a);

    // b. 输入 22.32 8.34E-09 → 读两个浮点数
    double b1, b2;
    printf("b: ");
    scanf("%lf %le", &b1, &b2);

    // c. 输入 linguini → 读字符串
    char c[50];
    printf("c: ");
    scanf("%s", c);

    // d. 输入 catch 22 → 读字符串和整数
    char d_str[50];
    int d_num;
    printf("d: ");
    scanf("%s %d", d_str, &d_num);

    // e. 输入 catch 22（跳过 catch）→ 用 %*s 跳过字符串
    int e_num;
    printf("e: ");
    scanf("%*s %d", &e_num);

    // 简单输出验证（可删除，仅演示读取）
    printf("a: %d\n", a);
    printf("b: %lf %le\n", b1, b2);
    printf("c: %s\n", c);
    printf("d: %s %d\n", d_str, d_num);
    printf("e: %d\n", e_num);

    return 0;
}
/*
a: 101
b: 22.32 8.34E-09
c: linguini
d: catch 22
e: catch 22
a: 101
b: 22.320000 8.340000e-009
c: linguini
d: catch 22
e: 22
*/