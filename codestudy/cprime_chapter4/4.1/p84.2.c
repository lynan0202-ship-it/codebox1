#include <stdio.h>
// 用于本地化设置（实际演示需包含）
#include <locale.h>  
// 用 #define 定义数值常量（宏常量）
#define PI 3.14159  

int main(void) {
    // 1. 字符与字符串基础
    // 单个字符（ASCII 存储）
    char initial = 'A';  
    // 字符串：字符数组 + 末尾 '\0'（实际存储 "Hi\0"）
    char greeting[10] = "Hi";  

    // 2. 常量定义
    // const 定义只读变量（符号常量）
    const double E = 2.71828;  
    // #define 的宏常量，直接替换
    double circle_area = PI * 5 * 5;  


    // 3. scanf 行为演示（模拟输入：-13.45e12# 0）
    int num;        // 存 %d 读取结果
    float f_num;    // 存 %f 读取结果
    char str[20];   // 存 %s 读取结果
    char first_ch;  // 存 %c 读取结果
    // 模拟用户输入的字符串（等效控制台输入 "-13.45e12# 0"）
    char input_buf[] = "-13.45e12# 0";  


    // 4. 本地化设置（示例：荷兰环境，逗号分隔小数）
    // 设置本地化：荷兰语（需系统支持，实际可能需管理员权限/环境配置）
    setlocale(LC_NUMERIC, "nl_NL");  


    // ========== 功能演示分割线 ==========

    // 演示 1：字符与字符串输出
    printf("单个字符：%c\n", initial);          // 输出 'A'
    // %s 自动识别 '\0'，输出 "Hi"
    printf("字符串：%s\n", greeting);          

    // 演示 2：常量使用
    printf("宏常量 PI = %f\n", PI);            // 输出 3.141590
    printf("const 常量 E = %f\n", E);          // 输出 2.718280
    printf("圆面积（PI*5^2） = %f\n", circle_area);  

    // 演示 3：scanf 行为（用 sscanf 模拟从字符串读，等效控制台输入）
    // %d：读 "-13"，遇 '.' 停止，残留 ".45e12# 0"
    sscanf(input_buf, "%d", &num);             
    printf("%%d 读取结果：num = %d\n", num);    // 输出 -13

    // %f：读 "-13.45e12"，遇 '#' 停止，残留 "# 0"
    sscanf(input_buf, "%f", &f_num);           
    printf("%%f 读取结果：f_num = %f\n", f_num); // 输出 -13.450000（科学计数法转普通浮点）

    // %s：读 "-13.45e12#"，遇空格（示例无空格，实际遇空白停止），残留 " 0"
    sscanf(input_buf, "%s", str);              
    printf("%%s 读取结果：str = %s\n", str);    // 输出 "-13.45e12#"

    // %c：直接读第一个字符（此处是 '-'），不跳过空白
    sscanf(input_buf, "%c", &first_ch);        
    printf("%%c 读取结果：first_ch = %c\n", first_ch); // 输出 '-'

    // 演示 4：本地化效果（荷兰环境，输出逗号分隔浮点数）
    // 荷兰环境下，printf 会用逗号替代小数点
    printf("荷兰本地化输出 PI：%f\n", PI);     


    return 0;
}

/*
单个字符：A
字符串：Hi
宏常量 PI = 3.141590
const 常量 E = 2.718280
圆面积（PI*5^2） = 78.539750
%d 读取结果：num = -13
%f 读取结果：f_num = -13450000465920.000000
%s 读取结果：str = -13.45e12#
%c 读取结果：first_ch = -
荷兰本地化输出 PI：3.141590
*/