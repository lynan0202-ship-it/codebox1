/*
知识要点总结：
1. const 用于保护数据，创建 const 数组后其元素值不能被修改；
2. 指向 const 的指针（如 const double *pd），不能通过该指针修改所指向数据的值，但指针本身可指向别处；
3. 把 const 数据或非 const 数据的地址赋值给指向 const 的指针是合法的，但不能把非 const 数据的地址赋值给普通指针（若原数据是 const 修饰的 ），否则可能通过指针修改 const 数据；
4. 函数形参使用 const 指针，可保护数据并让函数处理 const 数组。

代码总体逻辑说明：
1. 先定义 const 数组、普通数组，演示指向 const 的指针的使用规则，包括指针能否修改数据、能否指向别处；
2. 定义 show_array 函数，形参用 const 指针，分别传入普通数组和 const 数组名，体现 const 形参的作用；
3. 演示因违反 const 使用规则导致的错误情况（注释中体现 ），帮助理解规则边界。
*/

#include <stdio.h>

// 函数用于展示数组内容，const double *arr 表明不会通过该指针修改数组数据
void show_array(const double *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    // 普通数组，未被 const 修饰
    double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
    // const 修饰的数组，元素值不能修改
    const double locked[4] = {0.08, 0.075, 0.0725, 0.07}; 

    // 指向 const 的指针，可指向普通数组或 const 数组
    const double *pd = rates; 
    // 可以让指向 const 的指针指向别处
    pd = locked; 

    // 以下操作不允许，因为不能通过指向 const 的指针修改所指向数据的值
    // *pd = 29.89; // 错误，不允许通过 pd 修改数据
    // pd[2] = 222.22; // 错误，数组表示法也不能修改

    // 允许，因为 rates 本身未被 const 修饰，可直接修改数组元素
    rates[0] = 99.99; 

    // 演示函数形参使用 const 指针，可接受普通数组名（rates 会转换为指针 ）
    show_array(rates, 5); 
    // 也可接受 const 数组名（locked 转换为 const 指针 ）
    show_array(locked, 4); 

    // 以下是违反规则的情况演示（实际编译会报错，这里用注释说明 ）
    // double *pnc = locked; // 错误，locked 是 const 数组，不能把其地址给普通指针，否则可能通过 pnc 修改 locked 数据
    // pnc = &rates[3]; // 若上面错误语句去掉注释，这里虽语法允许，但结合前面错误，整体不合法

    // 指针指向 const 数据的地址，赋给普通指针，会有风险（若原数据是 const ）
    // const double *pc = rates;
    // double *p = pc; // 错误，不能把指向 const 的指针赋给普通指针，否则可能通过 p 修改 const 数据（这里 rates 实际非 const，但若原数据是 const 就会有问题 ）

    return 0;
}

/*
测试及验证建议方案：
1. 编译并运行代码，观察 show_array 函数输出，验证传入普通数组和 const 数组时，函数都能正常访问数据且未修改数据；
2. 尝试取消注释代码中违反 const 规则的语句（如 *pd = 29.89; 、double *pnc = locked; 等 ），查看编译器报错信息，理解错误原因，强化对规则的记忆；
3. 修改 rates 数组和 locked 数组的元素值（注意 locked 是 const 不能直接修改 ），调用 show_array 函数，检查输出是否符合预期，验证 const 对数据保护的效果；
4. 自定义其他函数，形参使用 const 指针，传入不同类型数组，测试函数对数据的处理能力，巩固 const 形参的用法。
*/