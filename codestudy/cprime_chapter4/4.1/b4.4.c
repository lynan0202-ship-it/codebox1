#include <stdio.h>
// 为使用 intmax_t、uintmax_t 等类型
#include <stdint.h>  
// 为使用 ptrdiff_t、size_t 等类型
#include <stddef.h>  

int main() {
    // hh 修饰符：和整型转换说明一起，处理 signed char 或 unsigned char 类型
    signed char sch = 'A';
    unsigned char uch = 255;
    printf("hh 修饰符：和整型转换说明配合，用 %%hhu 输出 signed char 转无符号显示，示例值（signed char 转无符号）：%hhu；用 %%hhx 输出 unsigned char 十六进制，示例值：%hhx\n", sch, uch);

    // j 修饰符：和整型转换说明一起，处理 intmax_t 或 uintmax_t 类型 
    intmax_t imax = INTMAX_MAX;
    uintmax_t umax = UINTMAX_MAX;
    printf("j 修饰符：和整型转换说明配合，用 %%jd 输出 intmax_t 类型值，示例值：%jd；用 %%jX 输出 uintmax_t 十六进制（大写），示例值：%jX\n", imax, umax);

    // l 修饰符：和整型转换说明一起，处理 long int 或 unsigned long int 类型 
    long int li = 123456789L;
    unsigned long int uli = 987654321UL;
    printf("l 修饰符：和整型转换说明配合，用 %%ld 输出 long int 类型值，示例值：%ld；用 %%lu 输出 unsigned long int 类型值，示例值：%lu\n", li, uli);

    // ll 修饰符：和整型转换说明一起，处理 long long int 或 unsigned long long int 类型（C99 及以上）
    long long int lli = 9223372036854775807LL;
    unsigned long long int ulli = 18446744073709551615ULL;
    printf("ll 修饰符：和整型转换说明配合，用 %%lld 输出 long long int 类型值，示例值：%lld；用 %%llu 输出 unsigned long long int 类型值，示例值：%llu\n", lli, ulli);

    // L 修饰符：和浮点转换说明一起，处理 long double 类型 
    long double ld = 3.14159265358979323846L;
    printf("L 修饰符：和浮点转换说明配合，用 %%Lf 输出 long double 类型值，示例值：%Lf\n", ld);

    // t 修饰符：和整型转换说明一起，处理 ptrdiff_t 类型（常用于指针差值，C99 及以上）
    int arr[2] = {0, 0};
    int *p1 = &arr[0], *p2 = &arr[1];
    ptrdiff_t diff = p2 - p1;
    printf("t 修饰符：和整型转换说明配合，用 %%td 输出 ptrdiff_t 类型（指针差值示例），示例值：%td\n", diff);

    // z 修饰符：和整型转换说明一起，处理 size_t 类型（常用于 sizeof 结果，C99 及以上）
    size_t sz = sizeof(int);
    printf("z 修饰符：和整型转换说明配合，用 %%zd 输出 size_t 类型（sizeof(int) 示例），示例值：%zd\n", sz);

    // h 修饰符：和整型转换说明一起，处理 short int 或 unsigned short int 类型 
    short int si = 32767;
    unsigned short int usi = 65535;
    printf("h 修饰符：和整型转换说明配合，用 %%hu 输出 unsigned short int 类型值，示例值：%hu；用 %%hx 输出 unsigned short int 十六进制，示例值：%hx\n", usi, usi);

    return 0;
}