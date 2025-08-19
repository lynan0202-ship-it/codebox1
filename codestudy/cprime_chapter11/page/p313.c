

/* 
 * 代码名称：hello.c（命令行参数转数字示例：atoi函数演示）
 * 知识要点总结：
 * 1. 命令行参数：argc记录参数个数，argv[]存储参数字符串（argv[0]是程序名）
 * 2. atoi函数：将字符串转为int（<stdlib.h>），仅转换开头数字，非数字开头返回0（行为未定义需注意）
 * 3. 逻辑短路：if中argc<2为真时，atoi不会执行，避免非法访问argv[1]
 * 4. 程序健壮性：校验参数数量和合法性，提示正确用法
 * 总体逻辑说明：
 * 1. 检查参数：若未传参数或参数非正整数，提示用法并退出
 * 2. 合法时，根据参数值循环输出问候语
 */

#include <stdio.h>
#include <stdlib.h>  // 包含atoi函数原型

int main(int argc, char *argv[])
{
    int i, times;

    // 校验参数：数量不足 或 转换后非正整数
    if (argc < 2 || (times = atoi(argv[1])) < 1) {
        printf("Usage: %s positive-number\n", argv[0]);  // 提示用法，%s显示程序名
        return 1;  // 异常退出
    }

    // 循环输出问候语
    for (i = 0; i < times; i++) {
        puts("Hello, good looking!");
    }

    return 0;  // 正常退出
}

/* 
 * 测试及验证建议：
 * 1. 合法测试：输入`./hello 3`，预期输出3行问候语
 * 2. 无参数测试：输入`./hello`，预期提示用法
 * 3. 非正数测试：输入`./hello 0`或`./hello -1`，预期提示用法
 * 4. 非数字测试：输入`./hello abc`，预期atoi返回0，触发用法提示
 * 5. 混合测试：输入`./hello 42abc`，预期输出42行问候语（atoi只取开头数字）
 * 
 * 验证：编译后在终端运行，观察输出是否符合预期，重点看参数校验和循环次数。
 */



/* 
 * 代码名称：strcnvt.c（字符串转数字示例：strtol函数演示）
 * 知识要点总结：
 * 1. strtol函数：支持2~36进制转换，通过endptr返回停止位置
 * 2. 自定义s_gets：封装fgets，处理换行符和缓冲区残留，避免溢出
 * 3. 多进制对比：同一字符串分别以10、16进制转换，观察结果差异
 * 4. 指针操作：endptr指向转换停止的字符，可打印其内容和ASCII码
 * 总体逻辑说明：
 * 1. 循环读取输入：空行则退出，否则执行两次转换
 * 2. 十进制转换：base=10，输出结果和停止位置
 * 3. 十六进制转换：base=16（支持a~f），输出结果和停止位置
 * 4. s_gets确保输入安全，处理换行和超长内容
 */

#include <stdio.h>
#include <stdlib.h>  // 包含strtol函数原型
#define LIM 30        // 输入缓冲区大小

// 自定义安全输入函数：处理换行和超长内容
char *s_gets(char *st, int n);

int main()
{
    char number[LIM];  // 存储用户输入
    char *end;         // 指向转换停止的字符
    long value;        // 存储转换结果

    puts("Enter a number (empty line to quit):");
    // 循环条件：读取成功 且 输入非空行
    while (s_gets(number, LIM) && number[0] != '\0') {
        // 十进制转换（base=10）
        value = strtol(number, &end, 10);
        printf("base 10: %ld, stopped at \"%s\" (%d)\n", 
               value, end, *end);  // *end是停止字符的ASCII码

        // 十六进制转换（base=16，支持0x前缀、a~f）
        value = strtol(number, &end, 16);
        printf("base 16: %ld, stopped at \"%s\" (%d)\n", 
               value, end, *end);

        puts("Next number:");  // 提示继续输入
    }
    puts("Bye!");  // 空行退出提示

    return 0;
}

// s_gets实现：安全读取一行，处理换行和缓冲区残留
char *s_gets(char *st, int n)
{
    char *ret_val = fgets(st, n, stdin);  // 读取一行，最多n-1字符
    if (ret_val) {  // 读取成功时处理
        int i = 0;
        // 找到行尾（换行或结束符）
        while (st[i] != '\n' && st[i] != '\0') i++;
        
        if (st[i] == '\n') {  // 存在换行符：截断
            st[i] = '\0';
        } else {  // 超长输入：清除缓冲区剩余字符
            while (getchar() != '\n') continue;
        }
    }
    return ret_val;  // 返回fgets结果（NULL表示EOF/错误）
}

/* 
 * 测试及验证建议：
 * 1. 基础测试：输入`10`
 *    - 十进制：value=10，end指向'\0'（输出空字符串，ASCII 0）
 *    - 十六进制：value=16（10₁₆=16₁₀），end指向'\0'
 * 2. 含非法字符：输入`10atom`
 *    - 十进制：value=10，end指向'a'（输出"atom"，ASCII 97）
 *    - 十六进制：value=266（10a₁₆=266₁₀），end指向't'（ASCII 116）
 * 3. 十六进制测试：输入`0xff`（或`ff`）
 *    - 十进制：value=0（'0'合法，'x'非法），end指向"xff"
 *    - 十六进制：value=255（ff₁₆=255₁₀），end指向'\0'
 * 4. 空行测试：直接回车，预期退出循环，输出"Bye!"
 * 5. 超长测试：输入30个以上字符，观察s_gets是否清除残留，下次输入是否正常
 * 
 * 验证：编译后运行，输入测试用例，对比转换结果、停止位置和ASCII码是否符合预期。
 * 易错点：
 * - strtol的base=0会自动识别进制（0x=16进制，0=8进制），可修改代码测试
 * - s_gets处理了换行，避免下次输入受影响，测试时故意输入超长内容验证
 * - end指向'\0'时，*end=0，输出空字符串和0，属于正常情况
 */