// ------------------------------
// 题干：下面的程序有什么问题？
// int main(void)
// {
//     int *fp;
//     int k;
// 
//     fp = fopen("gelatin");
//     for (k = 0; k < 30; k++)
//         fputs(fp, "Nanette eats gelatin.");
//     fclose(fp);
//     return 0;
// }
// 知识要点：
//  1. 文件指针类型：fopen返回FILE*，需修正指针类型
//  2. fopen参数：必须指定打开模式（如"w"写）
//  3. 错误检查：fopen失败需判断，避免空指针操作
//  4. fputs参数：字符串和文件指针顺序需修正
// 总体逻辑：
//  1. 修正指针类型为FILE*
//  2. 补充fopen模式并检查返回值
//  3. 调整fputs参数顺序
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp; // 修正：文件指针必须是FILE*类型
    int k;

    // 补充模式"w"（写模式），并检查打开失败
    fp = fopen("gelatin", "w"); 
    if (fp == NULL) {
        printf("无法打开文件！\n");
        exit(1);
    }

    for (k = 0; k < 30; k++) {
        // 修正参数顺序：字符串在前，文件指针在后
        fputs("Nanette eats gelatin.", fp); 
    }

    fclose(fp); // 关闭文件
    return 0;
}

// 测试验证方案：
//  1. 运行：编译后执行，生成gelatin文件
//  2. 预期：文件含30次"Nanette eats gelatin."（无换行）
//  3. 检查：打开文件查看内容重复次数
// 易错点提醒：
//  1. 忘记写fopen的模式参数
//  2. 搞反fputs的参数顺序
// 拓展思考：
//  1. 若要追加内容，将模式改为"a"即可
// ------------------------------