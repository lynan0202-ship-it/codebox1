
// ------------------------------
// 题干：b. 设计一个函数，接受struct gas类型的参数。假设传入的结构包含distance和gals信息。该函数为mpg成员计算正确的值（mpg = distance / gals），并把该值赋给合适的成员。
// 知识要点：
//  1. 结构体的指针传递（函数参数为结构体指针）
//  2. 结构体指针访问成员（使用->操作符）
//  3. 通过指针修改原结构体的成员（函数内直接修改主函数中的变量）
// 总体逻辑：
//  1. 定义与a相同的struct gas结构体
//  2. 写函数calculateMPG_b，接收struct gas *类型参数（结构体指针），通过指针访问并修改原结构体的mpg成员
//  3. main中定义结构体变量，初始化distance和gals，传递其地址给函数，之后打印修改后的成员
#include <stdio.h>

struct gas {
    float distance;
    float gals;
    float mpg;
};

// 函数：计算mpg并直接修改原结构体的成员（指针传递，操作原变量）
void calculateMPG_b(struct gas *carPtr) {
    // 通过指针访问结构体成员，计算并赋值mpg
    carPtr->mpg = carPtr->distance / carPtr->gals;
    // 无需返回，因为直接修改了原结构体的内存
}

int main() {
    // 定义并初始化结构体变量myCar，mpg初始为0.0
    struct gas myCar = {250.0, 10.0, 0.0};
    
    // 调用函数，传递myCar的地址（&myCar），函数内直接修改myCar
    calculateMPG_b(&myCar);
    
    // 打印myCar的成员（此时mpg已被修改）
    printf("Distance: %.1f miles\n", myCar.distance);
    printf("Gallons: %.1f gals\n", myCar.gals);
    printf("MPG: %.1f miles per gallon\n", myCar.mpg);
    
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：编译代码（如：gcc b.c -o b），运行可执行文件（如：./b）
//  2. 预期结果：输出“Distance: 250.0 miles”、“Gallons: 10.0 gals”、“MPG: 25.0 miles per gallon”（250 ÷ 10 = 25）
//  3. 检查点：查看mpg是否正确，且原结构体myCar的mpg确实被修改了
// 易错点提醒：
//  1. 混淆.和->操作符（结构体变量用.，结构体指针用->）
//  2. 调用函数时忘记加&，导致传递结构体拷贝而非地址（函数内修改拷贝，不影响原变量）
// 拓展思考：
//  1. 若要同时修改多个结构体成员，指针传递是否方便？很方便，因为可直接通过指针访问所有成员
//  2. 对比a和b的传递方式：
//     - a是“值传递”：函数内操作结构体拷贝，修改后需返回拷贝，原变量不受影响。
//     - b是“指针传递”：函数内通过地址直接操作原变量，无需返回，修改会直接影响原变量。当需要修改原变量时，指针传递更高效（无需拷贝整个结构体）。