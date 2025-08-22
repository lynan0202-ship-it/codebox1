/* 
代码名称：count.c（文件字符统计程序）
知识要点总结：
1. 标准I/O核心函数：fopen（打开文件）、getc（逐字符读取）、putc（逐字符输出）、fclose（关闭文件）
2. 命令行参数：通过argc判断参数数量，argv获取程序名和文件名
3. 文件指针（FILE*）：操作文件的核心句柄，标记文件当前位置
4. EOF的意义：文件结束标志（值为-1），用于判断读取是否结束
5. 错误处理：参数校验、文件打开失败的检测与处理
总体逻辑说明：
① 参数检查：确保用户提供了文件名（argc==2），否则提示用法并退出
② 文件打开：以文本读模式（"r"）打开指定文件，失败则报错退出
③ 字符处理：循环读取文件字符，同时输出到屏幕并计数，直到遇到EOF
④ 资源释放：关闭文件，避免资源泄漏
⑤ 结果输出：打印统计的字符总数
*/

#include <stdio.h>
#include <stdlib.h> // 提供exit函数原型

int main(int argc, char *argv[]) {
    int ch;          // 必须用int存储！因为getc返回值包含EOF（-1），char无法正确表示
    FILE *fp;        // 文件指针，指向打开的文件对象
    unsigned long count = 0; // 统计字符数，unsigned long适配大文件

    // 1. 校验命令行参数数量
    if (argc != 2) { 
        // argv[0]是程序自身的名称（如./a.out）
        printf("Usage: %s filename\n", argv[0]); 
        exit(EXIT_FAILURE); // 非0退出码表示异常
    }

    // 2. 打开文件："r" = 文本模式只读
    fp = fopen(argv[1], "r"); 
    if (fp == NULL) { // 打开失败时fopen返回NULL
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // 3. 循环读取字符，直到文件结束
    while ((ch = getc(fp)) != EOF) { 
        putc(ch, stdout); // 等价于putchar(ch)，将字符输出到屏幕
        count++; // 统计有效字符
    }

    // 4. 关闭文件（必须执行，否则可能丢失缓冲区数据）
    fclose(fp);

    // 5. 输出统计结果
    printf("\nFile %s has %lu characters\n", argv[1], count);

    return 0; // 正常退出，返回0
}

/* 
代码测试及验证建议方案：
1. 基础功能验证：
   - 步骤：① 创建test.txt写入"ABC" ② 编译运行：gcc count.c -o count ③ ./count test.txt
   - 预期：屏幕输出ABC，随后显示"File test.txt has 3 characters"

2. 错误场景测试：
   - 场景A：无参数运行 → ./count 
     预期：输出"Usage: ./count filename"
   - 场景B：文件不存在 → ./count nofile.txt 
     预期：输出"Can't open nofile.txt"

3. 特殊文件测试：
   - 空文件：创建empty.txt（0字节）→ ./count empty.txt 
     预期：无字符输出，显示"File empty.txt has 0 characters"
   - 含换行文件：Windows下创建test2.txt（内容：Hello\r\nWorld）
     预期：程序输出Hello\nWorld（文本模式自动转\n），统计字符数为11（Hello(5)+换行(1)+World(5)）

4. 边界验证：
   - 大文件测试：用工具生成10MB文本文件，对比程序计数与实际字符数（可通过wc -c命令验证）
   - 特殊字符测试：写入包含中文的文件（UTF-8编码），验证每个字节是否被正确计数（注意：中文是多字节，但本程序按字节统计）

易错点提醒：
① ch的类型：必须是int！若写成char，当读取到0xFF（如某些特殊字符）时，会被解释为-1（EOF），导致提前终止循环
② 文件模式："r"是文本模式，Windows下会自动转换\r\n为\n，统计的是转换后的字符数（如\r\n算1个字符）
③ 资源泄漏：忘记fclose(fp)会导致文件句柄泄漏，长期运行可能耗尽系统资源
*/