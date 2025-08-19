// ------------------------------
// 题干：改进 power() 函数，使其能正确计算负幂。处理 0 的任何次幂都为 0，任何数的 0 次幂都为 1（0 的 0 次幂处理为 1 ）。使用一个循环，并在程序中测试该函数。
// 知识要点：
//  1. 函数定义与逻辑处理（实现幂次计算，包含负幂、特殊情况 ）
//  2. 循环结构（用于计算幂次，处理正幂和负幂 ）
//  3. 条件判断（处理 0 次幂、0 的幂次等特殊情况 ）
// 总体逻辑：
//  1. 定义 `power` 函数，接收底数 `base` 和指数 `exponent` 参数，通过循环计算幂次，处理特殊情况
//  2. 在 `main` 函数中，定义不同的底数和指数，调用 `power` 函数并输出结果进行测试
#include <stdio.h>

// 定义函数计算幂次，处理特殊情况
double power(double base, int exponent) {
    // 处理 0 的 0 次幂，按题目要求返回 1
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

    double result = 1;
    int abs_exponent = exponent;
    // 如果指数为负，取绝对值，后续计算倒数
    if (exponent < 0) { 
        abs_exponent = -exponent;
    }
    // 循环计算正幂次
    for (int i = 0; i < abs_exponent; i++) { 
        result *= base;
    }
    // 如果指数为负，取倒数得到结果
    if (exponent < 0) { 
        result = 1 / result;
    }
    return result;
}

int main() {
    // 测试不同情况
    double base1 = 2, base2 = 0, base3 = 5;
    int exp1 = 3, exp2 = 5, exp3 = 0, exp4 = -2;

    printf("2^3 = %.2f\n", power(base1, exp1));
    printf("0^5 = %.2f\n", power(base2, exp2));
    printf("5^0 = %.2f\n", power(base3, exp3));
    printf("2^-2 = %.2f\n", power(base1, exp4));
    printf("0^0 = %.2f\n", power(0, 0));
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：
//     - 保存代码为 power_function.c
//     - 用 gcc 编译：gcc power_function.c -o power_function
//     - 运行：./power_function（Linux/Mac） 或 power_function.exe（Windows）
//  2. 预期结果：
//     - 2^3 = 8.00 ；0^5 = 0.00 ；5^0 = 1.00 ；2^-2 = 0.25 ；0^0 = 1.00 
//  3. 检查点：
//     - 确认特殊情况（0 的 0 次幂、0 的正数次幂、数的 0 次幂 ）处理正确
//     - 确认负幂计算正确，结果为正幂结果的倒数
// 易错点提醒：
//  1. 处理 0 的 0 次幂时，容易遗漏条件判断，导致结果错误
//  2. 计算负幂时，忘记先计算正幂再取倒数，或者在循环次数、符号处理上出错
// 拓展思考：
//  1. 如果要支持小数指数（如 2.5 次幂 ），如何修改函数？可结合数学库函数或更复杂的算法
//  2. 如何优化循环计算幂次的效率？比如使用快速幂算法（二分法思想 ） 