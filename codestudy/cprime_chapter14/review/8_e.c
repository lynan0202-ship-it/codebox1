// ------------------------------
// 题干：e. 调用scanf()读入一个用willie标识符标识的name成员中lname成员的值。
// 知识要点：
//  1. 嵌套结构体成员的访问（多级 . 操作符，willie.name.lname）
//  2. scanf 读入字符串（%s 格式说明符）
//  3. 字符数组的地址（数组名作为地址，不需要 &，因为数组名本身就是首地址）
// 总体逻辑：
//  1. 定义结构体类型 struct fullname 和 struct bard
//  2. 声明 struct bard 类型的变量 willie
//  3. 使用 scanf 读入字符串到 willie.name.lname 中
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

    // 提示输入 lname
    printf("请输入 willie 的姓（lname）：");
    // willie.name.lname 是字符数组，数组名就是首地址，所以 scanf 用 %s 读入字符串到该数组
    scanf("%s", willie.name.lname);

    // 打印读入的 lname
    printf("willie 的姓是：%s\n", willie.name.lname);

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：编译后运行，输入一个字符串（比如 Shakespeare）。
//  2. 预期结果：输出 “willie 的姓是：Shakespeare”。
//  3. 检查点：查看输出的字符串是否和输入一致，确认 scanf 正确读入到 lname 成员。
// 易错点提醒：
//  1. 错误地在 scanf 中使用 &willie.name.lname，因为数组名已经是地址，加 & 会导致地址错误（虽然有些编译器可能能运行，但逻辑错误）。
//  2. 输入的字符串长度超过 lname 的大小（20），导致缓冲区溢出，所以要提醒输入短一些的字符串。
// 拓展思考：
//  1. 如果要读入 fname 成员的值，应该怎么改代码？把 lname 换成 fname 即可。
// ------------------------------