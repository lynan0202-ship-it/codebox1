/*
知识要点总结：
1. 指针兼容性核心规则：
   - 不同类型指针直接赋值会触发编译器警告（如 int* 与 double* 互赋）
   - 指向数组的指针需匹配数组维度（如 int(*pa)[3] 需指向“内含3个int的数组”，与 int(*pb)[2] 不兼容）
   - const 指针安全规则：
     - 允许：非 const 指针 → const 指针（一级解引用安全）
     - 危险：const 指针 → 非 const 指针（可能通过新指针修改 const 数据）
     - 多级解引用时，const 限制可能失效（如 const int** 指向非 const 指针，间接修改 const 数据）
2. 声明语法辨析：
   - int* pax[2]：指针数组（[] 优先级高于 * ）
   - int (*pz)[2]：指向“内含2个int的数组”的指针（括号提升 * 优先级）
3. 数组与指针的等价表示：
   - zippo[m][n] ↔ *(*(zippo + m) + n) 
   - 指针表示法与数组表示法可互换，但需注意类型匹配

代码总体逻辑说明：
1. 定义基础类型变量（int、double）、数组（一维、二维）、指针（普通指针、指向数组的指针、const 指针）
2. 分场景演示指针赋值：
   - 合法兼容：同类型指针、非 const → const 指针（一级解引用）
   - 非法兼容：不同类型指针直接赋值、const → 非 const 指针（触发警告/错误）
   - 数组指针匹配：验证指向数组的指针与二维数组的兼容性
3. 通过 printf 打印地址和值，直观展示指针赋值后的行为，对比合法/非法场景的编译器反馈
*/

#include <stdio.h>

int main(void)
{
    // 基础类型与指针：演示数值类型赋值 vs 指针类型赋值
    int n = 5;
    double x = 3.14;
    int *pl = &n;         // 合法：int* 指向 int
    double *pd = &x;      // 合法：double* 指向 double

    // 非法示例1：不同类型指针直接赋值（无需强转，但编译器报错）
    // pd = pl;            // 错误：incompatible pointer types（类型不兼容）

    // const 指针安全规则演示
    const int y = 23;
    const int *p_const = &y;  // p_const 指向 const int
    int *p_nonconst = &n;     // p_nonconst 指向非 const int

    // 合法：非 const 指针 → const 指针（一级解引用安全）
    p_const = p_nonconst;     

    // 非法：const 指针 → 非 const 指针（触发警告：discarded qualifier）
    // p_nonconst = p_const; 

    // 数组与指针的等价表示
    int zippo[3][2] = { {1,2}, {3,4}, {5,6} };
    int (*pz)[2] = zippo;     // 合法：pz 指向“内含2个int的数组”，匹配 zippo 类型

    // 验证数组指针运算
    printf("zippo[1][0]（数组表示）= %d\n", zippo[1][0]);
    printf("zippo[1][0]（指针表示）= %d\n", *(*(zippo + 1) + 0));
    printf("pz[1][0]（指针数组表示）= %d\n", pz[1][0]);

    // 复杂场景：const 多级指针（潜在不安全）
    const int **pp2;
    int *pt = &n;
    pp2 = &pt;               // 合法：pp2 指向 int* （但 pp2 声明为 const int** ，实际指向非 const 指针）
    // *pp2 = &y;             // 危险：通过 pp2 修改 pt ，间接让 pt 指向 const int y 
    // *pt = 100;             // 非法：若 pt 指向 y（const），修改会触发未定义行为

    // 打印验证（实际运行前需注释危险操作）
    printf("n = %d, y = %d\n", n, y);
    printf("pl = %p（指向 n）, pd = %p（指向 x）\n", pl, pd);
    printf("p_const = %p（指向 %d）\n", p_const, *p_const);

    return 0;
}

/*
测试及验证建议方案：
1. 编译观察警告/错误：
   - 取消注释 `pd = pl;` ，查看编译器报错（类型不兼容）
   - 取消注释 `p_nonconst = p_const;` ，查看警告（discarded qualifier）
   - 取消注释 `*pp2 = &y;` 和 `*pt = 100;` ，观察运行时行为（可能修改 const 变量，触发未定义行为）
2. 验证数组指针匹配：
   - 修改二维数组 zippo 的维度（如改为 4x3 ），调整 `int (*pz)[3] = zippo;` ，检查是否兼容
   - 打印 `pz + 1` 的地址，对比 `zippo + 1` ，验证指针跳过“内含2个int的数组”
3. 调试查看指针指向：
   - 单步运行，观察 p_const、p_nonconst 的地址变化
   - 验证 `zippo[1][0]` 与 `*(*(zippo + 1) + 0)` 的值是否一致，理解数组与指针的等价表示
4. 跨编译器对比：
   - 分别用 gcc、clang 编译，观察警告细节差异（如 const 指针赋值的严格性）
   - 在 C++ 环境编译（如 g++ ），对比 C 和 C++ 对 const 指针的兼容性差异（C++ 更严格）
*/