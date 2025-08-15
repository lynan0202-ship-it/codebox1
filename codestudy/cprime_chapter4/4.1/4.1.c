// talkback.c -- 演示与用户交互
// 包含标准输入输出头文件，用于使用 printf、scanf 等函数
#include <stdio.h>  
// 包含字符串处理头文件，用于使用 strlen 函数（计算字符串长度）
#include <string.h>  
// 定义宏常量 DENSITY，代表人体密度（单位：磅/立方英尺），后续可直接用 DENSITY 代替 62.4
#define DENSITY 62.4  

// 程序入口函数，程序从这里开始执行
int main()
{
    // 定义浮点型变量 weight（存储体重）、volume（存储体积）
    float weight, volume;  
    // 定义整型变量 size（存储数组占用字节数）、letters（存储姓名长度）
    int size, letters;  
    // 定义字符数组 name，最多可存储 39 个有效字符 + 1 个字符串结束符 '\0'，用于存放用户姓名
    char name[40];  

    // 输出提示信息，询问用户的名字
    printf("Hi! What's your first name?\n");  
    // 使用 scanf 读取用户输入的名字，存入 name 数组。%s 按字符串格式读取，遇到空格、换行等分隔符停止
    scanf("%s", name);  

    // 输出提示信息，结合用户输入的名字，询问体重（磅为单位）
    printf("%s, what's your weight in pounds?\n", name);  
    // 读取用户输入的体重数值，存入 weight 变量，%f 按浮点型格式读取
    scanf("%f", &weight);  

    // 使用 sizeof 运算符计算 name 数组占用的总字节数，结果存入 size 变量
    size = sizeof(name);  
    // 使用 strlen 函数计算 name 数组中有效字符串的长度（即姓名实际字符数，不包含结束符 '\0' ），结果存入 letters 变量
    letters = strlen(name);  
    // 根据公式“体积 = 体重 / 密度”，计算体积并赋值给 volume 变量
    volume = weight / DENSITY;  

    // 输出用户姓名和计算得到的体积，%.2f 表示按浮点型输出，保留 2 位小数
    printf("Well, %s, your volume is %.2f cubic feet.\n", name, volume);  
 
    // 输出用户姓名和姓名的有效字符长度
    printf("Also, your first name has %d letters,\n", letters);  
    // 输出 name 数组占用的字节数（体现数组存储能力 ）
    printf("and we have %d bytes to store it.\n", size);  

    // 程序正常结束，返回 0 给操作系统
    return 0;  
}