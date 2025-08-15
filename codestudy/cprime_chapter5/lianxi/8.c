#include <stdio.h>

/**
 * @brief 将华氏温度转换为摄氏温度
 * 
 * 转换公式：摄氏温度 = (华氏温度 - 32) × 5/9
 * 
 * @param fahrenheit 华氏温度值
 * @return double 转换后的摄氏温度值
 */
double fahrenheitToCelsius(double fahrenheit) {
    return 5.0 / 9.0 * (fahrenheit - 32.0);
}

/**
 * @brief 将摄氏温度转换为开氏温度
 * 
 * 转换公式：开氏温度 = 摄氏温度 + 273.16
 * 
 * @param celsius 摄氏温度值
 * @return double 转换后的开氏温度值
 */
double celsiusToKelvin(double celsius) {
    return celsius + 273.16;
}

/**
 * @brief 主函数：程序入口点
 * 
 * 功能：接收用户输入的华氏温度，转换为摄氏和开氏温度并显示，
 *       输入非数字时退出程序
 * 
 * @return int 程序执行状态（0表示成功）
 */
int main(void) {
    // 声明变量存储华氏温度
    double fahrenheit;
    
    // 显示程序标题
    printf("=== 温度转换（华氏 → 摄氏 + 开氏）===\n");

    // 无限循环：持续接收用户输入直到输入无效
    while (1) {
        // 提示用户输入华氏温度
        printf("请输入华氏温度（输入字母退出）：");
        
        // 读取用户输入并判断是否为有效数字
        // scanf返回成功读取的变量个数，若不为1则表示输入无效
        if (scanf("%lf", &fahrenheit) != 1) {
            printf("退出程序！\n");
            break;  // 跳出循环，结束程序
        }

        // 调用转换函数计算摄氏温度
        double celsius = fahrenheitToCelsius(fahrenheit);
        // 调用转换函数计算开氏温度
        double kelvin = celsiusToKelvin(celsius);

        // 输出转换结果，保留2位小数
        // %f用于格式化浮点数，.2指定保留2位小数
        printf("华氏：%.2f°F → 摄氏：%.2f°C → 开氏：%.2fK\n", 
               fahrenheit, celsius, kelvin);
    }

    return 0;  // 程序正常结束
}