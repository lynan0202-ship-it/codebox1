/* 
 * 代码名称：mod_str.c（字符串处理示例：转大写与标点统计）
 * 知识要点总结：
 * 1. ctype.h 库函数：toupper（小写转大写）、ispunct（判断标点字符）
 * 2. 字符串输入处理：fgets 读取一行（避免缓冲区溢出），strchr 查找换行符并替换为 '\0' 截断字符串
 * 3. 函数设计：通过指针参数操作字符串，ToUpper 转换大小写，PunctCount 统计标点
 * 4. 字符串遍历：while(*str) 利用空字符 '\0' 作为结束标志遍历每个字符
 * 总体逻辑说明：
 * 1. 主函数 main：
 *    - 定义字符数组存储输入，用 fgets 读取用户输入
 *    - 用 strchr 定位换行符，替换为 '\0' 确保字符串正确结束
 *    - 调用 ToUpper 转换字符串为全大写，输出结果
 *    - 调用 PunctCount 统计标点个数，输出统计结果
 * 2. ToUpper 函数：
 *    - 遍历字符串每个字符，通过 toupper 转换为大写（ANSI C 中 toupper 仅处理小写字符，直接调用也安全）
 * 3. PunctCount 函数：
 *    - 遍历字符串，用 ispunct 判断是否为标点，统计数量 
 */

#include <stdio.h>   // 提供输入输出函数（如 fgets、puts、printf）
#include <string.h>  // 提供字符串处理函数（如 strchr）
#include <ctype.h>   // 提供字符处理函数（如 toupper、ispunct）

#define LIMIT 81     // 定义输入字符串的最大长度（含结束符）

// 函数声明：
void ToUpper(char *str);          // 将字符串转换为全大写
int PunctCount(const char *str);  // 统计字符串中的标点符号个数

int main(void)
{
    char line[LIMIT];  // 存储用户输入的字符串
    char *find;        // 用于定位换行符的指针

    puts("Please enter a line:");  // 提示用户输入
    fgets(line, LIMIT, stdin);     // 读取一行输入，最多读 LIMIT-1 个字符，避免溢出
    // 处理换行符：如果输入中存在 '\n'，将其替换为 '\0'，使字符串正确结束
    find = strchr(line, '\n');     // strchr 查找 '\n' 的位置，找不到返回 NULL
    if (find != NULL) {
        *find = '\0';  // 替换换行符为字符串结束符
    }

    ToUpper(line);  // 转换字符串为全大写
    puts(line);     // 输出转换后的字符串

    // 统计并输出标点个数：调用 PunctCount，传入 line 的地址
    printf("That line has %d punctuation characters.\n", PunctCount(line));

    return 0;
}

// ToUpper 函数：将字符串 str 转换为全大写
void ToUpper(char *str)
{
    // while(*str)：当 *str 不为 '\0'（空字符，ASCII 0）时循环，遍历每个字符
    while (*str) {
        *str = toupper(*str);  // 将当前字符转换为大写（toupper 会忽略非小写字符）
        str++;  // 指针后移，处理下一个字符
    }
}

// PunctCount 函数：统计字符串 str 中的标点符号个数，const 表示不修改传入的字符串
int PunctCount(const char *str)
{
    int ct = 0;  // 计数变量，初始为 0
    while (*str) {  // 遍历字符串每个字符
        if (ispunct(*str)) {  // ispunct 判断当前字符是否为标点符号
            ct++;  // 是标点则计数加 1
        }
        str++;  // 指针后移
    }
    return ct;  // 返回标点总数
}

/* 
 * 代码测试及验证建议方案：
 * 1. 基础功能测试：
 *    - 输入："Me? You talkin' to me? Get outta here!" 
 *    - 预期输出：全大写字符串，标点计数 4（?、'、?、!）
 * 2. 边界情况测试：
 *    - 输入空行（直接按回车）：输出空行，标点计数 0
 *    - 输入无标点字符串（如 "Hello World"）：输出全大写，标点计数 0
 *    - 输入全标点（如 "!!!??,"）：输出全大写（标点本身不变），计数 6
 * 3. 大小写测试：
 *    - 输入混合大小写（如 "AbC, xYz!"）：转换后应为 "ABC, XYZ!"，标点计数 2（, 和 !）
 * 4. 长度测试：
 *    - 输入超过 LIMIT-1 长度的字符串（如 80 个字符加换行）：检查是否正确截断，转换和计数是否正常
 * 
 * 验证方法：运行程序，输入测试用例，对比输出结果与预期是否一致，观察字符串转换和计数是否正确。
 */