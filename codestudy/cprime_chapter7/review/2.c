/*
2. 第 2 题：构造表达式
要点：根据自然语言描述，准确运用关系运算符和逻辑运算符组合出符合条件的表达式。
知识点：关系运算、逻辑运算的组合使用。
*/
#include <stdio.h>

int main(void) {
    // a. number等于或大于90，但是小于100
    // 知识点：>=、< 关系运算符及逻辑与 && 的使用
    int number = 95;
    int a_expr = (number >= 90) && (number < 100);
    printf("a表达式结果（number=95）：%s\n", a_expr ? "满足" : "不满足");

    // b. ch不是字符q或k
    // 知识点：!= 关系运算符及逻辑与 &&、逻辑非 ! 的使用，字符直接用单引号包裹比较
    char ch = 'm';
    int b_expr = (ch != 'q') && (ch != 'k');
    printf("b表达式结果（ch='m'）：%s\n", b_expr ? "满足" : "不满足");

    // c. number在1~9之间（包括1和9），但不是5
    // 知识点：>=、<=、!= 关系运算符及逻辑与 && 的使用
    number = 3;
    int c_expr = (number >= 1) && (number <= 9) && (number != 5);
    printf("c表达式结果（number=3）：%s\n", c_expr ? "满足" : "不满足");

    // d. number不在1~9之间
    // 知识点：逻辑非 ! 以及 >=、<= 关系运算符、逻辑与 && 的使用
    number = 10;
    int d_expr = !( (number >= 1) && (number <= 9) );
    printf("d表达式结果（number=10）：%s\n", d_expr ? "满足" : "不满足");

    return 0;
}
/*
a表达式结果（number=95）：满足
b表达式结果（ch='m'）：满足
c表达式结果（number=3）：满足
d表达式结果（number=10）：满足
*/