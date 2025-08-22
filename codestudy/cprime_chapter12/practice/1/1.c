// ------------------------------
// 题干：不使用全局变量，重写程序清单12.4（原程序用全局变量units，现通过指针传递实现变量修改）
// 知识要点：
//  1. 函数的指针传递（通过地址修改主函数变量的值）
//  2. while循环的条件判断与流程控制
//  3. 输入输出函数的基本使用（scanf、printf）
// 总体逻辑：
//  1. 主函数定义局部变量units，记录用户输入的数值
//  2. 通过while循环判断units是否为56，若不是则调用critic函数，并传递units的地址
//  3. critic函数通过指针接收units的地址，修改其值（实现跨函数修改变量，替代全局变量）
#include <stdio.h>

// 声明critic函数：参数是int指针，用于修改主函数的units
void critic(int *p_units);

int main(void) {
    int units;  // 局部变量，替代原全局变量
    
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);  // 读取用户输入到units
    
    // 循环判断：只要units不等于56，就调用critic修改它
    while (units != 56) {
        critic(&units);  // 传递units的地址，让critic能修改它
    }
    
    printf("You must have looked it up!\n");
    return 0;
}

// critic函数：接收units的指针，提示用户并重新读取值（修改主函数的units）
void critic(int *p_units) {
    printf("No luck, my friend. Try again.\n");
    scanf("%d", p_units);  // 直接写p_units，因为它本身就是地址（等价于&units在main里的作用）
    // 解释：*p_units是units的值，但scanf需要地址，所以这里p_units已经是地址，直接传即可
}

// 测试验证方案：
//  1. 怎么运行：编译代码（如 `gcc no_global.c -o no_global`），然后运行./no_global  
//  2. 预期结果：  
//     - 第一次输入非56的数（比如10），程序输出“No luck...Try again.”，并等待重新输入  
//     - 直到输入56，退出循环，输出“You must have looked it up!”  
//  3. 检查点：  
//     - 输入非56时是否进入循环，critic是否能修改units的值（比如输入10后，下一次循环判断的是新值）  
//     - 输入56后是否正确退出循环  
// 易错点提醒：  
//  1. 调用critic时忘记写&units，写成critic(units)：这样传的是值，critic无法修改main的units，会导致死循环！  
//  2. critic函数里写`scanf("%d", &p_units);`：p_units已经是地址，加&会变成指针的地址，导致数据存错位置（逻辑错误）  
// 拓展思考：  
//  1. 如果需要修改多个变量（比如同时改units和另一个变量），可以传结构体指针：  
//     → 定义`struct Data { int units; float price; };`，主函数传`&data`，critic用`struct Data *p`接收，通过`p->units`修改  
// 对比说明：  
//  指针传递 vs 值传递：  
//  - 值传递：函数里的形参是实参的拷贝，修改形参不影响实参（比如`void func(int x)`，main传a，func里x变化和a无关）  
//  - 指针传递：函数里的形参是实参的地址，通过`*形参`可以修改实参的值（本题核心用法，替代全局变量的跨函数修改）  
//  为什么不用全局变量？  
//  - 全局变量会让代码耦合度高，多个函数随意修改容易出错；指针传递更明确，能看到数据是被哪个函数修改的，可读性更好