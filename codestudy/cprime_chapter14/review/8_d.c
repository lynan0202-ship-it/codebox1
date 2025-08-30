// ------------------------------
// 题干：d. 调用scanf()读入一个用pt标识符标识的born成员的值。
// 知识要点：
//  1. scanf 函数的使用
//  2. 结构体指针的使用（-> 操作符）
//  3. 结构体成员地址的获取（通过指针时，用 &pt->born 获取成员地址）
// 总体逻辑：
//  1. 定义结构体类型 struct fullname 和 struct bard
//  2. 声明 struct bard 类型的变量 willie 和指向它的指针 pt
//  3. 使用 scanf，通过 pt->born 的地址读入整数
//  4. 打印读入的值，验证正确性
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
    // 声明指针 pt 并指向 willie
    struct bard *pt = &willie;

    // 提示输入
    printf("请输入 pt 所指向的 born 年份：");
    // scanf 中，&pt->born 是 pt 指向的结构体中 born 成员的地址
    scanf("%d", &pt->born);

    // 打印 pt->born 的值（也可以用 willie.born 验证，因为 pt 指向 willie）
    printf("pt->born 的值是：%d\n", pt->born);
    printf("willie.born 的值是：%d\n", willie.born); // 验证两者一致

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：编译后运行，输入一个整数（比如 1920）。
//  2. 预期结果：输出 pt->born 和 willie.born 都是 1920。
//  3. 检查点：确认两个输出一致，说明通过指针正确读入了数据。
// 易错点提醒：
//  1. 错误地写成 &(pt->born) 的形式（虽然效果一样，但容易多写括号，其实 &pt->born 就可以，因为 -> 优先级高于 &）。
//  2. 忘记让 pt 指向 willie，导致指针无效。
// 拓展思考：
//  1. 如果有多个结构体变量，pt 可以指向不同的变量，scanf 就能给不同变量的 born 赋值，试试定义另一个 struct bard 变量，让 pt 指向它，再输入数据。
// ------------------------------