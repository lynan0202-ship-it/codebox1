// ------------------------------
// 题干：c. 使用本题 a 和 b 部分的函数编写一个最小型的程序。最小型的意思是，该程序不需要实现菜单中各选项的功能，
//       只需显示这些选项并获取有效的响应即可。
// 知识要点：
//  1. 函数的组合调用（整合 9.a 的菜单显示、9.b 的输入校验 ）
//  2. 程序流程控制（通过函数调用完成 “显示菜单 → 校验输入” 闭环 ）
//  3. 函数返回值的使用（获取合法输入并输出 ）
// 总体逻辑：
//  1. 复用 9.a 的 show_menu 函数显示菜单
//  2. 复用 9.b 的 get_choice 函数获取合法输入
//  3. 在 main 函数中依次调用上述函数，完成 “显示 → 输入 → 输出结果” 的最小流程
#include <stdio.h>

// --------------- 复用 9.a 的函数 ---------------
void show_menu() {
    printf("Please choose one of the following:\n");
    printf("1) copy files          2) move files\n");
    printf("3) remove files        4) quit\n");
    printf("Enter the number of your choice:\n");
}

// --------------- 复用 9.b 的函数 ---------------
int get_choice(int lower, int upper) {
    int input;
    int valid = 0;
    while (!valid) {
        show_menu(); 
        int ret = scanf("%d", &input);
        if (ret != 1) { 
            return 4;
        } else if (input < lower || input > upper) {
            printf("输入超出范围 [ %d-%d ]，请重新输入！\n", lower, upper);
        } else {
            valid = 1;
        }
    }
    return input;
}

int main() {
    // 调用 9.b 的函数获取合法输入（假设选项范围 1-4 ）
    int choice = get_choice(1, 4); 
    printf("\n你选择的有效选项是：%d\n", choice);

    // 程序核心逻辑仅需 “显示菜单 + 校验输入”，无需实现选项功能
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：
//     - 保存代码为 exercise_9c.c
//     - 编译：gcc exercise_9c.c -o exercise_9c 
//     - 运行：./exercise_9c（Linux/Mac） 或 exercise_9c.exe（Windows）
//  2. 预期结果：
//     - 显示菜单 → 输入合法（1-4 ）：输出选择的数字
//     - 输入非法（如 5 或字母 ）：重新显示菜单 → 直到输入合法
//     - 输入非整数（如字母 ）：直接返回 4 并输出
//  3. 检查点：
//     - 验证菜单是否重复显示（输入非法时）
//     - 验证返回值是否符合 9.b 的规则（非整数返回 4 ，合法值在范围内 ）
// 易错点提醒：
//  1. 忘记关联 9.a、9.b 的函数实现，导致编译报错（需确保函数定义完整 ）
//  2. 输入非整数时，scanf 会残留错误输入在缓冲区，可能影响后续逻辑（可额外清理缓冲区，如加 getchar() ）
// 拓展思考：
//  1. 如果想记录用户尝试次数（非法输入次数 ），如何扩展代码？（添加计数器变量 ）
//  2. 如何优化输入体验？比如输入非法时，清空缓冲区避免死循环 