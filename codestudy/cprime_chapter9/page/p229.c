/* 
知识要点总结：
1. 变量作用域与内存地址：
   - 局部变量：在函数（如 `main`、`mikado` ）内部定义的变量（`pooh`、`bah` ）是局部变量，作用域仅限当前函数，不同函数的同名变量（如 `main` 的 `pooh` 和 `mikado` 的 `pooh` ）是独立的，内存地址不同，互不干扰。
   - 地址 `&` 运算符：`&变量名` 可获取变量的内存地址，用 `%p` 格式符可在 `printf` 中打印地址，观察不同变量、不同函数中变量的地址差异。
2. 函数参数传递（值传递）：
   - 当调用函数 `mikado(pooh)` 时，`main` 中的 `pooh`（值为 2 ）以“值传递”方式传给 `mikado` 的形参 `bah` 。形参 `bah` 是新的局部变量，有自己的内存地址，修改形参 `bah` 的值不会影响 `main` 中 `pooh` 的值，体现值传递的“单向传递、互不影响”特点。
3. 函数原型与调用：
   - 函数调用前需声明原型（`void mikado(int);` ），让编译器知晓函数的参数和返回值类型；`main` 中调用 `mikado` 时，实参与形参类型需匹配（这里 `int` 类型兼容 ），保证调用合法。
4. 内存地址的表示：
   - 不同系统打印地址的格式可能不同（如十六进制 ），但 `%p` 会按系统约定格式输出地址。通过观察地址，能直观看到不同变量在内存中是独立存储的，加深对“变量本质是内存中一块空间”的理解。

代码总体逻辑说明：
程序定义 `mikado` 函数和 `main` 函数。`main` 作为入口，先定义局部变量 `pooh`（值 2 ）和 `bah`（值 5 ），打印它们的值和地址；然后调用 `mikado(pooh)` ，将 `pooh` 的值传递给 `mikado` 的形参 `bah` 。`mikado` 函数内部定义自己的局部变量 `pooh`（值 10 ），打印该 `pooh` 和形参 `bah` 的值与地址。通过对比 `main` 和 `mikado` 中变量的地址和值，清晰展示“局部变量作用域独立、值传递不影响原变量”的特性，帮助理解变量内存管理和函数参数传递规则。
*/

#include <stdio.h>  // 引入标准输入输出库，使用 printf 函数

// 函数原型声明：告知编译器 mikado 函数接收一个 int 参数，无返回值
void mikado(int);  

int main(void) 
{
    // main 函数的局部变量：pooh 和 bah
    int pooh = 2, bah = 5;  

    // 打印 main 函数中 pooh 的值和地址
    printf("In main(), pooh = %d and &pooh = %p\n", pooh, &pooh);  
    // 打印 main 函数中 bah 的值和地址
    printf("In main(), bah = %d and &bah = %p\n", bah, &bah);  

    // 调用 mikado 函数，将 main 中的 pooh 的值（2 ）传递给 mikado 的形参 bah
    mikado(pooh);  

    return 0;  // 程序正常结束
}

// 函数定义：mikado 接收一个 int 类型参数 bah
void mikado(int bah) 
{
    // mikado 函数的局部变量 pooh，与 main 的 pooh 是不同变量
    int pooh = 10;  

    // 打印 mikado 函数中 pooh 的值和地址
    printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);  
    // 打印 mikado 函数中 bah（形参，接收 main 传递的值 ）的值和地址
    printf("In mikado(), bah = %d and &bah = %p\n", bah, &bah);  
}

/* 
代码测试及验证建议方案：
1. 基础地址与值验证：
   - 编译运行代码，观察输出中 `pooh`、`bah` 在 `main` 和 `mikado` 中的值和地址，确认不同函数的同名变量地址不同（如 `main` 的 `pooh` 地址和 `mikado` 的 `pooh` 地址不重复 ），验证局部变量的独立性。
   - 检查值传递效果：`main` 的 `pooh` 值为 2 ，传递给 `mikado` 的 `bah` 后，`mikado` 的 `bah` 值是 2 ，但修改 `mikado` 的 `bah`（如 `bah = 3;` ）不会影响 `main` 的 `pooh` ，体会值传递的“单向性”。
2. 变量作用域测试：
   - 在 `mikado` 函数中尝试访问 `main` 的 `bah` 变量（直接写 `printf("%d", bah);` ，但这里 `bah` 是 `mikado` 的形参，若删去形参 `bah` ，会报错 ），验证局部变量作用域仅限当前函数，无法访问其他函数的局部变量。
   - 在 `main` 函数中尝试访问 `mikado` 的 `pooh` 变量（如 `printf("%d", pooh);` ，`pooh` 是 `mikado` 的局部变量 ），会报错，强化对作用域的理解。
3. 地址格式与系统差异：
   - 在不同操作系统（Windows、Linux、macOS ）或编译器（gcc、clang、MSVC ）下运行代码，观察地址 `%p` 的输出格式（如十六进制长度、前缀 `0x` 等 ），理解地址表示因系统而异，但变量独立性的本质不变。
   - 尝试修改变量类型（如 `double pooh = 2.0;` ），观察地址和值的输出变化，体会不同类型变量在内存中的存储方式（地址连续分配、占用字节数不同 ）。
4. 函数原型与调用测试：
   - 故意删除 `mikado` 函数原型声明（`void mikado(int);` ），在旧编译器（如不严格的 C 编译器 ）中观察是否报错，理解函数原型在现代编译器中对类型检查的重要性（现代编译器通常会警告或报错，提示隐式声明函数 ）。
   - 修改函数调用参数类型（如 `mikado(3.5);` ，传递 `double` 类型 ），观察编译器报错信息，体会函数参数类型匹配的要求（需 `int` 类型，编译器会尝试隐式转换或报错 ）。
5. 拓展与易错点测试：
   - 定义全局变量 `int global_pooh = 1;` ，在 `main` 和 `mikado` 中访问，观察全局变量的地址和作用域（全局变量地址固定，所有函数可访问 ），对比局部变量，理解全局变量和局部变量的区别。
   - 尝试在函数中定义同名的局部变量和全局变量（如 `int pooh = 1;` 全局，`main` 中 `int pooh = 2;` ），观察输出，理解“局部变量优先”的屏蔽规则，避免实际编程中因同名变量导致逻辑错误。 
*/