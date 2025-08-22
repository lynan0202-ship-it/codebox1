// ------------------------------
// 题干：实现油耗计算的核心逻辑，用文件作用域的静态变量存储状态
// 知识要点：
//  1. 静态全局变量（文件作用域，内部链接，仅本文件访问）
//  2. 模式有效性检查（保留上一次有效模式）
//  3. 分支逻辑（公制/美制的输入和计算）
// 总体逻辑：
//  1. 定义3个static变量：current_mode（当前模式）、distance（距离）、fuel（燃料）
//  2. set_mode：处理模式输入，无效则保留历史有效模式
//  3. get_info：根据模式提示用户输入距离和燃料
//  4. show_info：根据模式计算油耗并输出
#include <stdio.h>
#include "pe12-2a.h"

// 文件作用域的静态变量（仅本文件可见）
static int current_mode = 0;   // 初始为0（公制模式：升/100公里）
static double distance = 0.0;  // 存储距离（公里或英里）
static double fuel = 0.0;      // 存储燃料（升或加仑）

// 设置模式：处理无效输入，更新current_mode
void set_mode(int mode) {
    if (mode == -1) {          // -1是退出信号，直接返回
        return;
    }
    // 检查模式是否有效（只能是0或1）
    if (mode != 0 && mode != 1) {
        printf("Invalid mode specified. Mode (%d) used.\n", current_mode);
    } else {
        current_mode = mode;   // 有效模式则更新
    }
}

// 获取输入：根据current_mode提示用户输入数据
void get_info(void) {
    if (current_mode == 0) {   // 公制模式：输入公里和升
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    } else {                   // 美制模式：输入英里和加仑
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
    }
}

// 显示油耗：根据current_mode计算并输出结果
void show_info(void) {
    if (current_mode == 0) {   // 公制计算：升/100公里 = (燃料 ÷ 距离) × 100
        double consumption = (fuel / distance) * 100;
        printf("Fuel consumption is %.2f liters per 100 km.\n", consumption);
    } else {                   // 美制计算：英里/加仑 = 距离 ÷ 燃料
        double consumption = distance / fuel;
        printf("Fuel consumption is %.2f miles per gallon.\n", consumption);
    }
}

// 测试验证方案：
//  1. 怎么运行：和pe12-2b.c一起编译（`gcc pe12-2b.c pe12-2a.c -o fuel`），运行./fuel
//  2. 预期输入输出（示例）：
//     → 输入0 → 600 → 78.8 → 输出13.13 liters per 100 km
//     → 输入1 → 434 → 12.7 → 输出34.2 miles per gallon
//     → 输入3 → 提示无效，使用上次模式（如1）→ 输入388 →15.3 → 输出25.4 miles per gallon
//  3. 检查点：
//     - 无效模式是否触发提示？
//     - 公制/美制计算是否符合公式？
// 易错点提醒：
//  1. 忘记给static变量赋初始值（current_mode默认0是公制，符合题意）
//  2. scanf中漏写&符号（如&distance），导致无法正确输入
// 拓展思考：
//  1. 若要支持“同时显示公制和美制结果”，如何修改show_info？
// 对比说明：
//  静态全局变量 vs 普通全局变量：
//  - 静态全局（static）：仅本文件可见，避免跨文件冲突
//  - 普通全局：跨文件可见（需extern引用），本题要求“文件作用域、内部链接”，故必须用static