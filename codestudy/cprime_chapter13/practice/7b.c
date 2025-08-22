// ------------------------------
// 题干：7.b. 修改程序，按行号配对打印（第1行：文件1行 | 文件2行；第2行：... 直到某文件结束）
// 知识要点：
//  1. 行号计数与格式化输出
//  2. 处理文件行不匹配（某文件已读完，另一还有行）
//  3. 行尾换行符处理
// 总体逻辑：
//  1. 同7a打开文件 → 2. 循环读两行 → 3. 按行号配对输出 → 4. 关闭文件
#include <stdio.h>
#include <string.h>

#define LINE_MAX 1024

int main() {
    char fn1[100], fn2[100];
    printf("请输入第一个文件名：");
    fgets(fn1, 100, stdin);
    fn1[strcspn(fn1, "\n")] = '\0';
    
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
    int line_num = 1; // 行号从1开始
    
    while (1) {
        char *r1 = fgets(line1, LINE_MAX, fp1);
        char *r2 = fgets(line2, LINE_MAX, fp2);
        
        // 打印行号
        printf("第%d行：", line_num);
        
        // 处理文件1的行
        if (r1) {
            line1[strcspn(line1, "\n")] = '\0'; // 去换行
            printf("%s | ", line1);
        } else {
            printf("（无） | "); // 文件1已读完
        }
        
        // 处理文件2的行
        if (r2) {
            line2[strcspn(line2, "\n")] = '\0'; // 去换行
            printf("%s", line2);
        } else {
            printf("（无）"); // 文件2已读完
        }
        printf("\n"); // 换行
        
        if (!r1 && !r2) break; // 都读完，退出
        line_num++; // 行号递增
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}

// 测试验证方案：
//  1. 准备文件：
//     file1.txt：
//     Apple
//     Banana
//     file2.txt：
//     Red
//     Yellow
//     Blue
//  2. 运行：输入两个文件名
//  3. 预期输出：
//     第1行：Apple | Red
//     第2行：Banana | Yellow
//     第3行：（无） | Blue
//  4. 检查：行号是否正确，空行是否显示“（无）”，格式是否对齐
// 易错点提醒：
//  1. 忘记去除行尾换行符，导致输出换行混乱
//  2. 行号计数错误（如循环内忘记递增，或初始值为0）
//  3. 文件读完后继续读取（但fgets返回NULL，不影响逻辑）
// 拓展思考：
//  1. 如何让输出更美观？（固定列宽，用printf格式控制）
//  2. 行号相同但内容长度差异大，如何对齐？（计算最大长度，填充空格）
// 对比说明：
//  7a是“交替输出”，侧重行顺序；7b是“行号配对”，侧重行关联，前者更自由，后者更规整。