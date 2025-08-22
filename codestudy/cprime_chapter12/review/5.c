// ------------------------------
// 题干：extern关键字有什么用途？
// 知识要点：
//  1. 声明外部变量：引用其他文件的全局变量（跨文件共享） 
//  2. 声明外部函数：引用其他文件的函数（跨文件调用，函数默认extern，可省略） 
//  3. 函数内声明extern局部变量：引用全局变量（少见，实际和全局变量是同一个） 
// 总体逻辑：
//  1. 创建两个文件：main.c（主文件）和 other.c（定义变量和函数） 
//  2. other.c 定义全局变量 g_var 和函数 other_func 
//  3. main.c 用extern声明并使用它们 
// 【编译命令】：gcc main.c other.c -o test （必须同时编译两个文件）

// ------ other.c 文件内容 ------
/*
int g_var = 1000;  // 定义全局变量（外部链接）

void other_func() {  // 函数默认extern（外部链接，可跨文件调用）
    printf("other_func 被调用，修改g_var\n");
    g_var = 2000;
}
*/

// ------ main.c 文件内容 ------
#include <stdio.h>

extern int g_var;        // 声明other.c的全局变量（跨文件引用）
extern void other_func();// 声明other.c的函数（extern可省略，写出来更清晰）

int main() {
    printf("main中访问g_var：%d\n", g_var);  // 输出1000（跨文件访问成功）
    other_func();                            // 调用other.c的函数，修改g_var
    printf("调用后，g_var：%d\n", g_var);    // 输出2000（跨文件修改成功）
    
    // 函数内声明extern局部变量（实际引用的是全局g_var，和上面的g_var是同一个）
    extern int g_var;  
    g_var = 3000;
    printf("函数内extern修改后：%d\n", g_var);  // 输出3000
    
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：写好两个文件，执行 gcc main.c other.c -o test && ./test 
//  2. 预期结果：依次输出 1000 → other_func被调用 → 2000 → 3000 
//  3. 检查点：能跨文件访问变量和函数，证明extern实现了“跨文件引用” 
// 易错点提醒：
//  1. 把“声明”当“定义”：extern int g_var是声明（不分配空间），int g_var=...是定义（分配空间），不能重复定义 
//  2. 忘记编译other.c，导致“g_var未定义”的链接错误 
// 拓展思考：
//  1. 如果多个文件都用extern声明同名变量，会冲突吗？不会，因为extern只是声明，定义只有一个 
// 对比说明：
//  extern声明 vs 变量定义： 
//  - extern int g_var：告诉编译器“变量存在，链接时找定义”（声明） 
//  - int g_var = 100;：分配空间并赋值（定义） 
//  函数的extern： 
//  - 函数默认是extern（外部链接），声明时可省略extern，但写extern更清晰（尤其跨文件时） 