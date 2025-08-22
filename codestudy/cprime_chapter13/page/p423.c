

/*
代码名称：reverse.c（文件内容倒序显示程序：演示fseek、ftell用法）
知识要点总结：
1. 文件随机访问核心函数：  
   - fseek(FILE *fp, long offset, int origin)：移动文件指针到指定位置  
     - origin取值：SEEK_SET（文件开头）、SEEK_CUR（当前位置）、SEEK_END（文件末尾）  
   - ftell(FILE *fp)：返回文件指针当前位置（相对于文件开头的字节偏移，类型long）  
2. 文件打开模式："rb"（二进制模式）→ 避免系统自动转换换行符（如DOS的\r\n转\n），保证字节定位精准  
3. 特殊字符处理：过滤DOS文件结束符（\x1A）和回车符（\r），适配多系统文本格式  
4. 循环逻辑：从文件末尾倒序遍历每个字节，逐字符读取并输出  

总体逻辑说明：  
① 交互输入：提示用户输入待处理的文件名  
② 文件打开：以二进制读模式（"rb"）打开，失败则报错退出  
③ 定位末尾：fseek(fp, 0, SEEK_END) 将指针移到文件末尾，ftell获取总字节数last  
④ 倒序读取：从last-1位置开始（count从1到last），每次通过fseek回退count字节，读取字符  
⑤ 字符过滤：跳过DOS文件结束符（\x1A）和回车符（\r），避免输出乱码  
⑥ 结果输出：倒序字符拼接成最终内容，最后换行并关闭文件  
*/

#include <stdio.h>
#include <stdlib.h>
#define SLEN 81        // 文件名最大长度（80字符 + 1个'\0'）
#define CNTRL_Z '\x1A' // DOS文本文件的结束标记（避免显示乱码）

int main(void) {
    char file[SLEN];   // 存储输入的文件名
    int ch;            // 存储当前读取的字符
    FILE *fp;          // 文件指针
    long count, last;  // count：当前遍历的偏移量；last：文件总字节数

    // ========== 1. 提示并获取文件名 ==========
    puts("Enter the name of the file to be processed:");
    scanf("%s", file);  // 读取文件名（假设无空格，若需支持空格需用fgets）

    // ========== 2. 打开文件（二进制模式关键！） ==========
    // "rb"模式：按原始字节处理，避免系统修改换行符（如DOS\r\n转\n），保证fseek/ftell精准
    if ((fp = fopen(file, "rb")) == NULL) { 
        printf("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);  // 打开失败，终止程序
    }

    // ========== 3. 定位文件末尾，获取总字节数 ==========
    fseek(fp, 0, SEEK_END);   // 将指针移到文件最后一个字节的下一个位置（EOF）
    last = ftell(fp);         // 获取当前位置（即文件总字节数，因为从开头到EOF的偏移）

    // ========== 4. 倒序遍历文件内容 ==========
    // count从1开始，每次回退count字节（如count=1→回退1字节，定位到最后一个有效字符）
    for (count = 1; count <= last; count++) { 
        fseek(fp, -count, SEEK_END);  // 从EOF往回移动count字节
        ch = getc(fp);                // 读取当前位置的字符

        // 过滤特殊字符：DOS结束符（\x1A）和回车符（\r，避免DOS文件换行混乱）
        if (ch != CNTRL_Z && ch != '\r') { 
            putchar(ch);  // 输出有效字符
        }
    }

    putchar('\n');  // 输出结束换行
    fclose(fp);     // 关闭文件
    return 0;
}


/*
代码测试及验证建议方案：
1. 基础功能验证：  
   • 创建test.txt，内容："Hello World"（11字节）  
   • 编译运行：gcc reverse.c -o reverse && ./reverse  
   • 输入test.txt → 输出："dlroW olleH"（严格倒序，含空格）  

2. 特殊格式文件测试：  
   • Windows下创建dos.txt（内容含\r\n换行）：  
     - 输入："AB\r\nCD"（实际字节：A B \r \n C D → 6字节）  
     - 预期输出："DC\nBA"（过滤\r，保留\n，倒序后为D C \n B A）  
   • UNIX格式文件（仅\n换行）：  
     - 输入："AB\nCD"（字节：A B \n C D → 5字节）  
     - 预期输出："DC\nBA"  

3. 边界情况测试：  
   • 空文件：输入空文件 → 输出空行（循环不执行，仅putchar('\n')）  
   • 单字符文件：内容"A" → 输出"A"  
   • 含DOS结束符的文件：在文件末尾添加\x1A → 程序自动过滤该字符，输出剩余内容倒序  

4. 模式差异测试：  
   • 故意用"r"（文本模式）打开DOS文件 → 观察ftell结果是否与实际字节数不符（如\r\n被转成\n，导致定位错误）  
   • 对比"rb"和"r"模式的输出差异，理解二进制模式的必要性  

5. 错误场景测试：  
   • 输入不存在的文件名 → 检查错误提示是否正常  
   • 文件无读取权限 → 验证程序是否退出并提示错误  

6. 逻辑调试技巧：  
   • 在循环内添加printf("count=%ld, ch=%c\n", count, ch); 观察每次读取的字符和偏移  
   • 修改CNTRL_Z为其他值，测试特殊字符过滤逻辑是否生效  
*/