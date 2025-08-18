/* 
问题3题干：假设有一个名为count的可执行程序，用于统计输入的字符数。设计一个使用count程序统计essay文件中字符数的命令行，并把统计结果保存在essayct文件中。

知识要点：
1. 命令行重定向语法：
   - < ：将文件内容作为程序输入
   - > ：将程序输出写入文件
2. 程序设计原则：从标准输入读取数据（不直接处理文件名参数）

总体逻辑：
实现count程序的核心功能：统计标准输入的字符总数并输出
通过命令行重定向演示文件统计流程

代码功能：
1. 循环读取字符直到EOF，统计总数量
2. 输出统计结果（字符总数）
*/

#include <stdio.h>

int main() {
    int ch;
    int count = 0; // 统计字符总数
    
    // 持续读取字符，直到文件结束
    while ((ch = getchar()) != EOF) {
        count++;
    }
    
    // 输出统计结果到标准输出（可通过>重定向到文件）
    printf("Total characters: %d\n", count);

    return 0;
}

/* 
测试验证方案：
1. 编译程序：
   gcc -o count count.c （或使用对应编译器命令）

2. 创建测试文件：
   echo "Hello C Primer Plus" > essay （Linux/Mac）
   或手动创建essay文件并写入内容

3. 执行重定向命令：
   ./count < essay > essayct 

4. 验证结果：
   - 打开essayct文件，检查是否包含"Total characters: [实际数量]"
   - 注意：实际数量包含换行符，需与手动统计对比（如"Hello C Primer Plus"含20个字符+1个换行符=21）
*/