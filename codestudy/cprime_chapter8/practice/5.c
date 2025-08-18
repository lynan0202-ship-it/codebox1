/* 
问题5题干：修改猜数字程序，使用二分查找策略。初始猜50，根据用户反馈（大了、小了、正确）调整范围，直到猜中。

知识要点：
1. 二分查找算法：每次取中间值，缩小查找范围
2. 用户交互：读取用户输入（字符）判断反馈
3. 循环控制：根据反馈调整查找范围（low, high）

总体逻辑：
1. 初始化范围（low=1, high=100）、猜测值、反馈字符
2. 循环猜测：
   - 计算中间值（mid = (low + high) / 2）
   - 提示用户猜测结果，读取反馈（g: 大了, l: 小了, c: 正确）
   - 根据反馈调整范围：
     - 大了（g）：high = mid - 1
     - 小了（l）：low = mid + 1
     - 正确（c）：结束循环
3. 输出结果（猜中或范围错误）

代码功能：
用二分查找策略实现智能猜数字游戏，最少次数猜中用户想的数字（1-100）
*/

#include <stdio.h>

int main() {
    char response;
    int low = 1, high = 100;
    int mid;

    printf("Think of a number between 1 and 100.\n");
    printf("I will guess it using binary search!\n");

    while (low <= high) {
        mid = (low + high) / 2; // 二分查找，取中间值
        printf("Is your number %d? (g: too high, l: too low, c: correct) ", mid);
        response = getchar();

        // 清理缓冲区残留字符（避免影响下次输入）
        while (getchar() != '\n') {
            continue;
        }

        if (response == 'g') { // 猜大了，调整上限
            high = mid - 1;
        } else if (response == 'l') { // 猜小了，调整下限
            low = mid + 1;
        } else if (response == 'c') { // 猜中
            printf("I got it! Your number is %d.\n", mid);
            return 0;
        } else { // 无效输入
            printf("Invalid response. Please enter g, l, or c.\n");
        }
    }

    // 如果范围无效（用户可能作弊）
    printf("Error: No number in the range %d-%d.\n", low, high);
    return 0;
}

/* 
测试验证方案：
1. 正常测试：
   - 想数字 25，程序猜测流程：
     50 (g) → 25 (c) → 猜中
   - 观察是否在 log2(100) ≈7 次内猜中

2. 边界测试：
   - 想数字 1：程序应依次猜 50(g)→25(g)→12(g)→6(g)→3(g)→2(g)→1(c)
   - 想数字 100：程序应依次猜 50(l)→75(l)→87(l)→93(l)→96(l)→98(l)→99(l)→100(c)

3. 作弊测试：
   - 故意反馈矛盾（如数字 50，第一次猜 50 时说 g），观察范围错误提示
*/