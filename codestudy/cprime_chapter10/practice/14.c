// ------------------------------
// 题干：以变长数组为函数参数，完成：
//  b. 计算 int 数组的平均值；
//  c/d. 扩展：计算总和、找最大值（演示 VLA 灵活性）。
// 知识要点：
//  1. 变长数组（VLA）：参数中动态指定数组大小（如 `int arr[n]`），C99+ 支持。
//  2. 函数通用性：一个函数支持任意长度的 int 数组，无需硬编码大小。
//  3. 多任务扩展：通过函数参数或返回值，扩展为计算总和、找最大值等。
// 总体逻辑：
//  1. 定义 `calc_avg` 函数，用 VLA 参数 `int arr[n]`，计算平均值。
//  2. 扩展 `calc_sum`（计算总和）、`find_max`（找最大值）函数，同样用 VLA。
//  3. 主函数测试：定义不同长度的数组，调用函数验证。

#include <stdio.h>

// 【任务b】计算平均值（VLA 版）
double calc_avg(int n, int arr[n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n; // 强制转换为浮点数，避免整数除法
}

// 【扩展】计算总和（VLA 版）
int calc_sum(int n, int arr[n]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// 【扩展】找最大值（VLA 版）
int find_max(int n, int arr[n]) {
    if (n <= 0) return -1; // 处理空数组
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    // 测试数组1：5个元素
    int arr1[] = {1, 2, 3, 4, 5};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);

    // 测试数组2：3个元素（负数+零）
    int arr2[] = {-10, 0, 20};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    // 调用函数，验证结果
    printf("=== 数组1（5个元素） ===\n");
    printf("平均值：%.2f\n", calc_avg(len1, arr1)); // 预期：3.00
    printf("总和：%d\n", calc_sum(len1, arr1));     // 预期：15
    printf("最大值：%d\n", find_max(len1, arr1));   // 预期：5

    printf("\n=== 数组2（3个元素） ===\n");
    printf("平均值：%.2f\n", calc_avg(len2, arr2)); // 预期：3.33（(-10+0+20)/3 ≈3.33）
    printf("总和：%d\n", calc_sum(len2, arr2));     // 预期：10
    printf("最大值：%d\n", find_max(len2, arr2));   // 预期：20

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：用支持 C99 的编译器编译（如 `gcc -std=c99 ex14.c -o ex14 && ./ex14`）。
//  2. 预期结果：
//     - 数组1：平均3.00，总和15，最大值5；
//     - 数组2：平均3.33，总和10，最大值20。
//  3. 检查点：核对计算结果是否与手动计算一致。

// 易错点提醒：
//  1. VLA 兼容性：若编译器报错，需开启 C99 模式（`-std=c99`），或改用动态分配（`malloc`）。
//  2. 整数除法陷阱：`sum / n` 若为整数，需强制转换为 `double`（如 `(double)sum / n`），否则丢失小数。
//  3. 空数组处理：`find_max` 中若 `n=0`，返回 `-1` 需主函数判断，避免误判。

// 拓展思考：
//  1. 同时返回多个结果：用结构体封装（如 `struct Stats { double avg; int sum; int max; }`），函数返回结构体。
//  2. 支持浮点数数组：将函数参数改为 `double arr[n]`，适配浮点数计算。
//  3. 对比静态数组和 VLA：静态数组（`int arr[10]`）编译时确定大小，VLA 运行时确定，灵活性更高但占栈空间。

// 对比说明：
//  - VLA vs 动态分配：
//    → VLA 语法简洁（直接 `int arr[n]`），但存储在栈上，尺寸过大易溢出；
//    → 动态分配（`malloc`）存储在堆上，更安全，但需手动管理内存（`free`）。
//  - 单一任务 vs 多任务函数：
//    → 拆分函数（`calc_avg`、`calc_sum`）更易读；合并函数（一次遍历完成多个计算）更高效，按需选择。