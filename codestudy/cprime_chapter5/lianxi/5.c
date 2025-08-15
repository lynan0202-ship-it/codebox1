#include <stdio.h>

int main(void) {
    int days;
    double total = 0.0;
    printf("=== 计算 N 天总收入 ===\n");
    printf("请输入天数 N：");
    scanf("%d", &days);

    // 累加 1~days 的和
    for (int i = 1; i <= days; i++) {
        total += i;  // 第 i 天赚 $i
    }

    printf("%d 天的总收入：$%.2f\n", days, total);

    return 0;
}
/*
=== 计算 N 天总收入 ===
请输入天数 N：
6 天的总收入：$21.00
*/