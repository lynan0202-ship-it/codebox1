#include <stdio.h>

int main(void) {
    // 测试用例：可修改 number 观察不同分支执行
    int number = 15; 

    // --------------------- 示例1：无花括号，演示“else 与最近 if 配对” --------------------- 
    // 场景：
    // if (number > 6) 为第 1 层 if
    //   → 内部嵌套 if (number < 12) 为第 2 层 if
    // else 与“最近未被花括号隔离的 if”配对（即第 2 层 if）
    if (number > 6)
        // 第 2 层 if：判断是否接近（6 < number < 12）
        if (number < 12)
            printf("You're close!\n");
        // else 与第 2 层 if 配对（而非第 1 层）
        else
            printf("Sorry, you lose a turn!\n");
    // 教程知识点：
    // 1. 编译器忽略缩进，仅按“就近原则”匹配 else
    // 2. 此例中，当 number > 12 时，进入 else 分支（如 number=15 会执行这里）
    // 3. 若希望 else 与第 1 层 if 配对，必须用花括号显式分组


    // --------------------- 示例2：用花括号改变配对关系（让 else 与第 1 层 if 配对） --------------------- 
    // 重置测试值（可修改验证）
    number = 5; 
    // 第 1 层 if：判断 number > 6？
    if (number > 6) {
        // 花括号包裹：将“if (number < 12) + printf”视为一个复合语句
        if (number < 12)
            printf("You're close!\n");
        // 花括号内无 else，因此第 1 层 if 的 else 会单独匹配
    }
    // else 与第 1 层 if（number > 6）配对 
    else
        printf("Sorry, you lose a turn!\n");
    // 教程知识点验证：
    // number=5 不满足 number>6 → 执行此 else，输出“Sorry, you lose a turn!”
    // 体现“花括号隔离内层 if 后，else 回归外层 if 配对”的规则


    // --------------------- 扩展：多层嵌套与 C99 标准（最少支持 127 层嵌套） --------------------- 
    // 演示多层嵌套（简化版，实际开发按需设计）
    int score = 1800;
    int bonus = 0;

    // 多层 else if 链式结构（教程提到“可连成一串处理多条件”）
    if (score < 1000)
        bonus = 0;
    else if (score < 1500)
        bonus = 1;
    else if (score < 2000)
        bonus = 2;
    else if (score < 2500)
        bonus = 4;
    else
        bonus = 6;
    // 输出结果：score=1800 → bonus=2（符合 1500<=score<2000 逻辑）
    printf("Bonus for score %d: %d\n", score, bonus);
    // 教程知识点：
    // 1. else if 是“if-else 嵌套”的简写，编译器按“就近匹配”处理每个 else
    // 2. C99 标准要求编译器最少支持 127 层嵌套，此处是简单链式嵌套示例


    return 0;
}