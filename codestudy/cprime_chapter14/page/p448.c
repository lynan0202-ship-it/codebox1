/*
代码名称：friend.c（嵌套结构示例程序）
知识要点总结：
1. 嵌套结构定义：结构体中包含另一个结构体（如struct guy 包含 struct names）
2. 多层成员访问：通过连续点运算符访问嵌套成员（如 fellow.handle.first）
3. 结构体初始化：支持嵌套结构的逐层初始化（按成员顺序赋值）
4. 常量字符串数组：用const char* 存储固定文本片段，方便复用
5. 条件判断与输出：根据结构体成员（如income）的值动态输出不同符号

代码总体逻辑说明：
① 定义基础结构体struct names（存储名和姓）
② 定义嵌套结构体struct guy（包含names结构、爱好、职业、收入）
③ 定义常量字符串数组msgs（预设文本模板）
④ 主函数中初始化struct guy类型变量fellow，设置所有成员值
⑤ 通过多层点运算符访问嵌套成员（如fellow.handle.first），结合msgs数组拼接输出个性化内容
⑥ 根据income的值判断输出特殊符号（!!! / $$$ / :-)）
⑦ 输出结尾固定内容，演示字符串拼接功能
*/

#include <stdio.h>
#define LEN 20  // 姓名字段的最大长度

// 常量字符串数组：存储预设的文本片段（共5个元素）
const char *msgs[] = {
    "Thank you for the wonderful evening, ",
    "You certainly prove that a ",
    "is a special kind of guy. We must get together",
    "over a delicious ",
    " and have a few laughs"
};

// 基础结构体：表示姓名（包含名和姓）
struct names {
    char first[LEN];  // 名
    char last[LEN];   // 姓
};

// 嵌套结构体：guy包含names结构体，以及其他属性
struct guy {
    struct names handle;  // 嵌套的names结构（先访问handle，再访问first/last）
    char favfood[LEN];    // 最喜欢的食物
    char job[LEN];        // 职业
    float income;         // 收入
};

int main(void) {
    // 初始化嵌套结构体：逐层赋值（按结构体成员顺序）
    struct guy fellow = {
        {"Ewen", "Villard"},  // handle的初始化：对应struct names的first和last
        "grilled salmon",     // favfood
        "personality coach",  // job
        68112.00              // income
    };

    // 输出示例：结合常量字符串和结构体成员，演示嵌套访问
    printf("Dear %s,\n\n", fellow.handle.first);  // 访问：fellow → handle → first
    printf("%s%s\n", msgs[0], fellow.handle.first);  // msgs[0] + 名字
    printf("%s%s\n", msgs[1], fellow.job);           // msgs[1] + 职业
    printf("%s\n", msgs[2]);                         // msgs[2]
    printf("%s%s%s\n", msgs[3], fellow.favfood, msgs[4]); // msgs[3]+食物+msgs[4]

    // 根据收入判断输出符号（演示条件分支）
    if (fellow.income > 150000.0)
        puts("!!!");          // 高收入
    else if (fellow.income > 75000.0)
        puts("$$$");          // 中等收入
    else
        puts(":-)");          // 普通收入

    // 输出结尾内容（演示字符串拼接）
    printf("\n%s\n%s\n", "See you soon,", "Shalala");
    printf("***%s***\n", fellow.handle.last);  // 访问姓：fellow → handle → last

    return 0;
}

/*
代码测试及验证建议方案：
1. 基础功能验证：
   - 运行程序，检查输出是否与教材示例一致（开头"Dear Ewen,"，中间包含"grilled salmon"和"personality coach"）
   - 观察符号输出是否为":-"（当前income=68112，符合else分支）

2. 嵌套成员修改测试：
   - 修改fellow的first为"Bob"、last为"Smith"，检查称呼和结尾的姓氏是否变化
   - 修改job为"teacher"、favfood为"pizza"，检查职业和食物描述是否正确替换
   - 故意写漏嵌套层级（如fellow.first），观察编译器报错信息，理解嵌套访问规则

3. 常量数组测试：
   - 修改msgs数组索引（如msgs[5]），观察是否触发数组越界（运行时可能崩溃）
   - 替换msgs[0]为"Hi, "，检查开头问候语是否变化

4. 条件逻辑测试：
   - 修改income为80000，验证是否输出"$$$"；修改为200000，验证是否输出"!!!"
   - 测试边界值（75000.0），观察是否进入else分支（输出":-"）

5. 初始化顺序测试：
   - 颠倒初始化顺序（如把"Villard"放在first位置），观察姓名输出是否混乱，理解初始化顺序必须匹配结构体定义
*/