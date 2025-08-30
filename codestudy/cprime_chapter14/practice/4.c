// ------------------------------
// 题干：4. 编写一个程序，创建一个有两个成员的结构模板：
// a. 第1个成员是社会保险号，第2个成员是一个有3个成员的结构，第1个成员代表名，第2个成员代表中间名，第3个成员表示姓。创建并初始化一个内含5个该类型结构的数组。该程序以下面的格式打印数据：
// Dribble, Flossie M. -- 302039823
// 如果有中间名，只打印它的第1个字母，后面加一个点（.）；如果没有中间名，则不用打印点。编写一个程序进行打印，把结构数组传递给这个函数。
// b. 修改a部分，传递结构的值而不是结构的地址。
// 知识要点：
//  a部分：
//   1. 结构体的嵌套定义（结构体中包含另一个结构体作为成员）
//   2. 结构体数组的使用与初始化
//   3. 函数的地址传递（传递结构体数组的首地址，属于指针传递）
//   4. 字符串长度判断（用`strlen`判断中间名是否存在）
//  b部分：
//   5. 结构体的传值调用（函数参数直接传递结构体变量，会拷贝结构体数据）
// 总体逻辑：
//  a部分：
//   1. 定义嵌套结构体`Name`（包含名、中间名、姓）和`Person`（包含社保号和`Name`）。
//   2. 初始化包含5个`Person`的数组。
//   3. 编写`printByAddress`函数，接收结构体数组的地址，遍历数组并按格式打印（处理中间名首字母）。
//   4. 主函数调用`printByAddress`，传递数组和长度。
//  b部分：
//   1. 编写`printByValue`函数，接收单个`Person`结构体（传值），按相同格式打印。
//   2. 主函数遍历结构体数组，逐个传递结构体给`printByValue`。
#include <stdio.h>
#include <string.h>  // 用于`strlen`函数判断字符串长度

// 定义姓名结构体（嵌套在Person中）
struct Name {
    char first[20];   // 名
    char middle[20];  // 中间名
    char last[20];    // 姓
};

// 定义人员结构体（包含社保号和姓名）
struct Person {
    long ssn;         // 社会保险号
    struct Name name; // 嵌套的姓名结构
};

// a部分：传递结构体数组的地址来打印
void printByAddress(struct Person persons[], int count) {
    printf("--- 部分a：传递结构数组的地址 ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s, ", persons[i].name.last);          // 打印姓，后跟逗号
        printf("%s", persons[i].name.first);           // 打印名
        if (strlen(persons[i].name.middle) > 0) {      // 判断中间名是否存在（长度>0）
            printf(" %c.", persons[i].name.middle[0]); // 打印中间名首字母 + 点
        }
        printf(" -- %ld\n", persons[i].ssn);           // 打印社保号
    }
}

// b部分：传递结构体的值来打印（单个结构体传值）
void printByValue(struct Person person) {
    printf("%s, ", person.name.last);          // 打印姓，后跟逗号
    printf("%s", person.name.first);           // 打印名
    if (strlen(person.name.middle) > 0) {      // 判断中间名是否存在
        printf(" %c.", person.name.middle[0]); // 打印中间名首字母 + 点
    }
    printf(" -- %ld\n", person.ssn);           // 打印社保号
}

int main() {
    // 初始化包含5个Person结构体的数组
    struct Person persons[5] = {
        {302039823, {"Flossie", "Mae", "Dribble"}},   // 有中间名（Mae）
        {123456789, {"Bob", "", "Smith"}},            // 无中间名
        {987654321, {"Alice", "Jane", "Johnson"}},    // 有中间名（Jane）
        {555123456, {"Charlie", "K", "Brown"}},       // 有中间名（单字母K）
        {777889900, {"David", "", "Lee"}}             // 无中间名
    };

    // 测试a部分：传递结构数组的地址
    printByAddress(persons, 5);

    // 测试b部分：逐个传递结构的值
    printf("\n--- 部分b：传递结构的值 ---\n");
    for (int i = 0; i < 5; i++) {
        printByValue(persons[i]);
    }

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：使用C语言编译器（如GCC）编译代码（例：`gcc 文件名.c -o struct_demo`），然后运行可执行文件（例：`./struct_demo`）。
//  2. 预期结果：
//     - a部分输出：
//       Dribble, Flossie M. -- 302039823
//       Smith, Bob -- 123456789
//       Johnson, Alice J. -- 987654321
//       Brown, Charlie K. -- 555123456
//       Lee, David -- 777889900
//     - b部分输出与a部分完全一致（打印格式相同，仅传递方式不同）。
//  3. 检查点：重点观察“中间名存在时是否打印首字母+点”“无中间名时是否不打印点”“姓名和社保号拼接是否正确”。
// 易错点提醒：
//  1. 嵌套结构体成员访问错误：比如误写`persons[i].middle`（正确应为`persons[i].name.middle`）。
//  2. 字符串空判断错误：用`==`比较字符串是否为空（C语言需用`strlen(str) == 0`，不能直接`str == ""`）。
//  3. 传值调用的误解：认为传值后函数能修改主函数的结构体（实际是拷贝，修改不影响原数据；本题仅打印，无修改，所以结果一致）。
// 拓展思考：
//  1. 若中间名是多单词（如“Mary Ann”），需打印所有中间名的首字母+点，如何修改？
//     可循环遍历中间名字符串，遇到非空格字符时取首字母，后续空格分隔的单词同理（如“Mary Ann”→“M. A.”）。
//  2. 如何从用户输入获取结构体数据，而非硬编码初始化？
//     在主函数中用循环，通过`scanf`或`fgets`依次读取每个`Person`的`ssn`、`name.first`、`name.middle`、`name.last`。
// 对比说明：
//  地址传递（a部分）：函数接收的是结构体数组的指针，传递时仅拷贝指针地址，效率高；若函数修改数组元素，主函数中数组会被改变。
//  传值调用（b部分）：函数接收的是结构体的拷贝，传递时会拷贝整个结构体数据（本题结构体小，开销不明显；若结构体很大，开销会很高）；函数内修改拷贝不影响主函数原结构体。
//  核心差异：地址传递是“共享原数据”，传值是“拷贝新数据”。