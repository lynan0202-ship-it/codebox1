// ------------------------------  
// 题干：完成make_array和show_array函数，make_array分配数组并初始化，show_array按行打印（每行8个）  
// 知识要点：  
//  1. 动态内存分配（malloc）与释放（free）  
//  2. 函数返回指针（动态数组的地址）  
//  3. 数组遍历与格式化输出  
// 总体逻辑：  
//  1. make_array：分配size个int的空间，每个元素设为value，返回指针  
//  2. show_array：遍历数组，每8个元素换行输出  
//  3. 主函数：循环输入size和value，调用函数，最后释放内存  
#include <stdio.h>  
#include <stdlib.h> // 包含malloc、free  

// 创建动态数组：size个元素，每个初始化为value  
int *make_array(int size, int value) {  
    int *arr = (int *)malloc(size * sizeof(int)); // 分配内存  
    if (arr == NULL) { // 检查分配失败（简单处理，实际可增强）  
        printf("Memory allocation failed!\n");  
        exit(1); // 直接退出，实际项目需更优雅处理  
    }  
    for (int i = 0; i < size; i++) {  
        arr[i] = value; // 初始化每个元素  
    }  
    return arr; // 返回动态数组的指针  
}  

// 打印数组：elem个元素，每行最多8个  
void show_array(const int *arr, int elem) {  
    for (int i = 0; i < elem; i++) {  
        printf("%d ", arr[i]);  
        if ((i + 1) % 8 == 0) { // 每8个元素换行  
            printf("\n");  
        }  
    }  
    if (elem % 8 != 0) { // 最后一行不足8个，补换行  
        printf("\n");  
    }  
}  

int main(void) {  
    int *pa;  
    int size;  
    int value;  

    printf("Enter the number of elements: ");  
    while (scanf("%d", &size) == 1 && size > 0) { // 输入有效且size>0  
        printf("Enter the initialization value: ");  
        scanf("%d", &value);  

        pa = make_array(size, value); // 创建动态数组  
        show_array(pa, size);         // 打印数组  
        free(pa); // 释放内存，避免泄漏  

        printf("Enter the number of elements (<1 to quit): ");  
    }  

    printf("Done.\n");  
    return 0;  
}  

// 测试验证方案：  
//  1. 怎么运行：编译后运行（如 `gcc 8.c -o 8 && ./8`），输入示例：  
//     → 输入 `5` → 输入 `10` → 输出5个10，一行显示（5<8，换行）  
//     → 输入 `10` → 输入 `2` → 输出两行，每行5个2  
//     → 输入 `0` → 退出  
//  2. 预期结果：  
//     - 数组元素全部是初始化的值，每行最多8个  
//     - 内存正常释放，无泄漏（可配合工具检查，如valgrind）  
//  3. 检查点：  
//     - make_array是否正确分配并初始化？（输出值是否一致）  
//     - show_array是否每行8个？（如10个元素，前8个一行，后2个一行）  
// 易错点提醒：  
//  1. malloc后未检查NULL：若内存不足，程序可能崩溃  
//  2. free忘记调用：导致内存泄漏，长期运行会占满内存  
//  3. show_array的换行逻辑错误：`(i+1)%8==0` 写成 `i%8==0`，导致第一行从第0个开始，多一个元素  
// 拓展思考：  
//  1. 若要支持二维数组动态分配，如何修改make_array？（返回int**，嵌套malloc）  
//  2. show_array如何处理更大的数组？（如每行10个，可添加参数控制每行数量）  
// 对比说明：  
//  动态数组 vs 静态数组：  
//  - 静态数组：大小编译时确定，存在栈上，超出范围易栈溢出  
//  - 动态数组：大小运行时确定，存在堆上，更灵活但需手动释放