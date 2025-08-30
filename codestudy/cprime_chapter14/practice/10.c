// ------------------------------
// 题干：编写一个程序，通过一个函数指针数组实现菜单。例如，选择菜单中的 a，将激活由该数组第 1 个元素指向的函数。
// 知识要点：
//  1. 函数指针的定义与使用 - 声明指向特定类型函数的指针变量
//  2. 函数指针数组 - 用数组存储多个函数指针，通过索引快速调用不同函数
//  3. 菜单交互逻辑 - 读取用户输入并通过函数指针分发到对应功能
// 总体逻辑：
//  1. 定义多个无参数、无返回值的功能函数（对应不同菜单选项）
//  2. 定义函数指针类型，创建函数指针数组并初始化（每个元素指向一个功能函数）
//  3. 循环显示菜单、读取用户输入
//  4. 根据输入的选项，查找函数指针数组的对应索引，调用目标函数
//  5. 当用户选择“退出”选项时，结束程序循环
#include <stdio.h>

// 定义函数指针类型：指向“无参数、无返回值”的函数
typedef void (*MenuFunc)(void);

// 功能函数1：对应菜单选项a的操作
void func_a(void) {
    printf("你选择了选项 a，执行 func_a 的功能～\n");
}

// 功能函数2：对应菜单选项b的操作
void func_b(void) {
    printf("你选择了选项 b，执行 func_b 的功能～\n");
}

// 功能函数3：对应菜单选项c的操作
void func_c(void) {
    printf("你选择了选项 c，执行 func_c 的功能～\n");
}

// 功能函数：处理“退出程序”的操作
void func_quit(void) {
    printf("触发退出逻辑，准备结束程序～\n");
}

int main() {
    // 函数指针数组：每个元素指向一个菜单功能函数
    MenuFunc menu_functions[] = {func_a, func_b, func_c, func_quit};
    // 菜单选项对应的字符（与函数指针数组索引一一对应）
    char menu_options[] = {'a', 'b', 'c', 'q'};
    // 计算菜单选项的数量
    int num_options = sizeof(menu_options) / sizeof(menu_options[0]);

    char user_choice;   // 存储用户输入的菜单选项
    int is_running = 1; // 程序运行标志（1=继续，0=退出）

    while (is_running) {
        // 显示菜单
        printf("\n=== 菜单 ===\n");
        for (int i = 0; i < num_options; i++) {
            if (menu_options[i] == 'q') {
                printf("%c) 退出程序\n", menu_options[i]);
            } else {
                printf("%c) 执行功能%d\n", menu_options[i], i + 1);
            }
        }
        printf("请输入选项（%c/%c/%c/%c）：", 
               menu_options[0], menu_options[1], menu_options[2], menu_options[3]);
        scanf(" %c", &user_choice); // 加空格跳过输入前的空白符（如换行）

        // 查找用户输入对应的函数索引
        int func_index = -1;
        for (int i = 0; i < num_options; i++) {
            if (user_choice == menu_options[i]) {
                func_index = i;
                break;
            }
        }

        if (func_index != -1) {
            // 通过函数指针数组调用对应的功能函数
            menu_functions[func_index]();

            // 若选择的是“退出”选项（对应字符'q'），设置退出标志
            if (user_choice == 'q') {
                is_running = 0;
            }
        } else {
            printf("无效的选项，请重新输入！\n");
        }
    }

    printf("程序已退出。\n");
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：使用GCC编译代码（如 `gcc menu_funcptr.c -o menu_funcptr`），然后运行可执行文件（如 `./menu_funcptr`）。
//  2. 预期结果：程序循环显示菜单，输入 'a' 会执行 func_a 并输出对应提示；输入 'b' 执行 func_b；输入 'c' 执行 func_c；输入 'q' 执行 func_quit 并退出程序；输入其他字符则提示“无效的选项”。
//  3. 检查点：每个有效选项是否调用了对应的函数并输出正确信息；输入 'q' 时是否能正常结束程序循环。
// 易错点提醒：
//  1. 函数指针数组的初始化：要确保函数的参数和返回值类型与定义的函数指针类型完全匹配（本题为“无参数、无返回值”）。
//  2. `scanf(" %c", &user_choice);` 中 `%c` 前的空格必须加，否则会读取到之前输入的换行符，导致选项识别错误。
//  3. 查找选项索引时，要确保循环遍历所有 `menu_options` 元素，避免因漏判导致 `func_index` 为 -1（无效索引）。
// 拓展思考：
//  1. 如果功能函数需要传递参数或有返回值，如何修改？可以定义带参数/返回值的函数指针类型（如 `typedef int (*FuncPtr)(int);`），并调整函数和函数指针数组的定义。
//  2. 如何动态扩展菜单选项？可以使用动态内存分配（如 `malloc`）来扩展函数指针数组，或在编译时预先定义足够大的数组，运行时动态填充。
//  3. 对比普通 `switch-case` 实现菜单，函数指针数组的优势是什么？函数指针数组让菜单逻辑更“模块化”，新增功能时只需添加函数和更新数组，无需修改大量 `switch-case` 分支，代码更易维护和扩展。