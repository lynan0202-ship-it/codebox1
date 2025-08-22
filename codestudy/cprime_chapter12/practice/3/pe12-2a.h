// ------------------------------
// 题干：重新设计编程练习2，仅使用自动变量，通过指针传递共享数据
// 知识要点：
//  1. 结构体封装数据（模式、距离、燃料）
//  2. 指针传递（函数通过地址修改主函数变量）
//  3. const修饰（只读数据，增强安全性）
// 总体逻辑：
//  1. 定义FuelData结构体，包含当前模式、距离、燃料
//  2. 主函数创建自动变量data，通过指针传递给set_mode/get_info/show_info
//  3. 函数通过指针修改data的值，实现跨函数数据共享（替代全局变量）
#ifndef PE12_2A_H
#define PE12_2A_H

// 封装模式、距离、燃料的数据结构
typedef struct {
    int current_mode; // 0=公制，1=美制（当前有效模式）
    double distance;  // 距离（公里/英里）
    double fuel;      // 燃料（升/加仑）
} FuelData;

// 初始化数据（可选，主函数也可直接赋值）
void init_data(FuelData *data);
// 设置模式：input_mode是用户输入值，data保存有效模式
void set_mode(FuelData *data, int input_mode);
// 获取输入：根据current_mode提示用户输入距离和燃料
void get_info(FuelData *data);
// 显示油耗：根据current_mode计算并输出（const保证不修改数据）
void show_info(const FuelData *data);

#endif