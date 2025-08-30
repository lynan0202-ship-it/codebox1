// ------------------------------
// 题干：f. 调用scanf()读入一个用pt标识符标识的name成员中lname成员的值。
// 知识要点：
//  1. 结构体指针访问嵌套成员（-> 和 . 结合，pt->name.lname）
//  2. scanf 读入字符串（%s）
//  3. 字符数组的地址（数组名作为地址，无需 &）
// 总体逻辑：
//  1. 定义结构体类型 struct fullname 和 struct bard
//  2. 声明 struct bard 类型的变量 willie 和指向它的指针 pt
//  3. 使用 scanf 读入字符串到 pt->name.lname 中
//  4. 打印读入的 lname，验证正确性
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

    // 提示输入 lname
    printf("请输入 pt 所指向的姓（lname）：");
    // pt->name.lname 是字符数组，数组名是首地址，scanf 用 %s 读入字符串
    scanf("%s", pt->name.lname);

    // 打印 pt->name.lname 的值（也可以用 willie.name.lname 验证）
    printf("pt->name.lname 的值是：%s\n", pt->name.lname);
    printf("willie.name.lname 的值是：%s\n", willie.name.lname); // 验证一致

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：编译后运行，输入一个字符串（比如 Byron）。
//  2. 预期结果：两个输出都显示 Byron。
//  3. 检查点：确认两个输出一致，说明通过指针正确读入了 lname。
// 易错点提醒：
//  1. 错误地使用 &pt->name.lname，因为数组名已经是地址，加 & 会导致地址错误。
//  2. 忘记 pt 指向 willie，导致指针无效。
// 拓展思考：
//  1. 尝试同时读入 fname 和 lname，用两次 scanf 分别处理 pt->name.fname 和 pt->name.lname。
// ------------------------------