/* 
问题2题干：编写一个程序，在遇到EOF之前，把输入作为字符流读取。程序要打印每个输入的字符及其相应的ASCII十进制值。注意处理非打印字符（如换行符、制表符等）。

知识要点：
1. 字符分类：区分打印字符（如 `a`）和非打印字符（如 `\n`）
2. 转义字符：用 `\n`、`\t` 等表示特殊字符
3. 条件判断：`isprint()` 函数判断是否为可打印字符（需 `ctype.h`）

总体逻辑：
1. 循环读取字符直到 EOF
2. 判断字符是否为可打印字符：
   - 是：直接打印字符和 ASCII 值
   - 否：用转义字符表示（如 `\n`、`\t`）
3. 每行限制打印 10 组（选做扩展，本题简化演示）

代码功能：
逐个输出字符及其 ASCII 值，特殊字符用转义符显示
*/

#include <stdio.h>
#include <ctype.h> // 包含 isprint() 函数

int main() {
    int ch;
    int line_count = 0; // 每行打印的字符组数

    while ((ch = getchar()) != EOF) {
        // 每行最多打印10组（选做要求，简化实现）
        if (line_count % 10 == 0 && line_count != 0) {
            putchar('\n'); // 满10组换行
        }

        // 判断是否为可打印字符
        if (isprint(ch)) {
            printf("'%c' (%d)\t", ch, ch);
        } else {
            // 特殊处理非打印字符
            switch (ch) {
                case '\n':
                    printf("'\\n' (%d)\t", ch);
                    break;
                case '\t':
                    printf("'\\t' (%d)\t", ch);
                    break;
                case '\r':
                    printf("'\\r' (%d)\t", ch);
                    break;
                default:
                    printf("'\\x%02x' (%d)\t", ch, ch); // 其他非打印字符用十六进制转义
                    break;
            }
        }

        line_count++;
    }

    putchar('\n'); // 最后换行，美化输出
    return 0;
}

/* 
测试验证方案：
1. 输入测试：
   - 输入 `Hello\tWorld\n`（含制表符和换行符）
   - 输出应包含：
     `'H' (72)  'e' (101)  'l' (108)  'l' (108)  'o' (111)  '\t' (9)  'W' (87)  'o' (111)  'r' (114)  'l' (108)  
     '\n' (10)`

2. 特殊字符测试：
   - 输入 `Ctrl+A`（非打印字符，ASCII 1）
   - 输出应为 `'\x01' (1)`

3. 每行限制验证：
   - 输入 11 个字符，观察是否第 11 个字符换行显示
*/