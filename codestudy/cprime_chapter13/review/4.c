// ------------------------------
// 题干：计算输入浮点数的平均值（支持文件或标准输入）
// 知识要点：
//  1. 命令行参数：argc判断输入来源（文件/标准输入）
//  2. 文件操作：fopen打开文件，fscanf读浮点数
//  3. 统计计算：累加和、计数，避免除以0
// 总体逻辑：
//  1. 判断参数，选择输入源（文件或stdin）
//  2. 循环读浮点数，累加和、计数
//  3. 计算并输出平均值（处理无数据情况）
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *input;     // 输入源（文件或stdin）
    double num, sum = 0.0; // 存储数字、累加和
    int count = 0;   // 数字个数

    // 选择输入源：无参数用stdin，有参数则打开文件
    if (argc == 1) {
        input = stdin;
    } else if (argc == 2) {
        input = fopen(argv[1], "r");
        if (input == NULL) {
            printf("无法打开文件：%s\n", argv[1]);
            exit(1);
        }
    } else {
        printf("用法：%s [文件名]\n", argv[0]);
        exit(1);
    }

    // 循环读浮点数，累加和、计数
    while (fscanf(input, "%lf", &num) == 1) {
        sum += num;
        count++;
    }

    // 关闭文件（非stdin时）
    if (input != stdin) fclose(input);

    // 输出结果（处理无数据情况）
    if (count == 0) {
        printf("无有效数据！\n");
    } else {
        double avg = sum / count;
        printf("个数：%d，总和：%.2f，平均值：%.2f\n", count, sum, avg);
    }

    return 0;
}

// 测试验证方案：
//  1. 运行1（标准输入）：执行程序，输入1.5 2.5 3.0，按Ctrl+D结束
//     预期：个数3，总和7.0，平均2.33
//  2. 运行2（文件输入）：创建data.txt（写"10 20 30"），执行./a.out data.txt
//     预期：个数3，总和60.0，平均20.0
//  3. 检查：对比输入和计算结果
// 易错点提醒：
//  1. 用%f而非%lf读double（类型不匹配）
//  2. 忘记处理count=0（除以0崩溃）
// 拓展思考：
//  1. 若输入含非数字，可通过fscanf返回值判断错误
// ------------------------------