#include <stdio.h>

int main(void) {
    int num;
    int max;
    
    printf("=== 打印整数范围 ===\n");
    printf("请输入一个整数：");
    scanf("%d", &num);
    
    max=num+10;
    // 循环打印 num 到 num+10
    for (int i = num; i <= max; i++) {
        // 用空格分隔输出
        printf("%d ", i);
    }
    printf("\n");  // 换行结尾

    return 0;
}
/*
=== 打印整数范围 ===
请输入一个整数：12
12 13 14 15 16 17 18 19 20 21 22 
*/