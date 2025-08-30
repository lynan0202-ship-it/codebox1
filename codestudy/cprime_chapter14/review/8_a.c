// ------------------------------
// 题干：

/*
struct fullname {
    char fname[20];
    char lname[20];
};
struct bard {
    struct fullname name;
    int born;
    int died;
};
struct bard willie;
struct bard *pt = &willie;
*/
//a. 用willie标识符标识willie结构的born成员。
// 知识要点：
//  1. 结构体的定义与嵌套（struct fullname 嵌套在 struct bard 中）
//  2. 结构体成员的访问（使用 . 操作符访问结构体中的成员）
// 总体逻辑：
//  1. 定义所需的结构体类型 struct fullname 和 struct bard
//  2. 声明 struct bard 类型的变量 willie
//  3. 访问 willie 的 born 成员（展示如何标识该成员）
#include <stdio.h>

// 定义 struct fullname，包含名（fname）和姓（lname）
struct fullname {
    char fname[20];
    char lname[20];
};

// 定义 struct bard，包含姓名（struct fullname 类型）、出生年份（born）、去世年份（died）
struct bard {
    struct fullname name;
    int born;
    int died;
};

int main() {
    // 声明 struct bard 类型的变量 willie
    struct bard willie;

    // 用 willie 标识其 born 成员，这里给 born 成员赋值 1900 作为示例
    willie.born = 1900;

    // 打印 born 成员的值，验证是否正确标识
    printf("willie.born = %d\n", willie.born);

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：使用 C 编译器（如 gcc）编译该代码为可执行文件，然后运行。
//  2. 预期结果：程序输出 “willie.born = 1900”。
//  3. 检查点：查看输出的数值是否为 1900，确认 born 成员被正确标识和赋值。
// 易错点提醒：
//  1. 注意结构体成员访问的 . 操作符使用，确保变量是结构体类型的实例。
// 拓展思考：
//  1. 如果要给 willie 的 name 成员（struct fullname 类型）赋值，应该怎么操作？可以尝试给 fname 和 lname 赋值。
// ------------------------------