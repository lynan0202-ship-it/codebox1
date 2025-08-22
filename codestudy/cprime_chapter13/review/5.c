// ------------------------------
// 题干：打印文件中包含指定字符的行（接受两个参数：字符、文件名）
// 知识要点：
//  1. 命令行参数：argc=3，提取字符和文件名
//  2. 文件操作：fgets逐行读，strchr查找字符
//  3. 错误处理：参数错误、文件打开失败
// 总体逻辑：
//  1. 检查参数，提取目标字符和文件名
//  2. 打开文件，逐行读取
//  3. 查找目标字符，输出包含的行
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strchr函数

int main(int argc, char *argv[]) {
    // 检查参数数量
    if (argc != 3) {
        printf("用法：%s <字符> <文件名>\n", argv[0]);
        exit(1);
    }

    char target = argv[1][0]; // 取第一个参数的第一个字符
    FILE *fp = fopen(argv[2], "r"); // 打开文件

    // 检查文件打开失败
    if (fp == NULL) {
        printf("无法打开文件：%s\n", argv[2]);
        exit(1);
    }

    char line[1024]; // 存储每行内容
    // 逐行读取文件
    while (fgets(line, sizeof(line), fp) != NULL) {
        // 查找目标字符，存在则输出该行
        if (strchr(line, target) != NULL) {
            printf("%s", line);
        }
    }

    fclose(fp); // 关闭文件
    return 0;
}

// 测试验证方案：
//  1. 运行：创建test.txt（写"apple\nbanana\ncherry"），执行./a.out 'a' test.txt
//  2. 预期：输出apple和banana（含'a'）
//  3. 检查：对比输出与文件内容
// 易错点提醒：
//  1. 直接用argv[1]作为字符（需取argv[1][0]）
//  2. 忽略参数数量检查（argc!=3时出错）
// 拓展思考：
//  1. 若要匹配多个字符（如"ab"），可改用strpbrk函数
// ------------------------------