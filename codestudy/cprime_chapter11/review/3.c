// ------------------------------
// 题干：3. 下面的程序会打印什么？  
// #include <stdio.h>  
// #include <string.h>  
// int main(void) {  
//     char food[] = "Yummy";  
//     char *ptr;  
//     ptr = food + strlen(food);  
//     while (--ptr >= food)  
//         puts(ptr);  
//     return 0;  
// }  
// 知识要点：  
//  1. strlen 函数：计算字符串长度（不含 '\0'）  
//  2. 指针运算：food + strlen(food) 指向 '\0' 的位置  
//  3. 逆序输出：通过指针自减，从末尾往开头遍历  
// 总体逻辑：  
//  1. 先定位到字符串末尾（'\0' 处），再逐步往前移动指针，每次输出子串  
#include <stdio.h>
#include <string.h> // 包含 strlen 函数

int main(void) {
    char food[] = "Yummy"; // 字符数组：'Y','u','m','m','y','\0'  
    char *ptr = food + strlen(food); // strlen(food)=5，ptr 指向 '\0'（索引5）  

    // 指针自减到 food 开头（索引0），每次输出从 ptr 开始的字符串  
    while (--ptr >= food) {  
        puts(ptr);  
    }  

    return 0;  
}  

// 测试验证方案：  
//  1. 运行：编译后执行，观察输出顺序  
//  2. 预期输出（逐行）：  
//     y  
//     my  
//     mmy  
//     ummy  
//     Yummy  
//  3. 检查点：看是否逆序输出每个字符的子串  
// 易错点提醒：  
//  1. 容易混淆 strlen 的返回值（不含 '\0'，所以 food + 5 指向 '\0'）  
//  2. while 循环的条件是 --ptr >= food，先自减再判断，所以第一次输出的是 'y'（索引4）  
// 拓展思考：  
//  1. 如果字符串是 "Hello"，输出会是什么？  
