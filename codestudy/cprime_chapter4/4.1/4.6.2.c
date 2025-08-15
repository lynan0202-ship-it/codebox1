/*
以下用生活场景类比 + 代码示例，给 C 语言初学者解释这段内容，帮你快速理解 “类型可移植性” 核心逻辑：
1. 先理解「sizeof 返回值的 “混乱” 问题」
假设你想做个 “给朋友寄礼物” 程序，需要知道 “礼物盒（数据类型）占多大空间（字节）”，用 sizeof 能查。
但早期 C 语言没统一规定 sizeof 返回啥整数类型：
在 A 编译器里，sizeof(int) 返回值是 unsigned int 类型（用 %u 打印）
在 B 编译器里，可能变成 unsigned long 类型（得用 %lu 打印）
如果代码里写死 printf("%u", sizeof(int))，换编译器就可能报错 / 输出乱码 —— 这就是可移植性问题：
一套代码，在不同环境表现不一致。
*/


/*
如果换到要求返回 unsigned long 的环境，%u 格式就不匹配，程序会出问题。
2. 解决思路：用「标准类型 + 修饰符」统一写法
为了让代码在不同环境都能跑（可移植），C 语言搞了两个 “小工具”：
① size_t 类型（解决 sizeof 返回值的类型统一）
C 标准通过 stddef.h 头文件（包含 stdio.h 时会自动引入），定义了 size_t 类型，专门用来存 sizeof 的返回值。
不管编译器底层用 unsigned int 还是 unsigned long，size_t 都会自动适配成正确类型
打印时，用 z 修饰符（比如 %zu），告诉 printf：“按 size_t 类型的规则打印”
② ptrdiff_t 类型（解决 “指针相减差值” 的类型统一）
如果做 “指针相减”（比如算数组里两个元素间隔），差值的类型也会因环境不同乱变。C 又定义了 ptrdiff_t 类型存这个差值，用 t 修饰符（比如 %td）打印。
*/
#include <stdio.h>
int main() {
    // 假设当前环境返回 unsigned int，用 %u 能正常打印
    printf("int 占 %u 字节\n", sizeof(int));
    
    // 正确写法：用 size_t 存 sizeof 返回值，用 %zu 打印
    size_t int_size = sizeof(int);
    printf("int 占 %zu 字节（可移植写法）\n", int_size);

    // 指针相减示例：算数组元素间隔
    int arr[] = {10, 20, 30};
    int *p1 = &arr[0], *p2 = &arr[2];
    // ptrdiff_t 存指针差值，%td 打印
    ptrdiff_t diff = p2 - p1;
    printf("两个指针间隔 %td 个元素（可移植写法）\n", diff);
    return 0;
}