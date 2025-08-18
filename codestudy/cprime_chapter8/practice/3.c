/* 
问题3题干：编写一个程序，在遇到EOF之前，把输入作为字符流读取。该程序要报告输入中的大写字母和小写字母的个数（使用ctype.h库的分类函数更方便）。

知识要点：
1. 字符分类函数：`isupper()`、`islower()`（需 `ctype.h`）
2. 条件判断：区分大写字母、小写字母
3. 计数逻辑：分别累加大小写字母数量

总体逻辑：
1. 初始化大写、小写字母计数器
2. 循环读取字符直到 EOF
3. 用 `isupper()` 和 `islower()` 判断字符类型，对应计数+1
4. 输出统计结果

代码功能：
统计输入中大写字母（A-Z）和小写字母（a-z）的数量
*/

#include <stdio.h>
#include <ctype.h> // 包含字符分类函数

int main() {
    int ch;
    int upper_count = 0; // 大写字母计数
    int lower_count = 0; // 小写字母计数

    while ((ch = getchar()) != EOF) {
        if (isupper(ch)) { // 判断是否为大写字母
            upper_count++;
        } else if (islower(ch)) { // 判断是否为小写字母
            lower_count++;
        }
        // 非字母字符不处理
    }

    // 输出统计结果
    printf("Uppercase letters: %d\n", upper_count);
    printf("Lowercase letters: %d\n", lower_count);

    return 0;
}

/* 
测试验证方案：
1. 简单输入测试：
   - 输入 `Hello World`
   - 输出应为：
     `Uppercase letters: 2`（H, W）
     `Lowercase letters: 8`（e, l, l, o, o, r, l, d）

2. 全大写/全小写测试：
   - 输入 `ABC` → 大写 3，小写 0
   - 输入 `abc` → 大写 0，小写 3

3. 混合测试：
   - 输入 `123Aa!@#` → 大写 1，小写 1
*/