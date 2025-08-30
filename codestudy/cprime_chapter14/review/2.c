// ------------------------------
// 题干：下面是程序的一部分，输出是什么？
// #include <stdio.h>
// struct house {
//     float sqft;
//     int rooms;
//     int stories;
//     char address[40];
// };
// int main(void)
// {
//     struct house fruzt = {1560.0, 6, 1, "22 Spiffo Road"};
//     struct house *sign;
// 
//     sign = &fruzt;
//     printf("%d %d\n", fruzt.rooms, sign->stories);
//     printf("%s \n", fruzt.address);
//     printf("%c %c\n", sign->address[3], fruzt.address[4]);
//     return 0;
// }
// 知识要点：
//  1. 结构体的定义与初始化 - 可在定义变量时用大括号为各成员赋初值
//  2. 结构体指针的使用 - 通过 `->` 操作符访问指针指向的结构体成员
//  3. 结构体成员的访问 - 通过 `.` 操作符访问结构体变量的成员
//  4. 字符串与字符数组 - 字符数组可存储字符串，通过下标能访问单个字符
// 总体逻辑：
//  1. 定义结构体 `house`，包含浮点型、整型、字符数组等成员
//  2. 在 `main` 中初始化 `struct house` 类型的变量 `fruzt`，同时定义结构体指针 `sign`
//  3. 让指针 `sign` 指向 `fruzt`，随后分别打印 `fruzt` 的 `rooms` 成员、`sign` 指向的 `stories` 成员、`fruzt` 的 `address` 字符串、`sign->address` 的第 4 个字符（下标 3）和 `fruzt.address` 的第 5 个字符（下标 4）
#include <stdio.h>

struct house {
    float sqft;       // 定义浮点型成员，代表房屋面积
    int rooms;        // 定义整型成员，代表房间数量
    int stories;      // 定义整型成员，代表楼层数
    char address[40]; // 定义字符数组成员，用于存储地址字符串
};

int main(void)
{
    // 初始化结构体变量 fruzt，依次为 sqft、rooms、stories、address 赋值
    struct house fruzt = {1560.0, 6, 1, "22 Spiffo Road"};
    struct house *sign; // 定义指向 struct house 类型的指针 sign

    sign = &fruzt; // 让 sign 指向 fruzt 变量（将 fruzt 的地址赋值给 sign）

    // 打印 fruzt 的 rooms 成员（值为 6）和 sign 指向的 stories 成员（值为 1）
    printf("%d %d\n", fruzt.rooms, sign->stories);
    // 打印 fruzt 的 address 字符串（内容为 "22 Spiffo Road"）
    printf("%s \n", fruzt.address);
    // 打印 sign->address[3]（即字符串 "22 Spiffo Road" 下标 3 的字符 'S'）和 fruzt.address[4]（下标 4 的字符 'p'）
    printf("%c %c\n", sign->address[3], fruzt.address[4]);
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：将代码保存为 .c 文件（如 house_test.c），用 C 编译器（如 gcc）编译：`gcc house_test.c -o house_test`，然后运行 `./house_test`
//  2. 预期结果：输出三行内容，第一行是 `6 1`，第二行是 `22 Spiffo Road `（注意字符串后有一个空格，因 printf 格式为 `"%s \n"`），第三行是 `S p`
//  3. 检查点：重点核对每个 printf 输出的内容是否与预期一致，尤其是字符下标访问的结果
// 易错点提醒：
//  1. 容易混淆结构体指针的 `->` 和结构体变量的 `.` 操作符，比如错误写成 `sign.stories`（sign 是指针，应使用 `->`）
//  2. 字符数组的下标容易数错，`address[3]` 是第 4 个字符（下标从 0 开始），要注意计数
// 拓展思考：
//  1. 如果结构体成员 `address` 存储的字符串长度超过 40 个字符会怎样？这会导致缓冲区溢出，可能破坏程序其他数据或引发错误，所以定义字符数组长度时要预留足够空间
//  2. 如何修改代码让 `sign` 指针指向另一个 `struct house` 类型的变量？可再定义一个 `struct house` 变量，然后将它的地址赋值给 `sign`（例如 `struct house another = {1200.0, 4, 2, "55 Main St"}; sign = &another;`）
// 对比说明：
//  结构体变量访问成员用 `.`：如 `fruzt.rooms`，是直接通过变量名访问；
//  结构体指针访问成员用 `->`：如 `sign->stories`，等价于 `(*sign).stories`，是通过指针间接访问。
// ------------------------------