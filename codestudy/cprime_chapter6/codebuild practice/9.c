#include <stdio.h>

// 定义函数：接收 a、b，返回计算结果
double calculate(double a, double b) {  
    return (a - b) / (a * b);
}

int main() {
    double a, b;
    while (scanf("%lf %lf", &a, &b) == 2) {
        if (a * b == 0) {
            printf("错误：乘积为 0，无法计算！\n");
            continue;
        }
        // 调用函数计算
        double result = calculate(a, b);  
        printf("结果: %.2f\n", result);
    }

    return 0;
}
/*
2
4
结果: -0.25
3
6
结果: -0.17
5
9
结果: -0.09
3
8
结果: -0.21
3
0
错误：乘积为 0，无法计算！
2
T
*/