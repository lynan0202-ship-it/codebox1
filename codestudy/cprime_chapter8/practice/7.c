
/* 
问题7题干：修改第7章的编程练习8，用字符代替数字标记菜单的选项。用q代替5作为结束输入的标记。

知识要点：
1. 菜单交互逻辑：从数字选项改为字符选项
2. 输入处理：使用字符（如 'a', 's', 'm', 'd', 'q'）作为菜单选择
3. 循环控制：通过字符判断退出（'q' 退出）
4. 功能复用：保留原菜单的加法、减法、乘法、除法功能

总体逻辑：
1. 显示字符标记的菜单（a:add, s:subtract, m:multiply, d:divide, q:quit）
2. 获取用户输入的字符选择
3. 根据选择执行对应运算或退出程序
4. 处理输入错误（非菜单字符）

代码功能：
实现字符标记的菜单驱动计算器，支持基本算术运算
*/

#include <stdio.h>

int main() {
    char choice;
    double num1, num2, result;

    // 显示菜单
    printf("=== Character Menu Calculator ===\n");
    printf("a. add\n");
    printf("s. subtract\n");
    printf("m. multiply\n");
    printf("d. divide\n");
    printf("q. quit\n");
    printf("Enter your choice: ");

    while ((choice = getchar()) != 'q') {
        // 清理缓冲区残留的换行符
        while (getchar() != '\n') continue;

        switch (choice) {
            case 'a':
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 's':
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 'm':
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 'd':
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                // 处理除数为0的情况
                while (num2 == 0) {
                    printf("Error: Division by zero! Enter a non-zero number: ");
                    scanf("%lf", &num2);
                }
                result = num1 / num2;
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                break;
            default:
                printf("Invalid choice. Please enter a, s, m, d, or q.\n");
        }

        // 显示菜单并等待下一次选择
        printf("\n=== Menu ===\n");
        printf("a. add\n");
        printf("s. subtract\n");
        printf("m. multiply\n");
        printf("d. divide\n");
        printf("q. quit\n");
        printf("Enter your choice: ");

        // 清理缓冲区残留的换行符（如果有）
        while (getchar() != '\n') continue;
    }

    printf("Bye!\n");
    return 0;
}

/* 
测试验证方案：
1. 正常运算测试：
   - 输入 'a'，执行加法：输入 5 和 3，检查结果是否为 8.00
   - 输入 's'，执行减法：输入 10 和 4，检查结果是否为 6.00
   - 输入 'm'，执行乘法：输入 3 和 7，检查结果是否为 21.00
   - 输入 'd'，执行除法：输入 8 和 2，检查结果是否为 4.00；测试除数为0的情况，确保程序提示重新输入

2. 退出测试：
   - 输入 'q'，检查程序是否退出并显示 "Bye!"

3. 错误输入测试：
   - 输入 'x'（无效选项），检查是否提示重新输入
   - 输入非数字字符作为运算数，检查程序行为（需额外处理，本题简化，实际可增强输入验证）

4. 连续操作测试：
   - 完成一次运算后，检查是否能继续选择其他操作
*/