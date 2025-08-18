/* 
知识要点总结：
1. 字符输入输出：getchar() 逐字符读取、putchar() 输出字符，处理输入流细节
2. 输入验证：过滤无效输入，清理缓冲区残留字符，保证程序健壮性
3. 菜单交互：while 循环维持交互，switch 分支处理选项，实现用户界面
4. 混合输入：兼容字符与数值输入，解决 scanf/getchar 混用的缓冲区问题
5. 函数封装：拆分输入处理、业务逻辑，让代码模块化、可复用

总体逻辑：
1. 主程序通过 get_choice() 获取用户输入（自动验证有效性）
2. 根据选项执行对应功能（建议输出、响铃、计数、退出）
3. 计数功能（count()）中，用 get_int() 处理数值输入验证，避免非法输入干扰
4. 所有输入操作均清理缓冲区，保证后续输入不受残留字符影响 
*/

#include <stdio.h>

// 读取一行第一个有效字符，丢弃剩余字符（清理缓冲区）
char get_first(void);
// 获取用户菜单选择（仅返回 a/b/c/q，自动过滤无效输入）
char get_choice(void);
// 数值输入验证：确保输入整数，清理非法字符，支持重新输入
int get_int(void);
// 执行计数逻辑，依赖 get_int 处理合法数值输入
void count(void);

int main(void) {
    char choice;

    // 持续交互直到用户输入 'q'
    while ((choice = get_choice()) != 'q') {
        switch (choice) {
            case 'a':
                printf("Buy low, sell high.\n");  // 输出投资建议
                break;
            case 'b':
                putchar('\a');  // 触发响铃（ANSI 标准，终端会发声/显示特殊符号）
                break;
            case 'c':
                count();  // 执行计数功能（含数值输入验证）
                break;
            default:
                // 理论上不会触发，因 get_choice 已过滤无效值
                printf("Program error! Please contact developer.\n");
                break;
        }
    }

    printf("Program exited successfully.\n");
    return 0;
}

// --- 核心函数实现 ---

char get_choice(void) {
    char ch;

    // 显示菜单，引导用户输入
    printf("\nEnter the letter of your choice:\n");
    printf("a. Investment advice\n");
    printf("b. Play a bell sound\n");
    printf("c. Count numbers\n");
    printf("q. Quit program\n");

    // 获取第一个有效字符，过滤无关输入
    ch = get_first();
    // 验证输入是否为菜单选项，否则循环提示
    while ((ch < 'a' || ch > 'c') && ch != 'q') {
        printf("Invalid input! Please respond with a, b, c, or q.\n");
        ch = get_first();  // 重新获取输入
    }

    return ch;
}

char get_first(void) {
    char ch;

    ch = getchar();  // 读取输入流第一个字符
    // 丢弃该行剩余字符（直到遇到换行符），避免干扰后续输入
    while (getchar() != '\n') {
        continue;
    }

    return ch;
}

int get_int(void) {
    int input;
    char ch;

    // scanf 返回 1 表示成功读取整数，否则进入清理逻辑
    while (scanf("%d", &input) != 1) {
        // 清理缓冲区残留的非数字字符
        while ((ch = getchar()) != '\n') {
            putchar(ch);  // 回显错误输入，方便用户检查
        }
        // 提示用户重新输入合法整数
        printf(" is not a valid integer.\n");
        printf("Please enter an integer (e.g., 1, -10, 100): ");
    }

    return input;
}

void count(void) {
    int n, i;

    printf("How many numbers do you want to count? Enter an integer: ");
    n = get_int();  // 调用数值验证函数，确保输入合法

    printf("Counting result: ");
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

/* 
代码测试与验证方案：

一、基础功能测试
1. 菜单交互：
   - 输入 a → 检查是否输出 "Buy low, sell high."
   - 输入 b → 检查终端响铃/特殊符号（\a 效果因系统而异）
   - 输入 q → 检查程序退出，输出 "Program exited successfully."

2. 无效字符处理：
   - 输入 x → 提示重新输入，直到输入 a/b/c/q
   - 输入 abc123 → 检查是否仅取 'a'，执行对应功能，剩余字符被清理

二、混合输入验证（count 功能）
1. 合法数值：
   - 输入 5 → 输出 1 2 3 4 5
   - 输入 -2 → 检查循环逻辑（i <= n 无输出，验证边界情况）
   - 输入 0 → 检查是否无计数输出（或根据需求调整逻辑）

2. 非法数值：
   - 输入 abc → 提示错误，重新输入 3 后正常计数
   - 输入 12.3 → 过滤小数，仅取 12 计数
   - 输入空行 → 循环提示，直到输入整数

三、缓冲区清理验证
1. 连续错误输入：
   - 输入 x → 提示 → 输入 12.5 → 提示 → 输入 10 → 检查计数是否为 1-10
   - 验证后续输入不受之前错误的影响

2. 跨平台测试：
   - 在 Windows/Linux/Mac 终端运行 → 检查响铃（\a）、换行符处理是否一致
   - 验证 getchar 清理逻辑是否兼容不同系统的行结束符（\r\n 或 \n）

四、模块化验证
1. 注释/删除 get_first 中清理缓冲区的逻辑 → 测试输入 abc 后，后续 get_choice 是否被残留字符干扰
2. 修改 get_int 的提示文本 → 检查用户体验是否清晰，验证输入逻辑是否健壮

建议通过手动输入覆盖所有分支，结合调试工具（如 gdb 跟踪变量值），确保输入处理、菜单交互、混合输入逻辑完全符合教材知识点，验证程序在各种场景下的鲁棒性。
*/