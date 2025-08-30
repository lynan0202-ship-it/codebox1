// ------------------------------
// 题干：编写一个名为transform()的函数，接受4个参数：内含double类型数据的源数组名、内含double类型数据的目标数组、一个表示数组元素个数的int类型参数、函数名（或等价的函数指针）。transform()函数应把指定函数应用于源数组中的每个元素，并把返回值储存在目标数组中。例如：transform(source, target, 100, sin); 该声明会把target[0]设置为sin(source[0])，等等，共有100个元素。在一个程序中调用transform()4次，以测试该函数。分别使用math.h函数库中的两个函数以及自定义的两个函数作为参数。
// 知识要点：
//  1. 函数指针的使用（指向“接受double参数、返回double值”的函数）
//  2. 数组作为函数参数（数组名退化为指针，传递首元素地址）
//  3. 数学库函数的调用与编译链接（需包含math.h并加-lm参数）
//  4. 自定义函数的编写与传递（函数名可作为函数指针使用）
// 总体逻辑：
//  1. 定义transform函数，遍历源数组，对每个元素调用传入的函数指针，结果存入目标数组
//  2. 在main函数中初始化源数组（值为0.0到9.0）
//  3. 四次调用transform，分别使用sin、cos（数学库函数）和两个自定义函数（平方、立方）
//  4. 每次调用后输出目标数组结果，验证转换正确性
#include <stdio.h>
#include <math.h> // 包含sin、cos等数学函数

// transform函数：将func应用到source每个元素，结果存到target
void transform(double source[], double target[], int n, double (*func)(double)) {
    for (int i = 0; i < n; i++) {
        target[i] = func(source[i]); // 调用传入的函数处理源元素，存入目标数组
    }
}

// 自定义函数：计算平方
double square(double x) {
    return x * x;
}

// 自定义函数：计算立方
double cube(double x) {
    return x * x * x;
}

int main() {
    const int ARR_SIZE = 10; // 数组大小，测试10个元素
    double source[ARR_SIZE]; // 源数组
    double target[ARR_SIZE]; // 目标数组

    // 初始化源数组：source[0]=0.0, source[1]=1.0, ..., source[9]=9.0
    for (int i = 0; i < ARR_SIZE; i++) {
        source[i] = (double)i;
    }

    // 第一次调用：使用sin函数
    transform(source, target, ARR_SIZE, sin);
    printf("应用sin函数的结果：\n");
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("sin(%.1f) = %.4f\n", source[i], target[i]);
    }

    // 第二次调用：使用cos函数
    transform(source, target, ARR_SIZE, cos);
    printf("\n应用cos函数的结果：\n");
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("cos(%.1f) = %.4f\n", source[i], target[i]);
    }

    // 第三次调用：使用自定义square函数
    transform(source, target, ARR_SIZE, square);
    printf("\n应用square函数的结果：\n");
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("square(%.1f) = %.1f\n", source[i], target[i]);
    }

    // 第四次调用：使用自定义cube函数
    transform(source, target, ARR_SIZE, cube);
    printf("\n应用cube函数的结果：\n");
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("cube(%.1f) = %.1f\n", source[i], target[i]);
    }

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：使用GCC编译（需链接数学库），命令为 `gcc transform_test.c -o transform_test -lm`，然后运行 `./transform_test`。
//  2. 预期结果：程序输出四组结果，分别是sin、cos、平方、立方函数作用于0.0~9.0的计算值。例如sin(0.0)输出0.0000，sin(1.0)输出约0.8415；square(2.0)输出4.0等。
//  3. 检查点：查看每组输出的数值是否与对应数学函数或自定义函数的计算结果一致（如cube(3.0)应输出27.0）。
// 易错点提醒：
//  1. 编译时忘记添加 `-lm` 参数，导致sin、cos等数学函数未定义的错误。
//  2. 函数指针的类型写错（如把 `double (*func)(double)` 写成其他形式），导致参数不匹配报错。
//  3. 源数组和目标数组的大小不一致，或循环次数`n`设置错误，导致数组越界。
// 拓展思考：
//  1. 如果要让transform处理多参数函数（如`pow(x, y)`），如何修改？可定义接受多参数的函数指针（如`double (*func)(double, double)`），并在transform中增加参数传递第二个参数。
//  2. 如何让transform支持不同类型的数组（如int数组）？可使用`void*`实现泛型，或为不同类型编写专用的transform函数（C语言可通过宏模拟重载）。