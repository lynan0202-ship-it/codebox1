/*
代码名称：位字段与按位运算对比演示程序
知识要点总结：
- 位字段：利用结构体定义不同宽度的位字段，实现数据的紧凑存储（如1位表示布尔值、3位表示8种颜色等）。
- 按位运算：通过与（&）、或（|）、取反（~）、移位（>>）等操作，直接操作整数的二进制位，模拟位字段的功能。
- 联合（union）：将“位字段结构体”和“无符号短整型”关联到同一块内存，实现两种方式对同一数据的访问与修改。
- 二进制位打印：自定义`itobs`函数，将整数转换为二进制字符串，直观查看内存的位模式。
总体逻辑说明：
1. 定义边框样式、颜色（三原色、混合色）以及按位运算所需的掩码等符号常量。
2. 定义位字段结构体`box_props`，包含“透明度、填充色、边框显示、边框色、边框样式”等字段；再定义联合`Views`，使该结构体与`unsigned short`共享同一块内存。
3. 编写两个`show_settings`函数：一个通过位字段结构体解析数据，另一个通过按位运算解析`unsigned short`的数据，均用于打印方框属性。
4. 编写`itobs`函数，将整数转换为二进制字符串，用于查看位模式。
5. `main`函数中，初始化联合变量后，先通过位字段方式打印初始设置；再用按位运算修改内存中的位，之后分别通过位字段和按位运算方式打印修改后的设置，并打印二进制位模式，对比两种方法的效果。
*/

#include <stdio.h>
#include <stdbool.h>   // 提供 bool、true、false 定义
#include <limits.h>    // 提供 CHAR_BIT（每个字符的位数，通常为8）

// ---------- 边框样式常量（位字段中 border_style 占2位，可存0~2） ----------
#define SOLID 0
#define DOTTED 1
#define DASHED 2

// ---------- 三原色常量（用于组合混合色，每位代表一种颜色是否启用） ----------
#define BLUE 4    // 二进制 100
#define GREEN 2   // 二进制 010
#define RED 1     // 二进制 001

// ---------- 混合色常量（通过三原色按位或 `|` 组合得到） ----------
#define BLACK 0               // 000
#define YELLOW (RED | GREEN)  // 011
#define MAGENTA (RED | BLUE)  // 101
#define CYAN (GREEN | BLUE)   // 110
#define WHITE (RED | GREEN | BLUE)  // 111

// ---------- 按位运算专用常量（用于直接操作 unsigned short 的二进制位） ----------
#define OPAQUE 0x1           // 第0位：1表示不透明（对应位字段 opaque）
#define FILL_BLUE 0x8        // 第3位：1表示填充色含蓝色
#define FILL_GREEN 0x4       // 第2位：1表示填充色含绿色
#define FILL_RED 0x2         // 第1位：1表示填充色含红色
#define FILL_MASK 0xE        // 0b1110：填充色的掩码（第1~3位）
#define BORDER 0x10          // 第4位：1表示显示边框（对应位字段 show_border）
#define BORDER_BLUE 0x800    // 第11位：1表示边框色含蓝色
#define BORDER_GREEN 0x400   // 第10位：1表示边框色含绿色
#define BORDER_RED 0x200     // 第9位：1表示边框色含红色
#define BORDER_MASK 0xE00    // 0b11100000000：边框色的掩码（第9~11位）
#define B_SOLID 0            // 第12~13位为0：实线边框
#define B_DOTTED 0x1000      // 第12位为1：点线边框
#define B_DASHED 0x2000      // 第13位为1：虚线边框
#define STYLE_MASK 0x3000    // 0b110000000000：边框样式的掩码（第12~13位）

// 颜色名称数组：索引与颜色值（BLACK、RED 等）一一对应
const char *colors[8] = {"black", "red", "green", "yellow",
                         "blue", "magenta", "cyan", "white"};

// 定义存储方框属性的位字段结构体
struct box_props {
    bool opaque : 1;           // 1位：true=不透明，false=透明
    unsigned int fill_color : 3;  // 3位：0~7对应8种填充色（BLACK~WHITE）
    unsigned int : 4;          // 4位未命名字段，用于内存填充（使布局规整）
    bool show_border : 1;      // 1位：true=显示边框，false=隐藏边框
    unsigned int border_color : 3;  // 3位：0~7对应8种边框色
    unsigned int border_style : 2;  // 2位：0~2对应SOLID/DOTTED/DASHED
    unsigned int : 2;          // 2位未命名字段，补充内存填充
};

// 联合：使 box_props 结构体与 unsigned short 共享同一块内存
union Views {
    struct box_props st_view;  // 位字段视图
    unsigned short us_view;    // 无符号短整型视图（按位运算用）
};

// 函数声明：通过位字段结构体打印属性
void show_settings(const struct box_props *pb);
// 函数声明：通过按位运算打印 unsigned short 对应的属性
void show_settings1(unsigned short us);
// 函数声明：将整数 n 转换为二进制字符串，存入 ps
char *itobs(int n, char *ps);

int main(void) {
    // 初始化联合变量：按位字段结构体的成员顺序赋值
    union Views box = {.st_view = {true, YELLOW, 0, true, GREEN, DASHED}};
    char bin_str[CHAR_BIT * sizeof(unsigned int) + 1];  // 存储二进制字符串的数组

    printf("Original box settings:\n");
    show_settings(&box.st_view);  // 通过位字段结构体打印初始设置

    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);  // 通过按位运算打印初始设置

    printf("Bits are %s\n", itobs(box.us_view, bin_str));  // 打印初始二进制位模式

    // ---------- 用按位运算修改内存中的位 ----------
    box.us_view &= ~FILL_MASK;          // 清空填充色的位（第1~3位设为0）
    box.us_view |= (FILL_BLUE | FILL_GREEN);  // 设置填充色为青色（BLUE | GREEN = CYAN）
    box.us_view |= OPAQUE;              // 设置“不透明”位（第0位设为1）
    box.us_view &= ~BORDER;             // 清空“显示边框”位（第4位设为0）
    box.us_view |= BORDER_RED;          // 设置边框色含红色（第9位设为1）
    box.us_view &= ~STYLE_MASK;         // 清空边框样式的位（第12~13位设为0）
    box.us_view |= B_DOTTED;            // 设置边框样式为点线（第12位设为1）

    printf("\nModified box settings:\n");
    show_settings(&box.st_view);  // 通过位字段结构体打印修改后设置

    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);  // 通过按位运算打印修改后设置

    printf("Bits are %s\n", itobs(box.us_view, bin_str));  // 打印修改后二进制位模式

    return 0;
}

// 函数定义：通过位字段结构体指针 pb，打印方框属性
void show_settings(const struct box_props *pb) {
    printf("Box is %s.\n", pb->opaque ? "opaque" : "transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border is %s.\n", pb->show_border ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is ");
    switch (pb->border_style) {
        case SOLID:
            printf("solid\n");
            break;
        case DOTTED:
            printf("dotted\n");
            break;
        case DASHED:
            printf("dashed\n");
            break;
        default:
            printf("unknown type\n");
    }
}

// 函数定义：通过按位运算，解析 unsigned short us 并打印方框属性
void show_settings1(unsigned short us) {
    printf("box is %s.\n", (us & OPAQUE) == OPAQUE ? "opaque" : "transparent");
    
    // 提取填充色：将 us 右移1位后，与 0b111（即7）按位与，得到填充色的3位值
    printf("The fill color is %s.\n", colors[(us >> 1) & 07]);
    
    printf("Border is %s.\n", (us & BORDER) == BORDER ? "shown" : "not shown");
    
    printf("The border style is ");
    switch (us & STYLE_MASK) {
        case B_SOLID:
            printf("solid\n");
            break;
        case B_DOTTED:
            printf("dotted\n");
            break;
        case B_DASHED:
            printf("dashed\n");
            break;
        default:
            printf("unknown type\n");
    }
    
    // 提取边框色：将 us 右移9位后，与 0b111（即7）按位与，得到边框色的3位值
    printf("The border color is %s.\n", colors[(us >> 9) & 07]);
}

// 函数定义：将整数 n 转换为二进制字符串，存入 ps（返回 ps 的起始地址）
char *itobs(int n, char *ps) {
    int i;
    // CHAR_BIT 是每个字符的位数（通常为8），sizeof(int) 是int的字节数，总位数为 CHAR_BIT * sizeof(int)
    const static int size = CHAR_BIT * sizeof(int);
    
    for (i = size - 1; i >= 0; i--, n >>= 1) {
        ps[i] = (n & 1) ? '1' : '0';  // 取 n 的最低位，转换为 '1' 或 '0'
    }
    ps[size] = '\0';  // 字符串结尾加'\0'
    return ps;
}

/*
代码测试及验证建议方案：
1. 初始值验证：运行程序后，检查“Original box settings”和“Box settings using unsigned int view”的输出，确认两种方式解析的初始值（不透明、填充色黄色、显示边框、边框色绿色、边框样式虚线）是否一致。
2. 修改后值验证：检查“Modified box settings”和“Box settings using unsigned int view”的输出，确认修改后的值（不透明、填充色青色、隐藏边框、边框色红色、边框样式点线）是否通过两种方式正确解析。
3. 二进制位验证：观察“Bits are ...”的输出，对比修改前后的二进制位模式，确认按位运算（如 `&= ~FILL_MASK`、`|= B_DOTTED` 等）是否正确修改了对应位。
4. 掩码与移位验证：修改按位运算的掩码（如将 `FILL_MASK` 改为 `0xF`）或移位位数（如将 `(us >> 1) & 07` 改为 `(us >> 2) & 07`），观察输出变化，理解“掩码提取指定位”和“移位对齐”的作用。
5. 联合一致性验证：在 `main` 中直接修改 `box.st_view.opaque = false`，然后打印 `box.us_view` 的二进制位，确认联合的两个成员共享同一块内存（修改位字段会同步影响 `unsigned short` 的值）。
*/