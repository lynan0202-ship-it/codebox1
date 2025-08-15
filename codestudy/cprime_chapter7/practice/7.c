/*
1. 题目问题：编写程序，提示用户输入一周工作小时数，假设基本工资、加班工资计算方式、税金分段计算规则，用 #define 定义符号常量，计算并打印工资总额、税金、净收入。
2. 问题要点与知识点：运用 #define 定义常量，通过条件判断计算正常工时和加班工时工资，再分段计算税金，涉及宏定义、条件判断、数学运算、工资税金计算逻辑知识点。
*/

#include <stdio.h>
#define BASE_HOUR 40     // 基础工作小时数
#define OVERTIME_RATE 1.5  // 加班工资倍数
#define BASE_PAY 10.00    // 基础时薪
#define TAX1 300         // 税金分段 1 额度
#define TAX1_RATE 0.15   
#define TAX2 150         // 税金分段 2 额度
#define TAX2_RATE 0.20
#define TAX3_RATE 0.25

int main() {
    float hours;
    printf("输入一周工作的小时数：");
    scanf("%f", &hours);
    // 计算总工资
    float grossPay;
    if (hours <= BASE_HOUR) {
        grossPay = hours * BASE_PAY;
    } else {
        grossPay = BASE_HOUR * BASE_PAY + (hours - BASE_HOUR) * BASE_PAY * OVERTIME_RATE;
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
    return 0;
}