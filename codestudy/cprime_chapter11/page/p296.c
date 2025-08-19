/* 
 * 代码名称：nogo_learn.c（含错误版和正确版，演示字符串比较陷阱）
 * 知识要点总结：
 * 1. 字符串比较禁忌：不能用 ==/!= 比较（比较的是指针地址，非内容）
 * 2. strcmp 函数：<string.h> 提供，按字典序比较字符串内容：
 *    - 返回 0 → 内容相同
 *    - 返回非0 → 内容不同（正数/负数代表大小关系，依赖实现）
 * 3. 安全输入函数 s_gets：基于 fgets 处理换行符和缓冲区溢出，替代不安全的 gets
 * 总体逻辑说明：
 * ① 错误版：用 try != ANSWER 比较指针，导致逻辑永远成立（循环无法退出）
 * ② 正确版：用 strcmp(try, ANSWER) != 0 比较内容，实现正确的循环判断
 * ③ 两个版本共享 s_gets 函数，确保输入安全 
 */


/* ---------------------- 错误版本：nogo_bug.c ---------------------- */
#include <stdio.h>
#define ANSWER "Grant"   // 字符串常量，存储在只读区
#define SIZE 40         // 输入缓冲区大小

// 声明安全输入函数（处理换行和溢出）
char *s_gets(char *st, int n);

int main(void)
{
    char try[SIZE];      // 局部数组，存储在栈区，地址与ANSWER不同
    
    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);   // 读取用户输入

    // 错误逻辑：比较指针地址！try是栈区地址，ANSWER是只读区地址，永远不等
    while (try != ANSWER) 
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
    }

    puts("That's right!");  // 永远不会执行到这里（除非代码修改）
    return 0;
}

// 安全输入函数实现：
char *s_gets(char *st, int n)
{
    char *ret_val = fgets(st, n, stdin);  // 读取一行，最多存n-1个字符
    if (ret_val) {  // 读取成功时处理换行符
        int i = 0;
        // 找换行符或字符串结束符
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {  // 输入未溢出，替换换行符为结束符
            st[i] = '\0';
        } else {  // 输入溢出，清理缓冲区剩余字符
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}


/* ---------------------- 正确版本：nogo_fixed.c ---------------------- */
#include <stdio.h>
#include <string.h>  // 必须包含！因为要用 strcmp
#define ANSWER "Grant"
#define SIZE 40

char *s_gets(char *st, int n);

int main(void)
{
    char try[SIZE];
    
    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);

    // 正确逻辑：比较字符串内容！strcmp返回0表示内容相同，非0表示不同
    while (strcmp(try, ANSWER) != 0) 
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
    }

    puts("That's right!");  // 输入正确时执行
    return 0;
}

// 同错误版本的 s_gets 实现（复用函数）
char *s_gets(char *st, int n)
{
    char *ret_val = fgets(st, n, stdin);
    if (ret_val) {
        int i = 0;
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}


/* 
 * 代码测试及验证建议方案：
 * 
 * 一、错误版本（nogo_bug.c）测试：
 * 1. 编译运行，输入 "Grant" → 观察是否进入循环（必然进入，因为地址不同）
 * 2. 输入任意内容（如 "Apple"）→ 观察是否永远提示错误（验证指针比较的缺陷）
 * 
 * 二、正确版本（nogo_fixed.c）测试：
 * 1. 输入 "Grant" → 检查是否直接输出 "That's right!"（正确退出循环）
 * 2. 输入错误内容（如 "Washington"）→ 检查是否提示错误并要求重输
 * 3. 输入带大小写差异的内容（如 "grant"）→ 检查是否因内容不同（大小写敏感）继续循环
 * 4. 测试输入溢出：输入40个字符（如"GrantGrantGrantGrantGrantGrantGrantGr"）→ 检查 s_gets 是否截断并清理缓冲区
 * 
 * 三、对比学习：
 * 1. 同时运行两个版本，输入相同内容，观察行为差异 → 理解指针比较 vs 内容比较
 * 2. 调试查看 try 和 ANSWER 的地址值 → 验证两者存储位置不同
 * 
 * 易错点提醒：
 * ▶ 忘记包含 <string.h> 会导致 strcmp 报错（未定义函数）
 * ▶ 混淆 strcmp 返回值：0表示相等，写条件时别搞反（如写成 `strcmp(...) == 0` 才是相等）
 * ▶ s_gets 处理换行符后，输入的字符串会丢失换行，但不影响内容比较
 */