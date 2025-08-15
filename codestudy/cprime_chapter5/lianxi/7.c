#include <stdio.h>

// 定义函数：计算 num 的立方
double cube(double num) {
    return num * num * num;
}

int main(void) {
    double input;
    printf("=== 计算立方值 ===\n");
    printf("请输入一个数：");
    scanf("%lf", &input);

    // 调用 cube 函数
    double result = cube(input);

    printf("%.2f 的立方值是：%.2f\n", input, result);

    return 0;
}