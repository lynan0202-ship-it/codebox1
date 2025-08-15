#include <stdio.h>
// 1. 修复：宏定义加 #
#define B "booboo"  
#define X 10

// 2. 修复：正确声明 main 函数
int main(void) {
    // 3. 修复：删除多余 q，正确声明变量
    int age;
    // 修复：给 name 分配数组空间（避免栈溢出）
    char name[50];  

    printf("Please enter your first name.");
    // 4. 修复：%s 读字符串，name 是数组名（本身是地址）
    scanf("%s", name);  
    // 5. 修复：%s 输出字符串（原 %c 是字符，不匹配字符串）
    printf("All right, %s, what's your age?\n", name);  

    // 6. 修复：%d 读整数，&age 传地址
    scanf("%d", &age);  
    // 7. 修复：声明 xp 并计算（原 xp 未定义）
    int xp = age + X;  

    // 8. 修复：%s 输出宏 B（字符串），%d 输出 xp（整数）
    printf("That's a %s! You must be at least %d.\n", B, xp);  

    // 9. 修复：正确拼写 return
    return 0;  
}