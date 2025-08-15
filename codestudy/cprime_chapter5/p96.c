//size_t
// sizeof.c -- 使用 sizeof 运算符
// 包含标准输入输出头文件，让程序可以使用 printf 函数
#include <stdio.h>
// 使用 C99 新增的 %zd 转换说明 -- 如果编译器不支持 %zd，请将其改成 %u 或 %lu
// 这是为了适配不同环境下打印 size_t 类型数据的需求

int main(void)
{
    // 定义一个 int 类型的变量 n，并初始化为 0
    int n = 0;
    // 定义一个 size_t 类型的变量 intsize，size_t 是用于存储大小（字节数）的无符号整数类型
    size_t intsize;

    // 计算 int 类型所占的字节数，并把结果赋值给 intsize
    // sizeof (int) 中的 int 是类型，运算对象是类型时要用圆括号括起来
    intsize = sizeof (int);
    // 打印相关信息：
    // %d 用于打印 int 类型的 n 的值
    // %zd 用于打印 size_t 类型的数据，这里分别打印 sizeof n（变量 n 所占字节数）和 intsize（int 类型所占字节数）
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", 
           n, sizeof n, intsize);
    // 注意：sizeof n 中运算对象是变，量名 n，圆括号可加可不加，习惯上对于变量也常省略圆括号，写成 sizeof n

    // 程序正常结束，返回 0
    return 0;
}
/*
n = 0, n has 4 bytes; all ints have 4 bytes.
*/