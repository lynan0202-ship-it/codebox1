// cmfit.c -- 浮点数比较
#include <math.h>   // 包含数学函数库，提供fabs()等数学函数
#include <stdio.h>

int main(void)
{
    const double ANSWER = 3.14159;  // 定义常量ANSWER存储π的目标值
    double response;                // 存储用户输入的π的近似值

    printf("What is the value of pi?\n");  // 提示用户输入π的值
    scanf("%lf", &response);              // 读取用户输入的浮点数

    // 循环条件：当用户输入值与目标值的绝对差值大于0.001时，继续循环
    // fabs()用于计算两个数差值的绝对值，确保比较的是距离大小而非正负
    while ((fabs(response - ANSWER) > 0.001))
    {
        printf("Try again!\n");    // 提示用户重新输入
        scanf("%lf", &response);   // 再次读取用户输入的浮点数
    }

    // 当用户输入值足够接近目标值（差值≤0.001）时，循环结束，程序退出
    return 0;
}
/*
What is the value of pi?
3.24
Try again!
4.45
Try again!
3.14159
*/