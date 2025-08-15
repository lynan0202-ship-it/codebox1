/* prin2.c--更多printf（）的特性
#include<stdio.h>
int main(void)
{
    unsigned int un=3000000000;
    short end = 200;
    long big = 65537;
    long long verybig =12345678908642;
    
    printf("un = %u and not %d and un_size=%d\n",un,un,sizeof(un));
    printf("end = %hd and not %d\n",end,end);
    printf("big = %ld and not %hd and not %o and not %lx\n",big,big,big,big);
    printf("verybig= %lld and not %llo and not %ld\n",verybig,verybig,verybig);

    return 0;
}

*/

/* 
 * prin2.c -- 演示更多 printf() 的格式化输出特性
 * 学习目标：
 *  1. 理解不同整数类型（unsigned int/short/long/long long）的格式化输出
 *  2. 掌握 %u/%d/%hd/%ld/%lld 等格式说明符的区别
 *  3. 体会 sizeof 关键字的用法
 *  4. 观察类型不匹配时的输出行为（虽然能编译，但可能有逻辑问题）
 */

// 包含标准输入输出库，让我们可以使用 printf 函数
#include <stdio.h>

// 程序入口函数
int main(void)
{
    // 1. 无符号整型（unsigned int）
    //    - 范围通常是 0 ~ 4294967295（32 位系统）
    //    - 这里赋值 3000000000，在无符号整型范围内
    unsigned int un = 3000000000;

    // 2. 短整型（short）
    //    - 范围通常是 -32768 ~ 32767（16 位）
    //    - 200 在 short 范围内
    short end = 200;

    // 3. 长整型（long）
    //    - 32 位系统中通常是 4 字节，64 位系统中通常是 8 字节
    //    - 65537 超出了 short 的范围（short 最大 32767），但在 long 范围内
    long big = 65537;

    // 4. 长长整型（long long）
    //    - 通常是 8 字节，范围更大
    //    - 12345678908642 是一个非常大的数，需要 long long 存储
    long long verybig = 12345678908642;


    // ====== 格式化输出演示 1：unsigned int ======
    // %u：以“无符号十进制”输出 unsigned int
    // %d：以“有符号十进制”输出（如果用 %d 输出 unsigned int，可能会溢出或显示异常值）
    // sizeof(un)：获取 un 变量的字节大小（unsigned int 通常是 4 字节）
    printf("un = %u and not %d and un_size=%d\n", un, un, sizeof(un));


    // ====== 格式化输出演示 2：short ======
    // %hd：以“有符号十进制”输出 short 类型
    // %d：虽然也能输出，但建议用 %hd 更明确（用 %d 时，short 会被提升为 int，但结果可能一样）
    printf("end = %hd and not %d\n", end, end);


    // ====== 格式化输出演示 3：long ======
    // %ld：以“有符号十进制”输出 long 类型
    // %hd：用 short 的格式输出 long（类型不匹配，可能会截断数据）
    // %o：以“八进制”输出 long（虽然能编译，但格式不匹配，结果无意义）
    // %lx：以“十六进制小写”输出 long（同样类型不匹配，结果无意义）
    printf("big = %ld and not %hd and not %o and not %lx\n", big, big, big, big);


    // ====== 格式化输出演示 4：long long ======
    // %lld：以“有符号十进制”输出 long long 类型
    // %llo：试图以“八进制”输出 long long（但标准 printf 没有 %llo，实际会报错或行为异常！）
    //       正确写法是 %llo 吗？不，C 标准中八进制 long long 是 %llo 吗？
    //       注意：实际标准格式是 %llo 吗？不！正确的八进制 long long 格式是 %llo 吗？
    //       真相：C 标准中，long long 的八进制是 %llo，十六进制是 %llx
    //       但很多编译器支持 %llo，但这里的写法有问题，因为 verybig 是十进制值，用 %llo 输出会按八进制解析吗？
    //       不，%llo 的意思是“把变量的值以八进制形式输出”，但这里的变量是十进制存储的，所以会把十进制值转成八进制输出
    //       不过，更重要的是：printf 的格式必须和变量类型严格匹配，否则可能导致未定义行为！
    // %ld：用 long 的格式输出 long long（类型不匹配，可能会截断数据）
    printf("verybig= %lld and not %llo and not %ld\n", verybig, verybig, verybig);


    // 程序正常结束
    return 0;
}