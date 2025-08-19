// ------------------------------
// 题干：两数的调和平均数这样计算：先得到两数的倒数，然后计算两个倒数的平均值，最后取计算结果的倒数。
//       编写一个函数，接受两个 double 类型的参数，返回这两个参数的调和平均数。
// 知识要点：
//  1. 函数的定义和返回值计算
//  2. 数学运算（倒数、平均数的计算 ）
//  3. 处理除零错误（虽然题目未明确，但可简单考虑 ）
// 总体逻辑：
//  1. 定义 `harmonicMean` 函数，接收两个 `double` 类型参数
//  2. 计算两个参数的倒数，然后求平均值，最后再取倒数得到调和平均数
//  3. 在 `main` 函数中定义两个 `double` 类型变量，调用函数并输出结果
#include <stdio.h>

// 定义 harmonicMean 函数，计算并返回两个 double 类型数的调和平均数
double harmonicMean(double x, double y) {
    // 检查参数是否为 0，避免除零错误（简单处理，实际可更完善 ）
    if (x == 0 || y == 0) { 
        printf("错误：参数不能为 0，无法计算倒数！\n");
        // 返回一个特殊值表示错误，这里简单返回 0
        return 0; 
    }
    // 计算 x 的倒数
    double reciprocal_x = 1 / x; 
    // 计算 y 的倒数
    double reciprocal_y = 1 / y; 
    // 计算两个倒数的平均值
    double avg_reciprocal = (reciprocal_x + reciprocal_y) / 2; 
    // 取平均值的倒数作为调和平均数
    return 1 / avg_reciprocal; 
}

int main() {
    // 定义两个 double 类型的变量
    double num1 = 2, num2 = 4; 
    printf("两个数分别是：%.1f 和 %.1f\n", num1, num2);

    // 调用 harmonicMean 函数，获取调和平均数
    double result = harmonicMean(num1, num2); 

    printf("调和平均数是：%.2f\n", result);
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：
//     - 保存代码为 harmonic_mean.c
//     - 用 gcc 编译：gcc harmonic_mean.c -o harmonic_mean
//     - 运行：./harmonic_mean（Linux/Mac） 或 harmonic_mean.exe（Windows）
//  2. 预期结果：
//     - 对于 2 和 4 ，调和平均数的计算过程：
//       倒数分别是 1/2 = 0.5 和 1/4 = 0.25 ，平均值是 (0.5 + 0.25)/2 = 0.375 ，倒数是 1/0.375 ≈ 2.67 
//     - 输出调和平均数约为 2.67 
//  3. 检查点：
//     - 确认计算过程和结果是否正确，可手动计算验证
// 易错点提醒：
//  1. 容易忘记处理参数为 0 的情况，导致除零错误
//  2. 数学运算过程中注意运算顺序，确保按照调和平均数的公式计算
// 拓展思考：
//  1. 如果参数是负数，调和平均数的计算逻辑是否需要调整？可以尝试传入负数测试
//  2. 如何更完善地处理除零错误？比如返回一个特殊的标记值或使用错误处理机制 