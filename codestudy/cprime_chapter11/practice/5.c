// ------------------------------
// 题干：5. 实现类似strchr的函数，查找字符首次出现位置，循环测试。  
// 知识要点：  
//  1. 指针遍历字符串：通过指针移动对比字符  
//  2. 函数返回值：找到返回字符指针，否则NULL  
//  3. 循环测试：主函数循环输入字符串和字符验证  
// 总体逻辑：  
//  1. 函数my_strchr遍历字符串，找到则返回指针，否则NULL  
//  2. 主函数循环输入，调用函数并输出结果  

#include <stdio.h>

// 查找c在str中首次出现的位置，返回指针或NULL
char *my_strchr(const char *str, char c) {
    while (*str != '\0') {
        if (*str == c) return (char *)str; // 找到，转换为char*
        str++;
    }
    return NULL; // 未找到
}

int main() {
    char str[100], ch;
    char *res;
    
    while (1) {
        printf("输入字符串（空行退出）：");
        if (fgets(str, 100, stdin) == NULL) break;
        // 去掉fgets的换行符
        char *nl = strchr(str, '\n');
        if (nl) *nl = '\0';
        if (str[0] == '\0') break; // 空字符串退出
        
        printf("输入查找字符：");
        scanf("%c", &ch);
        while (getchar() != '\n'); // 清理换行符
        
        res = my_strchr(str, ch);
        if (res) {
            printf("找到'%c'，位置：%ld，截取：%s\n", 
                   ch, res - str, res);
        } else {
            printf("未找到'%c'\n", ch);
        }
    }
    return 0;
}

// 测试验证方案：  
//  1. 运行：输入"hello"和'l' → 找到位置1，截取"llo"  
//  2. 预期：正确判断存在性，指针运算和截取正确  
//  3. 检查点：NULL判断、指针位置计算、输入清理  
// 易错点提醒：  
//  1. 指针类型转换：const char*转char*避免警告  
//  2. 输入缓冲区清理：scanf后必须清换行，否则影响fgets  
// 拓展思考：  
//  1. 如何实现strrchr（最后一次出现）？反向遍历  
//  2. 对比标准strchr：逻辑一致，效率可优化（汇编级）  