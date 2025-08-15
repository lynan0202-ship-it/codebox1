/* 
 * 程序：continue_demo.c
 * 功能：演示 continue 清理无效输入、控制循环流程
 * 知识覆盖：
 *  1. continue 跳过循环当前迭代，进入下一轮
 *  2. 配合条件判断，过滤无效数据
 */

#include <stdio.h>

int main(void) {
    char ch;
    int valid_count = 0;

    printf("输入字符（输入 # 结束）：\n");
    while ((ch = getchar()) != '#') {  
        // 如果是换行符，跳过（清理输入缓冲区残留）
        if (ch == '\n') {  
            continue;  // 跳过当前迭代，直接进入下一轮循环
        }
        // 如果是非字母，提示无效并跳过
        if (!isalpha(ch)) {  
            printf("无效输入：%c 不是字母！跳过...\n", ch);
            // 清理输入缓冲区剩余字符（如输入 "123abc\n"，需丢弃 "123"）
            while ((ch = getchar()) != '\n') {  
                continue;  // 持续读取，直到遇到换行符
            }
            continue;  // 跳过当前迭代，进入下一轮
        }
        // 有效字母，统计并输出
        valid_count++;
        printf("有效字符：%c（已统计 %d 个）\n", ch, valid_count);
    }

    printf("共统计 %d 个有效字母！\n", valid_count);
    return 0;
}