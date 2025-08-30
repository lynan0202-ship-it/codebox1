/*
代码名称：位字段实现方框属性存储与展示
知识要点总结：
- 位字段的定义：通过结构体创建不同宽度的位字段，实现数据紧凑存储（如1位、3位、2位字段）。
- 位字段的初始化：与普通结构体初始化语法一致，可在定义时为各字段赋值。
- 位字段的访问/修改：使用结构体成员运算符（.）对字段赋值、读取，需注意字段宽度的取值范围。
- 符号常量与位字段结合：通过`#define`定义颜色、边框样式的常量，提升位字段值的可读性。
- 结构体指针传参：通过指针传递位字段结构体，在函数中访问其成员以打印属性。
总体逻辑说明：
1. 定义边框样式、颜色的符号常量，以及颜色名称数组（用于将位字段值映射为可读字符串）。
2. 定义`box_props`结构体，包含表示“透明度、填充色、边框显示、边框色、边框样式”的位字段，及未命名位字段用于内存填充。
3. 编写`show_settings`函数，接收结构体指针，根据位字段值打印方框的各项属性。
4. `main`函数中，先初始化`box_props`并打印初始设置；再修改部分位字段值，再次打印验证修改效果。
*/

#include <stdio.h>
#include <stdbool.h>  // C99 提供 bool、true、false 定义

// 边框样式常量（2位字段可存 0~2）
#define SOLID 0
#define DOTTED 1
#define DASHED 2

// 三原色常量（用于组合混合色）
#define BLUE 4
#define GREEN 2
#define RED 1

// 混合色常量（通过三原色按位或组合得到）
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

// 颜色名称数组：索引与颜色值一一对应
const char *colors[8] = {"black", "red", "green", "yellow",
                         "blue", "magenta", "cyan", "white"};

// 定义存储方框属性的位字段结构体
struct box_props {
    bool opaque : 1;           // 1位：true=不透明，false=透明
    unsigned int fill_color : 3;  // 3位：0~7对应8种填充色
    unsigned int : 4;          // 4位未命名字段，用于内存填充（使布局规整）
    bool show_border : 1;      // 1位：true=显示边框，false=隐藏边框
    unsigned int border_color : 3;  // 3位：0~7对应8种边框色
    unsigned int border_style : 2;  // 2位：0~2对应SOLID/DOTTED/DASHED
    unsigned int : 2;          // 2位未命名字段，补充内存填充
};

// 打印方框属性的函数（接收结构体指针，避免拷贝开销）
void show_settings(const struct box_props *pb) {
    // 打印透明度
    printf("Box is %s.\n", pb->opaque ? "opaque" : "transparent");
    // 打印填充色（通过colors数组映射位字段值到字符串）
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    // 打印边框显示状态
    printf("Border is %s.\n", pb->show_border ? "shown" : "not shown");
    // 打印边框颜色
    printf("The border color is %s.\n", colors[pb->border_color]);
    // 根据边框样式常量，打印边框样式
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

int main(void) {
    // 初始化box_props结构体：按成员顺序赋值
    struct box_props box = {true, YELLOW, 0, true, GREEN, DASHED};

    printf("Original box settings:\n");
    show_settings(&box);  // 传递结构体地址，调用打印函数

    // 修改部分位字段属性
    box.opaque = false;        // 透明度改为“透明”
    box.fill_color = WHITE;    // 填充色改为“白色”
    box.border_color = MAGENTA; // 边框色改为“洋红色”
    box.border_style = SOLID;  // 边框样式改为“实线”

    printf("\nModified box settings:\n");
    show_settings(&box);  // 打印修改后的属性

    return 0;
}

/*
代码测试及验证建议方案：
1. 初始值验证：运行程序后，检查“Original box settings”输出，确认各属性是否与初始化值（opaque=true、fill_color=YELLOW、show_border=true、border_color=GREEN、border_style=DASHED）一致。
2. 修改后值验证：检查“Modified box settings”输出，确认修改后的属性（opaque=false、fill_color=WHITE、border_color=MAGENTA、border_style=SOLID）是否正确生效。
3. 边界值测试：尝试给位字段赋超出宽度的值（如给`border_style`（2位）赋3），观察程序输出（会因位截断出现意外值，需理解位字段的宽度限制）。
4. 内存布局测试：使用`sizeof(struct box_props)`查看结构体大小，修改未命名字段的宽度（如把`unsigned int : 4;`改为`unsigned int : 2;`），再次查看大小，理解“未命名字段用于内存填充/对齐”的作用。
5. 可读性验证：修改`colors`数组的颜色名称，或调整`#define`的颜色值（如把`RED`改为3），验证符号常量与位字段值的映射是否正确。
*/