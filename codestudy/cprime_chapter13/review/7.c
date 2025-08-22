// ------------------------------
// 题干：7.b. 分别用putc()和fwrite()储存字符'S'有何区别？
// 知识要点：
//  1. putc：按字符输出到文本流（默认模式）
//  2. fwrite：按二进制输出（这里字符占1字节，两者存储内容相同，但流处理不同）
//  3. 流的隐含差异：文本流可能转换换行符，二进制流直接读写
// 总体逻辑：
//  1. 存储同一字符，对比两个文件的存储细节
#include <stdio.h>

int main() {
    char ch = 'S'; // ASCII码0x53
    
    // ---- putc存储（文本流，默认模式） ----
    FILE *putc_file = fopen("char_putc.txt", "w");
    putc(ch, putc_file); // 写1字节：0x53
    fclose(putc_file);
    
    // ---- fwrite存储（二进制流） ----
    FILE *fwrite_file = fopen("char_fwrite.bin", "wb");
    fwrite(&ch, sizeof(char), 1, fwrite_file); // 写1字节：0x53
    fclose(fwrite_file);
    
    printf("已生成char_putc.txt和char_fwrite.bin\n");
    return 0;
}

// 测试验证方案：
//  1. 运行：编译后执行，生成两个文件
//  2. 检查：
//     - 文本编辑器打开：两个文件都显示'S'
//     - 二进制查看：hexdump都显示0x53（1字节）
//  3. 隐藏差异：文本流在跨平台时可能转换换行符，二进制流不会
// 易错点提醒：
//  1. putc的参数顺序：putc(字符, 文件指针)，别写反
//  2. fwrite的元素个数：sizeof(char)是1，所以写1个元素
// 拓展思考：
//  1. 若存多字节字符（如'中'，占3字节UTF-8），putc会拆分字节写，fwrite也一样？
//  2. 为什么putc属于文本操作？（因为它是stdio库的文本流函数）
// ------------------------------