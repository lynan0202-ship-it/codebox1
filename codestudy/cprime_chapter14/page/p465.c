/*
代码名称：AnonymousStructExample
知识要点总结：
1. 结构体嵌套：通过命名结构体（如names）作为成员，构建嵌套结构体系
2. 匿名结构体：直接嵌入无名称的结构体成员，其内部字段直接归属外层结构体
3. 成员访问：嵌套结构需"外层.嵌套成员.字段"，匿名结构可"外层.字段"直接访问
总体逻辑说明：
1. 定义两种person结构：
   - 嵌套版（person_nested）：包含命名结构体names作为成员
   - 匿名版（person_anonymous）：包含匿名结构体（无名称，直接定义first/last）
2. 分别初始化两个结构体变量，演示不同初始化语法
3. 通过printf输出成员，对比两种结构的访问差异
*/

#include <stdio.h>

// ========== 嵌套结构体演示 ==========
// 第一步：定义命名结构体names
struct names {
    char first[20];  // 名
    char last[20];   // 姓
};

// 第二步：定义包含names的嵌套结构体person_nested
struct person_nested {
    int id;          // 编号
    struct names name; // 嵌套的names成员（必须通过name访问内部字段）
};

// ========== 匿名结构体演示 ==========
struct person_anonymous {
    int id;          // 编号
    struct {         // 匿名结构体开始（无名称，直接定义字段）
        char first[20];
        char last[20];
    };               // 匿名结构体结束（注意分号，容易遗漏！）
};

int main() {
    // ---------- 嵌套结构体的使用 ----------
    // 初始化：需要两层大括号（外层给id，内层给name的first/last）
    struct person_nested ted_nested = {8483, {"Ted", "Grass"}}; 
    // 访问规则：必须通过 "name." 中转
    printf("嵌套结构访问：id=%d, 名=%s, 姓=%s\n", 
           ted_nested.id,        // 直接访问id
           ted_nested.name.first, // 必须通过name成员访问first
           ted_nested.name.last);  // 必须通过name成员访问last

    // ---------- 匿名结构体的使用 ----------
    // 初始化：只需一层大括号（因为first/last直接属于person_anonymous）
    struct person_anonymous ted_anonymous = {8483, {"Ted", "Grass"}}; 
    // 访问规则：直接访问first/last（它们是person_anonymous的直接成员）
    printf("匿名结构访问：id=%d, 名=%s, 姓=%s\n", 
           ted_anonymous.id,   // 直接访问id
           ted_anonymous.first, // 直接访问first（无需中转）
           ted_anonymous.last);  // 直接访问last（无需中转）

    return 0;
}

/*
代码测试及验证建议方案：
1. 编译验证：
   - 使用C11标准编译（如gcc：gcc -std=c11 代码.c -o out）
   - 检查是否报错（重点关注匿名结构体的分号、初始化大括号层数）

2. 功能验证：
   - 修改初始化值（如把"Ted"改成"Alice"），观察输出是否同步变化
   - 尝试给匿名结构体添加新字段（如char middle[10];），扩展初始化和输出，验证访问逻辑

3. 易错点测试：
   - 故意省略匿名结构体后的分号，看编译报错
   - 尝试用嵌套结构的方式访问匿名结构（如ted_anonymous.name.first），观察编译错误提示
   - 初始化时给匿名结构套两层大括号（如{{"Ted","Grass"}}），看是否能正常运行

4. 对比学习：
   - 分别注释掉嵌套版/匿名版代码，单独运行，对比代码量和访问方式的差异
   - 思考：如果结构体嵌套多层，匿名结构能减少多少访问层级？
*/