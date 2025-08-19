/* 
 * 代码名称：hello.c（字符串转数字之atoi函数演示 + 命令行参数处理）
 * 知识要点总结：
 * 1. 命令行参数机制：argc记录参数个数，argv[]存储参数内容（argv[0]是程序名）
 * 2. atoi函数功能：将字符串转换为int类型（定义在<stdlib.h>，仅处理开头数字，非数字开头返回0）
 * 3. 程序健壮性：通过argc检查参数数量，通过atoi返回值检查参数合法性
 * 4. 循环控制：根据转换后的数字，重复输出内容
 * 总体逻辑说明：
 * 1. 第一步：检查命令行参数数量，若不足2个（只有程序名），提示用法
 * 2. 第二步：用atoi将argv[1]转换为整数，若结果≤0，提示用法
 * 3. 第三步：根据转换后的数字，循环输出指定字符串
 */

#include <stdio.h>   // 提供printf、puts等输入输出函数
#include <stdlib.h>  // 提供atoi函数，用于字符串转整数

int main(int argc, char *argv[]) {
    int i;              // 循环计数器
    int repeat_times;   // 存储转换后的重复次数

    // 检查参数数量：argc至少为2（程序名 + 1个参数）
    // 同时检查转换后的次数是否为正数（atoi返回≤0时，也提示用法）
    if (argc < 2 || (repeat_times = atoi(argv[1])) <= 0) {
        // %s会自动替换为argv[0]，即程序的名称（如./hello）
        printf("Usage: %s positive_number\n", argv[0]);
        return 1;  // 非0返回值表示程序异常退出
    }

    // 根据转换后的次数，循环输出内容
    for (i = 0; i < repeat_times; i++) {
        puts("Hello, good looking!");  // 每次循环输出一行
    }

    return 0;  // 0返回值表示程序正常结束
}

/* 
 * 测试及验证建议方案（按步骤操作，观察输出是否符合预期）：
 * 
 * 1. 合法正数测试：
 *    - 命令：./hello 5（Windows下：hello.exe 5）
 *    - 预期：连续输出5行 "Hello, good looking!"
 * 
 * 2. 无参数测试：
 *    - 命令：./hello
 *    - 预期：输出 "Usage: ./hello positive_number"（提示正确用法）
 * 
 * 3. 零或负数测试：
 *    - 命令：./hello 0  或  ./hello -3
 *    - 预期：同样提示用法（因为repeat_times≤0）
 * 
 * 4. 非数字参数测试：
 *    - 命令：./hello abc  或  ./hello @#$
 *    - 预期：atoi返回0 → 触发repeat_times≤0 → 提示用法
 *    - 易错点：atoi遇到非数字会停止转换，只处理开头的数字部分（如"42abc"会转成42，属于合法情况！）
 * 
 * 5. 混合字符测试（重点观察atoi的行为）：
 *    - 命令：./hello 42abc
 *    - 预期：repeat_times=42 → 输出42行内容（atoi只解析开头的"42"）
 *    - 说明：atoi的局限性——无法区分有效数字和无效后缀，实际项目中建议用strtol更安全
 * 
 * 6. 边界值测试：
 *    - 命令：./hello 1
 *    - 预期：输出1行内容（验证最小正整数）
 * 
 * 验证方法：
 * - 编译：使用gcc编译（gcc hello.c -o hello），或通过IDE编译
 * - 运行：在终端/命令提示符中执行上述测试命令，对比输出与预期结果
 * 
 * 关键易错点提醒：
 * 1. 必须先检查argc≥2，再访问argv[1]！否则argc=1时，argv[1]不存在，会导致程序崩溃。
 * 2. atoi无法检测"完全无效"的输入（如"abc"和"0"都返回0），实际开发中如需严格校验，应使用strtol配合endptr判断。
 * 3. 命令行中，参数之间用空格分隔，若参数含空格，需用双引号包裹（如./hello "hello world"，但本程序中会被视为1个参数，转成0，触发用法提示，因为不是数字）。
 */