// ------------------------------
// 题干：定义一个结构模板以储存这些项：汽车名、马力、EPA（美国环保局）城市交通 MPG（每加仑燃料行驶的英里数）评级、轴距和出厂年份。使用 car 作为该模板的标记。
// 知识要点：
//  1. 结构体的定义（用 struct 关键字在函数外定义通用结构模板）
//  2. 结构体成员的多种类型（字符数组、int 类型、float 类型）
//  3. 字符串复制函数 strcpy 的使用（依赖 <string.h> 头文件）
// 总体逻辑：
//  1. 定义 struct car 结构体，包含汽车名、马力等五个成员
//  2. 在 main 中声明 struct car 类型的变量 my_car
//  3. 给 my_car 各成员赋值（用 strcpy 处理字符数组，直接赋值处理数值型）
//  4. 打印 my_car 各成员，验证结构体的存储与读取
#include <stdio.h>
#include <string.h>  // 为了使用 strcpy 函数

// 定义结构体模板 car，用于存储一辆汽车的各项信息
struct car {
    char name[50];     // 汽车名称，字符数组最多存 49 个有效字符（最后一个是 '\0'）
    int horsepower;    // 马力，整数类型
    float epa_mpg;     // EPA 城市每加仑行驶英里数，浮点类型
    float wheelbase;   // 轴距，浮点类型（单位：英寸）
    int year;          // 出厂年份，整数类型
};

int main() {
    // 声明 struct car 类型的变量 my_car，用来存具体某辆车的信息
    struct car my_car;

    // 给“汽车名”成员赋值：用 strcpy 把字符串复制到 name 数组
    strcpy(my_car.name, "Toyota Camry");
    // 给“马力”成员赋值
    my_car.horsepower = 203;
    // 给“EPA 评级”成员赋值
    my_car.epa_mpg = 28.5;
    // 给“轴距”成员赋值
    my_car.wheelbase = 111.2;
    // 给“出厂年份”成员赋值
    my_car.year = 2023;

    // 打印 my_car 各成员的值，检查是否存储正确
    printf("汽车名称：%s\n", my_car.name);
    printf("马力：%d 匹\n", my_car.horsepower);
    printf("EPA城市每加仑行驶英里数：%.1f\n", my_car.epa_mpg);
    printf("轴距：%.1f 英寸\n", my_car.wheelbase);
    printf("出厂年份：%d 年\n", my_car.year);

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：用 C 编译器（如 gcc）编译代码（例：gcc car_struct.c -o car_app），然后运行 ./car_app（Linux/macOS）或 car_app.exe（Windows）。
//  2. 预期结果：程序输出以下内容（与赋值一致）：
//     汽车名称：Toyota Camry
//     马力：203 匹
//     EPA城市每加仑行驶英里数：28.5
//     轴距：111.2 英寸
//     出厂年份：2023 年
//  3. 检查点：逐行核对输出内容，确认每个成员的打印值与代码中赋值的内容完全匹配。
// 易错点提醒：
//  1. 忘记包含 <string.h> 头文件，导致 strcpy 函数报错（编译时会提示“未定义的函数”）。
//  2. 直接用 “my_car.name = "XXX";” 给字符数组成员赋值（C 语言不允许直接给字符数组整体赋值，必须用 strcpy）。
//  3. 打印时格式符与成员类型不匹配（比如用 %d 打印 float 类型的 epa_mpg），导致输出错误数值。
// 拓展思考：
//  1. 如何存储多辆汽车？可以定义结构体数组，例：struct car cars[5]; 然后通过 cars[0]、cars[1] 分别存不同车辆。
//  2. 如何从用户输入获取信息？可改用 scanf 或 fgets，例：
//     printf("请输入汽车名称：");
//     fgets(my_car.name, 50, stdin);  // 注意 fgets 会包含换行，需额外处理的话可手动去掉 '\n'
//     printf("请输入马力：");
//     scanf("%d", &my_car.horsepower);
//  3. 若要添加“价格”“颜色”等成员，只需在 struct car 中新增成员即可，例：float price; char color[20];。
// ------------------------------