/* 
知识要点总结（主逻辑模块）：
1. 多文件协作：
   - 通过 `#include "hotel.h"` 包含头文件，获取符号常量和函数原型，调用 `hotel.c` 中实现的函数，实现主逻辑与函数实现的分离，让代码结构清晰。
2. 程序流程控制：
   - 在 `main` 函数中，用 `menu` 获取用户选择，根据选择的酒店编号设置房价，再调用 `getnights` 获取入住天数，最后用 `showprice` 计算并显示费用；如果选择退出（编号 5 ），结束程序，体现多函数协作完成业务流程。
3. 输入输出交互：
   - 结合 `menu`、`getnights` 的输入校验逻辑，保证用户输入合法，程序鲁棒性强（不会因非法输入崩溃 ）。

本文件总体逻辑：
作为程序入口，`main` 函数协调各个模块（`menu` 选酒店、`getnights` 要天数、`showprice` 算费用 ），通过循环让用户可重复选择酒店、输入天数，直到选择退出。把复杂业务拆分成多个函数，每个函数做一件事，符合模块化编程思想。
*/

#include "hotel.h"  // 包含自定义头文件，使用常量和函数声明
#include <stdio.h>

int main(void)
{
    int nights;       // 入住天数
    double hotel_rate; // 所选酒店的房价
    int code;         // 菜单选择编号

    // 循环：只要选择不是退出（QUIT=5 ），就继续执行
    while ((code = menu()) != QUIT)
    {
        // 根据选择的酒店编号，设置对应的房价
        switch (code)
        {
            case 1: hotel_rate = HOTEL1; break;
            case 2: hotel_rate = HOTEL2; break;
            case 3: hotel_rate = HOTEL3; break;
            case 4: hotel_rate = HOTEL4; break;
            default: 
                hotel_rate = 0.0; 
                printf("Oops!\n"); 
                break; // 理论上不会走到这，menu 已校验输入
        }

        // 获取入住天数
        nights = getnights();
        // 计算并显示总费用
        showprice(hotel_rate, nights);
    }

    printf("Thank you and goodbye.\n");
    return 0;
}