/*
知识要点总结：
1. 二维数组与函数参数：
   - 函数形参声明：`int ar[][COLS]`（必须指定第二维大小，第一维可省略）
   - 等价写法：`int (*ar)[COLS]`（指向内含 COLS 个 int 的数组的指针）
2. 多维数组的遍历：
   - 行遍历：外层循环控制行（ar[r]），内层循环控制列（ar[r][c]）
   - 列遍历：外层循环控制列，内层循环控制行（交换循环顺序，按列累加）
3. 函数参数传递：
   - 二维数组名 `junk` 可直接传递给 `int ar[][COLS]` 形参（数组退化为指针）
   - 行数需单独传递（函数无法直接获取二维数组的行数）
4. 等价声明对比：
   - `int ar[][COLS]` ↔ `int (*ar)[COLS]` 
   - 演示 typedef 简化复杂数组指针声明（如 `typedef int arr4[4];` ）

代码总体逻辑说明：
1. 定义二维数组 `junk` 并初始化，作为数据源
2. 实现 3 个函数：
   - `sum_rows`：按行累加，打印每行总和
   - `sum_cols`：按列累加，打印每列总和
   - `sum2d`：计算所有元素总和，返回结果
3. 在 `main` 中调用上述函数，传递 `junk` 和行数 `ROWS`，验证多维数组的函数处理逻辑
4. 通过 printf 输出行总和、列总和、全体总和，直观展示函数功能
*/

#include <stdio.h>
#define ROWS 3  // 二维数组行数
#define COLS 4  // 二维数组列数

// 按行求和：外层循环行，内层循环列
void sum_rows(int ar[][COLS], int rows) {
    for (int r = 0; r < rows; r++) {  // r：行索引
        int tot = 0;
        for (int c = 0; c < COLS; c++) {  // c：列索引
            tot += ar[r][c];  // 累加当前行的第 c 个元素
        }
        printf("row %d: sum = %d\n", r, tot);
    }
}

// 按列求和：外层循环列，内层循环行
void sum_cols(int ar[][COLS], int rows) {
    for (int c = 0; c < COLS; c++) {  // c：列索引
        int tot = 0;
        for (int r = 0; r < rows; r++) {  // r：行索引
            tot += ar[r][c];  // 累加当前列的第 r 个元素
        }
        printf("col %d: sum = %d\n", c, tot);
    }
}

// 计算全体元素总和
int sum2d(int ar[][COLS], int rows) {
    int tot = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < COLS; c++) {
            tot += ar[r][c];
        }
    }
    return tot;
}

int main(void) {
    // 初始化二维数组：3 行 4 列
    int junk[ROWS][COLS] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6}
    };

    // 调用函数处理二维数组
    sum_rows(junk, ROWS);  // 按行求和
    sum_cols(junk, ROWS);  // 按列求和
    int total = sum2d(junk, ROWS);  // 全体求和
    printf("Sum of all elements = %d\n", total);

    // （拓展）typedef 简化数组指针声明演示
    typedef int arr4[4];  // arr4 是“内含 4 个 int 的数组”类型
    arr4 arr3x4[ROWS] = junk;  // 等价于 int arr3x4[ROWS][COLS]
    // 验证 typedef 声明的兼容性
    sum_rows(arr3x4, ROWS);  // 可直接传递给 sum_rows

    return 0;
}

/*
测试及验证建议方案：
1. 基础功能验证：
   - 运行代码，检查行总和、列总和、全体总和是否与书中示例输出一致
   - 修改 `junk` 的元素值（如 `junk[1][2] = 10` ），重新运行，验证函数是否正确累加
2. 函数参数边界测试：
   - 传递行数 `ROWS = 0`（空数组），检查函数是否崩溃（应避免，但可观察逻辑）
   - 传递超过数组行数的值（如 `ROWS = 4` ），观察越界访问的行为（演示未定义行为风险）
3. 等价声明替换：
   - 将 `sum_rows` 形参改为 `int (*ar)[COLS]` ，验证是否与 `int ar[][COLS]` 等价
   - 使用 typedef 声明 `arr3x4` 后，替换 `junk` 的类型，检查是否兼容
4. 编译器警告检查：
   - 尝试省略第二维大小（如 `int ar[][]` ），查看编译器报错（必须指定第二维）
   - 传递错误类型参数（如 `int arr[ROWS]` ），检查类型不匹配警告
5. 拓展功能测试：
   - 修改 `sum_cols` ，让列索引从 1 开始，验证是否跳过第一列
   - 新增函数 `sum_diag` 计算对角线元素和（需行列数相等），练习多维数组访问
*/