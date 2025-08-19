// ------------------------------
// 题干：使用递归函数重写编程练习 8。
// 知识要点：
//  1. 递归函数的定义与调用（通过递归实现幂次计算，包含递归终止条件 ）
//  2. 幂次计算的递归逻辑（正幂、负幂、特殊情况处理 ）
// 总体逻辑：
//  1. 定义递归函数 `recursive_power`，处理特殊情况后，通过递归调用计算幂次
//  2. 正幂通过 `base * recursive_power(base, exponent - 1)` 实现递归，负幂通过倒数递归实现
//  3. 在 `main` 函数中测试递归函数，与题目8 测试类似
#include <stdio.h>

// 定义递归函数计算幂次
double recursive_power(double base, int exponent) {
    // 处理 0 的 0 次幂，返回 1
    if (base == 0 && exponent == 0) { 
        return 1;
    }
    // 处理 0 的正数次幂，返回 0
    if (base == 0) { 
        return 0;
    }
    // 处理任何数的 0 次幂，返回 1
    if (exponent == 0) { 
        return 1;
    }
    // 处理负幂，先计算正幂再取倒数
    if (exponent < 0) { 
        return 1 / recursive_power(base, -exponent);
    }
    // 正幂递归：base^exponent = base * base^(exponent - 1)
    return base * recursive_power(base, exponent - 1); 
}

int main() {
    double base1 = 2, base2 = 0, base3 = 5;
    int exp1 = 3, exp2 = 5, exp3 = 0, exp4 = -2;

    printf("2^3 = %.2f\n", recursive_power(base1, exp1));
    printf("0^5 = %.2f\n", recursive_power(base2, exp2));
    printf("5^0 = %.2f\n", recursive_power(base3, exp3));
    printf("2^-2 = %.2f\n", recursive_power(base1, exp4));
    printf("0^0 = %.2f\n", recursive_power(0, 0));
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：
//     - 保存代码为 recursive_power.c
//     - 用 gcc 编译：gcc recursive_power.c -o recursive_power
//     - 运行：./recursive_power（Linux/Mac） 或 recursive_power.exe（Windows）
//  2. 预期结果：
//     - 与题目8 结果一致，2^3 = 8.00 ；0^5 = 0.00 等 
//  3. 检查点：
//     - 确认递归函数的终止条件是否正确，避免栈溢出
//     - 验证递归计算的结果与题目8 中循环实现的结果是否一致
// 易错点提醒：
//  1. 递归函数容易忘记设置终止条件，导致栈溢出（如忘记处理 exponent == 0 等情况 ）
//  2. 处理负幂递归时，容易在符号转换、递归调用次数上出错
// 拓展思考：
//  1. 递归实现与循环实现的 `power` 函数，在效率和内存使用上有什么区别？对于大指数，递归可能导致栈溢出，循环更稳定
//  2. 如何优化递归函数的效率？可添加记忆化（缓存已计算的结果 ），但对于幂次计算场景不太适用，可结合题目8 思考 