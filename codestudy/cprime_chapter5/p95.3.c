//关系运算符（6 个 ，比较运算，结果是 0 或 1 ）
#include <stdio.h>
int main() {
    int a = 10, b = 5, c = 10;

    // 1. 大于 > 
    // 功能：判断左边是否 > 右边，成立返回 1，否则 0 
    int res_gt = (a > b); 
    printf("a > b → %d\n", res_gt); // 1（10>5 成立 ）

    // 2. 小于 < 
    // 功能：判断左边是否 < 右边，成立返回 1，否则 0 
    int res_lt = (a < b); 
    printf("a < b → %d\n", res_lt); // 0（10<5 不成立 ）

    // 3. 大于等于 >= 
    // 功能：判断左边是否 >= 右边，成立返回 1，否则 0 
    int res_ge = (a >= c); 
    printf("a >= c → %d\n", res_ge); // 1（10>=10 成立 ）

    // 4. 小于等于 <= 
    // 功能：判断左边是否 <= 右边，成立返回 1，否则 0 
    int res_le = (b <= c); 
    printf("b <= c → %d\n", res_le); // 1（5<=10 成立 ）

    // 5. 等于 == 
    // 功能：判断左右是否相等，成立返回 1，否则 0 。注意和赋值 = 区分！ 
    int res_eq = (a == c); 
    printf("a == c → %d\n", res_eq); // 1（a和c都是10 ）

    // 6. 不等于 != 
    // 功能：判断左右是否不相等，成立返回 1，否则 0 
    int res_ne = (b != c); 
    printf("b != c → %d\n", res_ne); // 1（5≠10 ）

    return 0;
}