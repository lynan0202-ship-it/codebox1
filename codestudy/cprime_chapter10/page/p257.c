// ------------------------------
// 知识要点总结：
//  1. 数组传参本质：传递数组首地址（指针），函数直接操作原数组
//  2. 数据修改风险：
//     - 函数通过指针可直接修改原数组元素（如 add_to 函数）
//     - 编程错误可能意外修改数据（如 sum 函数中 ar[i]++ 的错误）
//  3. const 保护机制：
//     - 用 const 修饰函数形参（const int ar[]），禁止函数修改数组
//     - 编译器会拦截修改操作，保护原数组数据
//  4. 函数设计选择：
//     - 需要修改数组时：用普通指针形参（int ar[]）
//     - 只读数组时：用 const 指针形参（const int ar[]）
// 
// 总体逻辑说明：
//  1. 定义 add_to 函数：修改数组元素（演示“需要修改”的场景）
//  2. 定义错误 sum 函数：因 ar[i]++ 意外修改数组（演示风险）
//  3. 定义安全 sum_const 函数：用 const 保护数组（演示“只读”场景）
//  4. 主函数调用这 3 个函数，验证数据修改和保护效果
//  5. 故意写错误代码（注释掉），让编译器报错，理解 const 的作用
// ------------------------------

#include <stdio.h>

// -------------------- 1. 需要修改数组：普通形参 --------------------
void add_to(double ar[], int n, double val) {
    for (int i = 0; i < n; i++) {
        ar[i] += val;  // 合法修改：函数需要修改原数组
    }
}

// -------------------- 2. 错误示例：意外修改数组（别学！） --------------------
// 错误函数：因 ar[i]++ 意外修改原数组
int sum_bad(int ar[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += ar[i]++;  // 危险操作：本意求和，实际修改了数组
    }
    return total;
}

// -------------------- 3. 安全只读：用 const 保护数组 --------------------
int sum_const(const int ar[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        // ar[i] += 1;  // 取消注释会报错！const 禁止修改
        total += ar[i];  // 合法只读：sum 需要数组值但不修改
    }
    return total;
}

int main(void) {
    // 初始化数组（模拟价格数据）
    double prices[5] = {10.5, 20.3, 5.7, 8.2, 15.0};
    int scores[4] = {80, 90, 85, 75};

    // -------------------- 测试 add_to：修改数组 --------------------
    printf("=== 测试 add_to（修改数组）===\n");
    printf("修改前 prices: ");
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", prices[i]);
    }
    printf("\n");

    add_to(prices, 5, 2.5);  // 每个元素加 2.5

    printf("修改后 prices: ");
    for (int i = 0; i < 5; i++) {
        printf("%.1f ", prices[i]);
    }
    printf("\n\n");

    // -------------------- 测试 sum_bad：意外修改数组 --------------------
    printf("=== 测试 sum_bad（意外修改）===\n");
    printf("调用前 scores: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    int bad_total = sum_bad(scores, 4);
    printf("sum_bad 结果: %d\n", bad_total);
    printf("调用后 scores: ");  // 数组已被意外修改
    for (int i = 0; i < 4; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n\n");

    // -------------------- 测试 sum_const：const 保护数组 --------------------
    printf("=== 测试 sum_const（const 保护）===\n");
    // 重置数组（恢复 scores 原始值）
    int scores_original[4] = {80, 90, 85, 75};  
    int const_total = sum_const(scores_original, 4);
    printf("sum_const 结果: %d\n", const_total);

    // 尝试修改 const 形参（编译器会报错，此处注释掉演示）
    // sum_const 函数内若写 ar[0] = 100; 会报错：
    //  assignment of read-only location '*(const int*)ar'
    printf("\n");

    return 0;
}

// 安全求和函数：用 const 保护数组，禁止修改
int sum_const(const int ar[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += ar[i];  // 只读操作，安全
    }
    return total;
}

// ------------------------------
// 测试及验证建议方案：
//  1. 基础功能测试：
//     a) 运行程序，检查 add_to 函数是否正确修改数组
//     b) 验证 sum_const 函数求和结果是否正确（应与原始数组一致）
// 
//  2. 错误场景测试：
//     a) 观察 sum_bad 调用后 scores 数组的变化（元素值 +1）
//     b) 取消 sum_const 内 ar[0] = 100; 的注释，编译看报错
// 
//  3. const 保护验证：
//     a) 尝试在 sum_const 中修改数组元素，确认编译器拦截
//     b) 传递 const 数组给普通函数（如 add_to），观察是否允许修改
// 
//  4. 易错点提醒：
//     - 数组传参后，函数操作的是原数组，修改会影响主函数
//     - const 修饰形参时，实参可以是普通数组（编译器自动转换）
//     - 区分“需要修改数组”和“只读数组”的函数设计
// 
//  5. 拓展思考：
//     - 如果函数形参是 const int ar[]，实参是 const int 数组，会怎样？
//     - 对比 sum_bad 和 sum_const，思考如何避免意外修改
// ------------------------------

// 特别说明（帮你避坑）：
//  1. const 是“编译期保护”：
//     - 编译器检查函数内的修改操作，运行时不影响
//  2. 实参与形参的 const 匹配：
//     - 普通数组可以传给 const 形参（安全降级）
//     - const 数组不能传给普通形参（编译器报错，保护数据）
//  3. 常见错误场景：
//     - 像 sum_bad 中因++操作意外修改数组，用 const 可避免