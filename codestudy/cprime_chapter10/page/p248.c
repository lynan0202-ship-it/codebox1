// ------------------------------
// 知识要点总结：
//  1. 数组名的本质：数组名是数组首元素的地址（常量，不能修改）
//  2. 指针运算规则：
//     - 指针 + n → 指向数组的第 n 个元素（地址跳过 n*sizeof(元素类型) 字节）
//     - *(指针 + n) → 等价于 数组[n]（访问第 n 个元素的值）
//  3. 指针与数组的等价性：
//     - 数组表示法 arr[n] 本质是 *(arr + n)
//     - 指针表示法 *(ptr + n) 等价于 数组表示法
//  4. 不同类型指针的步长：
//     - short* 指针 +1 → 跳过 2 字节（short 占 2 字节）
//     - double* 指针 +1 → 跳过 8 字节（double 占 8 字节）
//  5. 运算符优先级：* 和 + 的优先级（*ptr + n 不等价于 *(ptr + n)）
// 
// 总体逻辑说明：
//  1. 定义 short 和 double 类型的数组，用指针指向数组首地址
//  2. 演示指针 +n 的地址变化（验证不同类型指针的步长）
//  3. 用指针表示法遍历数组，对比数组表示法的结果
//  4. 故意写易错代码，解释 *ptr +n 和 *(ptr +n) 的区别
// ------------------------------

#include <stdio.h>
#define SIZE 4  // 数组元素个数

int main(void)
{
    // 定义 short 类型数组（占 2 字节/元素）
    short dates[SIZE] = {1, 2, 3, 4};  
    // 定义 double 类型数组（占 8 字节/元素）
    double bills[SIZE] = {1.1, 2.2, 3.3, 4.4};  

    // 指针指向数组首元素（数组名是首地址）
    short *pti = dates;  
    double *ptf = bills;  

    // -------------------- 演示指针 +n 的地址变化 --------------------
    printf("=== 指针 +n 的地址变化 ===\n");
    printf("%-10s %-16s %-16s\n", "index", "short 指针", "double 指针");
    for (int i = 0; i < SIZE; i++)
    {
        // 指针 +i 的地址：short* 每次跳 2 字节，double* 每次跳 8 字节
        printf("%-10d %p %p\n", i, pti + i, ptf + i);  
    }


    // -------------------- 数组表示法 vs 指针表示法 --------------------
    printf("\n=== 数组表示法 vs 指针表示法 ===\n");
    printf("%-10s %-10s %-10s\n", "index", "数组表示", "指针表示");
    for (int i = 0; i < SIZE; i++)
    {
        // 数组表示法：dates[i]
        int arr_val = dates[i];  
        // 指针表示法：*(dates + i) 或 *(pti + i)
        int ptr_val = *(dates + i);  

        printf("%-10d %-10d %-10d\n", i, arr_val, ptr_val);
    }


    // -------------------- 易错点演示：*ptr +n vs *(ptr +n) --------------------
    printf("\n=== 易错点：*ptr +n vs *(ptr +n) ===\n");
    // *(dates + 2) → 数组第3个元素（值为3）
    int right = *(dates + 2);  
    // *dates + 2 → 首元素值（1） +2 → 3（巧合相等，容易误导！）
    int wrong = *dates + 2;  

    printf("*(dates + 2) = %d\n", right);
    printf("*dates + 2 = %d\n", wrong);

    // 正确用法：*(dates + 3) → 数组第4个元素（值为4）
    int correct = *(dates + 3);  
    // 错误用法：*dates + 3 → 首元素值（1）+3 →4（巧合相等，实际逻辑错误）
    int mistake = *dates + 3;  

    printf("*(dates + 3) = %d\n", correct);
    printf("*dates + 3 = %d\n", mistake);


    return 0;
}

// ------------------------------
// 测试及验证建议方案：
//  1. 地址变化测试：
//     a) 观察 short 指针每次 +1 地址跳 2 字节，double 指针跳 8 字节
//     b) 验证地址变化规律：pti +1 的地址 = &dates[1]
// 
//  2. 等价性测试：
//     a) 检查数组表示法和指针表示法的输出是否完全一致
//     b) 修改数组元素值（如 dates[2] = 5），重新运行看结果是否同步变化
// 
//  3. 易错点测试：
//     a) 故意让 *dates +n 和 *(dates +n) 的值不同（如 dates[0]=1, dates[2]=6）
//     b) 重新运行，观察 wrong 和 right 的值是否不同，理解优先级问题
// 
//  4. 拓展思考：
//     - 如果指针类型是 int*（占4字节），指针 +1 会跳多少字节？
//     - 数组名作为函数参数时，为什么退化为指针？（提示：数组名是首地址）
//     - 对比指针表示法和数组表示法的编译结果，思考编译器如何处理
// 
//  5. 调试技巧：
//     - 用 printf 打印指针地址时，%p 自动显示十六进制，观察地址变化
//     - 遇到 *ptr +n 和 *(ptr +n) 混淆时，用括号强制改变优先级
// ------------------------------

// 关键区别总结（初学者必看！）：
//  1. 数组名是常量指针 → 不能赋值（如 dates = pti 会报错）
//  2. 指针 +n 的步长由类型决定 → short* 跳 2，double* 跳 8
//  3. *ptr +n ≠ *(ptr +n) → * 的优先级高于 +，前者是“首元素值 +n”，后者是“第n个元素值”
//  4. 数组表示法是语法糖 → 编译器自动转换为指针表示法


/*
=== 指针 +n 的地址变化 ===
index      short 指针      double 指针   
0          0x7ffeefbff8d0  0x7ffeefbff8a0
1          0x7ffeefbff8d2  0x7ffeefbff8a8
2          0x7ffeefbff8d4  0x7ffeefbff8b0
3          0x7ffeefbff8d6  0x7ffeefbff8b8

=== 数组表示法 vs 指针表示法 ===
index      数组表示    指针表示   
0          1          1         
1          2          2         
2          3          3         
3          4          4         

=== 易错点：*ptr +n vs *(ptr +n) ===
*(dates + 2) = 3
*dates + 2 = 3
*(dates + 3) = 4
*dates + 3 = 4
*/