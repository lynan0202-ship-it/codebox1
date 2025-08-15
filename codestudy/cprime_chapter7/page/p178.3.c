/*
运行逻辑：
输入非字母（如数字、符号）时，用 continue 跳过，清理缓冲区后进入下一轮。
输入字母时统计，输入 # 结束循环，演示 continue 精准控制循环流程。
示例 3：goto 语句（用法 + 替代方案）
*/
/*
/* 
 * 程序：goto_demo.c
 * 功能：演示 goto 基础用法，以及如何用 break/continue/if-else 替代
 * 知识覆盖：
 *  1. goto 跳转到标签，实现流程跳转
 *  2. 用 break 替代 goto 跳出多层循环
 *  3. 用 if-else 替代 goto 实现分支逻辑
 */

#include <stdio.h>

int main(void) {
    // ========== 示例 1：goto 基础用法（不推荐，仅演示） ==========
    int x = 1;
    if (x == 1) {
        goto label1;  // 跳转到 label1
    }
    printf("不会执行这里\n");
label1:  // 标签定义（需在函数内、goto 之后或之前）
    printf("跳转到 label1：x = %d\n", x);


    // ========== 示例 2：用 break 替代 goto 跳出多层循环 ==========
    // 场景：嵌套循环中，满足条件时直接终止所有循环
    int stop = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d %d/n",i,j);
            if (i == 2 && j == 2) {  
                printf("触发条件 i=2,j=2，用 break 跳出多层循环！\n");
                stop = 1;  // 设置跳出标志
                break;  // 跳出内层循环
            }
            printf("i=%d, j=%d\n", i, j);
        }
        if (stop) {  // 检查跳出标志，跳出外层循环
            break;  // 替代 goto，更清晰
        }
    }
    // 传统 goto 标签写法：
    // end_loop:
    //     printf("跳出多层循环\n");


    // ========== 示例 3：用 if-else 替代 goto 分支逻辑 ==========
    int score = 80;
    // 传统 goto 写法：
    // if (score >= 60) {
    //     goto pass;
    // } else {
    //     goto fail;
    // }
    // pass:
    //     printf("及格\n");
    //     goto end;
    // fail:
    //     printf("不及格\n");
    // end:
    //     printf("结束\n");

    // 推荐：用 if-else 替代，更清晰
    if (score >= 60) {
        printf("及格\n");
    } else {
        printf("不及格\n");
    }
    printf("结束\n");


    return 0;
}
/*
关键对比：
跳出多层循环：用 break 配合条件判断，比 goto 更清晰（避免标签混乱）。
分支逻辑：if-else 直接替代 goto 实现二选一，代码更易读、维护。
代码注释核心目的
知识串联：每个示例紧扣教材知识点，注释详细说明 break/continue/goto 的作用、场景。
对比清晰：通过 goto 用法 + 替代方案，直观展示 “为什么推荐用 break/continue/if-else”，呼应教材中 “避免滥用 goto” 的建议。
场景覆盖：从基础用法到实际替代方案，完整演示程序跳转控制的核心逻辑，帮你吃透教材中 break/continue/goto 的知识点！
如果对某个示例的逻辑还有疑问，或者想扩展其他场景（如 goto 处理错误跳转），可以随时补充说明～
*/
/*
跳转到 label1：x = 1
1 1/ni=1, j=1
1 2/ni=1, j=2
1 3/ni=1, j=3
2 1/ni=2, j=1
2 2/n触发条件 i=2,j=2，用 break 跳出多层循环！
及格
结束
*/