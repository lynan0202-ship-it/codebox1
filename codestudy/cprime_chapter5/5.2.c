// 程序功能：计算多个男鞋码对应的脚长（英寸），演示 while 循环用法
#include <stdio.h>
// 宏定义：脚长计算的调整值（常量）
#define ADJUST 7.31  
int main(void)
{
    // 定义 const 常量：转换比例（不可修改）
    const double SCALE = 0.333;  
    // 鞋码（初始值 3.0）
    double shoe, foot;  

    // 打印表头：鞋码（男）与脚长的对应关系
    printf("Shoe size (men's)  foot length\n");
    // 初始化鞋码为 3.0（男鞋起始码）
    shoe = 3.0;  

    // while 循环核心：条件判断 + 循环体
    // 条件：鞋码 < 18.5 时持续循环
    while (shoe < 18.5)  
    {
        // 脚长计算公式：SCALE * shoe + ADJUST
        foot = SCALE * shoe + ADJUST;  
        // 格式化输出：鞋码占 10 字符，脚长保留 2 位小数
        printf("%10.1f  %15.2f inches\n", shoe, foot);  

        // 鞋码递增 1.0（下次循环处理下一个码数）
        shoe = shoe + 1.0;  
    }
    // 循环结束后执行：提示语
    printf("If the shoe fits, wear it.\n");  

    return 0;
}
/*
Shoe size (men's)  foot length
       3.0             8.31 inches
       4.0             8.64 inches
       5.0             8.97 inches
       6.0             9.31 inches
       7.0             9.64 inches
       8.0             9.97 inches
       9.0            10.31 inches
      10.0            10.64 inches
      11.0            10.97 inches
      12.0            11.31 inches
      13.0            11.64 inches
      14.0            11.97 inches
      15.0            12.31 inches
      16.0            12.64 inches
      17.0            12.97 inches
      18.0            13.30 inches
If the shoe fits, wear it.
*/