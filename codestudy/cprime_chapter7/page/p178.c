/*
以下是整合教材中 break、continue、goto 知识，用代码示例 + 超详细注释的形式，覆盖 程序跳转控制（break/continue/goto 用法、场景对比、替代方案） 核心知识点：
知识要点与总体逻辑说明
知识覆盖：
break 语句：跳出循环 /switch，立即终止当前控制结构。
continue 语句：跳过循环当前迭代剩余部分，直接进入下一轮迭代（仅用于循环）。
goto 语句：跳转到函数内的标签位置，因易导致程序混乱，需谨慎使用。
场景对比：演示 goto 可模拟 if/if-else、循环控制，但推荐用 break/continue/if-else 替代，使代码更清晰。
总体逻辑：
通过 3 个示例程序，分别演示：
break 在循环、switch 中的用法。
continue 清理无效输入、控制循环迭代的逻辑。
goto 的基础用法，以及如何用 break/continue/if-else 替代 goto 实现更清晰的流程，完整覆盖教材中程序跳转控制的核心知识。
*/
/* 
 * 程序：break_demo.c
 * 功能：演示 break 在循环、switch 中的作用
 * 知识覆盖：
 *  1. break 跳出 for 循环：满足条件时提前终止循环
 *  2. break 跳出 switch：匹配 case 后，终止 switch 分支
 */

#include <stdio.h>

int main(void) {
    // 演示 break 跳出循环
    for (int i = 1; i <= 10; i++) {  
        if (i == 5) {  
            printf("触发 break，跳出 for 循环！当前 i = %d\n", i);
            break;  // 当 i=5 时，跳出 for 循环，循环立即终止
        }
        printf("for 循环迭代：i = %d\n", i);
    }

    // 演示 break 跳出 switch
    int choice = 2;
    switch (choice) {  
        case 1:
            printf("执行 case 1\n");
            break;  // 跳出 switch，避免贯穿到其他 case
        case 2:
            printf("执行 case 2\n");
            break;  // 跳出 switch
        default:
            printf("执行 default\n");
    }

    return 0;
}