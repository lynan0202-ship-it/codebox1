
#include <stdio.h>
int main() {
    // Daphne 的本金（固定 100 美元 ）
    double daphne = 100.0;  
    // Deirdre 的本金（固定 100 美元 ）
    double deirdre = 100.0;  
    int year = 0;

    // 循环：直到 Deirdre 的投资 > Daphne
    while (deirdre <= daphne) {  
        // Daphne 每年利息：100 * 5% = 5 美元（固定 ）
        daphne += 100 * 0.05;  
        // Deirdre 每年利息：当前金额的 5%（复利 ）
        deirdre += deirdre * 0.05;  
        year++; // 计数年份
    }

    printf("需要 %d 年，Deirdre 投资超过 Daphne\n", year);
    printf("Daphne 的最终金额：%.2f 美元\n", daphne);
    printf("Deirdre 的最终金额：%.2f 美元\n", deirdre);

    return 0;
}

/*
需要 2 年，Deirdre 投资超过 Daphne
Daphne 的最终金额：110.00 美元
Deirdre 的最终金额：110.25 美元
*/