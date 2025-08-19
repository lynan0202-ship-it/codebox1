/* 
知识要点总结：
1. 函数参数传递（值传递）：
   - 当调用 `interchange(x, y)` 时，`main` 中的 `x`、`y` 会**拷贝值**给 `interchange` 的形参 `u`、`v` ，形参和实参是独立的变量（内存地址不同 ）。
   - 修改形参 `u`、`v` 的值不会影响 `main` 中 `x`、`y` 的值，体现**值传递的“单向性”**（形参变化不反馈给实参 ）。
2. 函数定义与调用：
   - 函数声明（`void interchange(int u, int v);` ）让编译器提前知道函数的参数和返回值类型；`main` 中调用函数时，实参类型要与形参匹配（这里都是 `int` ）。
3. 变量作用域：
   - `main` 中的 `x`、`y` 和 `interchange` 中的 `u`、`v` 是**不同作用域的变量**，即使同名（如果修改示例让变量同名 ），内存地址也不同，互不干扰。

代码总体逻辑说明：
`main` 函数定义 `x=5`、`y=10` ，打印初始值后调用 `interchange` 函数尝试交换值。`interchange` 函数内用临时变量交换 `u`、`v` 的值，但因为是值传递，`main` 中的 `x`、`y` 不会被改变。程序通过打印对比，展示值传递的特点——形参交换不影响实参。
*/

#include <stdio.h>

// 函数声明：告知编译器函数的参数和返回值类型
void interchange(int u, int v);  

int main(void)
{
    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x, y);
    
    // 调用交换函数，但值传递无法改变 x、y 原值
    interchange(x, y);  
    
    printf("Now x = %d and y = %d.\n", x, y);
    return 0;
}

// 函数定义：尝试交换 u 和 v 的值（但不影响实参 ）
void interchange(int u, int v)
{
    int temp;
    printf("Originally u = %d and v = %d.\n", u, v);
    
    // 交换形参 u、v 的值
    temp = u;
    u = v;
    v = temp;
    
    printf("Now u = %d and v = %d.\n", u, v);
}

/* 
测试及验证建议方案：
1. 基础运行验证：
   - 编译运行 `gcc swap1.c -o swap1 && ./swap1` ，观察输出：
     - `main` 中 `x`、`y` 初始值 `5`、`10` ；
     - `interchange` 中 `u`、`v` 交换为 `10`、`5` ；
     - `main` 中 `x`、`y` 仍为 `5`、`10` ，验证值传递不影响实参。
2. 变量地址观察（拓展）：
   - 在 `main` 和 `interchange` 中添加 `printf("x addr: %p, u addr: %p\n", &x, &u);` ，观察实参 `x` 和形参 `u` 的地址不同，理解“值传递是拷贝值，不是共享地址”。
3. 同名变量测试（易混淆点）：
   - 修改 `interchange` 形参为 `x`、`y`（`void interchange(int x, int y)` ），重新编译运行，观察地址和值变化，强化“同名变量作用域不同，内存独立”的理解。
*/