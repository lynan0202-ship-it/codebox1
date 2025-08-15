#include <stdio.h>
// 标准 main 函数写法
int main(void) { 
    // 应是 int 类型，因为 legs / 4 结果是整数 
    int cows, legs; 
    printf("How many cow legs did you count?\n");
    // %d 用于输入整数
    scanf("%d", &legs); 
    cows = legs / 4;
    // %d 输出整数 cows 
    printf("That implies there are %d cows.\n", cows); 
    return 0;
}