
/* 
问题6题干：对于给定的输入（ch是int类型，而且是缓冲输入），下面各程序段的输出分别是什么？
a. 输入：If you quit, I will.[enter]
   程序段：while ((ch = getchar()) != 'i') putchar(ch);
b. 输入：Harhar[enter]
   程序段：while ((ch = getchar()) != '\n') { putchar(ch++); putchar(++ch); }

知识要点：
1. 循环终止条件：字符匹配（'i'或'\n'）
2. 自增运算符副作用：
   - ch++：先使用当前值，再自增
   - ++ch：先自增，再使用新值
3. 字符本质：ASCII码（自增会改变字符）

总体逻辑：
分别演示两个程序段的执行流程，可视化输出结果

代码功能：
1. 模拟问题6a的字符读取和输出
2. 模拟问题6b的自增运算和输出
*/

#include <stdio.h>

// 问题6a演示函数
void test_6a() {
    int ch;
    printf("=== 问题6a测试 ===\n");
    printf("输入模拟：If you quit, I will.\n");
    
    // 循环逻辑：遇到'i'停止，输出之前的字符
    while ((ch = getchar()) != 'i') {
        putchar(ch);
    }
    putchar('\n'); // 换行区分输出
}

// 问题6b演示函数
void test_6b() {
    int ch;
    printf("=== 问题6b测试 ===\n");
    printf("输入模拟：Harhar\n");
    
    // 循环逻辑：遇到换行停止，演示自增副作用
    while ((ch = getchar()) != '\n') {
        putchar(ch++); // 先输出旧值，再自增
        putchar(++ch); // 先自增，再输出新值
    }
    putchar('\n'); // 换行区分输出
}

int main() {
    // 注意：实际运行时需手动输入，或修改代码模拟输入
    // 这里通过函数调用演示逻辑，实际测试需手动输入
    
    test_6a();
    test_6b();
    
    return 0;
}

/* 
测试验证方案：
1. 手动输入测试：
   a. 运行程序后输入"If you quit, I will."，观察输出是否为"If you qu"
   b. 输入"Harhar"，观察输出是否为"HJacrthjacrt"（逐字符推导自增结果）

2. 手动推导验证：
   - 问题6b中，输入'H'的处理流程：
     ch = 'H'(72)
     putchar(72) → 输出'H'
     ch++ → ch=73
     ++ch → ch=74 → putchar(74) → 输出'J'
     最终第一个字符输出"HJ"，以此类推

3. 调试验证：
   使用调试器（gdb）单步执行，观察ch的值变化
*/