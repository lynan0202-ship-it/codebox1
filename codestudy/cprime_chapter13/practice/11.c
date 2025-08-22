// ------------------------------
// 题干：11. 编写一个程序，接受两个命令行参数。第1个参数是一个字符串，第2个参数是一个文件名。然后该程序查找该文件，打印文件中包含该字符串的所有行。因为该任务是面向行而不是面向字符的，所以要使用fgets()而不是getc()。使用标准C库函数strstr()在每一行中查找指定字符串。假设文件中的所有行都不超过255个字符。
// 知识要点：
//  1. 命令行参数（argc校验，提取目标字符串和文件名）
//  2. 文件行读取（fgets按行读取，处理换行符）
//  3. 字符串查找（strstr判断子串存在，区分大小写）
// 总体逻辑：
//  1. 检查参数数量：必须为3（程序名+字符串+文件名）
//  2. 打开文件→逐行读取→用strstr查找目标字符串→存在则打印该行
//  3. 关闭文件，处理错误（如文件打开失败）
#include <stdio.h>
#include <string.h> // 用于strstr

#define MAX_LINE 256 // 每行最多255字符+1个换行符

int main(int argc, char *argv[]) {
    // 步骤1：检查参数数量
    if (argc != 3) {
        printf("用法：%s <目标字符串> <文件名>\n", argv[0]);
        return 1;
    }

    char *target = argv[1];
    char *filename = argv[2];

    // 步骤2：打开文件
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(filename); // 打印系统错误
        return 1;
    }

    // 步骤3：逐行读取并查找
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp) != NULL) { // 读一行，直到EOF
        if (strstr(line, target) != NULL) { // 查找目标字符串
            printf("%s", line); // 打印包含目标的行（保留原换行符）
        }
    }

    // 步骤4：关闭文件
    fclose(fp);

    return 0;
}

// 测试验证方案：
//  1. 准备测试文件test.txt：
//     hello world\nfoo bar\nhello c\nTest Hello
//  2. 运行测试：
//     - ./a.out hello test.txt → 输出hello world、hello c（区分大小写，Test Hello不匹配）
//     - ./a.out foo test.txt → 输出foo bar
//     - ./a.out 空字符串 → 所有行都打印（strstr("","...")返回首地址）
//  3. 检查点：
//     - 参数不足时是否提示用法
//     - 文件无法打开时是否报错
//     - 行中包含目标字符串的位置是否正确（如"hello c"中的hello）
// 易错点提醒：
//  1. 忘记包含string.h，导致strstr未定义（编译器报错）
//  2. 目标字符串为空（argv[1]是空字符串），导致所有行都被打印（可添加if(target[0]=='\0')判断）
//  3. fgets读取的行包含换行符，打印时会自动换行（符合题目“打印行内容”的要求）
// 拓展思考：
//  1. 如何忽略大小写？将line和target转成小写后比较（如tolower，注意处理非ASCII字符）
//  2. 行长度超过255？题目假设不超过，若需支持可动态分配内存（如char *line = malloc(MAX_LINE); ）
// ------------------------------