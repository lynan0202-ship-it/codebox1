// ------------------------------
// 题干：实现油耗计算的核心函数，通过指针操作主函数的自动变量
// 知识要点：
//  1. 结构体指针的成员访问（->运算符）
//  2. 分支逻辑（公制/美制的输入和计算）
//  3. 无效模式处理（保留历史有效模式）
#include <stdio.h>
#include "pe12-2a.h"

// 初始化数据：模式设为0（公制），距离和燃料设为0
void init_data(FuelData *data) {
    data->current_mode = 0;  // 初始为公制模式
    data->distance = 0.0;    // 距离初始为0
    data->fuel = 0.0;        // 燃料初始为0
}

// 设置模式：处理用户输入的mode，无效则保留历史有效模式
void set_mode(FuelData *data, int input_mode) {
    if (input_mode == 0 || input_mode == 1) {
        data->current_mode = input_mode; // 有效模式，更新
    } else {
        // 无效模式，提示并保留当前有效模式
        printf("Invalid mode specified. Mode (%d) used.\n", data->current_mode);
    }
}

// 获取输入：根据当前模式提示用户输入距离和燃料
void get_info(FuelData *data) {
    if (data->current_mode == 0) { // 公制模式：公里 + 升
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &data->distance); // 直接修改主函数的distance
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &data->fuel);     // 直接修改主函数的fuel
    } else { // 美制模式：英里 + 加仑
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &data->distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &data->fuel);
    }
}

// 显示油耗：根据模式计算并输出结果
void show_info(const FuelData *data) {
    if (data->current_mode == 0) { // 公制：升/100公里 = (燃料 ÷ 距离) × 100
        double consumption = (data->fuel / data->distance) * 100;
        printf("Fuel consumption is %.2f liters per 100 km.\n", consumption);
    } else { // 美制：英里/加仑 = 距离 ÷ 燃料
        double consumption = data->distance / data->fuel;
        printf("Fuel consumption is %.2f miles per gallon.\n", consumption);
    }
}