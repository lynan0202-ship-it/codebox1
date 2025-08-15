#include <stdio.h>

int main() {
    int upper, lower;
    // 循环处理输入，直到上限 < 下限
    while (1) {  
        printf("请输入上限和下限（用空格分隔）: ");
        // 输入两个整数
        if (scanf("%d %d", &upper, &lower) != 2) {  
            break; // 输入非数字，退出循环
        }
        // 终止条件：上限 < 下限
        if (upper < lower) {  
            printf("Done\n");
            break;
        }

        int sum = 0;
        // 遍历上限到下限，累加平方
        for (int num = lower; num <= upper; num++) {  
            sum += num * num;
        }
        printf("平方和: %d\n", sum);
    }
    printf("WRONG IN NUM UP");
    return 0;
}
/*
请输入上限和下限（用空格分隔）: 10 4
平方和: 371
请输入上限和下限（用空格分隔）: 34 16
平方和: 12445
请输入上限和下限（用空格分隔）: 30 1
平方和: 9455
请输入上限和下限（用空格分隔）: 23 H
WRONG IN NUM UP
*/