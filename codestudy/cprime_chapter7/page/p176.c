/*
以下是对教程中 switch 相关知识（含多重标签、分支贯穿、break 作用等）进行完整整合，以原 vowels.c 程序为基础，补充示例并添加超详细注释的代码，清晰覆盖 多重 case 标签、switch 执行流程、break 控制分支、输入处理 等核心知识点：
知识要点与总体逻辑说明
知识覆盖：
多重 case 标签：多个 case 共用同一段逻辑（如 case 'a': case 'A': 共同统计字母 a/A 数量 ）。
switch 执行流程：匹配 case 后，若无 break，会 “贯穿” 执行后续 case 逻辑（可利用此特性实现多标签复用）。
break 的核心作用：跳出当前 switch 分支，精准控制执行范围。
输入处理与循环交互：通过 getchar() 持续读取字符，# 终止程序，配合逻辑统计元音字母数量。
总体逻辑：
程序启动后，提示用户输入文本，逐字符读取并判断是否为元音（含大小写）。利用 switch 的多重 case 标签，统一处理大小写元音（如 a/A 共享统计逻辑 ）；通过 break 控制分支结束，避免不必要的 “贯穿”；输入 # 时终止循环，最后输出各元音字母的统计结果，完整演示 switch 多场景用法。
带详细注释的完整代码（vowels_annotated.c）
*/
/* 
 * 程序：vowels_annotated.c
 * 功能：演示 switch 多重 case 标签、break 作用，统计文本中元音字母（a/e/i/o/u 大小写）数量
 * 知识覆盖：
 *  1. 多重 case 标签：多个 case 共享同一段逻辑（如 case 'a': case 'A': 共同处理字母 a/A）
 *  2. switch 执行流程：匹配 case 后，无 break 会“贯穿”执行后续 case
 *  3. break 作用：跳出 switch 分支，精准控制执行范围
 *  4. 输入处理：getchar() 逐字符读取，# 终止循环，持续统计元音
 */

#include <stdio.h>  // 提供 printf、getchar 等输入输出函数

int main(void) {
    char ch;  // 存储当前读取的字符
    // 统计各元音字母的计数器，初始化为 0
    int a_ct = 0, e_ct = 0, i_ct = 0, o_ct = 0, u_ct = 0;  

    // 程序功能提示
    printf("Enter some text; enter # to quit.\n");

    // while 循环：持续读取字符，直到输入 '#'
    while ((ch = getchar()) != '#') {  
        switch (ch) {  // 根据字符 ch 进行多分支选择
            // 处理元音字母 'a'（小写）和 'A'（大写）
            case 'a':  
            case 'A':  
                a_ct++;  // 共享统计逻辑，统计 a/A 的数量
                break;  // 跳出 switch，避免“贯穿”到后续 case
            // 处理元音字母 'e'（小写）和 'E'（大写）
            case 'e':  
            case 'E':  
                e_ct++;  // 统计 e/E 的数量
                break;
            // 处理元音字母 'i'（小写）和 'I'（大写）
            case 'i':  
            case 'I':  
                i_ct++;  // 统计 i/I 的数量
                break;
            // 处理元音字母 'o'（小写）和 'O'（大写）
            case 'o':  
            case 'O':  
                o_ct++;  // 统计 o/O 的数量
                break;
            // 处理元音字母 'u'（小写）和 'U'（大写）
            case 'u':  
            case 'U':  
                u_ct++;  // 统计 u/U 的数量
                break;
            // 非元音字母：无操作，继续循环
            default:  
                break;  // 习惯上可加 break，语法允许省略
        }
    }

    // 输出统计结果：按格式打印各元音字母数量
    printf("\nNumber of vowels:\n");
    printf("A: %d\tE: %d\tI: %d\tO: %d\tU: %d\n", 
           a_ct, e_ct, i_ct, o_ct, u_ct);

    return 0;
}
/*
关键逻辑分步解析
多重 case 标签用法：
case 'a': case 'A':：两个 case 共用 a_ct++; 逻辑，实现大小写元音统一统计，利用了 switch “匹配即执行，无 break 则贯穿” 的特性。
break 的精准控制：
每个元音分支后加 break，确保 “统计完当前元音后，立即跳出 switch”，避免执行后续无关 case（如统计 a 后，不会误执行 e 的逻辑 ）。
输入与循环终止：
while ((ch = getchar()) != '#')：持续读取字符，输入 # 时终止循环，程序进入结果统计阶段。
统计与输出：
用 a_ct 到 u_ct 分别统计各元音数量，最后格式化输出，清晰展示统计结果。
*/
/*
// 演示“分支贯穿”的示例片段（请勿在实际统计中使用）
case 'a':  
case 'A':  
    a_ct++;  
    // 移除 break，会继续执行后续 case！
case 'e':  // 注意：此处无 break 时，a/A 的统计会“贯穿”到 e 的逻辑
case 'E':  
    e_ct++;  
    break;
// 若输入 'a'，会同时执行 a_ct++ 和 e_ct++，导致统计错误
*/
/*
Enter some text; enter # to quit.
The gentle breeze whispers through the old oak tree.
#

Number of vowels:
A: 1    E: 10   I: 1    O: 3    U: 1
*/