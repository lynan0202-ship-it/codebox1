/*
5. 第 5 题：分析程序输出
要点：跟踪for循环的执行过程，根据if-else判断，确定每次循环输出的字符，理解循环和条件判断结合的执行流程。
知识点：for循环、if-else分支、putchar函数。
*/
#include <stdio.h>

int main(void) {
    int num;
    for (num = 1; num <= 11; num++) {
        if (num % 3 == 0) {
            putchar('$');
        } else {
            putchar('*');
            putchar('#');
        }
        putchar('%');
    }
    putchar('\n');
    return 0;
}
// 执行过程分析：
// num从1到11循环：
// num=1：不满足num%3==0，输出*#% 
// num=2：不满足num%3==0，输出*#% 
// num=3：满足，输出$% 
// num=4：不满足，输出*#% 
// num=5：不满足，输出*#% 
// num=6：满足，输出$% 
// num=7：不满足，输出*#% 
// num=8：不满足，输出*#% 
// num=9：满足，输出$% 
// num=10：不满足，输出*#% 
// num=11：不满足，输出*#% 
// 最后输出换行，可运行程序看实际输出验证 