/* 
 * 程序名称：power.c
 * 程序功能：
 *  1. 定义 power 函数，计算“数的整数次幂”（n 的 p 次方）
 *  2. 用 main 函数做“驱动程序”测试 power 函数，支持循环输入、退出功能  
 *  核心知识点对应教程：
 *  - 函数的“声明（原型）、调用、定义”完整流程  
 *  - while 循环结合 scanf 返回值实现“持续输入/退出”逻辑  
 *  - for 循环计算幂次的算法  
 */
#include <stdio.h>

// 函数原型（声明）：告诉编译器 power 函数的“返回类型、参数类型”
// 这一步是为了让 main 函数里调用 power 时，编译器能提前知道函数规则
double power(double n, int p);  // ANSI 函数原型写法

int main(void)
{
    // x：存储用户输入的“底数”（可以是小数）
    double x, xpow;  
    // exp：存储用户输入的“指数”（整数）
    int exp;         

    // 提示用户输入：需要输入“底数 + 指数”，或输入 q 退出
    printf("Enter a number and the positive integer power");
    printf(" to which the number will be raised. Enter q to quit.\n");

    // while 循环条件：
    // scanf("%lf%d", &x, &exp) == 2 表示“成功读取 2 个值（底数+指数）”时继续循环
    // 如果输入 q 或不匹配的格式，scanf 返回值不是 2，循环结束
    while (scanf("%lf%d", &x, &exp) == 2)  
    {
        // 调用 power 函数：把 x（底数）和 exp（指数）传进去，计算结果存到 xpow
        xpow = power(x, exp);  

        // 输出结果：x 的 exp 次幂 = xpow，保留 5 位小数
        printf("%g to the power %d is %g\n", x, exp, xpow);  

        // 提示用户继续输入或退出
        printf("Enter next pair of numbers or q to quit.\n");  
    }

    // 循环结束后，打印退出提示
    printf("Hope you enjoyed this power trip -- bye!\n");  

    return 0;
}

// 函数定义：实现“计算 n 的 p 次幂”的逻辑
// 参数：n（底数，double 类型）、p（指数，int 类型）
// 返回值：n^p 的结果（double 类型）
double power(double n, int p)  
{
    // pow：存储幂运算的结果，初始化为 1（任何数的 0 次幂是 1，循环乘法也从 1 开始）
    double pow = 1;  
    // i：循环计数器，用来控制“乘 n 的次数”（从 1 到 p）
    int i;          

    // for 循环逻辑：执行 p 次“乘以 n”，得到 n^p
    // 例如 p=3 时，循环做 pow = 1*n*n*n
    for (i = 1; i <= p; i++) // p=1
    {
        // 核心：每次循环让 pow 乘以 n，实现“累乘”
        pow *= n;  
    }

    // 返回计算好的幂结果，给 main 函数里的 xpow 赋值
    return pow;  
}
/*
Enter a number and the positive integer power to which the number will be raised. Enter q to quit.
4
6
4 to the power 6 is 4096
Enter next pair of numbers or q to quit.
*/