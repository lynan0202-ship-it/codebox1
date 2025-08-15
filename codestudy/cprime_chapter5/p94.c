/* 
 * divide.c -- 演示除法运算 
 * 程序通过不同类型（整数、浮点）的运算数，展示 C 语言中除法的不同表现：
 * 包括整数除法（截断小数）、浮点除法（保留小数）、混合类型除法（自动类型转换）
 */
#include <stdio.h>  // 包含标准输入输出函数（如 printf 等），让程序能输出结果
int main(void)
{
    // 1. 整数除法：运算数都是整数时，结果会截断小数部分（只保留整数商）
    // 5 和 4 都是 int 类型，5/4 结果是 1（丢弃小数 0.25 部分）
    printf("Integer division: 5/4 is %d \n", 5 / 4);  
    // 6 和 3 是 int 类型，6/3 结果是 2（能整除，无小数）
    printf("Integer division: 6/3 is %d \n", 6 / 3);  
    // 7 和 4 是 int 类型，7/4 结果是 1（截断小数 0.75 部分）
    printf("Integer division: 7/4 is %d \n", 7 / 4);  

    // 2. 浮点除法：运算数至少有一个是浮点数时，结果会保留小数（按浮点规则计算）
    // 7.0 是 double 类型，4 会被自动转成 double，7.0/4 结果是 1.75
    printf("floating division: 7.0/4 is %1.2f \n", 7.0 / 4);  

    // 3. 混合类型除法：运算数一个是浮点、一个是整数时，C 会自动把整数转成浮点再计算
    // 7 是 int 类型，会被转成 double 后参与运算，结果和 7.0/4 一样是 1.75
    printf("mixed division: 7/4.0 is %1.2f \n", 7 / 4.0);  

    return 0;  // 程序正常结束，返回 0 
}
/*
Integer division: 5/4 is 1 
Integer division: 6/3 is 2 
Integer division: 7/4 is 1 
floating division: 7.0/4 is 1.75 
mixed division: 7/4.0 is 1.75 
*/