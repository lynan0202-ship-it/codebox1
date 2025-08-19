// ------------------------------
// 题干：2. 下面的程序会打印什么？  
// #include <stdio.h>  
// int main(void) {  
//     char note[] = "See you at the snack bar.";  
//     char *ptr;  
//     ptr = note;  
//     puts(ptr);  
//     puts(++ptr);  
//     note[7] = '\0';  
//     puts(note);  
//     puts(++ptr);  
//     return 0;  
// }  
// 知识要点：  
//  1. 指针操作：指针自增（++ptr）会移动到下一个字符  
//  2. 字符串终止符：修改 note[7] 为 '\0' 会截断字符串  
//  3. puts 输出：从指针位置开始，直到遇到 '\0'  
// 总体逻辑：  
//  1. 逐步分析指针位置和字符串内容的变化，模拟每一步输出  
#include <stdio.h>

int main(void) {
    char note[] = "See you at the snack bar.";  
    char *ptr = note; // ptr 指向 note[0]（'S'）  

    puts(ptr); // 输出：See you at the snack bar.（从 note[0] 开始）  
    puts(++ptr); // ptr 移到 note[1]（'e'），输出：ee you at the snack bar.  

    note[7] = '\0'; // 将 note[7]（原空格）设为 '\0'，字符串截断为 "See you"  

    puts(note); // 从 note[0] 开始，到 '\0' 结束，输出：See you  
    puts(++ptr); // ptr 原本在 note[1]，++后移到 note[2]（'e'），输出：e you  

    return 0;  
}  

// 测试验证方案：  
//  1. 运行：直接编译执行，观察四行输出是否符合分析  
//  2. 预期输出：  
//     See you at the snack bar.  
//     ee you at the snack bar.  
//     See you  
//     e you  
//  3. 检查点：重点看截断后的输出和指针移动的效果  
// 易错点提醒：  
//  1. 容易算错指针位置（比如 ++ptr 后指向哪里）  
//  2. 忘记字符串索引从 0 开始，导致 note[7] 的位置判断错误  
// 拓展思考：  
//  1. 如果把 note[7] = '\0' 改成 note[6] = '\0'，输出会怎么变？  