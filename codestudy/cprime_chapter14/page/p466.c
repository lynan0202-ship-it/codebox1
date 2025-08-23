/*
代码名称：StructArrayFunctionDemo
知识要点总结：
1. 结构体数组定义：存储多个同类型结构体，每个元素包含结构体所有成员
2. 函数传参特性：结构体数组名作为参数时，传递的是数组首元素的地址（类似普通数组）
3. const修饰符：保护函数参数数据，确保函数内不会修改传入的结构体数组内容
4. 成员访问：通过 "数组元素.成员名" 访问结构体数组中每个元素的成员
5. 遍历逻辑：利用循环遍历结构体数组，累加指定成员的数值

代码总体逻辑说明：
1. 定义结构体funds：描述银行账户信息（银行名称、账户金额、储蓄名称、储蓄金额）
2. 定义结构体数组jones：存储2个funds类型的元素，初始化每个人的银行和储蓄信息
3. 实现sum函数：接收结构体数组和数组长度，遍历数组计算每个元素的银行账户+储蓄账户总和
4. 主函数调用sum，输出两笔账户的总金额
*/

#include <stdio.h>
#define FUNDLEN 50  // 定义银行/储蓄名称的最大长度
#define N 2         // 结构体数组的元素个数

// 定义结构体：描述银行和储蓄账户信息
struct funds {
    char bank[FUNDLEN];   // 银行名称
    double bankfund;      // 银行账户金额
    char save[FUNDLEN];   // 储蓄机构名称
    double savefund;      // 储蓄账户金额
};

// 函数声明：计算结构体数组中所有账户的总金额
// const修饰：保证函数内不会修改money数组的内容
double sum(const struct funds money[], int n);

int main(void) {
    // 初始化结构体数组：每个大括号对应一个funds元素
    struct funds jones[N] = {
        {
            "Garlic-Melon Bank",  // bank成员
            4032.27,              // bankfund成员
            "Lucky's Savings and Loan",  // save成员
            8543.94               // savefund成员
        },
        {
            "Honest Jack's Bank",  // 第二个元素的bank成员
            3620.88,               // 第二个元素的bankfund成员
            "Party Time Savings",  // 第二个元素的save成员
            3802.91                // 第二个元素的savefund成员
        }
    };

    // 调用sum函数：传递数组名jones（等价于&jones[0]，即首元素地址）和元素个数N
    double total = sum(jones, N);
    // 格式化输出：保留两位小数
    printf("The Joneses have a total of $%.2f\n", total);

    return 0;
}

// 函数定义：计算结构体数组中所有账户的总和
double sum(const struct funds money[], int n) {
    double total = 0.0;  // 总和初始化为0
    for (int i = 0; i < n; i++) {
        // 累加当前元素的银行账户和储蓄账户金额
        total += money[i].bankfund + money[i].savefund;
    }
    return total;  // 返回计算结果
}

/*
代码测试及验证建议方案：
1. 基础验证：
   - 编译运行，检查输出是否为$20000.00（验证计算逻辑）
   - 修改结构体数组的初始化值（如调整bankfund数值），观察总和是否同步变化

2. const特性测试：
   - 尝试在sum函数内修改money[i].bankfund（如money[i].bankfund = 0;），查看编译器是否报错（验证const的保护作用）

3. 数组传参对比：
   - 改用&jones[0]作为参数调用sum（sum(&jones[0], N)），观察结果是否相同（验证数组名等价于首元素地址）

4. 边界测试：
   - 修改N为1，只保留一个数组元素，检查计算是否正确
   - 将N改为3，添加第三个funds元素，验证循环是否能正确遍历

5. 成员访问测试：
   - 在主函数中单独打印jones[0].bank和jones[1].save，验证初始化是否正确
   - 故意写错成员名（如bankfund写成bank_fund），观察编译报错信息

6. 扩展练习：
   - 添加新的成员（如char owner[20]记录账户主人），修改初始化和sum函数，验证功能扩展能力
*/