#include <stdio.h>
// 用于 strlen 函数
#include <string.h>  
// 题目 c 的宏定义
#define Q "His Hamlet was funny without being vulgar."  

int main(void) {
    // ========== 题目 a 验证 ==========
    // 科学计数法：2.345×10² = 234.5
    double a_val = 2.345e2;  
    // %2.2f：字段宽度 2（实际会被内容撑大），保留 2 位小数
    printf("a. 输出结果：");
    printf("He sold the painting for $%2.2f.\n", a_val);  
    // 解释：234.5 按 %.2f 格式会补 0 到两位小数 → 234.50


    // ========== 题目 b 验证 ==========
    // 字符 'H'
    char b1 = 'H';  
    // ASCII 105 → 字符 'i'（ASCII 表中 105 对应 'i'）
    int b2 = 105;   
    // 八进制转义：\41 是 ASCII 33 → 字符 '!'
    char b3 = '\41';  

    printf("b. 输出结果：");
    // %c 逐个输出字符：'H' + 'i' + '!' → "Hi!"
    printf("%c%c%c\n", b1, b2, b3);  


    // ========== 题目 c 验证 ==========
    printf("c. 输出结果：\n");
    // %s 输出宏 Q 的字符串；strlen(Q) 计算字符串长度（不含 '\0'）
    printf("%s\nhas %d characters. \"Q\".\n", Q, strlen(Q));  
    // 解释：Q 字符串长度是 46（数字符个数，包括空格、标点）


    // ========== 题目 d 验证 ==========
    // 待比较的两个数值
    double d_val = 1201.0;  

    printf("d. 输出结果：");
    // %2.2e：科学计数法，保留 2 位小数 → 1.20e+03
    // %2.2f：浮点数，保留 2 位小数 → 1201.00
    printf("Is %2.2e the same as %2.2f?\n", d_val, d_val);  


    printf("3. 输出包含双引号的字符串 Q：\n");
    // %s 输出带双引号的字符串，strlen(Q) 计算长度（含转义后的字符）
    printf("%s\nhas %d characters.\n", Q, strlen(Q)); 


    return 0;
}
/*
a. 输出结果：He sold the painting for $234.50.
b. 输出结果：Hi!
c. 输出结果：
His Hamlet was funny without being vulgar.
has 42 characters.
d. 输出结果：Is 1.20e+003 the same as 1201.00?
*/