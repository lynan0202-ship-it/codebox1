#include <stdio.h>
// 定义 1 小时 = 60 分钟
#define MINUTES_PER_HOUR 60  

int main(void) {
    int minutes;
    printf("=== 分钟转小时 + 分钟 ===\n");

    // 循环输入，直到 minutes ≤ 0


    /*
    在 C 语言中，while (1) 表示创建一个无限循环（也叫死循环）。
具体来说：
while 循环的执行逻辑是：先判断括号里的 “条件表达式”，如果条件为 “真”（非 0 值），就重复执行循环体；如果为 “假”（0），就退出循环。
这里的 1 是一个非 0 的整数，在 C 语言中会被视为 “真”，因此 while (1) 的条件永远成立，循环会一直执行下去，不会自动结束。
在你提供的代码中，while (1) 的作用是让程序 “一直等待用户输入”，而循环的退出由循环体内部的 break 语句控制：
当用户输入的 minutes ≤ 0 时，会执行 break;，强制跳出这个无限循环，从而结束程序。
这种用法的好处是：可以灵活地在循环体内部根据特定条件（比如用户输入、业务逻辑等）控制循环的退出，而不是依赖 while 括号里的固定条件。
    */
    while (1) 
 
    {
        printf("请输入分钟数（≤0 退出）：");
        scanf("%d", &minutes);

        // 输入 ≤0 时退出循环
        if (minutes <= 0) 
        {
            printf("退出程序！\n");
            break;
        }

        // 计算小时和剩余分钟
        int hours = minutes / MINUTES_PER_HOUR;
        int remaining_minutes = minutes % MINUTES_PER_HOUR;

        // 输出结果
        printf("%d 分钟 = %d 小时 %d 分钟\n", minutes, hours, remaining_minutes);
    }

    return 0;
}

/*
=== 分钟转小时 + 分钟 ===
请输入分钟数（≤0 退出）：67
67 分钟 = 1 小时 7 分钟
请输入分钟数（≤0 退出）：-5
退出程序！
*/