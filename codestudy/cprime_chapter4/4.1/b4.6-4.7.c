#include <stdio.h>

int main(void)
{
    // 1. %d 转换说明：读取有符号十进制整数，跳过前导空白（空格/换行等）
    int num_d;
    printf("输入十进制整数（测试 %%d）：");
    scanf("%d", &num_d);  // 遇    非数字    停止读取，结果存入 num_d
    printf("读取结果（%%d）：%d\n\n", num_d);


    // 2. %f 转换说明：读取 float 类型浮点数（支持整数/小数形式）
    float num_f;
    printf("输入浮点数（测试 %%f）：");
    scanf("%f", &num_f);  // 自动识别小数点，转换为 float 存储
    printf("读取结果（%%f）：%.2f\n\n", num_f);


    // 3. %s 转换说明：读取字符串（从首  非空白   开始，遇空白停止）
    char name[20];  // 需预分配足够空间存储字符串
    printf("输入单个单词（测试 %%s）：");
    scanf("%s", name);  //     空白字符（空格/换行）会终止读取    ，结果存入 name
    printf("读取结果（%%s）：%s\n\n", name);


    // 4. %c 转换说明：读取单个字符（含空白字符，需注意前导空白）
    char ch;
    printf("输入任意字符（含空格，测试 %%c）：");
    // 空格跳过前导空白（避免读取上一次输入的换行符）
    scanf(" %c", &ch);  
    printf("读取结果（%%c）：'%c'\n\n", ch);


    // 5. 数字修饰符（如 %3s）：限制最大读取宽度
    char info[10];
    printf("输入字符（测试 %%3s，最多读3个）：");
    scanf("%3s", info);  // 最多读取3个字符，剩余内容留在输入缓冲区
    printf("读取结果（%%3s）：%s\n\n", info);


    // 6. * 修饰符（抑制赋值）：跳过指定数据，不存储结果
    int skip, keep;
    printf("输入两个整数（测试 %%*d 跳过第一个）：");
    // %*d 读取整数但不赋值，第二个整数存入 keep
    scanf("%*d %d", &keep);  
    printf("实际保留的整数（%%*d）：%d\n\n", keep);


    // 7. hh 修饰符：读取 signed char / unsigned char 类型
    signed char sc;
    unsigned char uc;
    printf("输入两个整数（测试 %%hhd 和 %%hhu）：");
    // %hhd 转换为 signed char，%hhu 转换为 unsigned char
    scanf("%hhd %hhu", &sc, &uc);  
    printf("signed char 结果（%%hhd）：%d\n", sc);   // 按有符号解析输出
    printf("unsigned char 结果（%%hhu）：%d\n", uc); // 按无符号解析输出（显示 ASCII 码值）

    return 0;
}