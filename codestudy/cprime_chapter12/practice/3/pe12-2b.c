// ------------------------------
// 题干：主程序，通过自动变量和指针传递，驱动油耗计算逻辑
// 知识要点：
//  1. 自动变量的作用域（主函数内的FuelData和input_mode）
//  2. 循环控制（直到输入-1退出）
//  3. 函数调用的指针传递（修改主函数变量）
#include <stdio.h>
#include "pe12-2a.h"

int main(void) {
    FuelData data;      // 自动变量：存储模式、距离、燃料（替代全局变量）
    int input_mode;     // 自动变量：用户输入的模式

    init_data(&data);   // 初始化数据（也可直接写 data.current_mode = 0; 等）

    // 第一次提示输入模式
    printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
    scanf("%d", &input_mode);

    // 循环：输入-1时退出，否则处理模式、输入、显示
    while (input_mode != -1) {
        set_mode(&data, input_mode); // 传递data的地址，让函数修改它
        get_info(&data);             // 传递地址，输入数据
        show_info(&data);            // 传递地址，显示结果

        // 下一轮提示
        printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
        scanf("%d", &input_mode);
    }

    printf("Done.\n"); // 退出提示
    return 0;
}