// ------------------------------
// 题干：13. 用变长数组（VLA）代替标准数组，完成编程练习12。
// 知识要点：
//  1. 变长数组（VLA）的定义与使用（C99及以上支持，大小运行时确定）
//  2. 同题目12的文件操作、字符映射、二维数组遍历
// 总体逻辑：
//  1. 定义行数和列数为变量（如rows=20，cols=30），用VLA定义int数组和char数组。
//  2. 其余步骤与题目12一致：读文件、转换字符、输出。

#include <stdio.h>

int main() {
    // 定义数组大小（运行时确定，此处写死为20行30列）
    int rows = 20;
    int cols = 30;
    
    // 变长数组（VLA）：运行时分配内存，大小由rows/cols决定
    int data[rows][cols];  // 存储原始数字
    char symbols[] = " .:~*=+###";  // 字符映射表
    
    // 步骤1：读取输入文件
    const char *input_file = "data.txt";
    FILE *fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        printf("无法打开输入文件 %s\n", input_file);
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp_in, "%d", &data[i][j]);
        }
    }
    fclose(fp_in);
    
    // 步骤2：转换为字符数组（VLA，每行cols+1列存'\0'）
    char chars[rows][cols + 1];  // 每行31列（30字符 + 1个'\0'）
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            chars[i][j] = symbols[data[i][j]];
        }
        chars[i][cols] = '\0';  // 每行末尾加结束符
    }
    
    // 步骤3：输出到屏幕和文件
    const char *output_file = "output_vla.txt";
    FILE *fp_out = fopen(output_file, "w");
    if (fp_out == NULL) {
        printf("无法打开输出文件 %s\n", output_file);
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        printf("%s\n", chars[i]);
        fprintf(fp_out, "%s\n", chars[i]);
    }
    fclose(fp_out);
    
    return 0;
}

// 测试验证方案：
//  1. 怎么运行：
//     - 同题目12准备data.txt，编译需支持C99（如gcc -std=c99 13.c -o 13）。
//     - 运行生成output_vla.txt，对比题目12的output.txt，内容应一致。
//  2. 检查点：
//     - 确认编译器支持VLA（如GCC默认支持，MSVC不支持，需换编译器）。
//     - 观察数组大小是否由变量rows/cols决定，而非编译时常量。
// 易错点提醒：
//  1. VLA兼容性：MSVC不支持VLA，需用GCC/Clang编译。
//  2. 栈溢出风险：VLA在栈上分配，若rows/cols过大（如1000×1000），可能栈溢出，建议改用malloc。
//  3. 变量定义顺序：VLA的大小必须是运行时确定的变量，且定义在变量之后（C99要求）。
// 拓展思考：
//  1. 若数组过大，如何避免栈溢出？用动态分配：int (*data)[cols] = malloc(rows * sizeof(*data))。
//  2. 对比VLA与静态数组：静态数组大小编译时确定，VLA更灵活但受栈大小限制。
//  3. C11中VLA是可选特性，未来可能废弃，如何替代？用malloc/calloc动态分配。