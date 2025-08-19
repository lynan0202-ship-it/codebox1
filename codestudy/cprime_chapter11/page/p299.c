

/*
代码名称：quit_chk.c  
知识要点总结：  
1. **strcmp函数**：比较字符串内容，返回0表示相等（用于判断用户是否输入"quit"）。  
2. **二维字符数组**：`input[LIM][SIZE]` 存储最多 `LIM` 行、每行最多 `SIZE-1` 个字符的字符串。  
3. **s_gets函数**：封装 `fgets`，解决两个问题：  
   - 替换换行符为 `\0`，规范字符串格式；  
   - 清理输入缓冲区残留字符（输入超长时），避免影响后续输入。  
4. **循环条件**：同时满足三个条件继续读取：  
   - 输入行数 `< LIM`（未达上限）；  
   - `s_gets` 读取成功（非EOF）；  
   - 当前行 **不是** "quit"（`strcmp` 返回非0）。  

代码总体逻辑：  
1. 提示用户输入（最多 `LIM` 行，输入"quit"停止）。  
2. 循环读取每行到 `input` 数组：  
   - 调用 `s_gets` 安全读取一行；  
   - 检查 **行数、读取状态、内容是否为quit**，满足则计数 `ct` 加1。  
3. 输出实际输入的行数。  
*/

#include <stdio.h>      // 提供printf、fgets、getchar等函数  
#include <string.h>     // 提供strcmp函数（比较字符串内容）  

#define SIZE 80         // 每行最大字符数（含'\0'，实际可存79个字符）  
#define LIM 10          // 最多读取的行数  
#define STOP "quit"     // 停止输入的关键字  

// 函数声明：安全读取字符串（处理换行符和输入溢出）  
char *s_gets(char *st, int n);  


int main(void)  
{  
    char input[LIM][SIZE];  // 存储输入的二维数组：LIM行，每行SIZE个字符  
    int ct = 0;             // 记录已输入的行数  

    printf("Enter up to %d lines (type quit to quit):\n", LIM);  

    // 循环条件解析：  
    // 1. ct < LIM → 未达最大行数  
    // 2. s_gets(...) != NULL → 读取成功（不是EOF）  
    // 3. strcmp(...) != 0 → 当前行不是"quit"（strcmp相等返回0，非0表示不相等）  
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && strcmp(input[ct], STOP) != 0)  
    {  
        ct++;  // 行数加1  
    }  

    printf("%d strings entered\n", ct);  // 输出最终输入的行数  
    return 0;  
}  


// 自定义安全输入函数：修复fgets的换行符残留和输入溢出问题  
char *s_gets(char *st, int n)  
{  
    char *ret_val;  // 存储fgets的返回值（判断是否读取成功）  
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

    return ret_val;  // 返回fgets的结果（调用者可判断是否读取成功）  
}  


/*  
代码测试及验证建议方案：  
1. **正常停止测试**：  
   - 输入2-3行后，输入"quit"，检查程序是否停止，输出行数是否正确。  
   - 测试大小写：输入"Quit"（大写），程序应继续运行（strcmp区分大小写）。  

2. **边界行数测试**：  
   - 连续输入`LIM`行（如10行），检查是否刚好读取10行，输出`10`。  
   - 输入`LIM-1`行后输入"quit"，输出行数应为`LIM-1`。  

3. **EOF测试**：  
   - 按 **Ctrl+D**（Linux/Mac）或 **Ctrl+Z**（Windows）模拟EOF，检查程序是否停止，输出行数是否为实际输入行数（<LIM）。  

4. **超长输入测试**：  
   - 输入一行超过`SIZE-1`个字符（如80个字符，SIZE=80时，输入81个字符），检查：  
     - 字符串是否被截断为79个字符 + `\0`；  
     - 后续输入是否正常（无残留字符干扰）。  

5. **空行测试（拓展）**：  
   - 修改循环条件为：`while (ct < LIM && s_gets(...) != NULL && input[ct][0] != '\0')`，  
   - 输入空行（直接按回车），检查程序是否停止（验证空行判断逻辑）。  

6. **易错点验证**：  
   - 尝试用 `==` 代替 `strcmp`（如 `input[ct] == STOP`），观察是否永远不停止（因比较**地址**而非内容），理解`strcmp`的必要性。  
   - 检查`s_gets`的换行符处理：输入一行后按回车，打印字符串长度（`strlen`），确认不含`\n`。  
*/