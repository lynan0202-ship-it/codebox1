/*
1. 题目问题：编写程序，只接受正整数输入，然后显示所有小于或等于该数的素数。
2. 问题要点与知识点：通过嵌套循环判断素数，外层循环遍历待判断数，内层循环验证是否为素数，涉及素数判断算法、循环嵌套、条件判断知识点。
*/

#include <stdio.h>
#include <stdbool.h>  // 使用 bool 类型

int main() {
    int num;
    printf("输入一个正整数：");
    scanf("%d", &num);
    printf("小于等于 %d 的素数有：", num);
    for (int i = 2; i <= num; i++) {  // 遍历 2 到输入数
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {  // 判断是否为素数
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {  // 是素数则输出
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}