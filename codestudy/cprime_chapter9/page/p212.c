/* 
知识要点总结：
1. 函数相关：
   - 函数原型声明：掌握 `void show_n_char(char ch, int num);` 这种带参数的函数原型写法，明确它告知编译器函数返回值类型、参数个数及类型。
   - 函数定义：理解带形式参数（`char ch, int num` ）的函数定义结构，形式参数是函数私有的局部变量，每次调用函数时会被实际参数赋值，完成特定功能（这里是打印指定字符 `num` 次 ）。
   - 函数调用：学会在 `main` 函数中用不同形式的实际参数（常量、变量、表达式等 ）调用函数，如 `show_n_char('*', WIDTH)` （常量作实参 ）、`show_n_char(SPACE, spaces)` （变量作实参 ）、`show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2)` （表达式作实参 ），明白实参的值会传递给形参。
2. 预处理指令：加深对 `#include <stdio.h>`（引入标准输入输出库 ）、`#include <string.h>`（引入字符串处理库，使用 `strlen` 函数 ）、`#define` 定义常量（`NAME`、`ADDRESS` 等 ）的理解，体会常量在统一配置程序内容（如公司信息、宽度 ）方面的作用。
3. 字符串处理：认识 `strlen` 函数（来自 `<string.h>` ），用于计算字符串的长度（不包含终止符 `\0` ），在计算空格数量时发挥作用（如 `(WIDTH - strlen(ADDRESS)) / 2` ）。
4. 变量类型与作用域：巩固局部变量（如 `show_n_char` 里的 `count` 、`main` 里的 `spaces` ）的概念，它们作用域仅限所在函数，不同函数同名变量不冲突。
5. 循环结构：熟练运用 `for` 循环（如 `for (count = 1; count <= num; count++)` ）实现重复操作，完成按次数打印字符的任务。

代码总体逻辑说明：
程序先通过预处理指令引入必要的库（`stdio.h` 用于输入输出，`string.h` 用于字符串长度计算 ），定义公司名称、地址等常量以及宽度常量 `WIDTH` 。接着声明 `show_n_char` 函数原型。`main` 函数作为入口，先调用 `show_n_char` 打印星号分隔栏，然后通过计算空格数量（利用 `strlen` 和表达式 ），调用 `show_n_char` 打印空格，让公司名称、地址、地点等信息在指定宽度（`WIDTH` ）内居中显示，最后再次调用 `show_n_char` 打印星号分隔栏收尾。`show_n_char` 函数内部借助 `for` 循环和 `putchar` 函数，根据传入的字符 `ch` 和次数 `num` ，完成打印指定字符 `num` 次的功能。整体通过函数封装通用功能（打印指定字符指定次数 ），结合实参的不同形式，实现复杂排版输出，体现函数参数传递、模块化编程的思想。
*/

#include <stdio.h>
#include <string.h>  // 引入字符串处理库，因为要使用 strlen 函数
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

// 函数原型声明，告诉编译器函数返回值类型、函数名、参数类型和个数
void show_n_char(char ch, int num);  

int main(void) 
{
    int spaces;  // 定义变量 spaces，用于存储计算得到的空格数量

    // 调用 show_n_char 函数，用常量 '*' 和 WIDTH 作实参，打印星号分隔栏
    show_n_char('*', WIDTH);  
    putchar('\n');  // 换行，让后续内容另起一行

    // 调用 show_n_char 函数，用常量 SPACE 和 12 作实参，打印 12 个空格
    show_n_char(SPACE, 12);  
    printf("%s\n", NAME);  // 打印公司名称

    // 计算使 ADDRESS 居中需要的空格数量：(总宽度 - 地址长度) / 2 
    spaces = (WIDTH - strlen(ADDRESS)) / 2;  
    // 调用 show_n_char 函数，用变量 spaces 作实参，打印对应数量空格
    show_n_char(SPACE, spaces);  
    printf("%s\n", ADDRESS);  // 打印公司地址

    // 计算使 PLACE 居中需要的空格数量，用表达式作实参直接传递
    show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);  
    printf("%s\n", PLACE);  // 打印公司所在地点

    // 再次调用 show_n_char 函数，打印星号分隔栏
    show_n_char('*', WIDTH);  
    putchar('\n');  // 换行

    return 0;  // main 函数返回 0，程序正常结束
}

// 函数定义：实现打印字符 ch 共 num 次的功能，返回值类型 void（无返回值 ）
void show_n_char(char ch, int num) 
{
    int count;  // 定义局部变量 count，控制循环次数
    // for 循环：从 1 开始，只要 count 小于等于 num 就执行循环体，每次 count 加 1
    for (count = 1; count <= num; count++) 
    {
        putchar(ch);  // 每次循环打印字符 ch
    }
}

/* 
代码测试及验证建议方案：
1. 基础功能验证：
   - 编译运行代码，观察输出是否和书中示例一致（公司信息居中，星号栏宽度正确 ）。若一致，说明函数调用、参数传递、排版逻辑基本正确。
   - 修改 `WIDTH` 的值（比如改成 50 ），重新编译运行，看内容是否依然居中，星号栏宽度是否改变，验证宽度常量对整体排版的影响。
2. 函数参数测试：
   - 尝试修改函数调用时的实参，比如把 `show_n_char('*', WIDTH)` 改成 `show_n_char('@', WIDTH)` ，看星号栏是否变成 `@` 符号栏，检验字符参数传递是否正常。
   - 故意传非法实参（如给 `show_n_char` 传字符参数用整数类型变量 ，虽然 C 语言会隐式转换，但可观察效果 ），理解实参和形参类型匹配以及隐式转换规则，也可测试传负数 `num` ，看函数如何处理（可能循环不执行或异常，理解循环条件边界情况 ）。
3. 字符串与计算测试：
   - 修改公司信息常量（如 `NAME` 改成更长的字符串 ），看 `strlen` 计算是否正确，排版是否依然居中，检验字符串长度计算和空格数量计算逻辑。
   - 把 `(WIDTH - strlen(ADDRESS)) / 2` 这类表达式直接写在函数调用实参位置（如 `show_n_char(SPACE, (WIDTH - strlen(ADDRESS)) / 2)`  ），和用变量 `spaces` 传递对比，看功能是否一致，体会实参用表达式的写法。
4. 函数拓展测试：
   - 新增一个自定义函数（如 `print_footer` ），功能是打印固定格式的页脚信息，在 `main` 函数合适位置调用，检验函数拓展和多函数协作时参数传递、程序流程的把控。
5. 易错点与边界测试：
   - 在 `show_n_char` 函数里，把 `for` 循环条件改成 `count < num` ，看打印次数是否少 1 ，理解循环条件对执行次数的影响，这是容易出错的地方。
   - 让 `strlen` 计算的字符串包含特殊字符（如 `NAME` 改成 `"GIGA@THINK, INC."`  ），看排版是否受影响，检验对字符串长度计算和排版逻辑的鲁棒性。 
*/