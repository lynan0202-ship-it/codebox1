/*
以下是完整包含教程知识点、详细注释的代码示例，以原 animals.c 程序为基础扩展完善，清晰呈现 switch 语句用法、break 作用、输入处理逻辑 等核心知识：
知识要点与总体逻辑说明
知识要点：
switch 语句：根据表达式值（需为整数 / 字符类型）匹配 case，实现多分支选择。
break 作用：跳出 switch 或循环，避免 “贯穿” 执行后续 case。
输入处理：用 getchar() 读取字符，结合 isalpha() 等函数校验输入合法性，用循环处理多余字符。
程序流程控制：通过 while 循环持续交互，# 字符终止程序，continue 跳过无效输入。
总体逻辑：
程序启动后，提示用户输入字母，根据字母（仅小写）匹配 switch 的 case，输出对应动物名；若输入非小写字母，提示格式错误；输入 # 则结束程序。利用 break 控制 switch 分支流程，while 循环维持交互，完整演示多分支选择与输入处理逻辑。
带详细注释的完整代码（animals_extended.c）
*/

/* 
 * 程序：animals_extended.c
 * 功能：演示 C 语言 switch 语句、break 作用，结合输入校验与循环交互
 * 知识覆盖：
 *  1. switch-case 多分支选择（依赖整数/字符类型匹配）
 *  2. break 跳出 switch 或循环的用法
 *  3. getchar() 字符输入、isalpha()/islower() 输入校验
 *  4. while 循环持续交互、continue 跳过无效输入、# 终止程序
 */

#include <stdio.h>   // 提供 printf、getchar 等输入输出函数
#include <ctype.h>   // 提供 isalpha、islower 等字符校验函数

int main(void) {
    char ch;  // 存储用户输入的字符

    // 程序功能引导：告知用户输入规则
    printf("Give me a letter of the alphabet, and I will give ");
    printf("an animal name beginning with that letter.\n");
    printf("Please type in a letter; type # to end my act.\n");

    // while 循环：持续交互，直到输入 '#'
    // (ch = getchar()) != '#' ：每次读取字符并判断是否为终止符 '#'
    while ((ch = getchar()) != '#') {  

        // 处理换行符：若输入是换行，跳过本次循环（重新等待输入）
        if (ch == '\n') {  
            printf("Please type a letter (a-z) or # to quit: ");
            continue;  // 跳过当前循环迭代，重新获取输入
        }

        // 校验：仅处理小写字母，非字母提示错误
        if (isalpha(ch)) {  // isalpha 判断是否为字母
            if (islower(ch)) {  // islower 进一步判断是否为小写字母
                // switch 多分支选择：根据字符 ch 的值匹配 case
                switch (ch) {  
                    case 'a':
                        printf("argali, a wild sheep of Asia\n");
                        break;  // 跳出 switch，避免执行后续 case
                    case 'b':
                        printf("babirusa, a wild pig of Malay\n");
                        break;
                    case 'c':
                        printf("coati, racoonlike mammal\n");
                        break;
                    case 'd':
                        printf("desman, aquatic, molelike critter\n");
                        break;
                    case 'e':
                        printf("echidna, the spiny anteater\n");
                        break;
                    case 'f':
                        printf("fisher, brownish marten\n");
                        break;
                    // 可继续扩展更多字母的 case...
                    default:  // 无匹配 case 时执行
                        printf("That's a stumper!\n");
                        break;  // 习惯上可加 break，虽语法允许省略
                }
            } else {
                // 输入非小写字母时的提示
                printf("I recognize only lowercase letters. Try again.\n");
            }
        } else {
            // 输入非字母时的提示（如数字、符号）
            printf("Invalid input! Please enter a letter (a-z) or # to quit.\n");
        }

        // 清理输入缓冲区：若输入含多余字符（如输入 "a123\n"），循环读取并丢弃
        // 避免多余字符干扰下一次输入
        while ((ch = getchar()) != '\n') {  
            continue;  // 持续读取，直到遇到换行符
        }

        // 提示用户继续输入或退出
        printf("Please type another letter or # to end: ");
    }

    // 程序结束提示
    printf("Bye!\n");
    return 0;
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch;
    printf("请输入一个字符：");
    ch = getchar();

    // 判断是否为字母
    if (isalpha(ch)) {
        printf("是字母\n");
        // 判断是否为小写字母
        if (islower(ch)) {
            printf("是小写字母。\n");
        } else {
            printf("不是小写字母。\n");
        }
    } else {
        printf("不是字母。\n");
    }
    return 0;
}
*/
/*
Give me a letter of the alphabet, and I will give an animal name beginning with that letter.
Please type in a letter; type # to end my act.
asgfkafjk skahf adjjagwk awdjbgakfa
argali, a wild sheep of Asia
Please type another letter or # to end: w
That's a stumper!
Please type another letter or # to end: e
echidna, the spiny anteater
Please type another letter or # to end: r
That's a stumper!
Please type another letter or # to end: r
That's a stumper!
Please type another letter or # to end: d
desman, aquatic, molelike critter
Please type another letter or # to end: a
argali, a wild sheep of Asia
Please type another letter or # to end: b
babirusa, a wild pig of Malay
Please type another letter or # to end: c
coati, racoonlike mammal
Please type another letter or # to end: d
desman, aquatic, molelike critter
Please type another letter or # to end: e
echidna, the spiny anteater
Please type another letter or # to end: f
fisher, brownish marten
Please type another letter or # to end: q
That's a stumper!
Please type another letter or # to end:
Please type a letter (a-z) or # to quit: z
That's a stumper!
Please type another letter or # to end: A
I recognize only lowercase letters. Try again.
Please type another letter or # to end: 1
Invalid input! Please enter a letter (a-z) or # to quit.
*/