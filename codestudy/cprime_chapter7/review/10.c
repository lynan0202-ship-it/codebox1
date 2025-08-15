/*
10. 重写习题 9（禁用 continue 和 goto）
要点：去掉 continue 和 goto，用 if-else 等语句重构流程，实现相同逻辑。
知识点：流程重构，用 if-else 替代跳转语句，理解不同控制语句的等价替换。
*/
#include <stdio.h>
int main(void)
{
    char ch;
    while ((ch = getchar()) != '#')
    {
        // 用 if-else 替代 continue，处理换行符情况，只有不是换行符才执行下面逻辑
        if (ch != '\n') { 
            printf("Step 1\n");
            // 用 if-else 替代 continue（原 ch == 'c' 时跳过后面逻辑）
            if (ch != 'c') { 
                // 用 if-else 替代 break（原 ch == 'b' 时跳出循环，这里通过控制循环条件等方式处理，不过因为是输入驱动循环，实际更简单的是用标志位等，这里简化处理）
                if (ch != 'b') { 
                    // 用 if-else 替代 goto（原 ch == 'h' 时跳转到 laststep）
                    if (ch != 'h') { 
                        printf("Step 2\n");
                    }
                    printf("Step 3\n");
                } else {
                    // 处理原 break 逻辑，这里直接跳出循环（因为要模拟 break 效果）
                    break; 
                }
            } else {
                printf("Step 3\n");
            }
        }
    }
    printf("Done\n");
    return 0;
}
// 重构思路：把原来用 continue、goto、break 控制的流程，通过嵌套的 if-else 来实现条件判断，
// 让程序在不同输入字符时，执行对应的输出逻辑，达到和原程序一致的效果（需要仔细调整条件判断 ） 