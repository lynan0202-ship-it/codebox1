// divisors.c -- 演示 if 嵌套、标记变量（flag）、stdbool.h 用法，判断素数并输出约数
#include <stdio.h>
// 提供 bool 类型、true/false 宏（替代 _Bool、1/0 ）
#include <stdbool.h>  

int main(void)
{
    // 待测试的数（用 unsigned long 扩大范围，支持更大数值）
    unsigned long num;  
    // 可能的约数（从 2 开始试除）
    unsigned long div;  
    // 素数标记：true 表示是素数，false 表示不是（stdbool.h 定义）
    bool isPrime;       

    // 提示用户输入，支持连续测试（输入 q 退出）
    printf("Please enter an integer for analysis; ");
    printf("Enter q to quit.\n");
    // 循环读取输入：scanf 返回 1 表示成功读取数字，否则退出
    while (scanf("%lu", &num) == 1) {  
        // 每次测试新数字，重置标记为“是素数”
        isPrime = true;  
        // 约数从 2 开始，到 sqrt(num) 结束（减少循环次数，优化效率）
        for (div = 2; (div * div) <= num; div++) {  
            // 判断是否能被 div 整除
            if (num % div == 0) {  
                // 能整除，说明不是素数，更新标记
                isPrime = false;  
                // 输出约数对：div 和 num/div
                if ((num / div) != div)  
                    printf("%lu is divisible by %lu and %lu.\n", 
                           num, div, num / div);
                else
                    // 平方数情况（如 144 = 12*12），只输出一次
                    printf("%lu is divisible by %lu.\n", num, div);
            }
        }
        // 循环结束后，根据标记判断是否为素数
        if (isPrime)  
            printf("%lu is prime.\n", num);

        // 提示继续输入或退出
        printf("Please enter another integer for analysis; ");
        printf("Enter q to quit.\n");
    }
    printf("Bye.\n");

    return 0;
}
/*
Please enter an integer for analysis; Enter q to quit.
35
35 is divisible by 5 and 7.
Please enter another integer for analysis; Enter q to quit.
78
78 is divisible by 2 and 39.
78 is divisible by 3 and 26.
78 is divisible by 6 and 13.
Please enter another integer for analysis; Enter q to quit.
5
5 is prime.
Please enter another integer for analysis; Enter q to quit.
345
345 is divisible by 3 and 115.
345 is divisible by 5 and 69.
345 is divisible by 15 and 23.
Please enter another integer for analysis; Enter q to quit.
46
46 is divisible by 2 and 23.
Please enter another integer for analysis; Enter q to quit.
6854
6854 is divisible by 2 and 3427.
6854 is divisible by 23 and 298.
6854 is divisible by 46 and 149.
Please enter another integer for analysis; Enter q to quit.
q
Bye.
*/