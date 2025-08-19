/* 
 * 代码名称：repeat.c（命令行参数解析演示程序）
 * 知识要点总结：
 * 1. main函数的命令行参数机制：
 *    - int argc：记录命令行参数的总个数（含程序自身名称）
 *    - char *argv[]：字符串数组，每个元素指向一个命令行参数（argv[0]是程序名，argv[1]开始是用户参数）
 * 2. 命令行参数的分隔规则：
 *    - 空格是默认分隔符，如"param1 param2"会被拆分为2个参数
 *    - 双引号可包裹含空格的参数，如"hello world"会被视为1个参数
 * 3. 数组遍历：通过for循环遍历指针数组，访问命令行参数内容
 * 总体逻辑说明：
 * 1. 程序启动时，系统自动填充argc和argv：
 *    - argc = 参数个数（例：运行"repeat a b"时，argc=3，argv[0]="repeat"、argv[1]="a"、argv[2]="b"）
 * 2. 第一步：计算用户参数个数（argc-1，减去程序名本身）并输出
 * 3. 第二步：通过for循环从argv[1]开始遍历，逐个打印参数的序号和内容
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int count;  // 循环计数器，用于遍历命令行参数
    
    // 输出用户传入的参数总数（排除程序名，所以是argc-1）
    printf("The command line has %d arguments:\n", argc - 1);
    
    // 遍历命令行参数：从第1个用户参数（argv[1]）开始，到最后一个参数结束
    for (count = 1; count < argc; count++) {
        // %d输出参数序号，%s输出argv[count]指向的字符串内容
        printf("%d: %s\n", count, argv[count]);
    }
    
    printf("\n");  // 换行优化输出格式
    return 0;
}

/* 
 * 代码测试及验证建议方案：
 * 1. 基础场景测试：
 *    - 命令：./repeat（Windows：repeat.exe）
 *    - 预期：The command line has 0 arguments:（仅程序名，无用户参数）
 * 2. 多参数测试（教材示例复现）：
 *    - 命令：./repeat Resistance is futile
 *    - 预期：3个参数，依次输出1: Resistance、2: is、3: futile
 * 3. 含空格的参数测试（双引号用法）：
 *    - 命令：./repeat "I love C" "command line"
 *    - 预期：2个参数，内容为"I love C"和"command line"（验证双引号的分组作用）
 * 4. 边界情况测试：
 *    - 命令：./repeat "" "" （两个空参数）
 *    - 预期：2个参数，内容均为空字符串（测试空参数处理）
 * 5. 路径验证（了解argv[0]）：
 *    - 命令：/user/bin/repeat test（Linux/Mac绝对路径运行）
 *    - 预期：argv[0]为"/user/bin/repeat"，参数1为"test"（观察程序名的完整路径）
 * 
 * 验证方法：
 * - 在终端（Linux/Mac）或命令提示符（Windows）中编译代码（gcc repeat.c -o repeat）
 * - 执行上述测试命令，对比输出与预期是否一致
 * 易错点提醒：
 * - argc最小值为1（仅程序名），因此循环条件count < argc不会越界
 * - 未加双引号的空格会被拆分，如输入"a b"（无引号）会被视为2个参数
 * - 不同系统中argv[0]可能包含完整路径（如Linux）或仅程序名（如Windows），需注意环境差异
 */