#include <stdio.h>

int main() {
    // 获取short类型占用的字节数
    size_t short_size = sizeof(short);
    // 获取int类型占用的字节数
    size_t int_size = sizeof(int);
    // 获取long类型占用的字节数
    size_t long_size = sizeof(long);
    // 获取long long类型占用的字节数
    size_t long_long_size = sizeof(long long);

    printf("short类型占用 %zu 字节，即 %zu 位\n", short_size, short_size * 8);
    printf("int类型占用 %zu 字节，即 %zu 位\n", int_size, int_size * 8);
    printf("long类型占用 %zu 字节，即 %zu 位\n",long_size, long_size * 8);
    printf("long long类型占用 %zu 字节，即 %zu 位\n", long_long_size, long_long_size * 8);

    return 0;
}