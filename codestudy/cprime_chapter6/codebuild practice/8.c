#include <stdio.h>

int main() {
    double a, b;
    // 循环处理输入，直到输入非数字
    while (scanf("%lf %lf", &a, &b) == 2) {  
        // 避免除以 0（题目未要求，可根据需求添加判断 ）
        if (a * b == 0) {  
            printf("错误：乘积为 0，无法计算！\n");
            continue;
        }
        // 计算公式
        double result = (a - b) / (a * b);  
        printf("结果: %.2f\n", result);
    }

    return 0;
}

/*
2
3
结果: -0.17
4
5
结果: -0.05
5
3
结果: 0.13
R
*/