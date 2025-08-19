// ------------------------------
// 题干：4. 类似题3，但限制单词最大长度（防止溢出）。  
// 知识要点：  
//  1. 增加max_len参数：控制单词最大长度（含'\0'）  
//  2. 结合前导空白跳过和长度限制，增强安全性  
// 总体逻辑：  
//  1. 函数读单词时，最多存储max_len-1个字符  
//  2. 主函数测试长度限制效果  

#include <stdio.h>

// 读取单词，限制最大长度max_len（含'\0'）
void read_limited_word(char *word, int max_len) {
    char ch;
    int i = 0;
    
    // 跳前导空白
    while ((ch = getchar()) != EOF && (ch == ' ' || ch == '\t' || ch == '\n'));
    if (ch == EOF) {
        word[0] = '\0';
        return;
    }
    
    // 读单词（最多max_len-1个字符）
    word[i++] = ch;
    while (i < max_len - 1) {
        ch = getchar();
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == EOF) break;
        word[i++] = ch;
    }
    word[i] = '\0';
    
    // 丢弃剩余字符
    while (ch != '\n' && ch != EOF) ch = getchar();
}

int main() {
    char word[10]; // 最多9个字符 + '\0'
    printf("输入单词（最多9字符）：\n");
    read_limited_word(word, 10);
    
    printf("单词：%s（长度：%zu）\n", word, strlen(word));
    return 0;
}

// 测试验证方案：  
//  1. 运行：输入"longword123"（10字符）→ 读"longword1"（9字符）  
//  2. 预期：单词长度≤9，前导空白跳过  
//  3. 检查点：数组截断、边界处理正确  
// 易错点提醒：  
//  1. max_len传0/1：导致数组溢出（主函数需保证max_len≥1）  
//  2. 忘记留'\0'：循环条件应为i < max_len-1  
// 拓展思考：  
//  1. 如何返回实际读取长度？添加int *len参数  