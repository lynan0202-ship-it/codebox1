// ------------------------------
// 题干：3. 读取一个单词（跳过前导空白，读非空白直到空白，丢弃剩余字符）。  
// 知识要点：  
//  1. 跳过前导空白：循环读直到非空白  
//  2. 读取单词：读非空白直到空白/EOF  
//  3. 丢弃剩余字符：清理输入行剩余内容  
// 总体逻辑：  
//  1. 函数先跳前导空白，再读单词字符，最后丢弃剩余  
//  2. 主函数调用后输出单词  

#include <stdio.h>

// 读取单词（跳前导空白，读非空白，丢弃剩余）
void read_word(char *word, int max_len) {
    char ch;
    int i = 0;
    
    // 跳前导空白
    while ((ch = getchar()) != EOF && (ch == ' ' || ch == '\t' || ch == '\n'));
    if (ch == EOF) {
        word[0] = '\0';
        return;
    }
    
    // 读单词字符（最多max_len-1个）
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
    char word[50];
    printf("输入一行文本（含前导空白和单词）：\n");
    read_word(word, 50);
    
    printf("读取的单词：%s\n", word);
    return 0;
}

// 测试验证方案：  
//  1. 运行：输入"   hello world" → 读"hello"；输入"\tfoo bar" → 读"foo"  
//  2. 预期：跳过前导空白，正确读取第一个单词  
//  3. 检查点：前导空白跳过、单词截断、剩余字符丢弃  
// 易错点提醒：  
//  1. 数组溢出：max_len需≥1，留'\0'位置  
//  2. EOF处理：全空白输入需返回空字符串  
// 拓展思考：  
//  1. 如何返回单词长度？添加输出参数记录i  
