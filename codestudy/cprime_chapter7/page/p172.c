/*
以下是对教程中 break.c 程序结合 break 核心知识点的详细注释，覆盖 break 在循环中的作用、嵌套循环控制、与 continue 的区别等内容：
1. 基础 break 用法示例（break.c 原程序）
*/

// break.c -- 演示 break 退出循环的用法（教材程序清单 7.10）
#include <stdio.h>

int main(void)
{
    float length, width;  // 存储矩形的长和宽

    // 提示用户输入矩形长度，说明输入非数字可退出
    printf("Enter the length of the rectangle:\n");
    // 循环条件：scanf 成功读取 1 个浮点数（%f）则继续，否则退出
    while (scanf("%f", &length) == 1) {  

        // 打印当前长度（保留 2 位小数）
        printf("length = %.2f\n", length);  
        // 提示用户输入宽度
        printf("Enter its width:\n");       

        // --------------------- break 核心用法：输入非数字时退出循环 --------------------- 
        // 条件：scanf 读取宽度失败（返回值 != 1，如输入 q）
        if (scanf("%f", &width) != 1) {     
            // 遇到非数字输入，执行 break 跳出当前 while 循环
            break;                           
        }

        // 读取宽度成功，打印宽度（保留 2 位小数）
        printf("width = %.2f\n", width);     
        // 计算并打印面积（长 * 宽）
        printf("Area = %.2f\n", length * width);  

        // 提示用户输入下一个矩形的长度，或输入非数字退出
        printf("Enter the length of the rectangle:\n");  
    }

    // 循环结束后执行：提示程序结束
    printf("Done.\n");  
    return 0;
}
/*
注释与知识点对应：
break 基础逻辑：if (scanf("%f", &width) != 1) break; → 当输入非数字时，break 直接跳出当前 while 循环，结束矩形面积计算流程。
循环条件关联：while (scanf("%f", &length) == 1) → 利用 scanf 返回值控制循环，break 是 “主动退出循环” 的补充（区别于条件不满足退出）。
流程简化：对比 “不用 break 需嵌套复杂条件”，break 让 “输入异常时退出” 逻辑更简洁，覆盖教材 “用 break 处理异常退出” 的知识点。
*/

/*
Enter the length of the rectangle:
34
length = 34.00
Enter its width:
4.5
width = 4.50
Area = 153.00
Enter the length of the rectangle:
34
length = 34.00
Enter its width:
q
Done.
*/