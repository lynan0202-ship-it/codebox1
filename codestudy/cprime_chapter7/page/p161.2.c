// 简化版：突出 if 嵌套、标记变量，演示素数判断核心逻辑
#include <stdio.h>
#include <stdbool.h>  // 启用 bool 类型

int main(void) {
    unsigned long num;
    unsigned long div;
    bool isPrime;

    printf("Enter a number (q to quit): ");
    // 读取数字，非数字则退出
    while (scanf("%lu", &num) == 1) {  
        isPrime = true;
        // 约数试除到 sqrt(num)
        for (div = 2; (div * div) <= num; div++) {  
            if (num % div == 0) {  // if 嵌套：判断整除
                isPrime = false;  
                printf("%lu has a divisor: %lu\n", num, div);
            }
        }
        // if-else 分支：根据标记输出结果
        if (isPrime)  
            printf("%lu is prime!\n", num);
        else
            printf("%lu is NOT prime.\n", num);

        printf("Next number (q to quit): ");
    }
    printf("Exit program.\n");
    return 0;
}
/*
关键注释与教程知识点对应
stdbool.h 与标记变量：
bool isPrime; + true/false：使用 C99 新增的 stdbool.h 类型，替代传统 _Bool 和 1/0，让代码更易读，对应教程 “stdbool.h 用法”。
if 嵌套与分支逻辑：
for 循环内的 if (num % div == 0)：演示 if 嵌套（循环内嵌套条件判断），判断是否整除。
循环后的 if (isPrime)：用 if-else 分支 根据标记输出结果，覆盖教程 “if 分支基本用法”。
算法优化（平方根终止条件）：
(div * div) <= num：通过 “试除到平方根” 减少循环次数，对应教程 “优化约数判断，避免冗余计算” 的思路。
连续输入与退出逻辑：
while (scanf("%lu", &num) == 1)：结合 scanf 返回值控制循环，实现 “连续测试 + 输入 q 退出”，覆盖教程 “循环与分支结合的交互逻辑”。
*/