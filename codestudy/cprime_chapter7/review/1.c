/*
1. 第 1 题：判断表达式真假
要点：理解关系运算符（>等 ）、逻辑运算符（&&、||、! ）的运算规则，以及字符以 ASCII 码参与比较的方式。
知识点：关系运算、逻辑运算、字符的 ASCII 码值比较。
*/
#include <stdio.h>

int main(void) {
    // 对于a: 100 > 3 为真，但 'a'的ASCII码是97，'c'是99，所以'a' > 'c'为假，逻辑与运算一假则假
    int a_result = (100 > 3) && ('a' > 'c');
    // 对于b: 100 > 3 为真，逻辑或运算一真则真
    int b_result = (100 > 3) || ('a' > 'c');
    // 对于c: 100 > 3 为真，逻辑非运算取反
    int c_result = !(100 > 3);

    printf("a表达式结果：%s\n", a_result ? "true" : "false");
    printf("b表达式结果：%s\n", b_result ? "true" : "false");
    printf("c表达式结果：%s\n", c_result ? "true" : "false");

    return 0;
}
/*
a表达式结果：false
b表达式结果：true
c表达式结果：false
*/