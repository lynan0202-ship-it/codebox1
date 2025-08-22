// ------------------------------
// 题干：7.a. 打开两个文件，交替打印行（文件1行→文件2行→文件1行→...直到较长文件结束）
// 知识要点：
//  1. 双文件并行读取（fgets同时读两个文件）
//  2. 循环控制（处理文件结束标记）
//  3. 行缓冲区操作
// 总体逻辑：
//  1. 读两个文件名 → 2. 打开文件 → 3. 循环读两行并输出 → 4. 关闭文件
#include <stdio.h>
#include <string.h>

#define LINE_MAX 1024

int main() {
    char fn1[100], fn2[100];
    printf("请输入第一个文件名：");
    fgets(fn1, 100, stdin);
    fn1[strcspn(fn1, "\n")] = '\0'; // 去换行
    
    printf("请输入第二个文件名：");
    fgets(fn2, 100, stdin);
    fn2[strcspn(fn2, "\n")] = '\0';
    
    FILE *fp1 = fopen(fn1, "r");
    FILE *fp2 = fopen(fn2, "r");
    if (fp1 == NULL || fp2 == NULL) {
        printf("无法打开文件！\n");
        if (fp1) fclose(fp1);
        if (fp2) fclose(fp2);
        return 1;
    }
    
    char line1[LINE_MAX], line2[LINE_MAX];
    while (1) {
        char *r1 = fgets(line1, LINE_MAX, fp1); // 读文件1行
        char *r2 = fgets(line2, LINE_MAX, fp2); // 读文件2行
        
        if (r1) printf("%s", line1); // 有内容则输出
        if (r2) printf("%s", line2); // 有内容则输出
        
        if (!r1 && !r2) break; // 都读完，退出
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}

// 测试验证方案：
//  1. 准备文件：
//     file1.txt：
//     Line1
//     Line3
//     file2.txt：
//     Line2
//     Line4
//     Line5
//  2. 运行：输入两个文件名
//  3. 预期输出：
//     Line1
//     Line2
//     Line3
//     Line4
//     Line5
//  4. 检查：行顺序是否交替，直到较长文件结束
// 易错点提醒：
//  1. 文件名含换行符未处理，导致打开失败
//  2. 循环条件错误（只判断一个文件结束，提前退出）
//  3. 未关闭已打开的文件，导致资源泄漏
// 拓展思考：
//  1. 长行超过LINE_MAX如何处理？（动态扩展缓冲区）
//  2. 二进制文件如何处理行？（自定义行分隔符）