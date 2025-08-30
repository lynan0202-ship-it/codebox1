// ------------------------------
// 题干：g. 构造一个标识符，标识willie结构变量所表示的姓名中名的第3个字母（英文的名在前）。
// 知识要点：
//  1. 结构体成员的多级访问（willie.name.fname）
//  2. 字符数组的索引访问（[] 操作符，注意索引从 0 开始）
// 总体逻辑：
//  1. 定义结构体类型 struct fullname 和 struct bard
//  2. 声明 struct bard 类型的变量 willie，并给 name.fname 赋值一个包含至少 3 个字母的字符串
//  3. 构造标识符 willie.name.fname[2] 来标识第 3 个字母
//  4. 打印该字母，验证正确性
#include <stdio.h>
#include <string.h> // 因为要使用 strcpy 函数

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

    // 给 willie 的 name.fname 赋值为 "William"（名是 William，第 3 个字母是 'l'，索引 2）
    strcpy(willie.name.fname, "William");

    // 构造标识符 willie.name.fname[2]，表示名的第 3 个字母
    char third_letter = willie.name.fname[2];

    // 打印该字母
    printf("willie 的名的第 3 个字母是：%c\n", third_letter);

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：编译后运行程序（需要支持 string.h 中的 strcpy）。
//  2. 预期结果：输出 “willie 的名的第 3 个字母是：l”（因为 William 的第 3 个字母是 l，索引 0 是 W，1 是 i，2 是 l）。
//  3. 检查点：查看输出的字符是否为 'l'，确认索引访问正确。
// 易错点提醒：
//  1. 忘记字符串索引从 0 开始，错误地使用 willie.name.fname[3]，导致取到第 4 个字母。
//  2. 给 fname 赋值的字符串长度不足 3，导致访问越界（比如赋值 "Hi"，然后访问索引 2，会得到不确定的字符）。
// 拓展思考：
//  1. 如果要获取姓的第 2 个字母，应该怎么构造标识符？用 willie.name.lname[1] 即可。
// ------------------------------