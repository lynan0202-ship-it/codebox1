/*
1. 题目问题：编写程序读取整数直到用户输入 0，结束后报告输入的偶数（不包括 0）个数、平均值，奇数个数、平均值。
2. 问题要点与知识点：利用循环读取整数，通过取余操作判断奇偶，进行数量和求和的累加，最后计算平均值，涉及输入、循环、条件判断、数学运算知识点。
*/

#include <stdio.h>

int main() {
    int num;                // 存储用户输入的整数
    int evenCount = 0;      // 统计偶数个数
    int oddCount = 0;       // 统计奇数个数
    int evenSum = 0;        // 累加偶数的和
    int oddSum = 0;         // 累加奇数的和

    // 提示用户输入数据
    printf("输入整数（输入 0 结束）：\n");

    // 循环读取用户输入，直到输入 0 结束
    while (1) {                   //
        scanf("%d", &num);      // 读取一个整数
        if (num == 0) {         // 如果输入为 0，跳出循环
            break;
        }
        // 判断当前输入的数是否为偶数
        if (num % 2 == 0) {     // 偶数条件：能被 2 整除
            evenCount++;        // 偶数个数加 1
            evenSum += num;     // 偶数累加到 evenSum
        } else {                // 否则为奇数
            oddCount++;         // 奇数个数加 1
            oddSum += num;      // 奇数累加到 oddSum
        }
    }

    // 输出偶数统计结果，注意防止除以 0
    if (evenCount > 0) {
        // 平均值 = 总和 / 个数，类型转换保证小数精度
        printf("偶数个数：%d，平均值：%.2f\n", evenCount, (float)evenSum / evenCount);
    } else {
        printf("没有输入偶数\n");
    }

    // 输出奇数统计结果，注意防止除以 0
    if (oddCount > 0) {
        printf("奇数个数：%d，平均值：%.2f\n", oddCount, (float)oddSum / oddCount);
    } else {
        printf("没有输入奇数\n");
    }

    return 0;   // 程序结
}