/*
 * File: p202.c
 * Purpose: [Add a brief description of the file's intended functionality here.]
 * Author: [Your Name]
 * Date: [Date]
 *
 * [Add any relevant notes or documentation here.]
以下是整合教材中 “混合输入（字符 + 数值）问题与解决方案” 的完整代码，包含 原始问题代码（showcharl.c）→ 
优化后代码（showchar2.c），注释详细梳理知识要点、问题根源和优化逻辑：
*/
/* 
知识要点与总体逻辑说明：
1. 核心场景：程序需要混合使用 getchar()（读字符）和 scanf()（读数值）处理输入
2. 原始问题根源：
   - getchar() 会读取所有字符（包括空格、换行符）
   - scanf() 读取数值时会跳过空白符（空格、换行、制表符），但会残留换行符
   - 两者混用导致输入缓冲区残留字符（如换行符），干扰下一轮输入
3. 优化目标：
   - 清理输入缓冲区残留的换行符、多余字符
   - 让程序能正确处理多轮输入，交互更友好
4. 关键技术：
   - 理解 getchar() 和 scanf() 的输入特性差异
   - 用 while 循环清理输入缓冲区（吃掉残留字符）
   - 用条件判断（scanf() 返回值）校验输入合法性 
*/

#include <stdio.h>

// 打印字符的函数：按指定行数、列数重复打印字符
void display(char cr, int lines, int width);

// ---------------------------
// 1. 原始版本（教材程序清单 8.5：showcharl.c）
// 问题：混合使用 getchar() 和 scanf() 导致输入残留，程序异常退出
// ---------------------------
void showcharl_demo() {
    int ch;          // 用 int 存字符（兼容 EOF 检测）
    int rows, cols;  // 行数、列数

    printf("\n----- 原始版本（showcharl.c）：存在输入残留问题 -----\n");
    printf("Enter a character and two integers:\n");

    // 循环条件：当读取的字符不是换行符时，继续处理
    while ((ch = getchar()) != '\n') {
        // 问题点1：scanf 读取数值时，若输入格式不对（如非数字），返回值 < 2，程序会异常
        // 问题点2：输入残留（如换行符、多余字符）会被下一轮 getchar() 读取，导致逻辑异常
        scanf("%d %d", &rows, &cols);
        // 传递字符时，显式转换类型（消除编译器警告）
        display((char)ch, rows, cols);

        printf("Enter another character and two integers:\n");
        printf("Enter a newline to quit.\n");
    }

    printf("Bye.\n");
}

// ---------------------------
// 2. 优化版本（教材程序清单 8.6：showchar2.c）
// 解决：清理输入缓冲区残留字符，校验 scanf() 输入合法性
// ---------------------------
void showchar2_demo() {
    int ch;          // 用 int 存字符（兼容 EOF 检测）
    int rows, cols;  // 行数、列数

    printf("\n----- 优化版本（showchar2.c）：清理残留 + 校验输入 -----\n");
    printf("Enter a character and two integers:\n");

    // 循环条件：当读取的字符不是换行符时，继续处理
    while ((ch = getchar()) != '\n') {
        // 优化1：校验 scanf() 输入是否合法（是否成功读入2个数值）
        if (scanf("%d %d", &rows, &cols) != 2) {
            printf("Input error! Please enter two integers.\n");
            // 清理输入缓冲区剩余字符（避免影响下一轮输入）
            while (getchar() != '\n') continue;
            // 跳过本次循环，重新输入
            continue;
        }

        // 传递字符时，显式转换类型（消除编译器警告）
        display((char)ch, rows, cols);

        // 优化2：清理输入缓冲区残留字符（如多余的换行符、空格）
        // 作用：避免残留字符被下一轮 getchar() 读取，导致循环异常
        while (getchar() != '\n') continue;

        printf("Enter another character and two integers:\n");
        printf("Enter a newline to quit.\n");
    }

    printf("Bye.\n");
}

// 字符打印函数实现：按 rows 行、width 列打印字符 cr
void display(char cr, int lines, int width) {
    int row, col;

    // 外层循环：控制行数
    for (row = 1; row <= lines; row++) {
        // 内层循环：控制每行打印的字符数量（列数）
        for (col = 1; col <= width; col++) {
            putchar(cr);
        }
        putchar('\n');  // 每行结束后换行
    }
}

int main(void) {
    // 先运行原始版本，演示问题
    showcharl_demo();
    // 再运行优化版本，对比效果
    showchar2_demo();

    return 0;
}

/* 
代码测试与验证建议：
1. 原始版本测试（showcharl_demo）：
   - 正常输入：如输入 'c' 2 3（按回车），观察打印是否正确
   - 异常输入：
     - 输入 'c' a 3（非数字），看程序是否异常退出
     - 输入 'c' 2（少一个数字），看程序是否异常
     - 输入后直接按回车，看程序是否提前退出
2. 优化版本测试（showchar2_demo）：
   - 重复测试上述异常输入，观察程序是否：
     - 提示"Input error! Please enter two integers."
     - 清理残留字符，允许重新输入
   - 测试多轮输入（如 'c' 2 3 → '!' 4 5 → 换行退出），看是否正常

通过对比两个版本的运行效果，能理解：
- getchar() 和 scanf() 的输入特性差异（换行符残留、空白符处理）
- 如何用循环清理输入缓冲区，避免残留字符干扰
- 如何用 scanf() 返回值校验输入合法性，让程序更健壮 
*/

/*

----- 原始版本（showcharl.c）：存在输入残留问题 -----
Enter a character and two integers:
'c' 2 3
Enter another character and two integers:
Enter a newline to quit.
Enter another character and two integers:
Enter a newline to quit.
'''
'''
Enter another character and two integers:
Enter a newline to quit.
Bye.

----- 优化版本（showchar2.c）：清理残留 + 校验输入 -----
Enter a character and two integers:
PS C:\code\codebox1> ^C
PS C:\code\codebox1>
PS C:\code\codebox1>  & 'c:\Users\33515\.vscode\extensions\ms-vscode.cpptools-1.26.3-win32-x64\debugAdapters\bin\WindowsDebugLauncher.exe' '--stdin=Microsoft-MIEngine-In-ozefkobi.ogt' '--stdout=Microsoft-MIEngine-Out-r3u2ttpa.k2z' '--stderr=Microsoft-MIEngine-Error-pnd3qhj4.syf' '--pid=Microsoft-MIEngine-Pid-abkis4ea.ctu' '--dbgExe=C:\Program Files\mingw64\bin\gdb.exe' '--interpreter=mi'

----- 原始版本（showcharl.c）：存在输入残留问题 -----
Enter a character and two integers:
'c' 2 3
Enter another character and two integers:
Enter a newline to quit.
Enter another character and two integers:
Enter a newline to quit.
'''
'''
Enter another character and two integers:
Enter a newline to quit.
Bye.

----- 优化版本（showchar2.c）：清理残留 + 校验输入 -----
Enter a character and two integers:
'c' 2 3
Input error! Please enter two integers.
'c' a 3
Input error! Please enter two integers.
'c' 2
Input error! Please enter two integers.
2 3

^Z
*/