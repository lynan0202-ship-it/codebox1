//四、逻辑运算符（3 个 ，用于逻辑判断，结果 0 或 1 ）
#include <stdio.h>
int main() {
    int a = 1, b = 0, c = 1;

    // 1. 逻辑与 && 
    // 功能：左右条件都为真（非 0 ），结果才为 1；只要有一个假（0 ），结果 0 
    // 口诀：“一假则假，全真才真” 
    int res_and = (a && b); 
    printf("a && b → %d\n", res_and); // 0（a=1真，b=0假 → 整体假 ）

    int res_and2 = (a && c); 
    printf("a && c → %d\n", res_and2); // 1（a=1真，c=1真 → 整体真 ）

    // 2. 逻辑或 || 
    // 功能：左右条件只要有一个为真（非 0 ），结果就为 1；全假才 0 
    // 口诀：“一真则真，全假才假” 
    int res_or = (b || a); 
    printf("b || a → %d\n", res_or); // 1（b=0假，a=1真 → 整体真 ）

    int res_or2 = (b || 0); 
    printf("b || 0 → %d\n", res_or2); // 0（b=0假，0假 → 整体假 ）

    // 3. 逻辑非 ! 
    // 功能：取反，真变假（1→0 ），假变真（0→1 ）
    int res_not = !a; 
    printf("!a → %d\n", res_not); // 0（a=1真 → 取反假 ）

    int res_not2 = !b; 
    printf("!b → %d\n", res_not2); // 1（b=0假 → 取反真 ）

    return 0;
}