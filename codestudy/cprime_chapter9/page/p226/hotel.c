/* 
知识要点总结（函数实现模块）：
1. 函数定义与头文件关联：
   - 实现 `hotel.h` 中声明的 `menu`、`getnights`、`showprice` 函数，函数定义的返回值类型、参数列表必须和头文件声明一致，否则编译器报错，保证接口统一。
2. 输入处理技巧：
   - `menu` 函数中通过 `scanf` 的返回值（成功读取的输入项数 ）判断用户输入是否合法（是否是整数、是否在 1 - 5 范围内 ）；遇到非法输入（如字母 ），用 `scanf("%*s")` 跳过无效输入，让程序能继续接收正确输入，避免死循环。
   - `getnights` 函数同样利用 `scanf` 返回值处理非整数输入，提示用户重新输入，保证获取的入住天数是合法整数。
3. 业务逻辑实现：
   - `showprice` 函数根据“每日房价 * 折扣率^（天数 - 1）”的规则计算总费用（第 1 天无折扣，第 2 天 95 折，第 3 天 95 折的 95 折，以此类推 ），用循环实现累计计算，体现业务逻辑与函数的封装。

本文件总体逻辑：
专注实现头文件声明的函数功能，`menu` 负责交互显示菜单、校验输入；`getnights` 负责获取合法入住天数；`showprice` 负责计算并展示费用。每个函数完成单一任务，让代码模块化、易维护。
*/

#include "hotel.h"  // 包含自定义头文件，使用其中的常量和函数声明
#include <stdio.h>

// 显示菜单并获取用户选择（返回酒店编号，5 表示退出）
int menu(void)
{
    int code, status;
    printf("\n%s\n", STARS);  // 打印装饰星号
    printf("Enter the number of the desired hotel:\n");
    printf("1) Fairfield Arms     2) Hotel Olympic\n");
    printf("3) Chertworthy Plaza  4) The Stockton\n");
    printf("5) quit\n");
    printf("%s\n", STARS);

    // 循环校验输入：必须是 1-5 的整数
    while ((status = scanf("%d", &code)) != 1 || (code < 1 || code > 5))
    {
        if (status != 1)  // 如果不是整数输入
        {
            scanf("%*s");  // 跳过无效的非整数输入（如字母、字符串 ）
        }
        printf("Enter an integer from 1 to 5, please.\n");
    }
    return code;
}

// 获取用户输入的入住天数（处理非整数输入，保证返回合法整数）
int getnights(void)
{
    int nights;
    printf("How many nights are needed? ");
    // 循环校验：必须输入整数
    while (scanf("%d", &nights) != 1)
    {
        scanf("%*s");  // 跳过非整数输入
        printf("Please enter an integer, such as 2.\n");
        printf("How many nights are needed? ");
    }
    return nights;
}

// 计算并显示总费用：房价每天打 DISCOUNT 折扣（第 1 天原价，第 2 天 rate*DISCOUNT，第 3 天 rate*DISCOUNT^2 ，以此类推 ）
void showprice(double rate, int nights)
{
    int n;
    double total = 0.0;
    double factor = 1.0;  // 折扣因子，第 1 天 factor=1（无折扣 ）

    for (n = 1; n <= nights; n++, factor *= DISCOUNT)
    {
        total += rate * factor;  // 每天费用累加（第 n 天费用：rate * DISCOUNT^(n-1) ）
    }
    printf("The total cost will be $%.2f.\n", total);
}