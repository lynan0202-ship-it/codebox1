/*
 * 代码名称：enum_color_demo
 * 知识要点总结：
 *  1. 枚举类型定义：使用enum关键字创建，枚举常量默认从0开始递增（如red=0、orange=1），也支持显式赋值。
 *  2. 枚举变量操作：C中枚举变量可像int遍历（如color++），C++标准不允许（本示例为C语言场景）。
 *  3. 枚举与字符串映射：通过字符串数组关联枚举值，提升代码可读性。
 *  4. switch应用：枚举值作为case标签，分支逻辑清晰。
 *  5. 输入处理：自定义s_gets处理换行符和缓冲区，避免输入残留问题。
 * 总体逻辑说明：
 *  1. 定义颜色枚举和对应字符串数组，建立“枚举值↔颜色名称”映射。
 *  2. 循环提示用户输入颜色，空行则退出。
 *  3. 遍历枚举值，通过strcmp匹配输入字符串与颜色名称，标记匹配结果。
 *  4. 匹配成功则用switch输出对应描述，失败则提示未知颜色。
 *  5. 每次输入后重置状态，持续交互直到用户主动退出。
 */

#include <stdio.h>
#include <string.h>   // 提供strcmp、strchr函数
#include <stdbool.h>  // 提供bool类型（C99特性）

// 自定义输入函数：处理换行符，清理输入缓冲区残留字符
char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);  // 读取一行输入，最多存n-1个字符
    if (ret_val) {                  // 读取成功时进入处理
        find = strchr(st, '\n');    // 查找换行符位置
        if (find) {                 // 找到换行符：替换为字符串结束符
            *find = '\0';
        } else {                    // 未找到换行符（输入超长）：清理剩余字符
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;  // 返回读取结果（失败时为NULL）
}

int main(void) {
    char choice[20];          // 存储用户输入的颜色字符串
    enum spectrum color;      // 枚举变量，类型为enum spectrum
    bool color_is_found = false;  // 标记是否找到匹配颜色

    puts("Enter a color (empty line to quit):");
    // 循环条件：输入非空且读取成功（空行时s_gets返回NULL或choice[0]为'\0'）
    while (s_gets(choice, 20) != NULL && choice[0] != '\0') {
        // 遍历所有枚举值（从red到violet）
        for (color = red; color <= violet; color++) {
            // 比较输入字符串与枚举对应颜色名称
            if (strcmp(choice, colors[color]) == 0) {
                color_is_found = true;  // 找到匹配，标记为真
                break;                  // 跳出循环，无需继续比较
            }
        }

        if (color_is_found) {
            // 根据枚举值分支处理
            switch (color) {
                case red:
                    puts("Roses are red.");
                    break;
                case orange:
                    puts("Poppies are orange.");
                    break;
                case yellow:
                    puts("Sunflowers are yellow.");
                    break;
                case green:
                    puts("Grass is green.");
                    break;
                case blue:
                    puts("Bluebells are blue.");
                    break;
                case violet:
                    puts("Violets are violet.");
                    break;
                default:  // 理论上不会触发，增强鲁棒性
                    puts("Unknown error in color match.");
                    break;
            }
        } else {
            // 未找到匹配，提示未知颜色
            printf("I don't know about the color %s.\n", choice);
        }

        color_is_found = false;  // 重置标记，准备下一次输入
        puts("Next color, please (empty line to quit):");
    }

    puts("Goodbye!");
    return 0;
}

// 定义枚举类型：颜色枚举，常量默认值red=0、orange=1...violet=5
enum spectrum {red, orange, yellow, green, blue, violet};
// 字符串数组：与enum spectrum的常量顺序严格对应
const char *colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};


/*
 * 代码测试及验证建议方案：
 * 1. 有效输入测试：
 *    - 输入"red"，检查输出是否为"Roses are red."；
 *    - 依次测试orange、yellow、green、blue、violet，确保每个case正确响应。
 * 2. 无效输入测试：
 *    - 输入"purple"，验证输出"I don't know about the color purple."；
 *    - 输入"Red"（大小写不同），因strcmp区分大小写，应判定为未知。
 * 3. 边界测试：
 *    - 直接按回车（空行），检查程序是否退出并输出"Goodbye!"；
 *    - 输入超长字符串（如"redxxxxxxxxxx..."），验证s_gets是否截断并清理缓冲区（后续输入仍正常）。
 * 4. 枚举特性扩展测试（可选）：
 *    - 修改枚举定义为`enum spectrum {red=3, orange, yellow...};`，调整colors数组顺序，测试匹配是否同步变化。
 * 5. 语言差异观察（了解）：
 *    - 将代码改为C++编译，尝试`color++`操作，观察是否报错（C++需转换为int类型，如`(int)color++`，对比C的兼容性）。
 */