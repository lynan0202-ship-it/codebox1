#include <stdio.h>

int main(void)
{
    // 最小分数（闭区间）
    const float MIN = 0.0f;  
    // 最大分数（闭区间）
    const float MAX = 100.0f;  

    float score;         // 存储当前输入的分数
    float total = 0.0f;  // 有效分数的总和
    int n = 0;           // 有效分数的个数
    // 初始化为最大值，方便后续更新最小值
    float min = MAX;     
    // 初始化为最小值，方便后续更新最大值
    float max = MIN;     

    // 提示用户输入第一个分数，或输入 q 退出
    printf("Enter the first score (q to quit): ");
    // 循环条件：scanf 成功读取 1 个浮点数（%f）则继续，否则退出（如输入 q）
    while (scanf("%f", &score) == 1) {  

        // --------------------- 1. continue 核心用法（跳过无效输入） --------------------- 
        // 教程知识点：如果分数超出 [MIN, MAX] 范围，跳过当前循环剩余逻辑，进入下一次循环
        if (score < MIN || score > MAX) {  
            // 提示用户输入无效
            printf("%0.1f is an invalid value. Try again: ", score);  
            // 跳过当前循环剩余代码，直接进入下一次循环（重新读取输入）
            continue;  
        }

        // --------------------- 2. 处理有效输入（continue 跳过的分支不执行这里） --------------------- 
        // 只有分数有效时，才会执行到这里
        printf("Accepting %0.1f\n", score);  

        // 更新总分
        total += score;  
        // 更新最小值：如果当前分数 < min，更新 min 为当前分数；否则保持原 min
        min = (score < min) ? score : min;  
        // 更新最大值：如果当前分数 > max，更新 max 为当前分数；否则保持原 max
        max = (score > max) ? score : max;  
        // 有效分数计数 +1
        n++;  
        //使用以上结构更新分数最小值。既用此可以持续更新最小值
        // 提示用户输入下一个分数，或输入 q 退出
        printf("Enter next score (q to quit): ");  
    }

    // --------------------- 3. 循环结束后：统计结果或提示无有效输入 --------------------- 
    if (n > 0) {  // 如果有有效分数
        // 计算平均分并输出：total / n
        printf("Average of %d scores is %0.1f\n", n, total / n);  
        // 输出最小值和最大值
        printf("Low = %0.1f, high = %0.1f\n", min, max);  
    } else {  // 没有有效分数
        printf("No valid scores were entered.\n");  
    }

    return 0;
}
/*
关键注释与教程知识点对应
continue 基础用法：
if (score < MIN || score > MAX) { ... continue; }
注释说明 continue 的作用：跳过当前循环剩余逻辑（如 total += score 等），直接进入下一次循环（重新读取输入），对应教程 “跳过无效输入，重新开始循环” 的逻辑。
循环流程控制：
解释 while (scanf("%f", &score) == 1) 的条件：scanf 成功读取浮点数（返回值为 1）则继续循环，否则退出（如输入 q），覆盖教程 “循环终止条件” 知识点。
变量初始化与更新：
min = MAX、max = MIN 的初始化逻辑：通过 “极值反向赋值” 确保第一次有效输入能正确更新 min 和 max，呼应教程 “变量初始值设置技巧”。
min = (score < min) ? score : min; 是三元运算符 ?: 的用法，与教程 7.5 节知识点关联，简化 if-else 判断。
*/
/*
// 替代 continue 的写法：用 if-else 包裹有效分支
if (score >= MIN && score <= MAX) {
    // 原有效分支代码（total += score、更新 min/max 等）
} else {
    // 原 continue 分支代码（提示无效输入）
}
*/
/*
Enter the first score (q to quit): 23
Accepting 23.0
Enter next score (q to quit): 56
Accepting 56.0
Enter next score (q to quit): 78
Accepting 78.0
Enter next score (q to quit): 86
Accepting 86.0
Enter next score (q to quit): -0
Accepting -0.0
Enter next score (q to quit): -8
-8.0 is an invalid value. Try again: 56
Accepting 56.0
Enter next score (q to quit): 87
Accepting 87.0
Enter next score (q to quit): 67
Accepting 67.0
Enter next score (q to quit): q
Average of 8 scores is 56.6
Low = -0.0, high = 87.0
*/
/*
关键注释与教程知识点一一对应
continue 基础逻辑（覆盖教程核心）：
c
运行
if (score < MIN_SCORE || score > MAX_SCORE) {  
    continue; // 跳过无效分数，进入下一次循环
}

注释说明 continue 的作用：跳过当前循环剩余代码，直接开始下一次循环迭代（重新判断 while 条件），对应教程 “用 continue 跳过无效输入” 的逻辑。
while 与 for 中 continue 的差异（教程重点对比）：
while 循环中，continue 后直接判断 while(...) 条件；既跳过while语句中的更新条件
for 循环中，continue 后会先执行 更新表达式（如 i++），再判断 for(...) 条件。
代码中通过 for (int i = 0; i < 5; i++) 演示，覆盖教程 “for 循环中 continue 会执行更新表达式” 的知识点。
continue 简化嵌套 vs if-else（教程对比用法）：
c
运行
// 用 if-else 替代 continue 的写法
if (num >= 0 && num <= 100) { ... } 
else { ... }

注释说明：简单逻辑下 if-else 可替代 continue，但代码复杂时（如多层嵌套），continue 能减少缩进，提升可读性，对应教程 “continue 简化嵌套” 的知识点。
无效输入处理（教程示例延伸）：
模拟 “分数统计” 场景，输入超出 [0, 100] 时用 continue 跳过，与教程 skipart.c 逻辑完全一致，覆盖 “跳过无效数据，重新开始循环” 的核心用法。
运行验证与教程完全匹配
输入输出示例（覆盖教程所有分支）：
*/