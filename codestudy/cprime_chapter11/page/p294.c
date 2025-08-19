/* 
代码名称：str_cat.c（教材程序清单11.18，演示strcat函数的拼接特性）
知识要点总结：
1. strcat函数：
   - 头文件：<string.h>，原型`char *strcat(char *dest, const char *src);`  
   - 功能：将`src`字符串拼接至`dest`末尾（覆盖`dest`原有的`\0`，并在新末尾补`\0`）  
   - 关键：`dest`必须预留足够空间（需容纳自身长度 + `src`长度），否则会**缓冲区溢出**！  
2. s_gets函数（自定义安全输入）：  
   - 基于`fgets`实现，解决两大问题：  
     - 替换`fgets`保留的换行符为`\0`，让输入更“干净”；  
     - 丢弃超长输入的多余字符，避免残留影响后续读取。  
   - 对比：比`gets`安全（限制长度），比`fgets`易用（自动处理换行）。  
3. 字符串修改规则：  
   - `strcat`会**修改第一个参数（dest）**，第二个参数（src）内容**保持不变**；  
   - 返回值是`dest`的首地址（可链式调用，如`strcat(strcat(a, b), c)`）。  
4. EOF处理：通过`fgets`的返回值（`NULL`表示文件尾/错误）判断输入结束。  

代码总体逻辑：  
1. 初始化：  
   - `flower[SIZE]`：存储用户输入（需足够大，容纳输入 + `addon`长度）；  
   - `addon[]`：固定字符串（拼接时自身不变）。  
2. 用户交互：  
   - 提示输入喜欢的花，调用`s_gets`读取一行（处理换行、超长）。  
3. 拼接验证：  
   - 若读取成功，调用`strcat(flower, addon)`拼接字符串；  
   - 打印`flower`（已修改）和`addon`（未修改），对比两者变化。  
4. 异常处理：  
   - 若`s_gets`返回`NULL`（如按`Ctrl+Z/Ctrl+D`），提示“输入结束”。  
5. 收尾：统一输出`bye`，结束程序。  
*/

#include <stdio.h>
#include <string.h>  // 必须包含，否则strcat未定义
#define SIZE 80       // 定义数组大小，需足够容纳输入 + addon长度

// 声明s_gets函数（定义在main之后，需提前告诉编译器）
char *s_gets(char *st, int n);

int main(void)
{
    char flower[SIZE];               // 存储用户输入的花名，大小80
    char addon[] = "s smell like old shoes.";  // 要拼接的字符串（自身不变）

    puts("What is your favorite flower?");
    if (s_gets(flower, SIZE)) {     // 读取成功（非EOF），进入拼接逻辑
        // strcat：将addon拼接到flower末尾  
        // 注意：必须保证flower有足够空间！否则会溢出！
        strcat(flower, addon);      
        puts(flower);  // 输出拼接后的flower（已修改）
        puts(addon);   // 输出addon（验证未被修改）
    } else {          // s_gets返回NULL → 遇到EOF（如Ctrl+Z/Ctrl+D）
        puts("End of file encountered!");
    }
    puts("bye");      // 程序结束提示
    return 0;
}

/* 
s_gets函数：安全读取一行输入，处理换行和超长情况  
参数：  
- `st`：目标字符数组（存储输入）；  
- `n`：数组大小（最多读`n-1`个字符，留1个给`\0`）。  
返回值：  
- 成功：`st`的首地址；  
- 失败/EOF：`NULL`。  
*/
char *s_gets(char *st, int n)
{
    char *ret_val;  // 存储fgets的返回值
    int i = 0;      // 遍历数组的索引

    // 1. 调用fgets读取：最多读n-1个字符，从标准输入(stdin)读
    ret_val = fgets(st, n, stdin);
    if (ret_val) {  // 读取成功（ret_val != NULL）
        // 2. 遍历找换行符或字符串结束符
        while (st[i] != '\n' && st[i] != '\0') {
            i++;  // 移动索引，直到找到目标字符
        }
        if (st[i] == '\n') {  // 找到换行符（输入长度 ≤ n-1）
            st[i] = '\0';     // 替换为结束符，去掉换行
        } else {  // 没找到换行符（输入超长，n-1字符已读满）
            // 3. 丢弃输入流中剩余的字符（直到换行或EOF）
            while (getchar() != '\n') {
                continue;  // 只要没读到换行，就一直读（丢弃）
            }
        }
    }
    return ret_val;  // 返回fgets的结果（成功→st地址，失败→NULL）
}


/* 
测试及验证建议方案：
1. 正常拼接测试：  
   - 输入：`Rose`（长度4，远小于`SIZE - strlen(addon)`=59）  
   - 预期输出：  
     Rose's smell like old shoes.  
     s smell like old shoes.  
     bye  
   - 验证：`flower`被修改，`addon`内容不变。  

2. 超长输入测试（考验空间和s_gets的处理）：  
   - 输入：59个`a`（如`aaaaaaaa...`，共59个），确保`59 + strlen(addon)=80`（刚好填满SIZE）  
   - 预期：拼接后正常输出，无溢出；  
   - 输入：60个`a`（超过59），s_gets会丢弃第60个及以后的字符，`flower`存前59个`a`，拼接后总长度80，正常输出。  

3. 空输入测试：  
   - 直接按回车（输入空行），`flower`为空字符串。  
   - 预期输出：  
     s smell like old shoes.  
     s smell like old shoes.  
     bye  

4. EOF测试：  
   - Windows：按`Ctrl+Z`再回车；Linux/Mac：按`Ctrl+D`。  
   - 预期：进入`else`分支，输出`End of file encountered!`和`bye`。  

5. 缓冲区溢出风险测试（必做！理解strcat的危险）：  
   - 修改`SIZE`为20，`addon`长度21，输入`abcdefghijklmnopqrs`（19字符）。  
   - 预期：`19 + 21 = 40 > 20`，发生**缓冲区溢出**（程序可能崩溃/行为异常）。  
   - 结论：必须保证`dest`数组足够大！  

6. addon不变性验证：  
   - 多次拼接后，打印`addon`，观察其内容是否始终为`s smell like old shoes.`；  
   - 尝试修改`addon`（如`addon[0] = 'S';`），看是否允许（`addon`是数组，可修改，但`strcat`的`src`是`const`，不影响拼接逻辑）。  


易错点提醒：  
- ❗ `strcat`**不检查`dest`的空间**！必须手动计算长度，确保`dest`能容纳拼接后的内容，否则会覆盖其他内存，导致崩溃。  
- `s_gets`的`n`必须是`dest`数组的实际大小（如`flower`是`SIZE`，就传`SIZE`），否则可能越界。  
- `fgets`读取的换行符会被`s_gets`替换为`\0`，所以`flower`中**不会有换行符**，拼接后格式整齐。  
- 若输入超长，`s_gets`会丢弃多余字符，但`strcat`仍需依赖`dest`的空间大小——**空间问题只能开发者自己保证**！  
*/