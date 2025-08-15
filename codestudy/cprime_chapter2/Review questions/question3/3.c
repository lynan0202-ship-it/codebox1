/*




6. 在 main、int、function、char、= 中，哪些是 C 语言的关键字？
关键字：int、char （int 用于声明整型变量，char 用于声明字符型变量，是 C 语言内置关键字 ）。
main 是函数名（程序入口约定叫 main ，但本身不是关键字 ）；function 不是 C 语言关键字；= 是赋值运算符，不是关键字。

*/


/*
7. 如何以下面的格式输出变量 words 和 lines 的值（这里，3020 和 350 代表两个变量的值 ）？

*/


#include<stdio.h>
int main(void)
{
    int a,b;
    a=3020;
    b=350;
    printf("There are %d words and %d lines \n",a,b);

    int words = 3020;
    int lines = 350;
    printf("There are %d words and %d lines.", words, lines);

    return 0;
}