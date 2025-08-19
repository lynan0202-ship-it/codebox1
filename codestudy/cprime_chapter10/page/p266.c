/*
知识要点总结：
1. 变长数组（VLA）：C99 引入，允许数组维度用变量指定，创建时维度由运行时变量决定
2. VLA 函数形参：声明如 `int ar[rows][cols]`，需先声明 rows/cols 再声明数组
3. VLA 特性：
   - 维度是变量，但创建后大小固定
   - 作为形参时不实际分配数组，本质是指针操作
   - 支持动态维度的二维数组处理，兼容传统数组
4. 传统数组 vs VLA：
   - 传统数组维度用常量（如 `#define`），VLA 用变量
   - VLA 让函数更灵活，可处理任意大小二维数组
5. 易错点：
   - VLA 形参声明顺序：`rows/cols` 必须在数组前
   - 编译器支持：需开启 C99/C11 支持（如 `gcc -std=c99`）

代码总体逻辑说明：
1. 定义变长数组处理函数 `sum2d`，支持任意大小二维数组求和
2. 主函数中：
   - 创建传统二维数组 `junk`、`morejunk`
   - 创建 VLA `varr`，维度由变量 `rs/cs` 指定
   - 分别调用 `sum2d` 处理传统数组和 VLA，验证兼容性
3. 输出不同数组的总和，演示 VLA 动态维度的优势
*/

#include <stdio.h>

// VLA 函数形参：先声明维度 rows/cols，再声明二维数组 ar
int sum2d(int rows, int cols, int ar[rows][cols]) {
    int tot = 0;
    // 双重循环遍历二维数组
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            tot += ar[r][c]; // 累加每个元素
        }
    }
    return tot; // 返回总和
}

int main(void) {
    // 传统二维数组：维度用常量
    #define ROWS 3
    #define COLS 4
    int junk[ROWS][COLS] = {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6}
    };

    // 另一个传统数组：维度变化
    int morejunk[ROWS - 1][COLS + 2] = {
        {20, 30, 40, 50, 60, 70},
        {5, 6, 7, 8, 9, 10}
    };

    // 变长数组（VLA）：维度用变量
    int rs = 3;
    int cs = 10;
    int varr[rs][cs]; // 运行时确定维度

    // 初始化 VLA：双重循环赋值
    for (int i = 0; i < rs; i++) {
        for (int j = 0; j < cs; j++) {
            varr[i][j] = i * j + j; // 简单公式赋值
        }
    }

    // 测试传统 3x4 数组
    printf("3x4 array\n");
    printf("Sum of all elements = %d\n", sum2d(ROWS, COLS, junk));

    // 测试传统 2x6 数组（ROWS-1=2, COLS+2=6）
    printf("2x6 array\n");
    printf("Sum of all elements = %d\n", sum2d(ROWS - 1, COLS + 2, morejunk));

    // 测试 3x10 VLA
    printf("3x10 VLA\n");
    printf("Sum of all elements = %d\n", sum2d(rs, cs, varr));

    return 0;
}

/*
测试及验证建议方案：
1. 基础功能验证：
   - 运行代码，检查输出总和是否与书中示例一致
   - 修改 `junk` 元素值（如 `junk[1][2] = 10`），重新运行验证求和逻辑
2. 编译器兼容性测试：
   - 使用 gcc 编译：`gcc -std=c99 -o vla_test vla_test.c`
   - 尝试用 C89 标准编译（`-std=c89`），观察 VLA 相关报错
3. 维度边界测试：
   - 传递 `rows=0` 或 `cols=0`，检查函数是否处理空数组
   - 传递极大维度（如 `rs=1000000`），观察内存分配情况（可能栈溢出）
4. 形参顺序测试：
   - 交换 `sum2d` 形参顺序（如 `int sum2d(int ar[rows][cols], int rows, int cols)`），查看编译器报错
5. VLA 特性验证：
   - 在 `sum2d` 中修改 `ar[r][c]` 的值（如 `ar[0][0] = 99`），主函数中检查 `junk` 或 `varr` 的值是否被修改（验证 VLA 形参本质是指针操作）
6. 动态维度测试：
   - 用用户输入的变量作为维度（如 `scanf("%d", &rs)`），创建 VLA 并测试
   - 对比传统数组和 VLA 的内存地址（通过 `printf("%p", varr)` 等），理解 VLA 的栈分配特性
*/