/* 
知识要点：
1. 字符输入输出：使用 getchar、printf 处理字符交互，理解输入缓冲区机制
2. 输入验证：通过循环和条件判断过滤无效输入，确保程序健壮性
3. 菜单逻辑：利用 while 循环实现持续交互，switch 分支处理不同选项
4. 函数封装：将输入处理、菜单逻辑拆分到独立函数，提升代码模块化

总体逻辑：
1. 程序启动后进入主循环，通过 get_choice 获取用户输入（自动过滤无效值）
2. 根据用户选择（a/b/c/q），用 switch 执行对应操作或退出程序
3. get_choice 负责显示菜单、调用 get_first 处理输入，确保只返回有效选项（a/b/c/q）
4. get_first 处理输入缓冲区，只读取第一个有效字符，丢弃行内剩余字符（含换行符） 
*/

#include <stdio.h>

// 获取用户选择（仅返回 a/b/c/q），封装菜单显示与输入验证逻辑
char get_choice(void);
// 读取一行的第一个字符，丢弃该行剩余字符（解决输入缓冲区残留问题）
char get_first(void);
// 演示用计数函数（可扩展实际功能）
void count(void);

int main(void) {
    int choice;

    // 持续交互直到用户输入 'q'
    while ((choice = get_choice()) != 'q') {
        switch (choice) {
            case 'a':
                printf("Buy low, sell high.\n");  // 执行 a 选项逻辑
                break;
            case 'b':
                putchar('\a');  // 执行 b 选项（响铃，ANSI 标准）
                break;
            case 'c':
                count();  // 执行 c 选项（调用计数函数）
                break;
            default:
                // 理论上不会触发，因 get_choice 已过滤无效值
                printf("Program error!\n");
                break;
        }
    }

    printf("Program exit.\n");
    return 0;
}

// --- 函数实现 ---

char get_choice(void) {
    int ch;

    // 显示菜单选项
    printf("Enter the letter of your choice:\n");
    printf("a. advice\tb. bell\n");
    printf("c. count\tq. quit\n");

    // 调用 get_first 获取第一个字符，过滤无效输入
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
    // 丢弃该行剩余字符（直到遇到换行符）
    while (getchar() != '\n') {
        continue;
    }

    return ch;
}

// 示例功能：简单计数演示（可扩展为实际业务逻辑）
void count(void) {
    int i;
    printf("Counting: ");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

/* 
代码测试与验证方案：

一、功能验证（分场景测试）
1. 有效输入测试：
   - 输入 a → 检查是否输出 "Buy low, sell high."
   - 输入 b → 检查是否触发响铃（终端可见 \a 效果）
   - 输入 c → 检查是否执行 count 并输出 1-10
   - 输入 q → 检查是否退出循环，程序结束

2. 无效输入测试：
   - 输入数字（如 1）、特殊字符（如 $）→ 检查是否提示重新输入
   - 输入多个字符（如 abc）→ 检查是否仅读取第一个字符 a，且不触发后续字符的逻辑
   - 输入空行（直接按回车）→ 检查是否提示重新输入

3. 边界场景测试：
   - 连续输入无效值（如 1、2、3）→ 检查是否每次都提示，直到输入有效字符
   - 混合输入（如 a123）→ 检查是否仅取第一个字符 a，丢弃 123 和换行符

二、缓冲区验证（核心痛点）
1. 输入超长内容（如 a followed by many chars）→ 检查 get_first 是否仅保留 'a'，剩余字符被丢弃
2. 输入换行符（单独按回车）→ 检查 get_first 是否正确识别为无效，触发重新输入

三、模块化验证（函数职责）
1. 注释掉 get_first 中丢弃剩余字符的逻辑 → 测试输入 abc 时，是否出现异常（如后续 getchar 读取到 b/c）
2. 修改 get_choice 的菜单选项 → 检查输入验证条件是否需要同步调整（验证逻辑与菜单的关联性）

四、扩展验证（可维护性）
1. 新增菜单选项（如 d. demo）→ 检查 get_choice 的条件判断是否需扩展 (ch < 'a' || ch > 'd')
2. 修改 count 函数逻辑（如计数到 20）→ 检查主程序 switch 是否无需改动（验证函数封装的解耦性） 

可通过手动输入测试 + 调试工具（如查看变量 ch 的值、单步执行函数）验证每一步逻辑，确保输入处理、菜单交互完全符合设计预期。
*/
