/* 
代码名称：io_pair.c（演示输入输出函数配对：gets/puts vs fgets/fputs）
知识要点总结：
1. 函数特性对比：
   - gets()：读一行，丢弃末尾换行符（不安全，易溢出，已废弃）
   - puts()：输出字符串，自动追加换行符
   - fgets()：读一行（最多n-1字符），保留末尾换行符（若输入未超长）
   - fputs()：输出字符串到指定流（如stdout），不追加换行符
2. 配对逻辑：
   - gets() + puts()：丢换行 + 加换行 → 最终换行效果一致
   - fgets() + fputs()：保换行 + 不加换行 → 最终换行效果一致
3. 安全警示：gets()无长度限制，实际开发禁止使用，仅作语法理解

代码总体逻辑：
1. 第一阶段（gets+puts）：
   - 循环读取用户输入（gets返回非NULL时持续读取）
   - 输出时puts自动补换行，抵消gets丢弃的换行，保持显示格式
2. 第二阶段（fgets+fputs）：
   - 限制每次读80字符（81字节数组存80字符+'\0'）
   - fgets保留输入换行，fputs不补换行，保持显示格式
3. 两阶段通过手动回车衔接，演示不同配对的换行行为差异
*/

#include <stdio.h>

int main(void) {
    char line[81];  // 80字符+1个'\0'，适配fgets的长度限制

    // ========== 测试1：gets() + puts() 配对 ==========
    printf("=== 测试1：gets() + puts() 配对（gets已废弃，仅演示）===\n");
    printf("输入多行文本（按 Ctrl+Z/Ctrl+D 结束）：\n");
    while (gets(line)) {  // gets读成功返回line地址，失败（EOF）返回NULL
        /* 
         * gets特性：
         * - 读取到换行符时，会丢弃换行符，只存字符内容到line
         * - 无长度限制！输入超过80字符会溢出（危险！）
         * puts特性：
         * - 输出line内容后，自动添加换行符
         * 效果：输入的换行被gets丢，puts补回来 → 显示格式和输入一致
         */
        puts(line);  
    }

    // 清理输入流残留（简单处理，实际需更严谨）
    printf("\n按回车继续测试2...\n");
    getchar();  // 读取测试1结束后的换行符

    // ========== 测试2：fgets() + fputs() 配对 ==========
    printf("\n=== 测试2：fgets() + fputs() 配对（推荐用法）===\n");
    printf("再次输入多行文本（按 Ctrl+Z/Ctrl+D 结束）：\n");
    while (fgets(line, 81, stdin)) {  // 最多读80字符（81-1），从标准输入读
        /* 
         * fgets特性：
         * - 读取到换行符时，会把换行符一起存入line（如果输入≤80字符）
         * - 第二个参数限制长度，避免溢出，更安全
         * fputs特性：
         * - 输出line内容，不会自动加换行符
         * 效果：fgets存了换行，fputs直接输出 → 显示格式和输入一致
         */
        fputs(line, stdout);  
    }

    return 0;
}

/* 
测试及验证建议方案：
1. 基础换行验证：
   - 测试1输入：Hello↵World↵（↵=回车）
     预期输出：Hello↵World↵（puts补换行，和输入对齐）
   - 测试2输入：Hello↵World↵
     预期输出：Hello↵World↵（fgets存换行，fputs直接输出）

2. 超长输入测试（仅测fgets）：
   - 测试2输入81个字符（如80个'A' + ↵）
     预期：fgets读80个'A' + '\0'，换行符留在输入流 → 下一次读取会先读换行符
     观察：输出80个'A'，然后下一行是空行（因为换行符被读取）

3. 安全对比测试：
   - 测试1输入81个字符（如80个'B' + ↵）
     预期：程序可能崩溃（缓冲区溢出），体会gets的危险性

4. EOF结束测试：
   - Windows：按 Ctrl+Z → 回车；Linux/Mac：按 Ctrl+D
     预期：两个循环均结束，进入下一阶段

5. 手动构造换行符：
   - 调试时，手动给line赋值：strcpy(line, "Test\n"); 调用fputs
     预期：输出"Test"并换行（模拟fgets保留换行的场景）
   - 赋值strcpy(line, "Test"); 调用fputs → 输出"Test"不换行（模拟输入无换行的场景）

6. 易错点验证：
   - 测试fgets的长度参数：传入81，实际最多存80字符，验证是否理解"n-1"规则
   - 观察gets的返回值：输入EOF时，gets返回NULL，循环结束
   - 对比puts和printf("%s\n")：功能类似，但puts更简洁（需传入字符串地址）
*/