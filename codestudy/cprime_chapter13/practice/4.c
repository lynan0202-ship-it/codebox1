// ------------------------------
// 题干：4. 编写一个程序，按顺序在屏幕上显示命令行中列出的所有文件。使用 argc 控制循环。
// 知识要点：
//  1. 命令行参数遍历（argc/argv循环）
//  2. 多文件逐行读取（fgets）
//  3. 文件打开失败处理
// 总体逻辑：
//  1. 检查参数数量 → 2. 循环处理每个文件 → 3. 逐行读文件并输出 → 4. 关闭文件
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) { // 至少传1个文件名
        printf("用法：%s 文件名1 文件名2 ...\n", argv[0]);
        return 1;
    }
    
    for (int i=1; i<argc; i++) { // 从第1个参数开始（argv[0]是程序名）
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("无法打开文件 %s\n", argv[i]);
            continue; // 跳过当前文件，处理下一个
        }
        
        char line[1024];
        while (fgets(line, 1024, fp) != NULL) { // 逐行读
            printf("%s", line); // fgets已含换行符
        }
        printf("\n"); // 文件间空一行分隔
        
        fclose(fp);
    }
    return 0;
}

// 测试验证方案：
//  1. 运行：创建file1.txt（"Hello"）、file2.txt（"World"），执行./a.out file1.txt file2.txt
//  2. 预期：先输Hello（换行），再输World（换行），中间空一行
//  3. 检查：文件内容是否按顺序输出，格式是否正确
// 易错点提醒：
//  1. 循环时i从1开始，忘记argc是参数总数，导致argv越界
//  2. 未处理文件打开失败，导致程序崩溃
//  3. fgets缓冲区过小，长行被截断（可增大缓冲区）
// 拓展思考：
//  1. 如何让文件分隔更明显？（输出文件名作为标题）
//  2. 二进制文件输出乱码，如何处理？（添加参数判断文件类型）