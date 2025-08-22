// ------------------------------
// 题干：8. 编写一个程序，以一个字符和任意文件名作为命令行参数。如果字符后面没有参数，该程序读取标准输入；否则，程序依次打开每个文件并报告每个文件中该字符出现的次数。文件名和字符本身也要一同检查。程序应包含错误检查，以确定参数数量是否正确和是否能打开文件。如果无法打开文件，程序应报告这一情况，然后继续处理下一个文件。
// 知识要点：
//  1. 命令行参数处理（argc、argv判断参数数量，提取目标字符）
//  2. 文件操作（fopen打开/关闭文件，fgetc逐字符读取）
//  3. 标准输入处理（getchar读取，EOF结束）
//  4. 错误处理（参数校验、文件打开失败处理）
// 总体逻辑：
//  1. 检查参数数量：至少需要1个字符参数，否则报错退出
//  2. 提取目标字符（取第一个参数的首字符）
//  3. 区分输入源：无文件名则读标准输入，有文件名则遍历处理每个文件
//  4. 对每个输入源：打开→统计字符→输出结果→关闭（文件需关闭，标准输入无需关闭）
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // 检查参数数量：至少需要程序名+字符（共2个参数）
    if (argc < 2) {
        printf("错误：缺少字符参数！用法：%s <字符> [文件名...]\n", argv[0]);
        return 1;
    }

    char target = argv[1][0]; // 提取目标字符（取第一个参数的首字符）
    int file_num = argc - 2;  // 计算文件名参数的数量

    if (file_num == 0) { // 无文件名，处理标准输入
        printf("开始读取标准输入...\n");
        int count = 0;
        int ch;
        // 逐字符读取标准输入，直到EOF（Ctrl+D）
        while ((ch = getchar()) != EOF) { 
            if (ch == target) count++; // 匹配则计数
        }
        printf("标准输入中 '%c' 出现次数：%d\n", target, count);
    } else { // 有文件名，遍历处理每个文件
        for (int i = 2; i < argc; i++) {
            const char *filename = argv[i];
            FILE *fp = fopen(filename, "r"); // 只读模式打开文件
            if (fp == NULL) { // 文件打开失败
                perror(filename); // 打印系统错误信息
                continue; // 跳过当前文件，处理下一个
            }

            int count = 0;
            int ch;
            // 逐字符读取文件内容，直到EOF
            while ((ch = fgetc(fp)) != EOF) { 
                if (ch == target) count++;
            }

            printf("文件 %s 中 '%c' 出现次数：%d\n", filename, target, count);
            fclose(fp); // 关闭文件，释放资源
        }
    }

    return 0;
}

// 测试验证方案：
//  1. 运行方式：
//     - 标准输入测试：编译后运行 ./a.out a ，输入"apple banana"后按Ctrl+D，应统计a的次数（2次）
//     - 文件测试：创建file1.txt（内容"abc aaa"），运行 ./a.out a file1.txt ，应输出"文件 file1.txt 中 'a' 出现次数：4"
//     - 错误测试：运行 ./a.out a nofile.txt ，应输出"nofile.txt: No such file or directory"
//  2. 检查点：
//     - 参数不足时是否提示错误
//     - 标准输入和文件的统计结果是否正确
//     - 文件打开失败时是否跳过并提示
// 易错点提醒：
//  1. 忘记检查argc < 2，导致argv[1]越界访问
//  2. fopen后未判断fp是否为NULL，直接操作导致崩溃
//  3. 标准输入结束符（EOF）处理：Windows下是Ctrl+Z，Linux/Mac是Ctrl+D
// 拓展思考：
//  1. 如何支持多字节字符（如中文）？可将target改为字符串，用宽字符函数（如fgetwc、wcschr）处理
//  2. 如何忽略大小写？统计前将字符转成统一大小写（如tolower(ch) == tolower(target)）
// ------------------------------