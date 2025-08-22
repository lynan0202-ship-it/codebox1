// ------------------------------
// 题干：2. 编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文件名。尽量使用标准IO和二进制模式。
// 知识要点：
//  1. 命令行参数（argc/argv）
//  2. 二进制文件操作（fopen的rb/wb模式）
//  3. 块读写（fread/fwrite）
// 总体逻辑：
//  1. 检查参数数量 → 2. 打开源文件和目标文件 → 3. 循环读写数据 → 4. 关闭文件
#include <stdio.h>
#include <stdlib.h> // exit函数

#define BUFFER_SIZE 1024 // 每次读写1KB

int main(int argc, char *argv[]) {
    if (argc != 3) { // 必须传2个文件名
        printf("用法：%s 源文件 目标文件\n", argv[0]);
        exit(1);
    }
    
    FILE *src = fopen(argv[1], "rb"); // 二进制读
    if (src == NULL) {
        printf("无法打开源文件 %s\n", argv[1]);
        exit(1);
    }
    
    FILE *dest = fopen(argv[2], "wb"); // 二进制写
    if (dest == NULL) {
        printf("无法打开目标文件 %s\n", argv[2]);
        fclose(src); // 先关源文件，避免泄漏
        exit(1);
    }
    
    char buffer[BUFFER_SIZE];
    size_t read_len;
    while ((read_len = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, read_len, dest); // 写实际读取的字节
    }
    
    fclose(src);
    fclose(dest);
    printf("拷贝完成！\n");
    return 0;
}

// 测试验证方案：
//  1. 运行：./a.out source.bin dest.bin（source.bin存在）
//  2. 预期：生成dest.bin，内容与source.bin一致（用md5sum验证）
//  3. 检查：文件大小、二进制内容是否相同
// 易错点提醒：
//  1. 忘记处理参数数量，导致argv越界
//  2. 打开目标文件失败时，未关闭源文件
//  3. 忽略fread/fwrite的返回值，导致部分内容未读写
// 拓展思考：
//  1. 缓冲区大小如何优化？（测试不同大小的性能）
//  2. 如何实现断点续传？（记录偏移量，用fseek定位）