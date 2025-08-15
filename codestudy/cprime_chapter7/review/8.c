/*
8. 分析程序输出内容
要点：跟踪 while 循环中 age 的变化，以及 if 条件判断执行情况，确定程序最终打印内容。
知识点：while 循环、age++ 后自增运算、if 条件判断。
*/
#include <stdio.h>
int main(void)
{
    int age = 20;
    while (age++ <= 65)
    {
        if ((age % 20) == 0) 
            printf("You are %d. Here is a raise.\n", age);
        if (age == 65)
            printf("You are %d. Here is your gold watch.\n", age);
    }
    return 0;
}
// 执行过程分析：
// age 从 20 开始，每次循环先判断 age++ <=65（判断时用原来的 age 值，判断后 age 自增 1）
// 当 age 自增后为 40、60 时，满足 (age % 20 == 0)，会打印 raise 相关内容
// 当 age 自增后为 65 时，打印 gold watch 相关内容 
// 可以自己逐步推导每一步 age 的值和输出情况，最终确定完整输出
/*
You are 40. Here is a raise.
You are 60. Here is a raise.
You are 65. Here is your gold watch.
*/