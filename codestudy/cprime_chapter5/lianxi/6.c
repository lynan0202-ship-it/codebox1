#include <stdio.h>

int main(void) {
    int days;
    double total = 0.0;
    printf("=== 计算 N 天平方和收入 ===\n");
    printf("请输入天数 N：");
    scanf("%d", &days);

    // 累加 1²+2²+...+days²
    for (int i = 1; i <= days; i++) {
        total += i * i;  // 第 i 天赚 $i²
    }

    printf("%d 天的平方和收入：$%.2f\n", days, total);

    return 0;
}
/*
=== 计算 N 天平方和收入 ===
请输入天数 N：6
6 天的平方和收入：$91.00
*/