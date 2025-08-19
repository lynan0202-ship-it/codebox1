// ------------------------------
// 题干：分别以传统方式和以变长数组为参数的方式，编写处理 shots 数组的 void 函数原型和函数调用
// 知识要点：
//  1. 三维数组的参数传递：传统方式需固定后两维，VLA 方式可动态指定维度。
//  2. 变长数组（VLA）的多维支持：C99/C11 允许多维 VLA，维度由参数决定。
//  3. 函数原型的复杂性：多维数组参数需明确除第一维外的维度（传统方式）或动态指定（VLA 方式）。
// 总体逻辑：
//  1. 传统方式：函数原型固定后两维为 6 和 8，调用时传数组名。
//  2. VLA 方式：函数原型通过参数动态指定后两维，调用时传入维度。
#include <stdio.h>

// 传统方式函数原型：后两维固定为 6 和 8
void traditional3D(double arr[][6][8], int rows);
// VLA 方式函数原型：后两维由参数 cols 和 depth 动态指定
void vla3D(int rows, int cols, int depth, double arr[rows][cols][depth]);

int main() {
    // 定义三维数组 shots
    double shots[5][6][8];
    int rows = 5, cols = 6, depth = 8;

    // 传统方式调用：后两维固定为 6 和 8
    traditional3D(shots, rows);
    // VLA 方式调用：动态传入维度
    vla3D(rows, cols, depth, shots);

    return 0;
}

// 传统方式函数定义：处理三维数组，后两维固定为 6 和 8
void traditional3D(double arr[][6][8], int rows) {
    printf("传统方式处理三维数组，行数：%d，列数固定为 6，深度固定为 8\n", rows);
    // 可在此添加数组处理逻辑（如遍历）
}

// VLA 方式函数定义：处理三维数组，维度由参数动态决定
void vla3D(int rows, int cols, int depth, double arr[rows][cols][depth]) {
    printf("VLA 方式处理三维数组，行数：%d，列数：%d，深度：%d\n", rows, cols, depth);
    // 可在此添加数组处理逻辑（如遍历）
}

// 测试验证方案：
//  1. 怎么运行：编译运行（如 `gcc -std=c99 -o test test.c`，然后 `./test`）。
//  2. 预期结果：输出两种方式的提示信息，无编译错误。
//  3. 检查点：确认函数调用成功，输出维度是否正确。
// 易错点提醒：
//  1. 传统方式容易漏写后两维的固定大小，导致编译错误。
//  2. VLA 方式在嵌套维度时，参数顺序容易写反（如把 cols 和 depth 写反）。
// 拓展思考：
//  1. 三维数组的遍历逻辑比二维更复杂，如何用嵌套循环实现？
//  2. 如果维度非常大，VLA 方式会导致栈溢出吗？为什么？
// 对比说明：
//  - 传统方式：维度固定，适合简单场景，兼容性好，但缺乏灵活性。
//  - VLA 方式：维度动态，适合复杂场景，但依赖 C99/C11，且需注意栈空间（VLA 存储在栈上）。