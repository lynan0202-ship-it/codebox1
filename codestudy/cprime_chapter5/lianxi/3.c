#include <stdio.h>
// 定义 1 周 = 7 天
const int DAYS_PER_WEEK = 7;  

int main(void) {
    int days;
    printf("=== 天数转周数 + 天数 ===\n");

    while (1) {
        printf("请输入天数（≤0 退出）：");
        scanf("%d", &days);

        if (days <= 0) {
            printf("退出程序！\n");
            break;
        }

        // 计算周数和剩余天数
        int weeks = days / DAYS_PER_WEEK;
        int remaining_days = days % DAYS_PER_WEEK;

        printf("%d 天 = %d 周 %d 天\n", days, weeks, remaining_days);
    }

    return 0;
}
/*
=== 天数转周数 + 天数 ===
请输入天数（≤0 退出）：20
20 天 = 2 周 6 天
请输入天数（≤0 退出）：-3
*/