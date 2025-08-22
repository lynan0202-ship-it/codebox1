/* 
代码名称：append.c（文件内容追加程序）
知识要点总结：
1. 标准I/O函数：fopen（文件打开）、fread/fwrite（二进制块读写）、setvbuf（自定义缓冲区）、feof/ferror（错误区分）、rewind（重置文件指针）。
2. 文件模式："a+"（追加读写，文件不存在则创建）、"r"（只读打开）。
3. 缓冲区配置：通过setvbuf设置全缓冲（_IOFBF），大小4096字节，提升读写效率。
4. 输入处理：自定义s_gets函数，解决fgets保留换行符的问题，支持空行退出。
5. 错误处理：检查文件打开失败、缓冲区创建失败、读写错误（ferror）。
6. 功能逻辑：将多个源文件内容追加到目标文件，最后显示目标文件内容。

总体逻辑说明：
1. 输入目标文件名，以"a+"模式打开，并用setvbuf配置4096字节全缓冲。
2. 循环输入源文件名（空行退出）：
   - 若源文件与目标文件同名，跳过（避免自追加）。
   - 以"r"模式打开源文件，并用setvbuf配置同样缓冲。
   - 调用append函数，通过fread/fwrite批量拷贝内容（每次4096字节）。
   - 检查源文件读错误、目标文件写错误，处理后关闭源文件。
3. 所有源文件处理完毕后，用rewind重置目标文件指针到开头，读取并显示内容。
4. 自定义函数：
   - s_gets：读取行输入，替换换行符为'\0'，清理多余字符。
   - append：循环读取源文件数据块，写入目标文件。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096  // 缓冲区大小，影响读写效率
#define SLEN 81       // 文件名最大长度

// 函数声明
void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int main(void)
{
    FILE *fa, *fs;     // fa: 目标文件指针，fs: 源文件指针
    int files = 0;     // 成功追加的文件数量
    char file_app[SLEN]; // 目标文件名
    char file_src[SLEN]; // 源文件名
    int ch;

    // 1. 输入目标文件名并打开
    puts("Enter name of destination file:");
    s_gets(file_app, SLEN);  // 替代fgets，处理换行符
    if ((fa = fopen(file_app, "a+")) == NULL) {  // "a+"：追加读写，不存在则创建
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }

    // 2. 配置目标文件的缓冲区：全缓冲，大小BUFSIZE
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {  // NULL表示让系统分配缓冲内存
        fprintf(stderr, "Can't create output buffer\n");
        exit(EXIT_FAILURE);
    }

    // 3. 循环处理源文件
    puts("Enter name of first source file (empty line to quit):");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0') {  // 空行退出
        // 避免自追加（源文件和目标文件同名）
        if (strcmp(file_src, file_app) == 0) {
            fputs("Can't append file to itself\n", stderr);
        } 
        // 打开源文件（只读模式）
        else if ((fs = fopen(file_src, "r")) == NULL) {
            fprintf(stderr, "Can't open %s\n", file_src);
        } 
        // 源文件打开成功，开始处理
        else {
            // 配置源文件的缓冲区（同目标文件，提升读效率）
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
                fputs("Can't create input buffer\n", stderr);
                continue;  // 跳过当前文件，尝试下一个
            }

            append(fs, fa);  // 拷贝源文件内容到目标文件

            // 检查读写错误
            if (ferror(fs) != 0) {  // 源文件读错误
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            }
            if (ferror(fa) != 0) {  // 目标文件写错误
                fprintf(stderr, "Error in writing file %s.\n", file_app);
            }

            fclose(fs);  // 关闭源文件
            files++;     // 统计成功追加的文件数
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }

    // 4. 显示目标文件内容（先重置指针到开头）
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);  // 将文件指针移到开头（"a+"模式下，写始终在末尾，但读可回到开头）
    printf("%s contents:\n", file_app);
    while ((ch = getc(fa)) != EOF) {  // 逐字符读取显示
        putchar(ch);
    }
    puts("Done displaying.");
    fclose(fa);  // 关闭目标文件

    return 0;
}

/* 
append函数：将源文件内容批量拷贝到目标文件
参数：
- source：源文件指针（已打开，读模式）
- dest：目标文件指针（已打开，写模式）
实现：
- 用静态缓冲区temp（只分配一次，提升效率）
- 每次读BUFSIZE个字符，再写入目标文件，直到读完（fread返回0）
*/
void append(FILE *source, FILE *dest)
{
    size_t bytes;                // 实际读取的字节数
    static char temp[BUFSIZE];   // 静态数组：仅第一次调用时分配，后续复用

    // fread返回“成功读取的块数”，这里块大小是1字节，所以等价于字节数
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0) {
        fwrite(temp, sizeof(char), bytes, dest);  // 写入实际读取的字节数
    }
}

/* 
s_gets函数：安全读取行输入（替代fgets的换行符问题）
功能：
1. 用fgets读取行，若成功，替换换行符为'\0'；
2. 若输入超长（无换行符），清理输入流中剩余的字符，避免影响后续输入。
参数：
- st：存储输入的缓冲区
- n：缓冲区大小（防止溢出）
返回：
- 成功：st的地址；失败（如EOF）：NULL
*/
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);  // 读取一行，包括换行符
    if (ret_val) {
        find = strchr(st, '\n');    // 查找换行符位置
        if (find) {                 // 如果找到换行符
            *find = '\0';           // 替换为字符串结束符
        } else {                    // 未找到换行符（输入超长）
            while (getchar() != '\n') {  // 清理输入流中剩余的字符
                continue;
            }
        }
    }
    return ret_val;
}

/* 
测试及验证建议方案：
1. 基础功能测试：
   - 准备2个源文件（如src1.txt、src2.txt，含不同内容），输入目标文件dest.txt。
   - 运行程序，输入源文件名，检查dest.txt是否包含两个文件的内容。
   - 输入空行退出，查看程序输出的追加文件数量是否正确。

2. 边界情况测试：
   - 输入源文件与目标文件同名（如dest.txt），检查程序是否提示"Can't append file to itself"。
   - 输入不存在的源文件名，检查程序是否提示"Can't open xxx"。
   - 测试空源文件（0字节），检查目标文件是否追加空内容（无报错）。

3. 缓冲区验证：
   - 修改BUFSIZE为1（极端值），观察setvbuf是否失败（程序输出"Can't create input/output buffer"）。
   - 对比使用setvbuf和不使用的情况，通过文件读写时间（大文件）感受缓冲的效率差异。

4. 错误模拟：
   - 手动删除目标文件的写权限，测试fopen("a+")是否失败，程序是否退出。
   - 在拷贝过程中强制终止程序（如Ctrl+C），检查ferror是否捕获错误。

5. 输入处理测试：
   - 输入带换行符的文件名（实际不可能，因为s_gets会处理），检查s_gets是否正确截断。
   - 输入超长文件名（超过SLEN，如81字符），检查s_gets是否清理多余字符，后续输入是否正常。

易错点提醒：
- setvbuf必须在fopen后、对文件操作前调用，否则行为未定义。
- s_gets中，若输入行超过缓冲区大小，需循环清理剩余字符，否则会残留到下一次输入。
- fread/fwrite的返回值是“块数”，而非字节数，需注意size和nmemb的乘积才是总字节数。
- rewind会重置文件指针到开头，若目标文件以"a+"打开，追加模式下写操作始终在末尾，但读操作可通过rewind回到开头。
*/