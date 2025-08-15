#include <stdio.h>

int main(void) {
    int mod;
    printf("=== 模运算程序 ===\n");
    printf("请输入模数：");
    scanf("%d", &mod);

    while (1) {
        int num;
        printf("请输入一个数（≤0 退出）：");
        scanf("%d", &num);

        if (num <= 0) {
            printf("退出程序！\n");
            break;
        }

        // 计算模运算
        int result = num % mod;
        printf("%d %% %d = %d\n", num, mod, result);
    }

    return 0;
}