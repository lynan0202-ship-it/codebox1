#include <stdio.h>

int main() {
    // 本金 100 万美元（税后 ）
    double money = 1000000.0;  
    int year = 0;

    // 循环：直到账户余额 <= 0
    while (money > 0) {  
        year++; // 计数年份
        // 每年利息：当前金额 × 8%
        money += money * 0.08;  
        // 每年取出 10 万美元
        money -= 100000;  

        // 避免余额为负时的异常显示（可选 ）
        if (money < 0) {  
            money = 0;
        }
    }

    printf("需要 %d 年取完账户的钱\n", year);
    return 0;
}
/*
需要 21 年取完账户的钱
*/