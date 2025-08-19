// ------------------------------
// 题干：a. 编写一个函数，显示一份有 4 个选项的菜单，提示用户进行选择（输出如下所示）。
//       输出示例：
//       Please choose one of the following:
//       1) copy files          2) move files
//       3) remove files        4) quit
//       Enter the number of your choice:
// 知识要点：
//  1. 函数的定义（无参数，实现简单输出功能）
//  2. 格式化输出（printf 的使用，控制文本格式 ）
// 总体逻辑：
//  1. 定义 `show_menu` 函数，无参数
//  2. 在函数内部，使用 printf 依次输出菜单的提示信息和选项
//  3. 在 `main` 函数中调用 `show_menu` 函数进行测试
#include <stdio.h>

// 定义显示菜单的函数
void show_menu() {
    printf("Please choose one of the following:\n");
    printf("1) copy files          2) move files\n");
    printf("3) remove files        4) quit\n");
    printf("Enter the number of your choice:\n");
}

int main() {
    // 调用函数显示菜单
    show_menu(); 
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：
//     - 保存代码为 menu_a.c
//     - 用 gcc 编译：gcc menu_a.c -o menu_a
//     - 运行：./menu_a（Linux/Mac） 或 menu_a.exe（Windows）
//  2. 预期结果：
//     - 输出符合题干要求的菜单文本
//  3. 检查点：
//     - 确认输出的菜单格式、内容与题目示例一致
// 易错点提醒：
//  1. 容易写错 printf 里的文本内容，导致菜单显示不正确
//  2. 注意空格和换行的控制，保证输出格式美观、符合题目要求
// 拓展思考：
//  1. 如果菜单选项要动态变化（比如根据用户权限显示不同选项 ），怎么修改函数？可以尝试增加参数控制显示内容
//  2. 如何让菜单的输出更美观，比如给选项添加颜色（在支持的终端下，结合转义字符实现 ） 