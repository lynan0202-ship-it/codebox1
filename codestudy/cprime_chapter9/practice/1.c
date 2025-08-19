// ------------------------------
// 题干：设计一个函数 min(x, y)，返回两个 double 类型值的较小值。在一个简单的驱动程序中测试该函数。
// 知识要点：
//  1. 函数的定义（返回值类型、参数类型）
//  2. 条件判断（比较两个数的大小）
//  3. 函数的调用和返回值的使用
// 总体逻辑：
//  1. 定义 `min` 函数，接收两个 `double` 类型参数
//  2. 在函数内部比较两个参数的大小，返回较小的值
//  3. 在 `main` 函数中定义两个 `double` 类型变量，调用 `min` 函数并输出结果
#include <stdio.h>

// 定义 min 函数，返回两个 double 类型值中的较小值
double min(double x, double y) {
    // 如果 x 小于 y，返回 x，否则返回 y
    return x < y ? x : y; 
}

int main() {
    // 定义两个 double 类型的变量
    double num1 = 3.5, num2 = 2.8; 
    printf("两个数分别是：%.1f 和 %.1f\n", num1, num2);

    // 调用 min 函数，获取较小值
    double result = min(num1, num2); 

    printf("较小的值是：%.1f\n", result);
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：
//     - 保存代码为 min_function.c
//     - 用 gcc 编译：gcc min_function.c -o min_function
//     - 运行：./min_function（Linux/Mac） 或 min_function.exe（Windows）
//  2. 预期结果：
//     - 输出两个数中较小的值，如示例中 3.5 和 2.8 的较小值是 2.8 
//  3. 检查点：
//     - 确认输出的较小值与实际计算结果一致
// 易错点提醒：
//  1. 容易将返回值类型写错，要确保是 `double` 类型
//  2. 注意比较运算符的使用，`>` 和 `<` 不要搞反
// 拓展思考：
//  1. 如果要比较多个 `double` 类型的值（比如三个数 ），怎么修改函数？可以尝试增加参数或改用数组传参
//  2. 如果要比较的是整数类型，函数该如何调整？（修改参数和返回值类型为 `int` ） 