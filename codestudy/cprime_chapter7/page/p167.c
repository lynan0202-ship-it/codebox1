// wordent.c -- 统计字符数、单词数、行数（覆盖教程核心逻辑：分支判断、空白字符处理、单词识别）
#include <stdio.h>     // 提供 getchar()、printf() 等输入输出函数
#include <ctype.h>     // 提供 isspace() 函数（判断空白字符）
#include <stdbool.h>   // 提供 bool 类型、true/false 宏定义（替代 int 标记更直观）

#define STOP '|'       // 输入终止符：读取到 '|' 时结束统计

int main(void)
{
    char c;            // 当前读取的字符
    char prev = '\n';  // 上一个读取的字符（用于判断“不完整行”）
    long n_chars = 0L; // 统计总字符数（包含空白字符）
    int n_lines = 0;   // 统计总行数（以 '\n' 换行符为标记）
    int n_words = 0;   // 统计总单词数
    int p_lines = 0;   // 统计“不完整行”数（无换行符结尾的行）
    // 标记：当前字符是否在单词中（true = 在单词内，false = 不在单词内）
    bool inword = false; 

    // 提示用户输入规则：输入内容以 '|' 终止
    printf("Enter text to be analyzed (| to terminate):\n");

    // 循环读取字符，直到遇到终止符 STOP
    while ((c = getchar()) != STOP) {  
        // 1. 统计总字符数：所有输入字符（包括空白、换行等）都计数
        n_chars++;  

        // 2. 统计行数：遇到换行符 '\n' 时行数+1
        if (c == '\n') {  
            n_lines++;
            // 换行符属于空白字符 → 单词结束，重置 inword 标记
            inword = false;  
        }

        // 3. 识别“新单词开始”：当前字符不是空白，且不在单词中
        // 教程知识点：!isspace(c) 等价于 c != ' ' && c != '\n' && c != '\t' 等判断
        //       !inword 确保是“单词的第一个非空白字符”
        if (!isspace(c) && !inword) {  
            inword = true;  // 标记为“进入单词”
            n_words++;      // 新单词数量+1
        }

        // 4. 识别“单词结束”：当前字符是空白，且在单词中
        if (isspace(c) && inword) {  
            inword = false; // 标记为“离开单词”
        }

        // 5. 保存当前字符到 prev，用于后续判断“不完整行”
        prev = c;  
    }

    // 6. 判断“不完整行”：如果终止符前一个字符不是换行符 → 最后一行无换行
    if (prev != '\n') {  
        p_lines = 1;
    }

    // 输出统计结果：覆盖教程“字符、单词、行数统计”需求
    printf("characters = %ld, words = %d, lines = %d, ",
           n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);

    // 【教程扩展】演示三元运算符（?:）的等价用法（关联 7.5 节知识点）
    // 例：模拟“如果行数 > 0 则输出完整，否则提示无内容”
    // 三元表达式语法：condition ? expr_true : expr_false
    n_lines > 0 ? 
        printf("统计完成（行数非零）\n") : 
        printf("无有效行数（可能未输入内容）\n");

    return 0;
}
/*
代码核心逻辑如下：

输入终止符定义
用 #define STOP '|' 定义输入终止符，用户输入内容遇到 | 时统计结束。

变量初始化

c：当前读取的字符
prev：上一个字符（用于判断最后一行是否完整）
n_chars：总字符数
n_lines：总行数（遇到换行符 \n 时计数）
n_words：总单词数
p_lines：不完整行数（最后一行没有换行符时为 1）
inword：标记当前是否在单词内（true/false）
主循环读取字符
使用 getchar() 逐个读取字符，直到遇到终止符 |。

统计字符数
每读取一个字符，n_chars++。

统计行数
遇到换行符 \n，n_lines++，并重置 inword 标记。

单词识别

新单词开始：当前字符不是空白（!isspace(c)），且之前不在单词内（!inword），则 n_words++，inword = true。
单词结束：当前字符是空白（isspace(c)），且之前在单词内（inword），则 inword = false。
判断不完整行
如果最后一个字符不是换行符，则 p_lines = 1，表示最后一行没有以换行结束。

输出统计结果
打印字符数、单词数、行数、不完整行数。

三元运算符演示
用三元运算符 n_lines > 0 ? ... : ... 判断是否有有效行数，输出不同提示。

总结：
本程序通过循环和分支判断，统计输入文本的字符数、单词数、行数，并能识别最后一行是否完整，展示了空白字符处理、单词识别和三元运算符的用法。
*/
/*
代码核心逻辑如下：

输入终止符定义
用 #define STOP '|' 定义输入终止符，用户输入内容遇到 | 时统计结束。

变量初始化

c：当前读取的字符
prev：上一个字符（用于判断最后一行是否完整）
n_chars：总字符数
n_lines：总行数（遇到换行符 \n 时计数）
n_words：总单词数
p_lines：不完整行数（最后一行没有换行符时为 1）
inword：标记当前是否在单词内（true/false）
主循环读取字符
使用 getchar() 逐个读取字符，直到遇到终止符 |。

统计字符数
每读取一个字符，n_chars++。

统计行数
遇到换行符 \n，n_lines++，并重置 inword 标记。

单词识别

新单词开始：当前字符不是空白（!isspace(c)），且之前不在单词内（!inword），则 n_words++，inword = true。
单词结束：当前字符是空白（isspace(c)），且之前在单词内（inword），则 inword = false。
判断不完整行
如果最后一个字符不是换行符，则 p_lines = 1，表示最后一行没有以换行结束。

输出统计结果
打印字符数、单词数、行数、不完整行数。

三元运算符演示
用三元运算符 n_lines > 0 ? ... : ... 判断是否有有效行数，输出不同提示。

总结：
本程序通过循环和分支判断，统计输入文本的字符数、单词数、行数，并能识别最后一行是否完整，展示了空白字符处理、单词识别和三元运算符的用法。
*/