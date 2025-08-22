// ------------------------------
// 题干：哪些类别的变量可以成为它所在函数的局部变量？
// 知识要点：
//  1. 自动局部变量（auto，默认，函数调用时创建，结束销毁，每次调用重新初始化）
//  2. 静态局部变量（static，程序运行期存在，函数结束后值保留，仅初始化一次）
// 总体逻辑：
//  1. 定义函数 func，内部定义 auto 变量和 static 变量 
//  2. 主函数多次调用 func，观察 auto 变量重置、static 变量累加的差异 
#include <stdio.h>

void func() {
    auto int auto_var = 0;  // auto修饰，每次调用重新赋值0（auto可省略，默认就是auto）
    static int static_var = 0;  // static修饰，仅第一次初始化，之后值保留
    
    auto_var++;  // 每次调用auto_var会回到0再+1，所以一直是1
    static_var++;  // 每次调用基于上次的值+1，持续累加
    
    printf("auto_var: %d, static_var: %d\n", auto_var, static_var);
}

int main() {
    printf("第一次调用 func：\n");
    func();  // 输出：auto_var:1, static_var:1
    printf("第二次调用 func：\n");
    func();  // 输出：auto_var:1, static_var:2
    printf("第三次调用 func：\n");
    func();  // 输出：auto_var:1, static_var:3
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：用gcc编译（gcc main.c -o test），运行./test 
//  2. 预期结果：三次调用分别输出 1,1；1,2；1,3 
//  3. 检查点：看static_var是否每次+1，auto_var是否一直是1 
// 易错点提醒：
//  1. 容易以为static局部变量是“全局可用”，其实它的作用域还是函数内部，只是值会保留 
// 拓展思考：
//  1. 如果在if语句的{}里定义static变量，多次进入if会怎样？比如在if里写static int x=0; x++，试试打印x 
// 对比说明：
//  auto局部变量 vs 静态局部变量： 
//  - 存储位置：auto存在栈里，static存在全局区 
//  - 初始化：auto每次调用都初始化，static只第一次初始化 
//  - 作用域：都只能在函数（或块）内部用，static的值能跨调用保留 