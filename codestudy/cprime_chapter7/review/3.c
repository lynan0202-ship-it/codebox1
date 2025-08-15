/*
3. 第 3 题：简化并改正程序
要点：梳理程序中复杂且错误的条件判断逻辑，简化并修正语法错误（如 && 写错成 &> 等 ），让程序逻辑清晰合理。
知识点：if-else 分支结构、条件表达式的合理简化。
*/
/**/
#include <stdio.h>

int main(void) {
    int weight, height; 
    printf("请输入体重（磅）和身高（英寸）：");
    scanf("%d %d", &weight, &height);

    // 原程序条件复杂且有语法错误，重新梳理逻辑：
    // 先判断身高范围，再结合体重判断
    if (height > 64) {
        if (height >= 72) {
            printf("You are very tall for your weight.\n");
        } else {
            printf("You are tall for your weight.\n");
        }
    } else if (weight > 300) {
        printf("You are quite heavy.\n");
    } else if (height < 48) {
        printf("You are quite short for your weight.\n");
    } else {
        printf("Your weight is ideal.\n");
    }

    return 0;
}
// 原程序问题：条件表达式书写错误（如height < 72 &&> 64 这种错误写法）、逻辑冗余，
// 这里重新整理条件，让判断更清晰，先按身高主要范围判断，再处理体重等情况 
/*
请输入体重（磅）和身高（英寸）：60
60
Your weight is ideal.
请输入体重（磅）和身高（英寸）：65 78
You are very tall for your weight.

请输入体重（磅）和身高（英寸）：72 304
You are very tall for your weight.
*/
/*
因为 if-else if-else 结构只会执行第一个满足条件的分支，执行完后就不会再判断后面的条件。

你的输入 72 304，height > 64 成立，于是进入第一个 if，然后 height >= 72 也成立，输出 You are very tall for your weight.，后面的 else if (weight > 300) 就不会再执行。

原因：

if-else if-else 是“只选一个”结构，满足第一个条件后，后面的条件都跳过。
如果想让多个条件都能输出，需要拆成多个独立的 if。
当前结构只会输出一句，这是 if-else if 的语法特性。
*/