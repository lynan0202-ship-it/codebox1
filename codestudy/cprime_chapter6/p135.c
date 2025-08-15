
/* 
 * 程序名称：zeno.c
 * 程序功能：计算“芝诺悖论”相关的级数和，通过累加 1 + 1/2 + 1/4 + 1/8 + ... 这样的级数，
 *           观察随着项数增加，和趋近于 2 的过程
 */
#include <stdio.h>  // 引入标准输入输出库，用于 printf、scanf 等函数

int main(void)
{
    // t_ct：用来记录“项数的计数”，比如第 1 项、第 2 项...
    int t_ct;  
    // time：存储最终累加的“总时间和”，用浮点数保证精度
    // power_of_2：辅助计算每一项的分母（2 的幂次），比如第 1 项分母是 2^0=1，第 2 项分母是 2^1=2...
    double time, power_of_2;  
    // limit：用来接收用户输入的“想计算的项数”，比如用户输入 10，就计算前 10 项的和
    int limit;               

    // 提示用户输入想计算的项数
    printf("Enter the number of terms you want: "); 
    // 读取用户输入的项数，存入 limit 变量
    scanf("%d", &limit);                           

    // 初始化：
    // time = 0 表示先把总和清零，准备开始累加
    // power_of_2 = 1 对应第 1 项的分母是 2^0 = 1
    // t_ct = 1 表示从“第 1 项”开始计数
    // 循环条件：只要 t_ct（当前项数）小于等于用户输入的 limit（总项数），就继续循环
    for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; 
         // 每次循环结束后，t_ct 自增 1（比如从第 1 项走到第 2 项）
         t_ct++, 
         // 每次循环结束后，power_of_2 乘以 2，实现 2 的幂次增长（分母从 1→2→4→8...）
         power_of_2 *= 2.0) 
    {
        // 核心：把“1 / 当前 power_of_2 的值”加到总和里
        // 比如第 1 项是 1/1，第 2 项是 1/2，第 3 项是 1/4...
        time += 1.0 / power_of_2;                    

        // 输出当前累加的结果：
        // %f 用来打印浮点数（time），%d 用来打印整数（t_ct，当前是第几项）
        printf("time = %f when terms = %d.\n", time, t_ct); 
    }

    // 程序正常结束，返回 0
    return 0; 
}/*
Enter the number of terms you want: 7
time = 1.000000 when terms = 1.
time = 1.500000 when terms = 2.
time = 1.750000 when terms = 3.
time = 1.875000 when terms = 4.
time = 1.937500 when terms = 5.
time = 1.968750 when terms = 6.
time = 1.984375 when terms = 7.
*/