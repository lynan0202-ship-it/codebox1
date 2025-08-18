/* 
问题6题干：修改程序清单8.8中的get_first()函数，让该函数返回读取的第1个非空白字符，并在一个简单的程序中测试。

知识要点：
1. 空白字符处理：跳过空格、换行、制表符等空白符
2. 函数封装：实现 `get_first()` 函数，专注返回第一个非空白字符
3. 输入清理：读取并丢弃后续字符（选做，本题简化）

总体逻辑：
1. 实现 `get_first()` 函数：
   - 循环读取字符，跳过空白符
   - 返回第一个遇到的非空白字符
2. 在主程序中测试该函数，读取用户输入的第一个非空白字符

代码功能：
封装 `get_first()` 函数，返回输入的第一个非空白字符
*/

#include <stdio.h>
#include <ctype.h> // 包含 isspace() 函数

// 函数定义：返回第一个非空白字符
int get_first(void) {
    int ch;

    // 跳过空白字符
    while ((ch = getchar()) != EOF && isspace(ch)) {
        continue;
    }

    // 返回第一个非空白字符（或 EOF）
    return ch;
}

int main() {
    int ch;

    printf("Enter some text (with leading spaces): ");
    ch = get_first(); // 获取第一个非空白字符

    printf("The first non-whitespace character is: ");
    if (ch != EOF) {
        putchar(ch);
        printf(" (ASCII: %d)\n", ch);
    } else {
        printf("EOF\n");
    }

    return 0;
}

/* 
测试验证方案：
1. 基本测试：
   - 输入 `   Hello`，输出应为 `H`（跳过
*/