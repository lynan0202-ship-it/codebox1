#include <stdio.h>
#define FREEZING 32  // 定义冰点温度阈值（华氏度）

int main(void)
{
    float temperature;  // 存储每日低温数据
    int cold_days = 0;  // 统计低于冰点的天数，初始化为0
    int all_days = 0;   // 统计总天数，初始化为0

    // 提示用户输入数据及操作方式
    printf("Enter the list of daily low temperatures.\n");
    printf("Use Celsius, and enter q to quit.\n");

    // while循环：持续读取温度数据直到输入非数字
    // scanf返回成功读取的数据个数，当读取到float时返回1，继续循环
    // 当输入q或其他非数字时，返回值不等于1，循环终止
    while (scanf("%f", &temperature) == 1) 
    {
        all_days++;  // 每成功读取一个温度，总天数加1

        // if条件判断：如果温度低于冰点
        // 满足条件时，寒冷天数计数器加1
        if (temperature < FREEZING)  
            cold_days++;  
    }

    // 输出统计结果
    printf("\nTotal days: %d\n", all_days);
    printf("Cold days: %d\n", cold_days);
    // 计算并输出寒冷天数的百分比
    // 使用(float)进行强制类型转换，避免整数除法导致的精度丢失
    printf("Cold days percentage: %.1f%%\n", (float)cold_days / all_days * 100);

    return 0;
}
