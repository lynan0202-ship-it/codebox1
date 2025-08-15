//七、指针相关运算符（2 个 ：* 解引用、& 取地址 ）
#include <stdio.h>
int main() {
    int num = 20; 
    // 指针变量 ptr，存储 num 的地址 
    int *ptr = &num; 

    // 1. 取地址运算符 & 
    // 功能：获取变量的内存地址，赋给指针 
    printf("num 的地址：%p\n", &num); // 输出类似 0x7ffe... ，不同环境地址不同 

    // 2. 解引用运算符 * 
    // 功能：通过指针访问它指向的变量的值 
    printf("通过指针访问 num 的值：%d\n", *ptr); // 20 

    // 通过指针修改变量值 
    *ptr = 30; 
    printf("修改后，num 的值：%d\n", num); // 30 

    return 0;
}
/*
num 的地址：000000000061FE44
通过指针访问 num 的值：20
修改后，num 的值：30
*/