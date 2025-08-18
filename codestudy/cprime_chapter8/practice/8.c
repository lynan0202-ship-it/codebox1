/* 
问题8题干：编写一个程序，显示一个提供加法、减法、乘法、除法的菜单。获得用户选择的选项后，程序提示用户输入两个数字，然后执行运算。程序使用float类型的变量存储用户输入的数字，如果用户输入失败，则允许再次输入。进行除法运算时，如果用户输入0作为第2个数（除数），程序应提示用户重新输入一个新值。

知识要点：
1. 菜单交互：数字或字符标记菜单选项（本题用数字示例，也可扩展为字符）
2. 输入验证：处理用户输入失败（如输入非数字字符）
3. 循环控制：允许用户多次选择操作，直到退出
4. 除法特殊处理：除数不能为0，需提示重新输入

总体逻辑：
1. 显示菜单（1:add, 2:subtract, 3:multiply, 4:divide, 5:quit）
2. 获取用户输入的菜单选项
3. 根据选项提示输入两个数字，执行运算或退出
4. 处理输入错误（非数字、除数为0等）

代码功能：
实现菜单驱动的计算器，支持基本算术运算和输入验证
*/

#include <stdio.h>

// 函数声明：获取有效的float输入
float get_valid_float(const char *prompt);

int main() {
    int choice;
    float num1, num2, result;

    // 显示菜单
    printf("=== Menu ===\n");
    printf("1. add\n");
    printf("2. subtract\n");
    printf("3. multiply\n");
    printf("4. divide\n");
    printf("5. quit\n");
    printf("Enter your choice: ");

    while (scanf("%d", &choice) == 1) {
        if (choice == 5) {
            printf("Bye!\n");
            break;
        }

        // 清理缓冲区残留的换行符
        while (getchar() != '\n') continue;

        switch (choice) {
            case 1:
                num1 = get_valid_float("Enter first number: ");
                num2 = get_valid_float("Enter second number: ");
                result = num1 + num2;
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                num1 = get_valid_float("Enter first number: ");
                num2 = get_valid_float("Enter second number: ");
                result = num1 - num2;
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                num1 = get_valid_float("Enter first number: ");
                num2 = get_valid_float("Enter second number: ");
                result = num1 * num2;
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                num1 = get_valid_float("Enter first number: ");
                // 处理除数为0的情况
                while (1) {
                    num2 = get_valid_float("Enter second number: ");
                    if (num2 != 0) {
                        break;
                    }
                    printf("Error: Division by zero! Enter a non-zero number: ");
                }
                result = num1 / num2;
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                break;
            default:
                printf("Invalid choice. Please enter 1-5.\n");
        }

        // 显示菜单并等待下一次选择
        printf("\n=== Menu ===\n");
        printf("1. add\n");
        printf("2. subtract\n");
        printf("3. multiply\n");
        printf("4. divide\n");
        printf("5. quit\n");
        printf("Enter your choice: ");
    }

    // 处理非数字输入导致的退出
    printf("Invalid input. Bye!\n");
    return 0;
}

// 函数定义：获取有效的float输入，处理输入失败的情况
float get_valid_float(const char *prompt) {
    float num;
    while (printf("%s", prompt) && scanf("%f", &num) != 1) {
        // 清理缓冲区残留的错误输入
        while (getchar() != '\n') continue;
        printf("Invalid input. Please enter a number: ");
    }
    return num;
}

/* 
测试验证方案：
1. 正常运算测试：
   - 选择加法（1），输入 2.5 和 3.7，检查结果是否为 6.20
   - 选择减法（2），输入 10.0 和 4.5，检查结果是否为 5.50
   - 选择乘法（3），输入 3.0 和 6.0，检查结果是否为 18.00
   - 选择除法（4），输入 8.0 和 2.0，检查结果是否为 4.00；测试除数为0的情况，确保程序提示重新输入

2. 退出测试：
   - 选择 5，检查程序是否退出并显示 "Bye!"

3. 输入验证测试：
   - 输入非数字字符（如 'abc'）作为运算数，检查程序是否提示重新输入
   - 输入多个错误后，检查是否仍能继续操作

4. 连续操作测试：
   - 完成一次运算后，检查是否能继续选择其他操作，输入新的数字执行运算

5. 边界值测试：
   - 输入极大或极小的浮点数（如 1e30 和 1e-30），检查运算结果是否合理
*/