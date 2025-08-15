//以下代码整合教程中 逻辑运算符 核心知识点（&&/||/! 用法、优先级、求值顺序、isoc646.h 备选拼写
// ），用详细注释串联所有教学内容，包含原示例 chcount.c 改造和扩展示例：
#include <stdio.h>
// 可选：启用 isoc646.h 备选拼写（如 and/or/not 代替 &&/||/! ）
// #include <isoc646.h>  // 已移除，使用标准逻辑运算符
#define PERIOD '.'  // 定义句号作为输入结束标志
int main(void)
{
    // 存储读取的字符
    char ch;          
    // 统计非引号字符数量
    int charcount = 0;  

    // --------------------- 1. 逻辑运算符基础用法（&& 示例） --------------------- 
    // 原示例逻辑：读取字符直到遇到句号，统计非单/双引号字符
    printf("Enter a sentence (end with %c):\n", PERIOD);
    // 条件：ch 不是句号时持续循环（getchar 读取输入字符）
    while ((ch = getchar()) != PERIOD) {  
        // 逻辑与（&&）：ch 不是双引号（"） 且 不是单引号（'）
        if (ch != '"' && ch != '\'') {  
            // 满足条件，计数+1
            charcount++;  
        }
    }
    // 输出结果：呼应原示例 chcount.c 功能
    printf("There are %d non-quote characters.\n", charcount);  


    // --------------------- 2. 逻辑运算符优先级与组合 --------------------- 
    int score = 95;
    // 示例：逻辑与（&&）优先级低于关系运算符（无需额外括号）
    // 等价于：(score >= 90) && (score <= 100)
    if (score >= 90 && score <= 100) {  
        printf("Score %d is in 90~100 (using &&)\n", score);
    }

    // 错误示范（教程强调：别模仿数学写法！）
    // if (90 <= score <= 100) { ... } 
    // 编译器会解析为 (90 <= score) <= 100 → 1/0 <= 100，永远为真
    // 正确写法必须拆分：(score >= 90) && (score <= 100)


    // --------------------- 3. 逻辑或（||）用法示例 --------------------- 
    int number = 5;
    // 逻辑或（||）：number 是 5 或 6 时为真
    if (number == 5 || number == 6) {  
        printf("Number %d is 5 or 6 (using ||)\n", number);
    }


    // --------------------- 4. 逻辑非（!）用法示例 --------------------- 
    int isSunny = 0;
    // 逻辑非（!）：反转布尔值（false → true）
    if (!isSunny) {  
        printf("It's not sunny (using !)\n");
    }


    // --------------------- 5. 求值顺序与短路特性 --------------------- 
    int x = 0, y = 10;
    // 逻辑与（&&）短路：左边为假，右边不执行
    // x == 0 为假，所以 (y / x) 不会执行（避免除零错误）
    if (x != 0 && (y / x) > 5) {  
        // 永远不会执行到这里
        printf("This won't print.\n");  
    }

    // 逻辑或（||）短路：左边为真，右边不执行
    // x == 0 为真，所以 (y / x) 不会执行（避免除零错误）
    if (x == 0 || (y / x) > 5) {  
        printf("Short-circuit works: x is 0, skip risky part.\n");
    }


    // --------------------- 6. isoc646.h 备选拼写（教程知识点） --------------------- 
    // 启用 isoc646.h 后，可用 and/or/not 代替 &&/||/!
    // 需包含 <isoc646.h> 头文件（顶部已包含）
    char ch2 = getchar();
    // 使用标准逻辑运算符 &&
    if (ch2 != PERIOD && ch2 != '"' && ch2 != '\'') {  
        printf("Using standard &&: count non-quote\n");
    }


    // --------------------- 7. 逻辑运算符优先级总结 --------------------- 
    // 逻辑非（!）> 关系运算符（>/>=/== 等）> 逻辑与（&&）> 逻辑或（||）
    // 示例：!a && b == c 等价于 ((!a) && (b == c))
    int a = 1, b = 2, c = 2;
    if (!a && b == c) {
        printf("Priority: ! has higher precedence than &&\n");
    }

    return 0;
}
/*
Enter a sentence (end with .):
do you want to drunk about"water" or "whatermalon"! \\\|||                      




a
d
d
.
There are 65 non-quote characters.
Score 95 is in 90~100 (using &&)
Number 5 is 5 or 6 (using ||)
It's not sunny (using !)
Short-circuit works: x is 0, skip risky part.
Using standard &&: count non-quote
*/