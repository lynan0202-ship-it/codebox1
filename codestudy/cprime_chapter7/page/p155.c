#include <stdio.h>   // 提供 getchar、putchar 等输入输出函数
#include <ctype.h>   // 提供字符分类、转换函数（isalpha/tolower/toupper 等）

int main(void) {
    char ch;
    // 循环读取字符，直到遇到换行符（按下回车键结束输入）
    while ((ch = getchar()) != '\n') {  
        if (isalpha(ch)) {  // 判断是否为字母（来自 ctype.h 的字符测试函数）
            // 若为字母，转换为下一个字母输出（类似文中“字母替换”逻辑）
            putchar(ch + 1);  
            // 拓展演示：也可结合大小写转换，比如转小写后 +1 再转大写 
            // putchar(toupper(tolower(ch) + 1)); 
        } else {
            // 非字母字符原样输出（体现“保留非字母”需求）
            putchar(ch);  
        }
    }
    // 补充：演示 tolower/toupper 函数（来自 ctype.h 的字符映射函数）
    // 假设处理一个大写字母，转小写再转大写的示例
    char demoCh = 'Z';
    // tolower 将大写转小写，toupper 小写转大写（不修改原字符，需赋值生效）
    demoCh = tolower(demoCh);  // 'Z' -> 'z'
    demoCh = toupper(demoCh);  // 'z' -> 'Z' 
    // 输出结果验证（实际场景可按需用，这里仅演示函数用法）
    printf("\n演示大小写转换：原大写 Z 经处理后恢复为 %c\n", demoCh);

    return 0; 
}