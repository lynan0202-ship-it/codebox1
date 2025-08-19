/* 
 * 代码名称：join_chk.c
 * 知识要点总结：
 * 1. 字符串拼接函数：strcat（无长度检查，需手动确保安全）、strncat（指定最大添加字符数，更安全）
 * 2. 自定义输入函数 s_gets：基于 fgets 实现，处理换行符和多余输入，避免缓冲区溢出
 * 3. 字符串长度计算（strlen）的实际应用：判断拼接是否会导致缓冲区溢出
 * 总体逻辑说明：
 * 1. 定义两个字符串数组 flower（大空间）和 bug（小空间），以及固定后缀 addon
 * 2. 通过 s_gets 安全读取用户输入，避免原始 gets 函数的溢出风险
 * 3. 对 flower 使用 strcat：先通过 strlen 计算拼接后长度，确保不超过数组大小后再拼接
 * 4. 对 bug 使用 strncat：计算剩余可用空间（总大小 - 当前长度 -1），作为最大添加字符数，强制控制拼接安全
 * 5. 输出两次拼接结果，对比 strcat 和 strncat 的使用场景差异
 */

#include <stdio.h>
#include <string.h>  // 包含 strlen、strcat、strncat 等字符串操作函数

#define SIZE 30      // flower 数组的最大容量（含末尾空字符）
#define BUGSIZE 13   // bug 数组的最大容量（含末尾空字符）

// 自定义安全输入函数声明：读取一行输入，自动处理换行符和多余字符
char *s_gets(char *st, int n);

int main(void)
{
    char flower[SIZE];      // 存储用户输入的花名
    // 固定拼接的后缀字符串（注意：实际长度需通过 strlen 计算，不要硬编码）
    char addon[] = "s smell like old shoes.";  
    char bug[BUGSIZE];      // 存储用户输入的虫子名
    int available;          // 记录 bug 数组剩余可用空间（用于 strncat）

    // ========== 第一步：处理花名的拼接（用 strcat，需手动检查安全） ==========
    puts("What is your favorite flower?");
    // 调用 s_gets 读取输入：最多读 SIZE-1 个字符，避免溢出
    s_gets(flower, SIZE);   
    // 检查拼接安全性：addon长度 + flower长度 + 1（空字符） <= SIZE？
    if (strlen(addon) + strlen(flower) + 1 <= SIZE) {
        // strcat 会自动将 addon 拼接到 flower 末尾，并替换原空字符
        strcat(flower, addon);  
    }
    puts(flower);  // 输出拼接后的结果


    // ========== 第二步：处理虫子名的拼接（用 strncat，强制控制长度） ==========
    puts("What is your favorite bug?");
    s_gets(bug, BUGSIZE);  // 安全读取虫子名，最多 BUGSIZE-1 个字符
    // 计算剩余可用空间：总容量 - 当前已用长度（不含空字符） -1（预留空字符位置）
    available = BUGSIZE - strlen(bug) - 1;  
    // strncat 第三个参数：最多添加 available 个字符（确保不会溢出）
    strncat(bug, addon, available);  
    puts(bug);  // 输出拼接后的结果

    return 0;
}


// ========== 自定义安全输入函数实现 ==========
char *s_gets(char *st, int n)
{
    char *ret_val;  // 保存 fgets 的返回值，判断是否读取成功
    int i = 0;

    // 调用 fgets 读取：从 stdin 读，最多存 n-1 个字符，末尾自动加 '\0'
    ret_val = fgets(st, n, stdin);  
    if (ret_val) {  // 如果读取成功（不是 EOF 或错误）
        // 遍历找换行符（输入结束标志）或字符串结束符（输入长度不足）
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {  // 如果找到换行符（输入没超过 n-1 个字符）
            st[i] = '\0';     // 替换换行符为字符串结束符，去掉换行
        } else {  // 没找到换行符（输入超过 n-1 个字符，缓冲区还有剩余）
            // 清理缓冲区剩余字符，避免影响后续输入
            while (getchar() != '\n') {  
                continue;
            }
        }
    }
    return ret_val;  // 返回 fgets 的结果，供调用者判断是否读取有效
}


/* 
 * 代码测试及验证建议方案：
 * 1. 正常输入测试：
 *    - 输入 flower 为 "Rose"，检查输出是否为 "Roses smell like old shoes."
 *    - 输入 bug 为 "Aphid"，检查输出是否为 "Aphids smell"（因 available=13-5-1=7，addon 前7个字符是 "s smell"）
 * 2. 边界测试：
 *    - 让 flower 输入长度为 10（如 "TulipRed"），计算 10 + strlen(addon)(19) +1=30，刚好等于 SIZE，验证 strcat 是否正常拼接
 *    - 让 bug 输入长度为 12（如 "Centipede"），available=13-12-1=0，验证 strncat 是否不添加内容
 * 3. 溢出测试：
 *    - 输入 flower 时故意打 35 个字符（如 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"），检查 flower 只存前29个，且后续输入不影响
 *    - 输入 bug 时打 15 个字符（如 "bbbbbbbbbbbbbbb"），检查 bug 只存前12个，剩余字符被清理
 * 4. 逻辑验证：
 *    - 故意让 flower 拼接长度超过 SIZE（如输入20个字符），验证 if 条件是否阻止 strcat 执行，输出原内容
 *    - 对比 strcat（依赖手动判断）和 strncat（强制控长）的安全差异，观察两种函数的行为区别
 */