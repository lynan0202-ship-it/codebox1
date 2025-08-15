/* prntval.c -- 演示 printf() 的返回值，重点理解输出格式与字符计数逻辑 */
#include <stdio.h>
int main(void)
{
    int bph2o = 212;  // 定义变量存储水的沸点数值（华氏度）
    int rv;           // 用于存储 printf 函数的返回值（输出字符个数）

    // 1. 执行 printf 并捕获返回值
    //    格式说明："%d F is water's boiling point.\n" 是输出模板
    //    %d 会被 bph2o 的值（212）替换，最终输出如 "212 F is water's boiling point.\n"
    //    printf 返回值：本次输出的字符总数（包含空格、标点、换行符等所有字符），赋值给 rv
    rv = printf("%d F is water's boiling point.\n", bph2o);

    // 2. 打印返回值说明
    //    这里用 rv 的值，展示上一条 printf 实际输出了多少个字符
    //    格式中的 %d 会被 rv 的值替换，直观呈现字符计数结果
    printf("The printf() function printed %d characters.\n", rv);

    return 0;
}

/*
212 F is water's boiling point.
The printf() function printed 32 characters.
*/