// 1. 头文件引入：
//    stdio.h 是“standard input output”的缩写，引入它才能用 printf 函数输出内容到屏幕
#include <stdio.h>  
//    limits.h 里定义了各种“整型变量（比如 char、int、long 等）”能存的最大、最小值，类似“说明书”
#include <limits.h>  
//    float.h 里定义了各种“浮点型变量（比如 float、double ）”的精度、范围等“说明书”
#include <float.h>  

// 2. 程序入口：所有 C 程序都从 main 函数开始执行
int main(void)
{
    // 先打印一行提示，告诉用户接下来要展示“系统的数值限制信息”，和书中风格一致
    printf("Number limits information for this system:\n");

    // ======================== 下面开始打印 limits.h 里的“整型常量” ========================
    // CHAR_MIN 和 CHAR_MAX 是 char 类型的“最小、最大值”
    // 注意：char 类型在 C 里可能是“有符号”或“无符号”，由编译器决定，所以数值可能不同
    printf("The minimum value of type char is: %d\n", CHAR_MIN);
    printf("The maximum value of type char is: %d\n", CHAR_MAX);

    // SCHAR_MAX、SCHAR_MIN 是“signed char（明确有符号的 char ）”的最大、最小值
    // 有符号 char 范围通常是 -128 ~ 127（8 位二进制，最高位当符号位）
    printf("The maximum value of type signed char is: %d\n", SCHAR_MAX);
    printf("The minimum value of type signed char is: %d\n", SCHAR_MIN);

    // UCHAR_MAX 是“unsigned char（无符号的 char ）”的最大值
    // 无符号 char 范围是 0 ~ 255（8 位全存数值，没有符号位），所以用 %u（无符号格式）输出
    printf("The maximum value of type unsigned char is: %u\n", UCHAR_MAX);

    // SHRT_MAX、SHRT_MIN 是“short 类型（短整型，通常占 2 字节 ）”的最大、最小值
    printf("The maximum value of type short is: %d\n", SHRT_MAX);
    printf("The minimum value of type short is: %d\n", SHRT_MIN);

    // USHRT_MAX 是“unsigned short（无符号短整型 ）”的最大值
    printf("The maximum value of type unsigned short is: %u\n", USHRT_MAX);

    // INT_MAX、INT_MIN 是“int 类型（普通整型，通常占 4 字节 ）”的最大、最小值
    // 范围一般是 -2147483648 ~ 2147483647
    printf("The maximum value of type int is: %d\n", INT_MAX);
    printf("The minimum value of type int is: %d\n", INT_MIN);

    // UINT_MAX 是“unsigned int（无符号普通整型 ）”的最大值
    printf("The maximum value of type unsigned int is: %u\n", UINT_MAX);

    // LONG_MAX、LONG_MIN 是“long 类型（长整型，通常占 4 或 8 字节 ）”的最大、最小值
    // %ld 是“long 类型”的输出格式，因为数值可能很大，用 %d 可能存不下（会溢出）
    printf("The maximum value of type long is: %ld\n", LONG_MAX);
    printf("The minimum value of type long is: %ld\n", LONG_MIN);

    // ULONG_MAX 是“unsigned long（无符号长整型 ）”的最大值
    printf("The maximum value of type unsigned long is: %lu\n", ULONG_MAX);

    // LLONG_MAX、LLONG_MIN 是“long long 类型（长长整型，通常占 8 字节 ）”的最大、最小值
    // %lld 是“long long 类型”的输出格式
    printf("The maximum value of type long long is: %lld\n", LLONG_MAX);
    printf("The minimum value of type long long is: %lld\n", LLONG_MIN);

    // ULLONG_MAX 是“unsigned long long（无符号长长整型 ）”的最大值
    printf("The maximum value of type unsigned long long is: %llu\n", ULLONG_MAX);


    // ======================== 下面开始打印 float.h 里的“浮点型常量” ========================
    // FLT_MANT_DIG 是“float 类型的尾数位”，简单说就是 float 用来存“有效数字”的二进制位数
    // 数值越大，精度越高（但也不是越大越好，要平衡范围和性能）
    printf("The number of mantissa bits for type float is: %d\n", FLT_MANT_DIG);
    // FLT_DIG 是“float 类型能用十进制表示的‘可靠有效数字位数’”
    // 比如 FLT_DIG 是 6，就表示 float 存 1.23456 是准的，存 1.234567 可能就不准了
    printf("The number of decimal digits that type float can reliably represent is: %d\n", FLT_DIG);

    // FLT_MIN_10_EXP 是“float 类型能存的、带全部有效数字的‘最小 10 的幂次’”
    // 比如这个值是 -37，就表示 float 能存像 1.23e-37 这样的数（还能保证有效数字）
    printf("The smallest negative power of 10 for which a type float is a normalized number is: %d\n", FLT_MIN_10_EXP);
    // FLT_MAX_10_EXP 是“float 类型能存的、带全部有效数字的‘最大 10 的幂次’”
    // 比如这个值是 38，就表示 float 能存像 1.23e38 这样的数（还能保证有效数字）
    printf("The largest positive power of 10 for which a type float is a normalized number is: %d\n", FLT_MAX_10_EXP);

    // FLT_MIN 是“float 类型能存的‘最小正数’”（比 0 大一点点的数）
    // 用 %e 是“科学计数法”格式，符合 float 数值大/小的时候的展示习惯
    printf("The smallest positive normalized value for type float is: %e\n", FLT_MIN);
    // FLT_MAX 是“float 类型能存的‘最大正数’”
    printf("The largest positive value for type float is: %e\n", FLT_MAX);
    // FLT_EPSILON 是“1.0 和比 1.0 大的最小 float 数的差”，体现 float 的“精度极限”
    // 比如 FLT_EPSILON 是 1.19e-07，就表示 1.0 + 1.19e-07 会变成另一个数，再加更小的数就没变化了
    printf("The smallest difference between 1.0 and a larger float value for type float is: %e\n", FLT_EPSILON);


    // 下面这些是 double 类型的，和 float 逻辑一样，只是把 FLT 换成 DBL （DBL 就是 double 的缩写）
    // 可以对比着看 float 和 double 的区别（通常 double 精度更高、范围更大）
    printf("The number of mantissa bits for type double is: %d\n", DBL_MANT_DIG);
    printf("The number of decimal digits that type double can reliably represent is: %d\n", DBL_DIG);
    printf("The smallest negative power of 10 for which a type double is a normalized number is: %d\n", DBL_MIN_10_EXP);
    printf("The largest positive power of 10 for which a type double is a normalized number is: %d\n", DBL_MAX_10_EXP);
    printf("The smallest positive normalized value for type double is: %e\n", DBL_MIN);
    printf("The largest positive value for type double is: %e\n", DBL_MAX);
    printf("The smallest difference between 1.0 and a larger double value for type double is: %e\n", DBL_EPSILON);


    // 3. 返回 0 给操作系统：告诉系统“程序正常结束”
    return 0;
}

/*

头文件是干啥的？
可以理解成 “别人写好的说明书”。比如 limits.h 里写好了 CHAR_MIN 这些常量，你引入它，就能直接用这些 “说明书数值”，不用自己算～
为什么有 %d、%u、%ld 这些奇怪符号？
它们是 printf 的 “格式说明符”，告诉 printf ：“你后面的变量该用啥格式打印”。
比如 %d 是打印 “有符号整数”，%u 是打印 “无符号整数”（防止负数乱码），%ld 是打印 “长整型”（数值太大时，用 %d 存不下，会溢出）。
浮点型的 %e 是啥意思？
%e 是 “科学计数法” 格式。比如 1.23e3 就是 1.23 × 10³ ，适合打印特别大或特别小的数（像 float、double 的范围很大，用科学计数法更直观）。
这些常量的值在我电脑上和别人的不一样？
有可能！因为 limits.h 和 float.h 里的常量，是根据你的 “操作系统、编译器” 决定的。比如有的编译器里 char 是 “无符号” 的，那 CHAR_MAX 就是 255 ；有的是 “有符号” 的，CHAR_MAX 就是 127 。只要符合 C 语言标准就行～
这样逐行拆解后，不管是头文件、格式符，还是每个常量的意义，应该都能看明白啦！
*/