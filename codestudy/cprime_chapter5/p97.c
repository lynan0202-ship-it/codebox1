// min_sec.c -- 把秒数转换为分钟和秒
// 包含标准输入输出头文件，让程序能使用 printf、scanf 等输入输出函数
#include <stdio.h>  
// 定义宏 SEC_PER_MIN，代表 1 分钟的秒数（60 秒），提升代码可读性和可维护性
#define SEC_PER_MIN 60  

int main(void)
{
    // 定义变量：
    // sec 存储用户输入的总秒数，min 存储转换后的分钟数，left 存储剩余秒数
    int sec, min, left;  

    // 输出提示信息，告知用户程序功能：将秒数转换为分钟和秒的形式
    printf("Convert seconds to minutes and seconds!\n");  
    // 提示用户输入秒数，说明输入 <=0 时退出程序
    printf("Enter the number of seconds (<=0 to quit):\n");  
    // 读取用户输入的整数，存入 sec 变量，& 是取地址符，让 scanf 能把值写入 sec 的内存地址
    scanf("%d", &sec);  

    // while 循环：只要用户输入的 sec 大于 0，就持续进行秒数转换操作
    while (sec > 0)  
    {
        // 计算分钟数：总秒数除以 1 分钟的秒数（整数除法，结果是商，即分钟数）
        min = sec / SEC_PER_MIN;  
        // 计算剩余秒数：总秒数对 1 分钟的秒数取模，结果是余数，即剩余秒数
        left = sec % SEC_PER_MIN;  
        // 输出转换结果，格式为 “X seconds is Y minutes, Z seconds.”
        printf("%d seconds is %d minutes, %d seconds.\n", sec, min, left);  

        // 提示用户输入下一个要转换的秒数，或输入 <=0 退出
        printf("Enter next value (<=0 to quit):\n");  
        // 读取新的秒数，更新 sec 的值，为下一轮循环做准备
        scanf("%d", &sec);  
    }

    // 当用户输入 <=0 时，循环结束，输出 Done! 表示程序完成任务
    printf("Done!\n");  

    // main 函数返回 0，告知操作系统程序正常结束
    return 0;  
}
/*
Convert seconds to minutes and seconds!
Enter the number of seconds (<=0 to quit):
89374
89374 seconds is 1489 minutes, 34 seconds.
Enter next value (<=0 to quit):
7236
7236 seconds is 120 minutes, 36 seconds.
Enter next value (<=0 to quit):
-244
Done!
*/