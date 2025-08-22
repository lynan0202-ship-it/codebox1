// ------------------------------
// 题干：补全文件操作的参数（fp1读terky，fp2写jerky）
// 知识要点：
//  1. 文件读写函数：getc读、fprintf/putc写、fclose关闭
//  2. 参数规则：读用fp1，写用fp2；函数参数顺序需匹配
// 总体逻辑：
//  1. getc从fp1读；fprintf/putc向fp2写；fclose关闭fp2
#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    char ch;

    fp1 = fopen("terky", "r");
    fp2 = fopen("jerky", "w");
    if (fp1 == NULL || fp2 == NULL) return 1; // 假设打开成功，简化处理

    // a. 从terky（fp1）读字符
    ch = getc(fp1); 

    // b. 向jerky（fp2）写ch，带换行
    fprintf(fp2, "%c\n", ch); 

    // c. 向jerky（fp2）写ch
    putc(ch, fp2); 

    // d. 关闭jerky文件（fp2）
    fclose(fp2); 

    fclose(fp1); // 顺带关闭fp1
    return 0;
}

// 测试验证方案：
//  1. 运行：创建terky（写"A"），编译执行后查看jerky内容
//  2. 预期：jerky含两行"A"（fprintf带换行，putc不带）
//  3. 检查：打开jerky文件对比内容
// 易错点提醒：
//  1. 搞反getc的参数（写成fp2）
//  2. fprintf/putc的参数顺序错误
// 拓展思考：
//  1. 若fp2用"a"模式，内容会追加而非覆盖
// ------------------------------