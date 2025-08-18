/* 
问题1题干：设计一个程序，统计在读到文件结尾之前读取的字符数。

知识要点：
1. EOF 检测：`getchar() != EOF` 判断输入结束
2. 字符计数：通过循环累加字符数量
3. 输入处理：缓冲输入的基本用法

总体逻辑：
1. 初始化计数器，循环读取字符直到 EOF
2. 每次读取字符时计数器 +1
3. 输出最终统计的字符总数

代码功能：
统计用户输入的字符总数（按 Ctrl+D/Ctrl+Z 结束输入）
*/

#include <stdio.h>

int main() {
    int ch;       // 存储读取的字符（用 int 兼容 EOF）
    int count = 0; // 统计字符总数

    // 循环读取字符，直到遇到 EOF
    while ((ch = getchar()) != EOF) {
        count++; // 每读一个字符，计数+1
    }

    // 输出统计结果
    printf("Total characters: %d\n", count);

    return 0;
}

/* 
测试验证方案：
1. 直接输入测试：
   - 输入 `Hello` 后按 Ctrl+D（Linux/Mac）或 Ctrl+Z（Windows）
   - 输出应为 `Total characters: 5`（含换行符则+1）

2. 重定向测试：
   - 创建测试文件 `test.txt`，输入 `echo "Hi" > test.txt`
   - 执行命令 `./a.out < test.txt`
   - 输出应为 `Total characters: 3`（`Hi` + 换行符）

3. 特殊字符测试：
   - 输入包含空格、换行符、特殊符号（如 `!@#`），验证计数准确性
*/