// ------------------------------  
// 题干：考虑下面两行代码，就输出的结果而言有何异同：  
// int *p1 = (int *)malloc(100 * sizeof(int));  
// int *p1 = (int *)calloc(100, sizeof(int));  
// 知识要点：  
//  1. 动态内存分配（malloc/calloc的功能）  
//  2. 内存初始化差异（malloc不初始化，calloc清0）  
// 总体逻辑：  
//  1. 分别用malloc和calloc分配100个int的内存  
//  2. 打印前3个元素，对比初始化差异  
//  3. 释放内存避免泄漏  
#include <stdio.h>  
#include <stdlib.h> // 包含malloc/calloc/free  

int main() {  
    // malloc分配：内存值随机（未初始化）  
    int *p_malloc = (int *)malloc(100 * sizeof(int));  
    // calloc分配：内存值全为0（每个字节清0，int是4字节，所以整个int为0）  
    int *p_calloc = (int *)calloc(100, sizeof(int));  

    // 打印malloc的结果（随机值，每次运行可能不同）  
    printf("malloc分配的前3个值：%d, %d, %d\n", p_malloc[0], p_malloc[1], p_malloc[2]);  
    // 打印calloc的结果（固定为0）  
    printf("calloc分配的前3个值：%d, %d, %d\n", p_calloc[0], p_calloc[1], p_calloc[2]);  

    // 释放内存，避免泄漏  
    free(p_malloc);  
    free(p_calloc);  

    return 0;  
}  

// 测试验证方案：  
//  1. 怎么运行：gcc编译后运行（如 `gcc 6.c -o 6 && ./6`）  
//  2. 预期结果：  
//     - malloc行输出随机数（如 `1234, -5678, 9012`，每次不同）  
//     - calloc行输出 `0, 0, 0`  
//  3. 检查点：对比两者输出，看calloc是否清0  
// 易错点提醒：  
//  1. 忘记包含 `stdlib.h`，导致函数未定义  
//  2. 分配后忘记`free`，造成内存泄漏  
// 拓展思考：  
//  1. 如果分配`char`类型，calloc会把每个字符设为`'\0'`，试试修改代码为`char*`  
// 对比说明：  
//  malloc vs calloc：  
//  - 参数：malloc传总字节数，calloc传“元素个数 + 单个元素大小”  
//  - 初始化：malloc不初始化，calloc清0  
//  - 场景：calloc更适合数组初始化，malloc更灵活  