#include <stdio.h>
// 辅助函数：打印整数二进制（简单版，只打低 8 位演示 ）
void print_bin(int num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1); 
    }
    printf("\n");
}

int main() {
    int a = 6, b = 3; 
    // a 二进制：0000 0110 
    // b 二进制：0000 0011 
    print_bin(a);
    print_bin(b);

    // 1. 按位与 & 
    // 功能：二进制位 “同位都 1 才 1，否则 0” 
    int res_and = a & b; 
    printf("a & b 二进制：");
    print_bin(res_and); // 0000 0010（6 & 3 = 2 ）

    // 2. 按位或 | 
    // 功能：二进制位 “同位有 1 就 1，全 0 才 0” 
    int res_or = a | b; 
    printf("a | b 二进制：");
    print_bin(res_or); // 0000 0111（6 | 3 = 7 ）

    // 3. 按位异或 ^ 
    // 功能：二进制位 “同位不同则 1，相同则 0” 
    int res_xor = a ^ b; 
    printf("a ^ b 二进制：");
    print_bin(res_xor); // 0000 0101（6 ^ 3 = 5 ）

    // 4. 按位取反 ~ 
    // 功能：二进制位 “1 变 0，0 变 1”，注意符号位也会取反（演示时看低 8 位 ）
    int res_not = ~a; 
    printf("~a 二进制：");
    print_bin(res_not); // 1111 1001（实际是补码，这里简化看低 8 位 ）

    // 5. 左移 << 
    // 功能：二进制位整体左移 n 位，右边补 0，相当于乘以 2^n（不溢出时 ）
    int res_lshift = a << 2; 
    printf("a << 2 后值：%d，二进制：", res_lshift);
    print_bin(res_lshift); // 0001 1000（6<<2=24 ）

    // 6. 右移 >> 
    // 功能：二进制位整体右移 n 位，左边补符号位（正数补 0，负数补 1 ），相当于除以 2^n（整除 ）
    int res_rshift = a >> 1; 
    printf("a >> 1 后值：%d，二进制：", res_rshift);
    print_bin(res_rshift); // 0000 0011（6>>1=3 ）

    return 0;
}
/*
00000110
00000011
a & b 二进制：00000010
a | b 二进制：00000111
a ^ b 二进制：00000101
~a 二进制：11111001
a << 2 后值：24，二进制：00011000
a >> 1 后值：3，二进制：00000011
*/