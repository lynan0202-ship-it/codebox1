/*
6. 第 6 题：分析程序输出
要点：跟踪while循环和switch语句的执行，注意i++在switch中的执行时机，以及case中没有break时的贯穿情况。
知识点：while循环、switch语句、case的贯穿性、自增运算。
*/
#include <stdio.h>

int main(void) {
    int i = 0;
    while (i < 3) {
        switch (i++) { 
            case 0:
                printf("fat ");
                // 没有break，会继续执行case 1
            case 1:
                printf("hat ");
        }
    }
    return 0;
}
// 执行过程：
// 第一次循环：i=0，进入switch，i++后i变为1，执行case 0输出fat ，然后因为没有break，执行case 1输出hat 
// 第二次循环：i=1，进入switch，i++后i变为2，执行case 1输出hat 
// 第三次循环：i=2，进入switch，i++后i变为3，执行case 1输出hat 
// 循环条件i < 3，此时i变为3，循环结束。实际输出为fat hat hat hat  ，可运行查看结果验证
/*
fat hat hat 
*/