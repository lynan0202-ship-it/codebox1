// ------------------------------
// 题干：d. （拓展）基于 9.c 的最小程序，实现菜单选项功能（如 copy files 打印提示 ）
// 知识要点：
//  1. 多分支流程控制（switch-case 处理不同选项 ）
//  2. 函数的完整流程（显示 → 输入 → 执行功能 ）
//  3. 程序功能扩展（将 “获取输入” 与 “执行逻辑” 结合 ）
// 总体逻辑：
//  1. 复用 9.a/9.b 的函数获取用户选择
//  2. 通过 switch-case 判断选项，执行对应功能（打印提示模拟实际操作 ）
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
    int choice = get_choice(1, 4); 
    printf("\n你选择的选项是：%d\n", choice);

    // 根据选择执行对应功能（模拟实现）
    switch (choice) {
        case 1:
            printf("→ 模拟执行「copy files」：文件复制中...（实际需结合文件操作实现）\n");
            break;
        case 2:
            printf("→ 模拟执行「move files」：文件移动中...\n");
            break;
        case 3:
            printf("→ 模拟执行「remove files」：文件删除中...（注意测试环境，避免误删 ）\n");
            break;
        case 4:
            printf("→ 执行「quit」：程序退出\n");
            break;
        default:
            printf("→ 无效选项（通常不会走到这里，因 get_choice 已校验 ）\n");
    }

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：
//     - 保存代码为 exercise_9d.c
//     - 编译：gcc exercise_9d.c -o exercise_9d 
//     - 运行：./exercise_9d（Linux/Mac） 或 exercise_9d.exe（Windows）
//  2. 预期结果：
//     - 输入 1-4 ：执行对应模拟功能（如 copy/move 提示 ）
//     - 输入 4 ：程序退出
//  3. 检查点：
//     - 验证功能分支是否正确（switch-case 匹配 ）
//     - 验证输入校验与功能执行的完整流程
// 易错点提醒：
//  1. switch-case 容易忘记写 break ，导致“穿透”执行多个分支
//  2. 模拟危险操作（如 remove ）时，需注释提醒测试环境，避免误删文件
// 拓展思考：
//  1. 如何真正实现 “copy files” 功能？（结合文件操作函数 fopen/fread/fwrite ）
//  2. 如果菜单选项动态变化（如配置文件定义 ），如何重构代码？（用数组存储菜单 ）