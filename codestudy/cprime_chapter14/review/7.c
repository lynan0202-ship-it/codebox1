// ------------------------------
// 题干：考虑下面程序片段：
// struct name {
//     char first[20];
//     char last[20];
// };
// 
// struct bem {
//     int limbs;
//     struct name title;
//     char type[30];
// };
// struct bem *pb;
// struct bem deb = {
//     6,
//     { "Berbnazel", "Gwolkapwolk" },
//     "Arcturan"
// };
// pb = &deb;
// a. 下面的语句分别打印什么？
// printf("%d\n", deb.limbs);
// printf("%s\n", pb->type);
// printf("%s\n", pb->type + 2);
// b. 如何用结构表示法（两种方法）表示"Gwolkapwolk"？
// c. 编写一个函数，以 bem 结构的地址作为参数，并以下面的形式输出结构的内容（假定结构模板在一个名为 starfolk.h 的头文件中）：
// Berbnazel Gwolkapwolk is a 6-limbed Arcturan.
// 知识要点：
//  1. 结构体的定义与嵌套初始化（结构体中包含另一个结构体）
//  2. 结构体成员访问：`.` 操作符（直接访问结构体变量的成员）和 `->` 操作符（通过指针访问结构体成员）
//  3. 字符串数组的指针操作（通过指针偏移访问子字符串）
//  4. 函数参数传递：结构体指针作为参数，实现对结构体的间接访问与操作
// 总体逻辑：
//  1. 定义结构体并初始化变量 `deb`，让指针 `pb` 指向 `deb`
//  2. 执行问题a的三个 `printf`，分别测试结构体成员访问和字符串偏移效果
//  3. 用两种结构表示法展示问题b中 `"Gwolkapwolk"` 的访问方式
//  4. 编写 `printBem` 函数（接收结构体指针），按指定格式输出内容，并在 `main` 中调用验证问题c
#include <stdio.h>
#include "starfolk.h"  // 包含结构体定义的头文件

// 问题c：函数接收bem结构的地址，按格式输出内容
void printBem(struct bem *pbem) {
    // 通过指针访问嵌套结构体的成员（first、last）和普通成员（limbs、type），拼接成指定格式输出
    printf("%s %s is a %d-limbed %s.\n", 
           pbem->title.first,  // 访问name结构体里的first成员
           pbem->title.last,   // 访问name结构体里的last成员
           pbem->limbs,        // 访问肢体数量limbs
           pbem->type);        // 访问种族类型type
}

int main() {
    // 初始化struct bem类型的变量deb：limbs为6，title的first是"Berbnazel"、last是"Gwolkapwolk"，type是"Arcturan"
    struct bem deb = {
        6,
        { "Berbnazel", "Gwolkapwolk" },
        "Arcturan"
    };
    struct bem *pb = &deb;  // 让指针pb指向deb的地址，后续通过pb间接访问deb的成员

    // 问题a：测试三个printf语句
    printf("问题a - 第一个打印（deb.limbs）：");
    printf("%d\n", deb.limbs);  // 用`.`操作符直接访问deb的limbs成员，结果为6

    printf("问题a - 第二个打印（pb->type）：");
    printf("%s\n", pb->type);  // 用`->`操作符通过指针pb访问type成员，结果为"Arcturan"

    printf("问题a - 第三个打印（pb->type + 2）：");
    // pb->type是字符串"Arcturan"，+2表示指针向后偏移2个字符（跳过前两个字符），从第三个字符（索引2）开始输出，结果为"cturan"
    printf("%s\n", pb->type + 2);

    // 问题b：两种结构表示法访问"Gwolkapwolk"
    printf("问题b - 第一种表示（deb.title.last）：");
    printf("%s\n", deb.title.last);  // 用`.`操作符，先访问deb的title，再访问title的last

    printf("问题b - 第二种表示（pb->title.last）：");
    printf("%s\n", pb->title.last);  // 用`->`操作符，通过pb访问title，再访问title的last

    // 问题c：调用printBem函数，传递deb的地址
    printf("问题c - 调用printBem(&deb)的输出：");
    printBem(&deb);  // 传递deb的地址，函数内部通过指针访问并输出指定格式内容

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：将`starfolk.h`和`main.c`放在同一文件夹，打开终端，用GCC编译：`gcc main.c -o bem_test`，然后运行`./bem_test`
//  2. 预期结果：
//     问题a - 第一个打印（deb.limbs）：6
//     问题a - 第二个打印（pb->type）：Arcturan
//     问题a - 第三个打印（pb->type + 2）：cturan
//     问题b - 第一种表示（deb.title.last）：Gwolkapwolk
//     问题b - 第二种表示（pb->title.last）：Gwolkapwolk
//     问题c - 调用printBem(&deb)的输出：Berbnazel Gwolkapwolk is a 6-limbed Arcturan.
//  3. 检查点：每个输出行是否与预期一致，重点验证结构体成员访问、指针偏移、函数输出格式的正确性
// 易错点提醒：
//  1. 混淆`.`和`->`的用法：结构体**变量**用`.`访问成员，结构体**指针**用`->`访问成员（比如`deb`是变量，用`deb.limbs`；`pb`是指针，用`pb->type`）
//  2. 字符串指针偏移的理解：`pb->type + 2`是将字符串指针向后移动2个字符，输出从该位置开始的子串，要注意数组索引从0开始
// 拓展思考：
//  1. 如果结构体里的`char`数组改为`char*`（动态分配字符串），代码需要注意什么？——需用`malloc`分配内存，使用后用`free`释放，否则会内存泄漏；初始化时要给指针赋值有效地址
//  2. 若要让`printBem`函数能修改结构体成员，应该怎么做？——在函数内对`pbem`指向的成员赋值（比如`pbem->limbs = 8;`），因为传递的是地址，修改会影响原变量
//  3. 对比“值传递结构体”和“指针传递结构体”：值传递是拷贝整个结构体，函数内修改不影响原变量；指针传递是传地址，修改会影响原变量，且更节省内存（无需拷贝大结构体）