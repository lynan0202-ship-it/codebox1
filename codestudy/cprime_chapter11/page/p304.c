

/*
代码名称：copy2.c  
知识要点总结：  
1. **strcpy函数特性**：  
   - 返回值：第1个参数（目标字符串指针）的值，即目标地址。  
   - 目标指针灵活性：可指向数组**中间位置**（非开头），但需保证目标数组有**足够空间**存储源字符串（含`\0`）。  
   - 复制规则：完整复制源字符串（包括末尾的`\0`），会覆盖目标地址后的内存内容。  
2. **数组与指针**：`copy+7` 表示数组`copy`的第8个元素（下标7）的地址，体现指针算术。  


代码总体逻辑：  
1. 定义 **源字符串** `orig`（指向常量字符串`WORDS`）和 **目标数组** `copy`（初始化为一个长字符串）。  
2. 输出 `orig` 和 `copy` 的初始内容。  
3. 调用 `strcpy(copy + 7, orig)`：将`orig`（"beast"）复制到`copy`的第8个元素位置（下标7）。  
4. 输出 **修改后的`copy`**（观察覆盖效果）和 **strcpy的返回值**（即`copy + 7`，从该地址开始打印字符串）。  
*/  

#include <stdio.h>      // 提供 printf、puts 等输入输出函数  
#include <string.h>     // 提供 strcpy 函数原型  

#define WORDS "beast"    // 源字符串（常量）  
#define SIZE 40         // 目标数组大小，需足够容纳操作后的字符串  


int main(void)  
{  
    const char *orig = WORDS;  // orig 指向常量字符串 "beast"  
    // copy 数组初始化为一个长字符串，需保证 SIZE 足够大  
    char copy[SIZE] = "Be the best that you can be.";  
    char *ps;  // 用于存储 strcpy 的返回值  


    // 步骤1：输出初始内容  
    puts(orig);   // 打印源字符串：beast  
    puts(copy);   // 打印初始 copy：Be the best that you can be.  


    // 步骤2：调用 strcpy，目标是 copy + 7（数组第8个元素，下标7）  
    // strcpy 会把 orig 的内容（包括 '\0'）复制到 copy + 7 的位置  
    ps = strcpy(copy + 7, orig);  


    // 步骤3：输出结果  
    puts(copy);   // 打印修改后的 copy：Be the beast（因为 copy+7 开始的 "best t" 被 "beast\0" 覆盖）  
    puts(ps);     // 打印 strcpy 的返回值（copy + 7）：beast  


    return 0;  
}  


/*  
代码测试及验证建议方案：  
1. **基础运行验证**：  
   - 编译运行，观察输出是否为：  
     beast  
     Be the best that you can be.  
     Be the beast  
     beast  
   - 理解 `copy+7` 的覆盖效果：原`copy`中 "best t" 被 "beast\0" 替换，导致 "that" 被截断。  

2. **内存覆盖细节验证**：  
   - 修改 `copy` 的初始字符串为更短的内容（如 `"Hello"`），观察 `strcpy(copy+2, orig)` 后的结果（如 "Hebeast"）。  
   - 用调试工具（或循环打印`copy`每个字符的ASCII值），查看 `\0` 的位置变化，验证是否覆盖了后续字符。  

3. **边界风险测试**：  
   - 尝试让目标地址超出数组范围（如 `copy + 39`，假设 SIZE=40），观察程序是否崩溃（提醒：`strcpy` 不检查目标空间，易导致**缓冲区溢出**，实际开发需用`strncpy`或确保空间充足）。  

4. **返回值特性验证**：  
   - 打印 `ps` 和 `copy + 7` 的地址（用 `printf("%p\n", ps); printf("%p\n", copy + 7);`），确认两者相等，验证strcpy返回目标指针。  

5. **易错点模拟**：  
   - 定义 **指针而非数组** 作为目标（如 `char *bad_target; strcpy(bad_target, orig);`），观察程序崩溃（因指针未分配内存，非法访问），理解“目标必须是有效内存（如数组）”的重要性。  
*/