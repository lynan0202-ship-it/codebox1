/* 
知识要点：
1. 字符输入处理：用 getchar 读取字符，解决 scanf 残留缓冲区问题
2. 输入验证逻辑：通过循环过滤无效输入，确保程序健壮性
3. 菜单交互设计：while 循环持续交互，switch 分支处理选项
4. 混合输入处理：兼容字符和数值输入，清理缓冲区残留数据
5. 函数封装思想：将输入处理、业务逻辑拆分，提升代码模块化

总体逻辑：
1. 主程序通过 get_choice 获取用户输入（自动过滤无效值）
2. 根据选项执行对应操作（a:建议 / b:响铃 / c:计数 / q:退出）
3. 计数功能（count）需处理数值输入验证，确保输入为整数
4. 所有输入操作均清理缓冲区，避免残留字符干扰后续逻辑 
*/

#include <stdio.h>

// 获取用户选择（仅返回 a/b/c/q），封装菜单显示与输入验证
char get_choice(void);
// 读取一行第一个字符，丢弃剩余字符（清理输入缓冲区）
char get_first(void);
// 数值输入验证函数（替代原 count 功能，演示混合输入处理）
int get_int(void);
// 执行计数逻辑（依赖 get_int 处理输入）
void count(void);

int main(void) {
    int choice;

    // 持续交互直到用户输入 'q'
    while ((choice = get_choice()) != 'q') {
        switch (choice) {
            case 'a':
                printf("Buy low, sell high.\n");  // 执行建议输出
                break;
            case 'b':
                putchar('\a');  // 执行响铃（ANSI 标准）
                break;
            case 'c':
                count();  // 执行计数功能（含数值输入验证）
                break;
            default:
                // 理论上不会触发，因 get_choice 已过滤无效值
                printf("Program error!\n");
                break;
        }
    }

    printf("Bye.\n");
    return 0;
}

// --- 核心函数实现 ---

char get_choice(void) {
    int ch;

    // 显示菜单选项（引导用户输入）
    printf("Enter the letter of your choice:\n");
    printf("a. advice\tb. bell\n");
    printf("c. count\tq. quit\n");

    // 获取第一个有效字符（过滤空行/无效输入）
    ch = get_first();
    // 若输入不在 a-c 且不是 q，循环提示重新输入
    while (((ch < 'a' || ch > 'c') && ch != 'q')) {
        printf("Please respond with a, b, c, or q.\n");
        ch = get_first();  // 重新获取输入
    }

    return ch;
}

char get_first(void) {
    int ch;

    ch = getchar();  // 读取第一个字符
    // 丢弃该行剩余字符（直到遇到换行符，清理缓冲区）
    while (getchar() != '\n') {
        continue;
    }

    return ch;
}

// 数值输入验证：确保输入为整数，否则循环提示
int get_int(void) {
    int input;
    char ch;

    // scanf 返回值 !=1 表示输入失败（非整数）
    while (scanf("%d", &input) != 1) {
        // 清理缓冲区残留的非数字字符
        while ((ch = getchar()) != '\n') {
            putchar(ch);  // 回显错误输入（方便用户排查）
        }
        // 提示重新输入整数
        printf(" is not an integer.\nPlease enter an integer value, such as 25, -178, or 3: ");
    }

    return input;
}

// 计数功能实现（依赖 get_int 处理输入）
void count(void) {
    int n, i;

    printf("Count how far? Enter an integer: ");
    n = get_int();  // 调用数值验证函数

    printf("Counting: ");
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

/* 
代码测试与验证方案：

一、基础功能验证
1. 字符输入测试：
   - 输入 a → 检查是否输出 "Buy low, sell high."
   - 输入 b → 检查是否触发响铃（终端可见 \a 效果）
   - 输入 q → 检查是否退出程序，输出 "Bye."

2. 无效字符测试：
   - 输入 x → 检查是否提示重新输入，直到输入 a/b/c/q
   - 输入多个字符（如 abc）→ 检查是否仅取第一个字符，丢弃剩余内容

二、混合输入验证（count 功能）
1. 有效数值测试：
   - 输入 5 → 检查是否输出 1-5 的计数
   - 输入 -3 → 检查是否输出 1-(-3)（因循环 i<=n，实际无输出，需观察逻辑是否合理）
   - 输入 0 → 检查是否无计数输出（或根据需求调整逻辑）

2. 无效数值测试：
   - 输入 abc → 检查是否提示错误，重新输入后正常计数
   - 输入 12.3 → 检查是否过滤小数部分，仅取 12 计数
   - 输入 （空行）→ 检查是否循环提示，直到输入整数

三、边界场景测试
1. 连续错误输入：
   - 输入 x → 提示 → 输入 12.5 → 提示 → 输入 10 → 检查计数是否为 1-10
   - 验证缓冲区清理是否彻底，后续输入不受影响

2. 跨平台测试：
   - 在 Windows/Linux/Mac 终端运行 → 检查响铃（\a）、换行符处理是否一致
   - 验证 getchar 清理缓冲区逻辑是否兼容不同系统的行结束符（\r\n 或 \n）

四、模块化验证
1. 注释/删除 get_first 中清理缓冲区的逻辑 → 测试输入 abc 后，后续 get_choice 是否受残留字符影响
2. 修改 get_int 的提示文本 → 检查用户体验是否清晰，验证输入逻辑是否健壮

可通过手动输入覆盖所有分支，结合调试工具（如 gdb 跟踪变量 ch、input 的值），确保输入处理、菜单交互、混合输入逻辑完全符合教材知识点与设计预期。
*/