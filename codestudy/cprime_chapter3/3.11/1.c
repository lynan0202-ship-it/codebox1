#include <stdio.h>
int main() {
    // 整数上溢，不同系统 int 范围不同，这里用超过范围值测试，如 32 位 int 最大约 21 亿 
    int int_overflow = 2147483647 + 1; 
    printf("Integer overflow: %d\n", int_overflow);
    
    // 浮点上溢，超过 float 能表示的最大值 
    float float_overflow = 3.4e38 * 10; 
    printf("Float overflow: %f\n", float_overflow);
    
    // 浮点下溢，接近 0 的极小值 
    float float_underflow = 1.0e-38 / 10000; 
    printf("Float underflow: %f\n", float_underflow);
    return 0;
}