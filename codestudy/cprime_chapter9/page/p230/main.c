/* 
知识要点总结（多文件部分）：
1. 多文件拆分：
   - 把函数定义放到单独文件（`swap_fun.c` ），主逻辑放 `main.c` ，通过**头文件（`swap_fun.h` ）共享函数声明**，实现代码模块化。
2. 头文件作用：
   - 用 `swap_fun.h` 声明函数原型（`void interchange(int *u, int *v);` ），让 `main.c` 能调用 `swap_fun.c` 中的函数，避免重复声明。
3. 编译命令：
   - 在 UNIX/Linux 下，用 `gcc main.c swap_fun.c -o swap` 编译多个文件；Windows 下 IDE 需把两个文件加入项目编译，或用 `gcc` 命令行编译。

代码总体逻辑（多文件）：
`main.c` 包含头文件 `swap_fun.h` ，调用 `interchange` 函数；`swap_fun.c` 实现函数逻辑。通过多文件拆分，模拟实际项目中“功能模块分离”的开发方式。
*/

#include <stdio.h>
// 包含头文件，获取函数声明
#include "swap_fun.h"  

int main(void)
{
    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x, y);
    
    // 调用 swap_fun.c 中的函数
    interchange(&x, &y);  
    
    printf("Now x = %d and y = %d.\n", x, y);
    return 0;
}