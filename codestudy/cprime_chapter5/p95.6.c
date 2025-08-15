//六、条件运算符（1 个 ，三目运算符 ）
#include <stdio.h>
int main() {
    int score = 85;

    // 条件运算符：condition ? expr1 : expr2 
    // 功能：条件成立（非 0 ），执行 expr1；否则执行 expr2 
    // 这里判断分数是否 >=60，输出 “及格” 或 “不及格” 
    char *result = (score >= 60) ? "及格" : "不及格"; 
    printf("成绩 %d 评定：%s\n", score, result); // 输出 “及格” 

    // 再演示数值运算场景 
    int a = 10, b = 5; 
    int max = (a > b) ? a : b; 
    printf("a 和 b 中较大的数：%d\n", max); // 10 

    return 0;
}
/*
成绩 85 评定：及格
a 和 b 中较大的数：10
*/