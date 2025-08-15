/*
2. 嵌套循环中 break 的作用（教材扩展案例）
*/

/**/

#include <stdio.h>

int main(void)
{
    int p, q;  // 嵌套循环的控制变量

    // 外层循环：p > 0 时持续执行
    while (scanf("%d", &p) == 1 && p > 0) {  
        printf("Outer loop: p = %d\n", p);  

        // 提示用户输入内层循环变量 q
        printf("Enter q (q > 0 to continue inner loop): ");  
        // 内层循环：q > 0 时持续执行
        while (scanf("%d", &q) == 1 && q > 0) {  
            printf("Inner loop: p*q = %d\n", p * q);  

            // --------------------- 嵌套循环中 break 的作用 --------------------- 
            // 条件：当 p*q > 100 时，跳出**当前内层循环**（外层循环不受影响）
            if (p * q > 100) {                      
                printf("p*q = %d > 100 → break inner loop\n", p*q);
                // 仅跳出内层 while 循环，外层循环继续执行
                break;                               
            }

            // 提示用户继续输入 q，或输入非正数退出内层循环
            printf("Enter next q (q > 0 to continue): ");  
        }

        // --------------------- 外层循环的 break（教材补充逻辑） --------------------- 
        // 条件：如果 q <= 0（内层循环因 q 非正退出），同时 p > 100，跳出外层循环
        if (q <= 0 && p > 100) {                      
            printf("p = %d > 100且q <= 0 → break outer loop\n", p);
            // 跳出外层 while 循环，结束整个嵌套流程
            break;                                     
        }

        // 提示用户继续输入 p，或输入非正数退出外层循环
        printf("Enter next p (p > 0 to continue): ");  
    }

    printf("Nested loops done.\n");
    return 0;
}
/*
注释与知识点对应：
内层 break 作用：if (p*q > 100) break; → 仅跳出当前内层 while 循环，外层循环继续执行（覆盖教材 “嵌套循环中 break 只影响当前循环” 的知识点）。
外层 break 补充：if (q <= 0 && p > 100) break; → 演示 “在内层循环结束后，通过条件判断执行外层 break”，实现 “跳出多层循环” 的进阶用法。
对比 continue：break 是 “终止当前循环”，continue 是 “跳过当前迭代剩余逻辑”，结合教材图 7.3 可直观区分两者流程差异。
*/
/*
16
Outer loop: p = 16
Enter q (q > 0 to continue inner loop): 4 
Inner loop: p*q = 64
Enter next q (q > 0 to continue): 6
Inner loop: p*q = 96
Enter next q (q > 0 to continue): 7
Inner loop: p*q = 112
p*q = 112 > 100 → break inner loop
Enter next p (p > 0 to continue): 24
Outer loop: p = 24
Enter q (q > 0 to continue inner loop): 3
Inner loop: p*q = 72
Enter next q (q > 0 to continue): 45
Inner loop: p*q = 1080
p*q = 1080 > 100 → break inner loop
Enter next p (p > 0 to continue): q 
Nested loops done.
*/
/*
24
Outer loop: p = 24
Enter q (q > 0 to continue inner loop): 4
Inner loop: p*q = 96
Enter next q (q > 0 to continue): 5
Inner loop: p*q = 120
p*q = 120 > 100 → break inner loop
Enter next p (p > 0 to continue): -5
Nested loops done.
*/