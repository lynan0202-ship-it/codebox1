
/* 
问题7题干：C如何处理不同计算机系统中的不同文件和换行约定？

知识要点：
1. 换行符差异：
   - Windows：\r\n（回车+换行）
   - Linux/Mac：\n（换行）
2. C标准库行为：
   - 文本模式读写时，自动转换换行符：
     - 读入时：\r\n → \n
     - 写出时：\n → 系统对应的换行符

总体逻辑：
通过代码演示换行符的统一处理机制

代码功能：
1. 读取包含不同换行符的输入
2. 输出读取到的换行符实际值（验证统一为\n）
*/

#include <stdio.h>

int main() {
    int ch;
    
    printf("Enter text with newlines (Windows/Linux/Mac都可测试)\n");
    printf("Press Ctrl+D/Ctrl+Z to end input\n");
    
    // 持续读取字符，直到EOF
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            printf("Detected newline (ASCII: 10)\n");
        } else {
            printf("Character: %c (ASCII: %d)\n", ch, ch);
        }
    }

    return 0;
}

/* 
测试验证方案：
1. 跨平台测试：
   - Windows：用记事本输入内容（含回车），保存后测试
   - Linux/Mac：用vim输入内容（含换行），保存后测试

2. 观察输出：
   无论原始文件用\r\n还是\n，程序中检测到的换行符ASCII值都是10（\n）

3. 写入验证（扩展）：
   修改代码，将\n写入文件，观察不同系统下的实际存储（\n或\r\n）
*/