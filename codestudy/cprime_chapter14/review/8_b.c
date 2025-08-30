// ------------------------------
// 题干：b. 用pt标识符标识willie结构的born成员。
// 知识要点：
//  1. 结构体指针的使用（struct bard * 类型的指针）
//  2. 通过指针访问结构体成员（-> 操作符）
//  3. 取地址操作（& 符号，获取变量的地址）
// 总体逻辑：
//  1. 定义结构体类型 struct fullname 和 struct bard
//  2. 声明 struct bard 类型的变量 willie，并声明指向它的指针 pt
//  3. 通过 pt 指针访问 willie 的 born 成员
#include <stdio.h>

struct fullname {
    char fname[20];
    char lname[20];
};

struct bard {
    struct fullname name;
    int born;
    int died;
};

int main() {
    // 声明 struct bard 类型的变量 willie
    struct bard willie;
    // 声明指向 struct bard 的指针 pt，并让它指向 willie（取 willie 的地址）
    struct bard *pt = &willie;

    // 用 pt 标识 willie 的 born 成员，给 born 赋值 1950
    pt->born = 1950;

    // 打印 pt->born 的值，验证是否正确
    printf("pt->born = %d\n", pt->born);

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：用 C 编译器编译后运行可执行文件。
//  2. 预期结果：输出 “pt->born = 1950”。
//  3. 检查点：确认输出的数值是 1950，说明通过指针正确访问了 born 成员。
// 易错点提醒：
//  1. 容易混淆 -> 和 . 操作符，记住指针用 ->，结构体变量用 .。
//  2. 忘记给指针赋值（让 pt 指向 willie），导致指针悬空。
// 拓展思考：
//  1. 除了 pt->born，还可以用 (*pt).born 来访问，试试这两种方式有什么区别（写法不同，效果一样）。
// ------------------------------