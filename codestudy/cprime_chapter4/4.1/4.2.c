/* praisel.c -- 使用不同类型的字 */
#include <stdio.h>
#include <string.h>  // 为了使用strncpy函数

#define PRAISE "You are an extraordinary being."
#define MAX_NAME_LENGTH 39  // 留出一个字符给字符串结束符

int main(void)  // 修正函数名拼写错误
{
    char name[40];

    printf("What's your name?\n");  // 添加换行符
    
    // 安全地读取字符串，防止缓冲区溢出
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // 移除可能的换行符
        name[strcspn(name, "\n")] = 0;
    } else {
        // 处理读取错误liulahdlhjl
        printf("Error reading input\n");
        return 1;
    }

    printf("Hello, %s. %s\n", name, PRAISE);

    return 0;
}