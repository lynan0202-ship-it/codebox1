// ------------------------------
// 题干：a. 设计一个函数，接受struct gas类型的参数。假设传入的结构包含distance和gals信息。该函数为mpg成员计算正确的值（mpg = distance / gals），并把值返回该结构。
// 知识要点：
//  1. 结构体的定义与成员访问（使用.操作符）
//  2. 函数的参数传递（结构体的“值传递”，函数内操作的是结构体拷贝）
//  3. 函数返回结构体类型的值
// 总体逻辑：
//  1. 定义struct gas结构体，包含distance（距离）、gals（汽油加仑数）、mpg（每加仑英里数）
//  2. 写函数calculateMPG_a，接收struct gas类型参数，计算mpg并赋值给该结构体拷贝的mpg成员，再返回这个拷贝
//  3. main中定义结构体变量，初始化distance和gals，调用函数后接收返回的结构体，打印结果
#include <stdio.h>

// 定义结构体类型struct gas
struct gas {
    float distance;  // 行驶的距离（英里）
    float gals;      // 消耗的汽油量（加仑）
    float mpg;       // 每加仑能行驶的英里数（distance / gals）
};

// 函数：计算mpg并返回包含该值的结构体（值传递，操作的是结构体拷贝）
struct gas calculateMPG_a(struct gas car) {
    // 计算每加仑英里数：距离 ÷ 汽油量
    car.mpg = car.distance / car.gals;
    return car;  // 返回修改后的结构体拷贝
}

int main() {
    // 定义并初始化结构体变量myCar，mpg先设为0.0（后续计算）
    struct gas myCar = {300.0, 15.0, 0.0};
    
    // 调用函数，传入myCar的拷贝，接收返回的结构体
    struct gas resultCar = calculateMPG_a(myCar);
    
    // 打印结果：距离、汽油量、计算出的mpg
    printf("Distance: %.1f miles\n", resultCar.distance);
    printf("Gallons: %.1f gals\n", resultCar.gals);
    printf("MPG: %.1f miles per gallon\n", resultCar.mpg);
    
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：用C编译器（如gcc）编译代码（命令如：gcc a.c -o a），然后运行可执行文件（如：./a）
//  2. 预期结果：输出“Distance: 300.0 miles”、“Gallons: 15.0 gals”、“MPG: 20.0 miles per gallon”（因为300 ÷ 15 = 20）
//  3. 检查点：重点看MPG是否是distance除以gals的结果
// 易错点提醒：
//  1. 忘记用.操作符访问结构体成员（比如写成car->mpg，而值传递的参数是结构体变量，不是指针）
//  2. 忽略“gals为0会导致除法错误”（题目假设gals有效，所以暂不处理）
// 拓展思考：
//  1. 若要计算多辆车的MPG，如何修改？可以定义结构体数组，用循环调用函数处理每个元素
//  2. 若distance或gals是负数，怎么优化？可添加判断（如if (car.gals > 0)），避免非法除法


