// ------------------------------
// 题干：c. 调用scanf()读入一个用willie标识符标识的born成员的值。
// 知识要点：
//  1. scanf 函数的使用（从标准输入读取数据）
//  2. 结构体成员的地址获取（& 操作符，获取 int 类型成员的地址）
//  3. 结构体成员的访问（. 操作符）
// 总体逻辑：
//  1. 定义结构体类型 struct fullname 和 struct bard
//  2. 声明 struct bard 类型的变量 willie
//  3. 使用 scanf，通过 willie.born 的地址读入一个整数
//  4. 打印读入的 born 值，验证是否正确
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

    // 提示用户输入 born 的值
    printf("请输入 willie 的 born 年份：");
    // scanf 中，&willie.born 是 willie.born 成员的地址，scanf 把输入的整数存到该地址
    scanf("%d", &willie.born);

    // 打印读入的 born 值
    printf("你输入的 willie.born 是：%d\n", willie.born);

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：编译后运行程序，当提示输入时，输入一个整数（比如 1880）。
//  2. 预期结果：程序输出 “你输入的 willie.born 是：1880”（假设输入 1880）。
//  3. 检查点：查看输出是否和输入的整数一致，确认 scanf 正确读入数据到 born 成员。
// 易错点提醒：
//  1. 忘记在 scanf 中写 &，导致 scanf 试图修改一个值而不是地址，程序可能崩溃或出现错误。
// 拓展思考：
//  1. 如果要输入 died 成员的值，代码应该怎么改？只需要把 &willie.born 换成 &willie.died 即可。
// ------------------------------