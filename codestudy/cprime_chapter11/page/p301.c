/*
代码名称：copy1.c  
知识要点总结：  
1. **strcpy函数**：将源字符串（第2参数）完整复制到目标数组（第1参数），包含终止符`\0`。目标数组必须有足够空间（否则会溢出！）。  
2. **字符串首字符判断**：可通过`temp[0] == 'q'`检查，也可使用`strncmp(temp, "q", 1)`（更通用，支持多字符前缀判断）。  
3. **s_gets函数**：封装`fgets`，解决两个关键问题：  
   - 替换输入末尾的`\n`为`\0`，让字符串格式更规范；  
   - 清理输入缓冲区中超长的残留字符，避免影响后续输入。  
4. **二维字符数组**：`qwords[LIM][SIZE]` 用于存储最多`LIM`个字符串，每个字符串最多容纳`SIZE-1`个有效字符（预留`\0`位置）。  

代码总体逻辑：  
1. 提示用户输入 `LIM` 个以 `q` 开头的单词。  
2. 循环读取用户输入到临时数组 `temp`：  
   - 若首字符不是 `q`，提示错误并跳过本次循环；  
   - 若是 `q`，则通过 `strcpy` 将 `temp` 的内容复制到 `qwords` 数组，并增加有效单词计数 `i`。  
3. 当输入达到 `LIM` 个有效单词或输入结束时，遍历 `qwords` 输出所有符合条件的单词。  
*/  

#include <stdio.h>      // 提供 printf、fgets、getchar 等函数  
#include <string.h>     // 提供 strcpy、strncmp 函数原型  

#define SIZE 40         // 每个单词的最大长度（含 '\0'，实际存储 39 个字符）  
#define LIM 5           // 最多接受的单词数量  

// 函数声明：安全读取字符串（处理换行符和缓冲区残留）  
char *s_gets(char *st, int n);  


int main(void)  
{  
    char qwords[LIM][SIZE];  // 存储符合条件的单词：LIM 行，每行 SIZE 个字符  
    char temp[SIZE];         // 临时存储每次输入的单词  
    int i = 0;               // 记录已存储的有效单词数量  

    // 提示用户输入规则  
    printf("Enter %d words beginning with q:\n", LIM);  

    // 循环条件：① 未达最大单词数 ② 读取输入成功（s_gets 返回非 NULL）  
    while (i < LIM && s_gets(temp, SIZE))  
    {  
        // 检查首字符是否为 'q'（区分大小写，'Q' 会被判定为不符合）  
        if (temp[0] != 'q')  
        {  
            // 首字符不是 'q'，提示错误，不计数  
            printf("%s doesn't begin with q!\n", temp);  
        }  
        else  
        {  
            // 首字符是 'q'，用 strcpy 复制到 qwords 数组  
            // 注意：strcpy 参数顺序是「目标数组在前，源字符串在后」  
            strcpy(qwords[i], temp);  
            i++;  // 有效单词数加 1  
        }  
    }  

    // 输出所有符合条件的单词  
    puts("\nHere are the words accepted:");  
    for (int j = 0; j < i; j++)  
    {  
        puts(qwords[j]);  
    }  

    return 0;  
}  


// 自定义安全输入函数：修复 fgets 的缺陷  
char *s_gets(char *st, int n)  
{  
    char *ret_val;  // 存储 fgets 的返回值（判断读取是否成功）  
    int i = 0;      // 遍历字符串的索引  

    // 第一步：用 fgets 读取一行，最多读 n-1 个字符（预留 '\0' 位置）  
    ret_val = fgets(st, n, stdin);  

    if (ret_val)  // 如果读取成功（不是 EOF）  
    {  
        // 寻找换行符（\n）或字符串结束符（\0）  
        while (st[i] != '\n' && st[i] != '\0')  
        {  
            i++;  
        }  

        if (st[i] == '\n')  // 找到换行符 → 输入未超长  
        {  
            st[i] = '\0';  // 将换行符替换为 '\0'，截断字符串  
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

    return ret_val;  // 返回 fgets 的结果（调用者可判断读取状态）  
}  


/*  
代码测试及验证建议方案：  
1. **正常流程测试**：  
   - 输入 5 个以 `q` 开头的单词（如 quilt、quiz、quest、quiet、quick），检查输出是否完整显示这 5 个单词。  

2. **不符合条件测试**：  
   - 输入非 `q` 开头的单词（如 apple、Banana），检查是否提示 `... doesn't begin with q!`，且不计入结果。  
   - 输入大写 `Q` 开头的单词（如 Quilt），观察是否因区分大小写被判定为不符合。  

3. **边界情况测试**：  
   - 输入刚好 5 个符合条件的单词，检查是否停止输入，输出 5 个单词。  
   - 输入超过 `SIZE-1` 个字符的单词（如 40 个字符的 `q` 开头单词），检查 `s_gets` 是否截断，且 `strcpy` 是否安全（目标数组 `SIZE` 足够）。  

4. **strcpy 特性验证**：  
   - 手动修改代码，让 `temp` 包含 `\0`（如 `strcpy(temp, "q\0abc");`），观察 `qwords` 中存储的是否只有 `"q"`（验证 `strcpy` 会复制到 `\0` 为止）。  

5. **易错点模拟**：  
   - 交换 `strcpy` 的参数顺序（如 `strcpy(temp, qwords[i])`），观察是否因「目标数组不可写」导致运行错误（实际是逻辑错误，需保证目标数组可修改）。  
   - 注释掉 `s_gets` 中清理缓冲区的代码，输入超长字符后继续输入，观察是否干扰后续读取（验证缓冲区残留的影响）。  

6. **拓展测试（strncmp 版本）**：  
   - 将 `if (temp[0] != 'q')` 替换为 `if (strncmp(temp, "q", 1) != 0)`，测试功能是否一致（仍区分大小写，若要忽略大小写需额外处理，如转小写后比较）。  
*/