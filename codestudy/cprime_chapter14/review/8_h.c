// ------------------------------
// 题干：h. 构造一个表达式，表示willie结构变量所表示的名和姓中的字母总数。
// 知识要点：
//  1. 结构体成员的多级访问（willie.name.fname 和 willie.name.lname）
//  2. strlen 函数的使用（计算字符串长度，需要 #include <string.h>）
//  3. 表达式的构造（将两个字符串长度相加）
// 总体逻辑：
//  1. 定义结构体类型 struct fullname 和 struct bard
//  2. 声明 struct bard 类型的变量 willie，并给 name.fname 和 name.lname 赋值
//  3. 构造表达式 strlen(willie.name.fname) + strlen(willie.name.lname) 计算总长度
//  4. 打印总长度，验证正确性
#include <stdio.h>
#include <string.h> // 因为要使用 strlen 函数

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

    // 给名和姓赋值，比如 fname 是 "William"（长度 7），lname 是 "Shakespeare"（长度 10）
    strcpy(willie.name.fname, "William");
    strcpy(willie.name.lname, "Shakespeare");

    // 构造表达式计算名和姓的字母总数
    int total_length = strlen(willie.name.fname) + strlen(willie.name.lname);

    // 打印总长度
    printf("willie 的名和姓的字母总数是：%d\n", total_length);

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：编译后运行程序（需要支持 string.h）。
//  2. 预期结果：输出 “willie 的名和姓的字母总数是：17”（因为 William 长度 7，Shakespeare 长度 10，7+10=17）。
//  3. 检查点：查看输出的数值是否为 17，确认 strlen 和加法的使用正确。
// 易错点提醒：
//  1. 忘记包含 string.h 头文件，导致 strlen 函数未定义。
//  2. 错误地认为 strlen 计算的是数组大小（20），而实际是字符串的有效长度（直到 '\0'）。
// 拓展思考：
//  1. 如果要计算名、姓和中间名的总长度，需要怎么修改结构体和代码？可以在 struct fullname 中添加中间名的字符数组，然后用 strlen 相加三个数组的长度。
// ------------------------------