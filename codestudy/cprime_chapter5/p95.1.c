//算数运算符
#include <stdio.h>
int main() {
    int a = 10, b = 3;

    // 1. 加法运算符 + 
    // 功能：两数相加，或对变量做自增前的 “值参与运算”（单独用 ++a 是自增，这里演示 + 运算 ）
    int sum = a + b; 
    printf("a + b = %d\n", sum); // 输出 13 

    // 2. 减法运算符 - 
    // 功能：两数相减，或对变量做自减前的 “值参与运算”（单独用 --b 是自减，这里演示 - 运算 ）
    int diff = a - b; 
    printf("a - b = %d\n", diff); // 输出 7 

    // 3. 乘法运算符 * 
    // 功能：两数相乘，注意和指针的 “*” 区分开（这里是算术乘法 ）
    int product = a * b; 
    printf("a * b = %d\n", product); // 输出 30 

    // 4. 除法运算符 / 
    // 功能：整数相除取商（截断小数）；浮点数相除保留小数。这里演示整数除法 
    int quot_int = a / b; 
    printf("a / b（整数除） = %d\n", quot_int); // 输出 3（10÷3 商 3 余 1 ）

    // 演示浮点数除法（让其中一个数转成 float ）
    float quot_float = (float)a / b; 
    printf("a / b（浮点除） = %.2f\n", quot_float); // 输出 3.33 

    // 5. 取余运算符 % 
    // 功能：整数相除取余数，只用于整数运算，不能对浮点数用 
    int rem = a % b; 
    printf("a %% b = %d\n", rem); // 输出 1（10÷3 余 1 ）

    // 6. 自增运算符 ++（前置 ）
    // 功能：先把变量值 +1，再用新值参与运算 
    int x = 5; 
    int res_pre = ++x; 
    printf("++x 后，x = %d，res_pre = %d\n", x, res_pre); // x=6，res_pre=6 

    // 7. 自减运算符 --（前置 ）
    // 功能：先把变量值 -1，再用新值参与运算 
    int y = 5; 
    int res_pre_dec = --y; 
    printf("--y 后，y = %d，res_pre_dec = %d\n", y, res_pre_dec); // y=4，res_pre_dec=4 

    // 自增运算符 ++（后置 ）
    // 功能：先用变量旧值参与运算，再把变量值 +1 
    int m = 5; 
    int res_post = m++; 
    printf("m++ 后，m = %d，res_post = %d\n", m, res_post); // m=6，res_post=5 

    // 自减运算符 --（后置 ）
    // 功能：先用变量旧值参与运算，再把变量值 -1 
    int n = 5; 
    int res_post_dec = n--; 
    printf("n-- 后，n = %d，res_post_dec = %d\n", n, res_post_dec); // n=4，res_post_dec=5 

    return 0;
}