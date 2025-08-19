/*
代码名称：quit_chk.c  
知识要点总结：  
1. **strcmp函数**：比较字符串内容，返回0表示相等（核心：比较内容而非地址，不可用`==`替代）。  
2. **二维字符数组**：`input[LIM][SIZE]` 存储多行输入，每行最多存 `SIZE-1` 个有效字符（留`\0`位置）。  
3. **s_gets函数**：封装`fgets`，解决两大问题：  
   - 替换换行符 `\n` 为 `\0`，规范字符串格式；  
   - 清理输入缓冲区残留字符（输入超长时），避免干扰后续输入。  
4. **循环退出条件**：同时满足 **行数未超限、读取成功、内容非quit** 三个条件才继续读取。  

代码总体逻辑：  
1. 提示用户输入规则（最多`LIM`行，输入`quit`停止）。  
2. 循环读取每行到`input`数组：  
   - 调用`s_gets`安全读取（处理换行和溢出）；  
   - 若 **行数<LIM、读取成功、内容≠quit**，则行数`ct`加1。  
3. 输出最终输入的行数，程序结束。  
*/  

#include <stdio.h>      // 提供输入输出函数（printf、fgets、getchar等）  
#include <string.h>     // 提供strcmp函数（字符串内容比较）  

#define SIZE 80         // 每行最大字符数（含'\0'，实际存79个字符）  
#define LIM 10          // 最多允许输入的行数  
#define STOP "quit"     // 触发停止的关键字  

// 函数声明：安全读取字符串（处理换行符和缓冲区残留）  
char *s_gets(char *st, int n);  


int main(void)  
{  
    char input[LIM][SIZE];  // 定义二维数组：LIM行，每行SIZE个字符  
    int ct = 0;             // 记录已输入的行数  

    // 提示用户输入规则  
    printf("Enter up to %d lines (type quit to quit):\n", LIM);  

    // 循环条件解析：  
    // 1. ct < LIM → 未达最大行数  
    // 2. s_gets(...) != NULL → 读取成功（非EOF）  
    // 3. strcmp(...) != 0 → 当前行不是"quit"（strcmp相等返回0，非0表示不相等）  
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && strcmp(input[ct], STOP) != 0)  
    {  
        ct++;  // 行数加1  
    }  

    // 输出最终输入的行数  
    printf("%d strings entered\n", ct);  
    return 0;  
}  


// 自定义安全输入函数：修复fgets的缺陷  
char *s_gets(char *st, int n)  
{  
    char *ret_val;  // 存储fgets的返回值（判断读取是否成功）  
    int i = 0;      // 遍历字符串的索引  

    // 第一步：用fgets读取一行，最多读n-1个字符（留1个位置给'\0'）  
    ret_val = fgets(st, n, stdin);  

    if (ret_val)  // 如果读取成功（不是EOF）  
    {  
        // 寻找换行符（\n）或字符串结束符（\0）  
        while (st[i] != '\n' && st[i] != '\0')  
        {  
            i++;  
        }  

        if (st[i] == '\n')  // 找到换行符 → 输入未超长  
        {  
            st[i] = '\0';  // 替换换行符为结束符，去掉换行  
        }  
        else  // 没找到换行符 → 输入超长，缓冲区有残留字符  
        {  
            // 清理多余字符：持续读取，直到遇到换行符  
            while (getchar() != '\n')  
            {  
                continue;  
            }  
        }  
    }  

    return ret_val;  // 返回fgets的结果（调用者可判断读取状态）  
}  


/*  
代码测试及验证建议方案：  
1. **正常停止测试**：  
   - 输入3行后输入`quit`，检查输出是否为`3`，程序是否停止。  
   - 输入`Quit`（大写），观察程序是否继续运行（因strcmp区分大小写）。  

2. **边界行数测试**：  
   - 连续输入10行（LIM=10），检查输出是否为`10`。  
   - 输入9行后输入`quit`，输出应为`9`。  

3. **EOF测试**：  
   - 按 **Ctrl+D**（Linux/Mac）或 **Ctrl+Z**（Windows）模拟EOF，检查输出是否为实际输入行数（<10）。  

4. **超长输入测试**：  
   - 输入一行81个字符（SIZE=80），检查：  
     - 字符串是否被截断为79个字符 + `\0`；  
     - 下一行输入是否正常（无残留字符干扰）。  

5. **空行检测（拓展）**：  
   - 修改循环条件为：`while (ct < LIM && s_gets(...) != NULL && input[ct][0] != '\0')`，  
   - 输入空行（直接回车），检查程序是否停止（验证空行判断）。  

6. **易错点验证**：  
   - 用`==`替代`strcmp`（如`input[ct] == STOP`），观察是否永远不停止（因比较地址而非内容）。  
   - 打印`input[0]`的长度（`strlen(input[0])`），验证`s_gets`是否正确替换了换行符。  
*/