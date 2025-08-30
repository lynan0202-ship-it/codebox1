// ------------------------------
// 题干：声明一个指向函数的指针，该函数返回指向char的指针，接受一个指向char的指针和一个char类型的值。
// 知识要点：
//  1. 函数指针的声明语法（如何声明指向特定返回值、参数的函数的指针）
//  2. 函数签名的匹配（指针指向的函数需与声明的返回值、参数列表完全一致）
// 总体逻辑：
//  1. 定义一个符合“返回char*、接收char*和char”的示例函数，用于测试
//  2. 声明该类型的函数指针
//  3. 在main中让指针指向示例函数，通过指针调用函数并验证结果
#include <stdio.h>
#include <string.h> // 用于strchr函数（查找字符在字符串中的位置）

// 示例函数：在字符串s中查找字符c，返回首次出现c的位置（char*类型）
char* findChar(char* s, char c) {
    return strchr(s, c); // strchr会返回s中首次出现c的位置的指针，无则返回NULL
}

int main() {
    // 声明函数指针：指向“返回char*，参数为char*和char”的函数
    char* (*funcPtr)(char*, char);
    
    // 让函数指针指向findChar函数
    funcPtr = findChar;
    
    // 测试：在"hello"中查找字符'l'
    char testStr[] = "hello";
    char targetChar = 'l';
    char* result = funcPtr(testStr, targetChar); // 通过函数指针调用函数
    
    // 打印结果
    if (result != NULL) {
        printf("找到字符'%c'，从该位置开始的子串：%s\n", targetChar, result);
    } else {
        printf("未找到字符'%c'\n", targetChar);
    }
    
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：用C编译器（如gcc）编译代码（例：gcc func_ptr_demo.c -o func_ptr_demo），然后运行可执行文件（例：./func_ptr_demo）
//  2. 预期结果：输出“找到字符'l'，从该位置开始的子串：llo”（因为"hello"中'l'首次出现在第2位，后续子串为"llo"）
//  3. 检查点：重点看输出的子串是否是目标字符首次出现位置后的字符串
// 易错点提醒：
//  1. 函数指针声明容易写错格式，比如漏写括号（如写成 char* *funcPtr(char*, char)，会变成返回char**的函数声明，而非函数指针）
//  2. 函数指针指向的函数，返回值和参数必须严格匹配，否则可能导致不可预期的错误
// 拓展思考：
//  1. 若要让函数指针指向不同功能但签名一致的函数（比如“替换字符”的函数），如何扩展？可定义另一个“返回char*、接收char*和char”的函数，然后让指针指向它
//  2. 函数指针常用于回调场景（如qsort的比较函数），尝试自定义一个数组，用函数指针实现不同的排序规则（如升序/降序）