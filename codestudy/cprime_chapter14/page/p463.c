/*
代码名称：flexemb.c
知识要点总结：
1. 柔性数组成员（C99特性）：  
   - 定义规则：结构体最后一个成员，数组无长度（`type name[]`），结构体至少有一个其他成员。  
   - 内存特性：柔性数组**不占结构体自身内存**，需通过 `malloc` 额外分配空间。  
2. 内存分配：  
   - 公式：`malloc(sizeof(struct) + 元素数量 × sizeof(元素类型))`，将柔性数组和结构体“拼接”分配。  
3. 访问方式：  
   - 通过结构体指针直接访问 `->scores[i]`，利用内存连续性实现动态数组。  
4. 注意事项：  
   - 不能**赋值拷贝**柔性数组成员的结构体（需用 `memcpy` 手动拷贝）。  
   - 不能**值传递**含柔性数组的结构体给函数（需传指针）。  
   - 柔性数组不能作为“结构体的成员的成员”（即不能嵌套定义）。  

代码总体逻辑说明：  
1. **动态分配两次柔性数组**：  
   - 第一次：`n=5`，分配 `sizeof(struct flex) + 5×sizeof(double)` 内存，填充 `scores` 为 `20.0-i`，计算 `average`。  
   - 第二次：`n=9`，分配 `sizeof(struct flex) + 9×sizeof(double)` 内存，填充 `scores` 为 `20.0-i/2.0`，计算 `average`。  
2. **showFlex函数**：  
   - 接收结构体指针（`const` 保护，确保只读），遍历柔性数组 `scores` 打印，输出 `average`。  
3. **内存管理**：  
   - 每次分配后用 `free` 释放，避免内存泄漏。  
*/

#include <stdio.h>
#include <stdlib.h>  // 提供 malloc、free

// 定义含柔性数组成员的结构体
struct flex {
    size_t count;    // 柔性数组的元素数量（必须存在，记录数组长度）
    double average;  // 辅助字段（示例用途）
    double scores[]; // 柔性数组成员：必须是最后一个成员，无长度
};

// 函数声明：打印柔性数组内容（const 确保不修改数据）
void showFlex(const struct flex *p);

int main(void)
{
    struct flex *pf1, *pf2; // 指向柔性结构体的指针
    int n = 5;              // 第一次数组长度
    int i;
    double tot = 0;         // 用于计算总和

    // ========== 第一次分配：n=5 ==========
    // 分配内存：结构体大小 + 5个double的大小
    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
    if (pf1 == NULL) {      // 检查分配失败（实际开发必做，示例简化）
        fprintf(stderr, "Malloc failed!\n");
        exit(1);
    }

    pf1->count = n;         // 设置柔性数组的元素数量
    for (i = 0; i < n; i++) {
        pf1->scores[i] = 20.0 - i; // 填充柔性数组：20,19,18,17,16
        tot += pf1->scores[i];     // 累加计算总和
    }
    pf1->average = tot / n; // 计算平均值（18.0）
    showFlex(pf1);          // 打印结果


    // ========== 第二次分配：n=9 ==========
    n = 9;                  // 第二次数组长度
    tot = 0;                // 重置总和

    // 分配内存：结构体大小 + 9个double的大小
    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
    if (pf2 == NULL) {
        fprintf(stderr, "Malloc failed!\n");
        exit(1);
    }

    pf2->count = n;         // 设置柔性数组的元素数量
    for (i = 0; i < n; i++) {
        // 填充柔性数组：20.0, 19.5, 19.0, ..., 16.0（步长0.5）
        pf2->scores[i] = 20.0 - i / 2.0; 
        tot += pf2->scores[i];           // 累加计算总和
    }
    pf2->average = tot / n; // 计算平均值（约17.5）
    showFlex(pf2);          // 打印结果


    // ========== 释放内存 ==========
    free(pf1);
    free(pf2);

    return 0;
}

/* 
showFlex 函数：打印柔性数组内容和平均值  
参数：const struct flex *p → 只读指针，防止修改结构体数据  
访问逻辑：  
- p->count 是柔性数组的元素数量，遍历范围 [0, p->count-1]  
- p->scores[i] 直接访问柔性数组成员（依赖内存连续性）  
*/
void showFlex(const struct flex *p)
{
    int i;
    printf("Scores : ");
    for (i = 0; i < p->count; i++) {
        printf("%.1f ", p->scores[i]); // 打印每个分数
    }
    printf("\nAverage: %.1f\n", p->average); // 打印平均值
}


/*
代码测试及验证建议方案：
1. 输出验证：  
   - 检查 n=5 时，输出是否为 `Scores : 20.0 19.0 18.0 17.0 16.0`，`Average: 18.0`。  
   - 检查 n=9 时，输出是否为 `Scores : 20.0 19.5 19.0 18.5 18.0 17.5 17.0 16.5 16.0`，`Average: 17.5`。  

2. 内存正确性验证：  
   - 使用 `valgrind --leak-check=full ./flexemb` 检测内存泄漏，确保 `free` 调用正确。  
   - 尝试注释 `free(pf1)` 或 `free(pf2)`，观察泄漏报告。  

3. 柔性数组特性验证：  
   - 尝试**赋值拷贝**结构体：`struct flex f = *pf1;`，然后访问 `f.scores[0]`（会触发未定义行为，因为柔性数组成员的内存未被拷贝）。  
   - 尝试**值传递**结构体给函数：`showFlex(*pf1)`（编译器可能报错，或运行时崩溃，因为值传递会截断柔性数组成员）。  

4. 边界测试：  
   - 设置 `n=0`，观察程序行为（柔性数组长度为0，需确保代码逻辑兼容，本示例中 `n` 从1开始更安全）。  
   - 分配极大的 `n`（如1000000），检查内存分配是否成功，程序是否正常运行。  

5. 编译器兼容性：  
   - 使用 `gcc` 编译时，需添加 `-std=c99` 选项（如 `gcc -std=c99 flexemb.c -o flexemb`），确保支持柔性数组成员特性。  
*/