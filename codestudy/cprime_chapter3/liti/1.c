#include <stdio.h>
int main(void)  // 明确返回类型和参数列表
{
    float g, b;
    float tax, rate = 0.1f;  // 初始化 rate 为 0.1

    g = 1e21f;  // 修正为有效的浮点数常量（1×10²¹）
    tax = rate * g;  // 使用已初始化的 rate

    printf("Tax: %e\n", tax);  // 输出计算结果（可选）
    
    return 0;  // 添加返回语句
}