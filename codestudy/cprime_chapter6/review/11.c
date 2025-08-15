#include <stdio.h>
#define SIZE 8
int main(void)
{
    int by_twos[SIZE];
    int index;

    // 问题 1: 数组下标越界
    // 数组下标从 0 开始, 但循环从 index = 1 到 SIZE(即 8)
    // 当 index = 8 时, by_twos[8] 超出数组范围(数组下标最大为 7)
    for (index = 1; index <= SIZE; index++)
        by_twos[index] = 2 * index;

    // 问题 2: printf 中传入数组名, 但 %d 期望单个 int 值
    // 数组名是地址, 直接用 %d 输出会导致未定义行为
    for (index = 1; index <= SIZE; index++)
        printf("%d ", by_twos);

    printf("\n");
    return 0;
}