#include <stdio.h>
int main(void)
{
    long num;
    long sum = 0L;
    // status 用于接收 scanf 的返回值：成功读入整数返回 1，读入非数值（如 'q'）返回 0
    int status;  

    printf("Please enter an integer to be summed (q to quit): ");
    // scanf 成功读入 1 个整数时返回 1，读入 'q' 这类非数值时返回 0
    status = scanf("%ld", &num);  

    // 问题核心！这里用了赋值运算符 '='，而非关系运算符 '=='
    // 本意是判断 status 是否等于 1，实际却把 1 赋值给 status，且赋值表达式结果恒为 1（非零即“真”）
    while (status == 1)  
    {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        // 每次循环重新读入，但如果输入 'q'，scanf 返回 0，status 会被赋值为 0
        status = scanf("%ld", &num);  
        // 然而！下一轮循环时，while (status = 1) 又把 status 强行改回 1，导致循环永远无法退出
    }

    printf("Those integers sum to %ld.\n", sum);
    return 0;
}
/*
Please enter an integer to be summed (q to quit): 1
Please enter next integer (q to quit): 2
Please enter next integer (q to quit): 32
Please enter next integer (q to quit): 352
Please enter next integer (q to quit): q
Those integers sum to 387.
*/