// ------------------------------  
// 题干：按照程序清单12.13修改，输出类似示例（输入组数和骰子面数，生成随机投掷结果）。  
// 知识要点：  
//  1. 二维数组（存储每组投掷结果）  
//  2. 循环输入（直到输入q退出）  
//  3. 随机数生成（模拟骰子投掷：1~sides）  
// 总体逻辑：  
//  1. 循环提示输入“组数”和“骰子面数”，输入q则退出  
//  2. 生成二维数组：rows行（组数），cols列（每次投掷结果，本题示例中cols固定？实际按逻辑，假设每组一个结果？或示例中的输出是每组一个数？重新分析示例：  
//     示例输入：6面骰子，18组 → 输出18个数，每行5个（示例输出有12 10 6 9 8... 共18个）  
//     → 修正：每组生成一个数（骰子投掷结果，1~sides），共sets组  
//  3. 输出结果，每行最多5个数字  
#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h> // 用于判断输入是否是字母（q）  

int main() {  
    int sets, sides;  
    char input[10]; // 存储输入（处理q退出）  

    printf("Enter the number of sets; enter q to stop: ");  
    while (scanf("%s", input) == 1) { // 读取输入，若是字符串（q）则退出  
        if (isalpha(input[0])) { // 判断是否是字母（q）  
            break;  
        }  
        sets = atoi(input); // 转换为整数（组数）  

        printf("How many sides and how many dice? ");  
        scanf("%d", &sides); // 读取骰子面数  

        // 生成sets个随机数（1~sides），模拟投掷结果  
        printf("Here are %d sets of %d-sided throws.\n", sets, sides);  
        for (int i = 0; i < sets; i++) {  
            int result = rand() % sides + 1; // 1~sides  
            printf("%d ", result);  
            if ((i+1) % 5 == 0) { // 每5个换一行  
                printf("\n");  
            }  
        }  
        printf("\n");  

        printf("Enter the number of sets; enter q to stop: ");  
    }  

    printf("Done.\n");  
    return 0;  
}  

// 测试验证方案：  
//  1. 怎么运行：编译后运行（如 `gcc 7.c -o 7 && ./7`），输入示例：  
//     → 输入 `18` → 输入 `6` → 应输出18个1~6的数，每行5个  
//     → 输入 `q` → 退出  
//  2. 预期结果：  
//     - 符合示例格式，如：  
//       Enter the number of sets; enter q to stop: 18  
//       How many sides and how many dice? 6  
//       Here are 18 sets of 6-sided throws.  
//       3 5 2 6 1  
//       4 3 2 5 6  
//       ...（共18个，每行5个）  
//  3. 检查点：  
//     - 输入q是否正确退出？  
//     - 数字是否在1~sides之间？  
//     - 每行是否最多5个数字？  
// 易错点提醒：  
//  1. 输入处理错误：未判断字母输入（直接用%d读取，导致q无法识别，程序崩溃）  
//  2. 随机数范围错误：`rand() % sides`（得到0~sides-1，漏+1，导致出现0）  
//  3. 换行逻辑错误：`(i+1) % 5 == 0` 写成 `i % 5 == 0`（导致第一行从第0个开始，多一个数）  
// 拓展思考：  
//  1. 若要支持“多个骰子”（如2个6面骰子，结果是和），如何修改？→ 每组生成多个数，求和后存储  
//  2. 如何让随机数更随机？→ 添加 `srand(time(0))` 在main开头（但需包含time.h）  
// 对比说明：  
//  单骰子 vs 多骰子：  
//  - 单骰子：每组一个数（1~sides）  
//  - 多骰子：每组多个数，需求和/或存储所有结果（本题示例是单骰子，按题意调整）  