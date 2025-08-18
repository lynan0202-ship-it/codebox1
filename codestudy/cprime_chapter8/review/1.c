/* 
问题1题干：putchar(getchar())是一个有效表达式，它实现什么功能？getchar(putchar())是否也是有效表达式？

知识要点：
1. 函数嵌套调用逻辑：先执行内层函数，结果作为外层函数参数
2. getchar() 返回值：int类型（存储字符ASCII或EOF）
3. putchar(int c) 参数要求：需传入字符的ASCII码（int类型）
4. 语法合法性：函数参数类型必须匹配

总体逻辑：
- 演示putchar(getchar())的"回声"效果：读取一个字符并立即输出
- 验证getchar(putchar())的语法错误：putchar返回void，无法作为getchar参数

代码功能：
1. 循环读取字符并回显，直到遇到EOF（Ctrl+D/Ctrl+Z）
2. 尝试非法嵌套getchar(putchar())，展示编译错误
*/

#include <stdio.h>

int main() {
    int ch; // 用int存储getchar()返回值，兼容EOF(-1)和字符(0-127)
    
    // 合法嵌套：先getchar()读字符，结果给putchar()输出
    while ((ch = getchar()) != EOF) {
        putchar(ch);
        
        // 以下是非法嵌套演示（取消注释会编译报错）
        // getchar(putchar(ch)); 
        // 错误原因：putchar()返回void类型，不能作为getchar()的参数
        // 编译器会提示：void value not ignored as it ought to be
    }

    return 0;
}

/* 
测试验证方案：
1. 正常运行测试：
   - 输入：abc（回车）
   - 输出：abc（验证回声效果）
   - 结束方式：按Ctrl+D（Linux/Mac）或Ctrl+Z（Windows）终止程序

2. 非法嵌套测试：
   - 取消注释getchar(putchar(ch)); 
   - 编译代码，观察错误提示（验证语法合法性）

3. EOF验证：
   - 输入时直接按Ctrl+D/Ctrl+Z，程序应正常退出
*/