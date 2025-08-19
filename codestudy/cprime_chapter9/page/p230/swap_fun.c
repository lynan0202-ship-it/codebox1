// 实现交换函数，无需包含头文件（但建议包含，用于自洽检查 ）
#include "swap_fun.h"  

// 函数定义：和单文件版本逻辑一致
void interchange(int *u, int *v)
{
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}