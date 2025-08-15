/*
1. 题目问题：修改练习 7，用 switch 实现工资等级选择菜单，根据选择的等级计算工资，程序循环运行直到选择退出，输入无效时提示重新输入。
2. 问题要点与知识点：结合 switch 实现多分支选择，处理用户输入验证，循环控制程序流程，涉及 switch 语法、循环、输入验证、多工资等级处理知识点。
*/

#include <stdio.h>
#define RATE1 8.75
#define RATE2 9.33
#define RATE3 10.00
#define RATE4 11.20
#define BASE_HOUR 40     // 基础工作小时数
#define OVERTIME_RATE 1.5  // 加班工资倍数
#define TAX1 300         // 税金分段 1 额度
#define TAX1_RATE 0.15   
#define TAX2 150         // 税金分段 2 额度
#define TAX2_RATE 0.20
#define TAX3_RATE 0.25

int main() {
    int choice;
    while (1) {
        printf("*************************\n");
        printf("1) $%.2f/hr\n", RATE1);
        printf("2) $%.2f/hr\n", RATE2);
        printf("3) $%.2f/hr\n", RATE3);
        printf("4) $%.2f/hr\n", RATE4);
        printf("5) quit\n");
        printf("*************************\n");
        printf("Enter the number corresponding to the desired pay rate or action: ");
        scanf("%d", &choice);
        if (choice == 5) {  // 选择退出
            break;
        } else if (choice < 1 || choice > 4) {  // 输入无效
            printf("输入无效，请重新输入正确的选项！\n");
            continue;
        }
        float hours;
        printf("输入工作的小时数：");
        scanf("%f", &hours);
        // 根据选择的等级计算时薪
        float rate;
        switch (choice) {
            case 1:
                rate = RATE1;
                break;
            case 2:
                rate = RATE2;
                break;
            case 3:
                rate = RATE3;
                break;
            case 4:
                rate = RATE4;
                break;
            default:
                rate = 0;
        }
        // 计算总工资
        float grossPay;
        if (hours <= BASE_HOUR) {
            grossPay = hours * rate;
        } else {
            grossPay = BASE_HOUR * rate + (hours - BASE_HOUR) * rate * OVERTIME_RATE;
        }
        // 计算税金
        float tax = 0;
        if (grossPay > TAX1 + TAX2) {
            tax = TAX1 * TAX1_RATE + TAX2 * TAX2_RATE + (grossPay - TAX1 - TAX2) * TAX3_RATE;
        } else if (grossPay > TAX1) {
            tax = TAX1 * TAX1_RATE + (grossPay - TAX1) * TAX2_RATE;
        } else {
            tax = grossPay * TAX1_RATE;
        }
        // 计算净收入
        float netPay = grossPay - tax;
        printf("工资总额：%.2f 美元\n", grossPay);
        printf("税金：%.2f 美元\n", tax);
        printf("净收入：%.2f 美元\n", netPay);
    }
    return 0;
}