/* 
问题4题干：编写一个程序，在遇到EOF之前，把输入作为字符流读取。该程序要报告平均每个单词的字母数（空白符分隔单词，标点可选做处理）。

知识要点：
1. 单词识别：空白符（空格、换行、制表符等）分隔单词
2. 状态机思想：记录是否在单词中（in_word）
3. 平均值计算：总字母数 / 单词数
4. 选做扩展：用 `ispunct()` 处理标点（本题简化，暂不考虑）

总体逻辑：
1. 初始化状态变量（是否在单词中）、字母计数器、单词计数器
2. 循环读取字符直到 EOF
3. 判断字符是否为空白符：
   - 是空白符：如果之前在单词中，结束当前单词（单词数+1）
   - 非空白符：字母数+1，标记为在单词中
4. 最后计算并输出平均单词长度（注意处理单词数为0的情况）

代码功能：
统计输入的单词数和总字母数，计算平均单词长度
*/

#include <stdio.h>
#include <ctype.h> // 包含 isspace() 函数

int main() {
    int ch;
    int in_word = 0; // 标记是否在单词中（0：不在，1：在）
    int letter_count = 0; // 总字母数
    int word_count = 0;   // 单词数

    while ((ch = getchar()) != EOF) {
        if (isspace(ch)) { // 判断是否为空白符（空格、换行、制表符等）
            if (in_word) { // 如果之前在单词中，说明单词结束
                word_count++;
                in_word = 0; // 标记为不在单词中
            }
        } else { // 非空白符，属于单词内容
            letter_count++;
            in_word = 1; // 标记为在单词中
        }
    }

    // 处理最后一个单词（如果输入不以空白符结束）
    if (in_word) {
        word_count++;
    }

    // 计算并输出平均值（避免除以0）
    if (word_count > 0) {
        double average = (double)letter_count / word_count;
        printf("Total words: %d\n", word_count);
        printf("Total letters: %d\n", letter_count);
        printf("Average word length: %.2f\n", average);
    } else {
        printf("No words entered.\n");
    }

    return 0;
}

/* 
测试验证方案：
1. 简单输入测试：
   - 输入 `Hello world`
   - 输出应为：
     `Total words: 2`
     `Total letters: 10`
     `Average word length: 5.00`

2. 复杂输入测试：
   - 输入 `   Hello   world!  `（含多个空格和标点）
   - 输出应为：
     `Total words: 2`（忽略标点和多余空格）
     `Total letters: 10`
     `Average word length: 5.00`

3. 边界测试：
   - 输入空（直接 EOF）：输出 `No words entered.`
   - 输入 `a`：平均长度 1.00
*/