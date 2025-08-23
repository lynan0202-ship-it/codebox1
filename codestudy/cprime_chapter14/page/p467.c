/* 
代码名称：booksave.c（结构体内容保存到文件示例）
知识要点总结：
1. 结构体应用：定义 struct book 存储书籍的标题、作者、价格信息。
2. 文件操作：
   - 以 "a+b" 模式打开文件（二进制追加+读取，不存在则创建）。
   - 使用 rewind 定位文件开头，fread 读取已有数据，fwrite 写入新数据。
3. 二进制IO：通过 sizeof(struct book) 确定数据块大小，一次读写一个结构体。
4. 输入处理：
   - 自定义 s_gets 函数，解决 fgets 残留换行符和缓冲区溢出问题。
   - 配合 getchar 清理 scanf 后的输入残留。
5. 流程控制：区分文件已有数据和新增数据，处理数组容量上限。

代码总体逻辑：
1. 文件打开：尝试以 "a+b" 模式打开 book.dat，失败则退出。
2. 读取已有数据：定位文件开头，循环读取结构体到数组，同时打印内容。
3. 接收新数据：提示用户输入书籍信息（标题非空时持续输入），存到数组。
4. 写入新数据：若有新增内容，遍历新增部分，打印并写入文件。
5. 收尾：关闭文件，结束程序。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // 提供 strchr 函数

#define MAXTITL 40  // 书名最大长度（含结束符）
#define MAXAUTL 40  // 作者名最大长度（含结束符）
#define MAXBKS 10   // 最多存储的书籍数量

// 自定义字符串读取函数：解决 fgets 换行符和缓冲区溢出问题
char *s_gets(char *st, int n)
{
    char *ret_val = fgets(st, n, stdin);  // 读取一行，最多存 n-1 个字符
    if (ret_val != NULL) {                // 若读取成功
        char *find = strchr(st, '\n');    // 查找换行符位置
        if (find != NULL) {               // 若找到换行符
            *find = '\0';                 // 替换为字符串结束符
        } else {                          // 若没找到（输入超长）
            while (getchar() != '\n') {   // 清理输入缓冲区剩余字符
                continue;
            }
        }
    }
    return ret_val;  // 返回读取结果（成功非空/失败NULL）
}

// 定义书籍结构体
struct book {
    char title[MAXTITL];  // 书名
    char author[MAXAUTL]; // 作者
    float value;          // 价格
};

int main(void)
{
    struct book library[MAXBKS];  // 存储书籍的结构体数组
    int count = 0;                // 记录已读/已存的书籍总数
    int filecount = 0;            // 记录文件中原有书籍数量
    FILE *pbooks;                 // 文件指针
    size_t size = sizeof(struct book);  // 单个结构体的字节大小

    // 打开文件：a+b 模式支持二进制读写，追加时不会覆盖原有内容
    if ((pbooks = fopen("book.dat", "a+b")) == NULL) {
        fprintf(stderr, "Can't open book.dat file.\n");
        exit(1);  // 打开失败，终止程序
    }

    rewind(pbooks);  // 定位到文件开头，准备读取已有内容

    // 读取文件中已有的书籍（每次读1个结构体，共读 size 字节）
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
        if (filecount == 0) {  // 首次读取时打印标题
            puts("Current contents of book.dat:");
        }
        // 打印已读书籍信息
        printf("%s by %s: $%.2f\n", 
               library[count].title, 
               library[count].author, 
               library[count].value);
        count++;  // 计数加1
    }
    filecount = count;  // 记录文件原有书籍数量

    // 若数组已满，提示并退出
    if (count == MAXBKS) {
        fprintf(stderr, "The book.dat file is full.\n");
        fclose(pbooks);
        exit(2);
    }

    // 提示用户添加新书
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");

    // 循环接收新书信息（标题非空且数组未满）
    while (count < MAXBKS && 
           s_gets(library[count].title, MAXTITL) != NULL && 
           library[count].title[0] != '\0') {
        
        // 输入作者
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        
        // 输入价格（注意：scanf 后需清理换行符）
        puts("Now enter the value.");
        scanf("%f", &library[count].value);
        while (getchar() != '\n') {  // 清理 scanf 残留的换行符
            continue;
        }

        count++;  // 新书计数加1

        // 若还能继续输入，提示下一个标题
        if (count < MAXBKS) {
            puts("Enter the next title.");
        }
    }

    // 若有新增书籍（count > filecount），写入文件并打印
    if (count > filecount) {
        puts("Here is the list of your books:");
        for (int i = filecount; i < count; i++) {  // 遍历新增部分
            printf("%s by %s: $%.2f\n", 
                   library[i].title, 
                   library[i].author, 
                   library[i].value);
            // 将新增结构体写入文件（每次写1个，共写 size 字节）
            fwrite(&library[i], size, 1, pbooks);
        }
    } else {  // 无新增书籍
        puts("No books? Too bad.");
    }

    puts("Bye.");
    fclose(pbooks);  // 关闭文件
    return 0;
}

/* 
测试及验证建议方案：
1. 首次运行测试：
   - 输入2本新书，观察输出是否包含“Here is the list...”，且内容正确。
   - 检查目录下是否生成 book.dat 文件。

2. 二次运行测试：
   - 程序应先打印上次保存的书籍（验证 rewind + fread 生效）。
   - 再添加1本新书，确认输出和文件内容更新。

3. 边界测试：
   - 连续输入10本新书（达 MAXBKS），检查是否提示“文件满”并退出。
   - 输入超长标题（如50个字符），观察 s_gets 是否截断，且后续输入正常。

4. 异常测试：
   - 删除 book.dat 后运行，验证是否创建新文件并正常工作。
   - 修改文件权限使 fopen 失败，检查错误提示是否输出。

5. 数据一致性验证：
   - 多次运行，对比程序输出和 book.dat 的读写结果（可通过二进制编辑器辅助观察，或重复读取验证）。

易错点提醒：
- "a+b" 模式：追加时文件指针默认在末尾，必须用 rewind 回到开头才能读取原有内容。
- 输入处理：s_gets 处理了换行符，但 scanf 后需单独清理换行符（二者输入机制不同）。
- 数组索引：filecount 记录文件原有数据量，写入时从 filecount 开始，避免覆盖已有内容。
*/