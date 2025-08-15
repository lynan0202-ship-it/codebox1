#include <stdio.h>

int main() {
    int lower, upper;
    printf("请输入下限和上限: ");
    // 输入范围
    scanf("%d %d", &lower, &upper);  

    // 打印表头
    printf("整数\t平方\t立方\n");  
    
    // 遍历范围内的整数
    for (int num = lower; num <= upper; num++) {  
        printf("%d\t%d\t%d\n", num, num * num, num * num * num);
    }
    return 0;
}

/*
4       16      64
5       25      125
6       36      216
7       49      343
8       64      512
9       81      729
10      100     1000
*/