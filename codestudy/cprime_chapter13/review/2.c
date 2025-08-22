// ------------------------------
// 题干：分析程序功能（命令行运行，提取文件中的数字字符）
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// int main(int argc, char *argv[])
// { ... }
// 知识要点：
//  1. 命令行参数：argc判断参数数量，argv获取文件名
//  2. 文件操作：getc读字符，isdigit判断数字
//  3. 错误处理：参数不足或文件打开失败时退出
// 总体逻辑：
//  1. 检查参数，打开指定文件
//  2. 逐字符读取，筛选数字并输出
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int ch;          // 存储读取的字符（用int存EOF）
    FILE *fp;        // 文件指针

    // 检查参数数量，不足则退出
    if (argc < 2) exit(EXIT_FAILURE);

    // 打开文件，失败则退出
    if ((fp = fopen(argv[1], "r")) == NULL) exit(EXIT_FAILURE);

    // 逐字符读取，筛选数字输出
    while ((ch = getc(fp)) != EOF) {
        if (isdigit(ch)) putchar(ch); // 是数字则输出
    }

    fclose(fp); // 关闭文件
    return 0;
}

// 测试验证方案：
//  1. 运行：创建test.txt（含"a1b2c3"），执行./a.out test.txt
//  2. 预期：输出"123"
//  3. 检查：对比输出与文件中的数字
// 易错点提醒：
//  1. 把ch定义为char（无法正确判断EOF）
//  2. 忘记关闭文件
// 拓展思考：
//  1. 若提取字母，将isdigit改为isalpha即可
// ------------------------------