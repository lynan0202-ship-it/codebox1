/* 
知识要点总结：
1. 输入处理与验证：通过 `get_long` 函数处理用户输入，校验是否为合法长整数，清理错误输入；利用 `bad_limits` 校验范围上下限的有效性。
2. 模块化编程：将输入获取、范围校验、业务计算（平方和）拆分为独立函数，主函数 `main` 负责流程串联，增强代码可读性与可维护性。 
3. 数据类型与转换：使用 `long` 存储整数范围，`double` 存储平方和避免溢出；`scanf` 格式化输入转换、`getchar` 清理缓冲区字符。
4. 程序流程控制：`while` 循环实现持续交互，支持用户多次输入范围，通过条件判断（`start != 0 || stop != 0`）控制退出逻辑。

总体逻辑：
1. 程序启动后，提示用户输入整数范围上下限，说明范围边界与退出条件（输入 `0 0` 退出）。
2. 调用 `get_long` 获取用户输入的上下限，进入循环处理：
   - 若上下限非全 `0`，调用 `bad_limits` 校验范围有效性。
   - 若范围无效，提示重新输入；若有效，调用 `sum_squares` 计算平方和并输出结果。
   - 循环提示用户输入新的范围，直至输入 `0 0` 退出，打印 `Done.` 结束程序。
*/

#include <stdio.h>    // 提供标准输入输出函数（如 printf、scanf、getchar 等）
#include <stdbool.h>  // 提供 bool 类型及 true/false 宏定义

// 函数声明
// 获取合法 long 类型整数，处理非数字输入
long get_long(void);
// 校验范围 [begin, end] 是否有效，low 为下限、high 为上限
bool bad_limits(long begin, long end, long low, long high);
// 计算 [a, b] 区间内所有整数的平方和，返回 double 类型避免溢出
double sum_squares(long a, long b);

int main(void)
{
    // 定义范围的上下限边界，比题目要求的 ±10000000 多 1，用于校验“小于/大于”逻辑
    const long MIN = -100000001L;  
    const long MAX = +100000001L;  
    long start;    // 存储用户输入的范围下限
    long stop;     // 存储用户输入的范围上限
    double answer; // 存储平方和计算结果

    // 程序功能说明，告知用户输入规则与边界
    printf("This program computes the sum of the squares of integers in a range.\n"
           "The lower bound should not be less than -10000000 and\n"
           "the upper bound should not be more than +10000000.\n"
           "Enter the limits (enter 0 for both limits to quit):\n"
           "lower limit: ");
    start = get_long();  // 获取下限输入
    printf("upper limit: ");
    stop = get_long();   // 获取上限输入

    // 循环逻辑：只要上下限不全为 0，就持续处理输入
    while (start != 0 || stop != 0)
    {
        // 校验输入的范围是否有效
        if (bad_limits(start, stop, -10000000, +10000000))
        {
            printf("Please try again.\n"); // 范围无效，提示重新输入
        }
        else
        {
            // 范围有效，计算平方和
            answer = sum_squares(start, stop);
            // 输出结果，%g 自动优化浮点数显示（去除无意义小数位）
            printf("The sum of the squares of the integers ");
            printf("from %ld to %ld is %g\n", start, stop, answer);
        }

        // 提示用户继续输入或退出
        printf("Enter the limits (enter 0 for both limits to quit):\n"
               "lower limit: ");
        start = get_long();
        printf("upper limit: ");
        stop = get_long();
    }

    printf("Done.\n"); // 退出循环，程序结束提示
    return 0;
}

// get_long 函数实现：读取合法 long 整数，处理错误输入
long get_long(void)
{
    long input; // 存储最终读取的合法整数
    char ch;    // 用于清理输入缓冲区的字符

    // scanf 返回值 !=1 说明输入无法匹配 %ld 格式（非数字输入）
    while (scanf("%ld", &input) != 1)
    {
        // 清理缓冲区：逐个读取字符直到换行，避免残留字符影响后续输入
        while ((ch = getchar()) != '\n')
        {
            putchar(ch); // 可选：回显错误字符，让用户看到输入内容
        }
        // 提示用户重新输入合法整数
        printf(" is not an integer.\nPlease enter an integer value, such as 25, -178, or 3: ");
    }
    return input; // 返回合法的 long 整数
}

// bad_limits 函数实现：校验范围 [begin, end] 是否有效
bool bad_limits(long begin, long end, long low, long high)
{
    bool not_good = false; // 标记范围是否无效，默认有效（false）

    // 情况 1：下限大于上限（逻辑颠倒）
    if (begin > end)
    {
        printf("%ld isn't smaller than %ld.\n", begin, end);
        not_good = true;
    }
    // 情况 2：begin 或 end 小于全局下限 low
    if (begin < low || end < low)
    {
        printf("Values must be %ld or greater.\n", low);
        not_good = true;
    }
    // 情况 3：begin 或 end 大于全局上限 high
    if (begin > high || end > high)
    {
        printf("Values must be %ld or less.\n", high);
        not_good = true;
    }

    return not_good; // 返回范围是否无效
}

// sum_squares 函数实现：计算 [a, b] 区间内所有整数的平方和
double sum_squares(long a, long b)
{
    double total = 0; // 存储总和，用 double 避免 long 类型溢出（数值过大时）
    long i;

    // 遍历区间内每个整数，累加平方值
    for (i = a; i <= b; i++)
    {
        // 强制转换为 double 计算，避免整数溢出（如 i 极大时，i*i 可能超过 long 范围）
        total += (double)i * (double)i;
    }
    return total; // 返回最终平方和
}

/* 
测试与验证建议方案（分点）：
1. 正常流程测试：
   - 输入合法范围（如 3 12），验证输出是否为 645（与教程示例一致）。
   - 输入 0 0，检查程序是否退出并打印 Done.。

2. 边界值测试：
   - 输入 -10000000 10000000（范围边界），验证程序是否正常计算。
   - 输入 -10000001 0（低于下限），检查 bad_limits 是否提示 Values must be -10000000 or greater.。

3. 错误输入测试：
   - 输入非整数（如 low、a big number），验证 get_long 是否提示重新输入，且最终能读取合法整数。
   - 输入范围颠倒（如 10 5），检查 bad_limits 是否提示 10 isn't smaller than 5.。

4. 溢出测试（拓展）：
   - 输入极大范围（如 100000 200000），观察 sum_squares 用 double 存储是否仍能正确计算（避免 long 溢出导致错误）。
*/
/*
This program computes the sum of the squares of integers in a range.
The lower bound should not be less than -10000000 and
the upper bound should not be more than +10000000.
Enter the limits (enter 0 for both limits to quit):
lower limit: -6548
upper limit: 673789895858585
-6548 isn't smaller than -278570599.
Values must be -10000000 or greater.
Please try again.
Enter the limits (enter 0 for both limits to quit):
lower limit: -54
upper limit: 65
The sum of the squares of the integers from -54 to 65 is 147620
Enter the limits (enter 0 for both limits to quit):
lower limit: 0
upper limit: 0  
Done.
*/