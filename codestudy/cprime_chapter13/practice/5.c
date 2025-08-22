// ------------------------------
// 题干：5. 修改程序清单13.5中的程序，用命令行界面代替交互式界面。（假设13.5是算术运算程序，如加减）
// 知识要点：
//  1. 命令行参数解析（strcmp判断操作）
//  2. 字符串转数值（atoi）
//  3. 条件分支（if-else处理不同操作）
// 总体逻辑：
//  1. 检查参数数量 → 2. 解析操作和数值 → 3. 执行运算并输出结果
#include <stdio.h>
#include <stdlib.h> // atoi
#include <string.h> // strcmp

int main(int argc, char *argv[]) {
    if (argc != 4) { // 格式：程序 操作 数1 数2
        printf("用法：%s [add/sub] 数字1 数字2\n", argv[0]);
        return 1;
    }
    
    char *op = argv[1];
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);
    
    if (strcmp(op, "add") == 0) {
        printf("%d + %d = %d\n", num1, num2, num1+num2);
    } else if (strcmp(op, "sub") == 0) {
        printf("%d - %d = %d\n", num1, num2, num1-num2);
    } else {
        printf("不支持的操作：%s\n", op);
        return 1;
    }
    return 0;
}

// 测试验证方案：
//  1. 运行：./a.out add 10 20 → 预期30；./a.out sub 50 30 → 预期20
//  2. 检查：运算结果是否正确，参数错误时提示是否清晰
// 易错点提醒：
//  1. 忘记包含stdlib.h/string.h，导致atoi/strcmp未定义
//  2. 用==比较字符串（如if(op=="add")），应改用strcmp
//  3. 参数数量判断错误（如argc写成3）
// 拓展思考：
//  1. 如何支持乘除？（添加else if分支）
//  2. 如何支持浮点数？（改用atof，输出%f）
// 对比说明：
//  交互模式适合手动操作，命令行模式适合脚本调用，前者实时输入，后者参数化执行。