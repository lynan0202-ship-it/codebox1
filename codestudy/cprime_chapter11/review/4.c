// ------------------------------
// 题干：4. 下面的程序会打印什么？  
// #include <stdio.h>  
// #include <string.h>  
// int main(void) {  
//     char goldwyn[40] = "art of it all ";  
//     char samuel[40] = "I read p";  
//     const char *quote = "the way through.";  
//     strcat(goldwyn, quote);  
//     strcat(samuel, goldwyn);  
//     puts(samuel);  
//     return 0;  
// }  
// 知识要点：  
//  1. strcat 函数：拼接字符串（目标数组必须有足够空间，且以 '\0' 结尾）  
//  2. 数组拼接：注意源和目标的顺序，以及数组长度是否足够  
// 总体逻辑：  
//  1. 先拼接 goldwyn 和 quote，再拼接 samuel 和 goldwyn，最后输出 samuel  
#include <stdio.h>
#include <string.h> // 包含 strcat 函数

int main(void) {
    char goldwyn[40] = "art of it all "; // 末尾有空格，确保 '\0' 存在  
    char samuel[40] = "I read p";        // 末尾是 'p'，后续要拼接  
    const char *quote = "the way through.";  

    // 第一步：goldwyn = "art of it all " + "the way through." → "art of it all the way through."  
    strcat(goldwyn, quote);  

    // 第二步：samuel = "I read p" + "art of it all the way through." → "I read part of it all the way through."  
    strcat(samuel, goldwyn);  

    puts(samuel); // 输出拼接后的 samuel  

    return 0;  
}  

// 测试验证方案：  
//  1. 运行：编译后执行，观察输出内容  
//  2. 预期输出：I read part of it all the way through.  
//  3. 检查点：看 "p" 和 "art" 是否拼接成 "part"  
// 易错点提醒：  
//  1. strcat 的第一个参数必须是可修改的数组（不能是 const 指针）  
//  2. 容易忽略数组长度：如果 goldwyn 或 samuel 空间不足，会导致溢出（本题中 40 足够）  
// 拓展思考：  
//  1. 如果 goldwyn 初始值是 "art of it all"（末尾无空格），输出会变成 "I read partof it all the way through."，为什么？  
//  2. 尝试用 strncat 替代 strcat，避免缓冲区溢出风险  