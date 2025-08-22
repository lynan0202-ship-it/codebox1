// ------------------------------
// 题干：3. 编写一个文件拷贝程序，提示用户输入文本文件名，并以该文件名作为原始文件名和输出文件名。该程序要使用 ctype.h 中的 toupper() 函数，在写入到输出文件时把所有文本转换成大写。使用标准IO和文本模式。
// 知识要点：
//  1. 文本文件读写（fopen的r/w模式）
//  2. 字符转换（toupper函数）
//  3. 内存缓冲（先读入内存再写入，避免覆盖）
// 总体逻辑：
//  1. 读文件名 → 2. 读文件内容到缓冲区 → 3. 转换为大写 → 4. 写回原文件
#include <stdio.h>
#include <ctype.h>   // toupper
#include <string.h>  // strcspn

#define MAX_FILE_SIZE 1024*1024 // 假设文件最大1MB

int main() {
    char filename[100];
    printf("请输入文本文件名：");
    fgets(filename, 100, stdin); // 支持空格
    filename[strcspn(filename, "\n")] = '\0'; // 去掉换行
    
    // 第一步：读原文件内容
    FILE *fp_read = fopen(filename, "r");
    if (fp_read == NULL) {
        printf("无法读取文件 %s\n", filename);
        return 1;
    }
    
    char buffer[MAX_FILE_SIZE];
    size_t read_len = fread(buffer, 1, MAX_FILE_SIZE-1, fp_read);
    buffer[read_len] = '\0'; // 确保是字符串
    fclose(fp_read);
    
    // 第二步：转换为大写
    for (size_t i=0; i<read_len; i++) {
        buffer[i] = toupper(buffer[i]);
    }
    
    // 第三步：写回原文件（会清空原内容）
    FILE *fp_write = fopen(filename, "w");
    if (fp_write == NULL) {
        printf("无法写入文件 %s\n", filename);
        return 1;
    }
    
    fwrite(buffer, 1, read_len, fp_write);
    fclose(fp_write);
    
    printf("内容已转大写并保存！\n");
    return 0;
}

// 测试验证方案：
//  1. 运行：创建test.txt（内容"Hello World!"），运行后输入test.txt
//  2. 预期：test.txt内容变为"HELLO WORLD!"
//  3. 检查：非字母字符（如标点）是否保留，全大写是否正确
// 易错点提醒：
//  1. fgets读入的文件名含换行，忘记处理导致打开失败
//  2. 缓冲区过小，大文件内容丢失（可改用动态分配）
//  3. 写文件前未关闭读模式文件（虽本例已关，但逻辑易出错）
// 拓展思考：
//  1. 大文件如何处理？（逐行读转换，或动态分配缓冲区）
//  2. 如何避免覆盖原文件？（先写临时文件，再替换）