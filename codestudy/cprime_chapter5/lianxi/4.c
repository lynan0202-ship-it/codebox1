#include <stdio.h>
// 1 英寸 = 2.54 厘米
const double CM_PER_INCH = 2.54;  
// 1 英尺 = 12 英寸
const int INCHES_PER_FOOT = 12;  

int main(void) {
    double height_cm;
    printf("=== 身高转换（厘米 ↔ 英尺+英寸）===\n");

    while (1) {
        printf("请输入身高（厘米，≤0 退出）：");
        scanf("%lf", &height_cm);

        if (height_cm <= 0) {
            printf("退出程序！\n");
            break;
        }

        // 转换为英寸
        double height_inches = height_cm / CM_PER_INCH;
        // 计算英尺和剩余英寸
        int total_inches = (int)height_inches;  // 转换为整数英寸
        int feet = total_inches / INCHES_PER_FOOT;
        double remaining_inches = total_inches % INCHES_PER_FOOT + (height_inches - total_inches);

        // 输出结果（保留 1 位小数）
        printf("%.1f 厘米 = %d 英尺 %.1f 英寸\n", height_cm, feet, remaining_inches);
    }

    return 0;
}


/*
=== 身高转换（厘米 ↔ 英尺+英寸）===

请输入身高（厘米，≤0 退出）：173
173.0 厘米 = 5 英尺 8.1 英寸

请输入身高（厘米，≤0 退出）：23
23.0 厘米 = 0 英尺 9.1 英寸

请输入身高（厘米，≤0 退出）：
*/