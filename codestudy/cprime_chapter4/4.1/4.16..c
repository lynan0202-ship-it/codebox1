//第一段代码（演示 printf 动态格式控制）

/*
核心体现 printf 中 * 修饰符的动态控制作用：%*d 让字段宽度由变量 width 决定，%*.*f 让总宽度、小数精度分别由 width 和 precision 决定，摆脱写死格式的限制。
输入驱动输出：通过两次 scanf 获取不同的格式控制参数，对应教程里 “程序运行时动态决定格式化信息” 的讲解逻辑，让用户输入参与格式化输出的规则设定。
第二段代码（
*/

#include <stdio.h>
int main(void)
{
    // 用于存储字段宽度
    unsigned width, precision;
    // 定义一个整数，后续用于演示按指定宽度输出
    int number = 256;
    // 定义一个浮点数，后续用于演示按指定宽度和精度输出
    double weight = 242.5;

    // 提示用户输入用于控制输出宽度的字段宽度值
    printf("Enter a field width:\n");
    // 读取用户输入的字段宽度，存入 width 变量
    scanf("%d", &width);
    // 使用 %*d 格式，* 会用 width 的值作为字段宽度，输出 number 的值
    printf("The number is: %*d\n", width, number);

    // 提示用户输入用于控制浮点数输出的宽度和精度值
    printf("Now enter a width and a precision:\n");
    // 读取两个整数，分别存入 width（控制整体宽度）和 precision（控制小数位数）
    scanf("%d %d", &width, &precision);
    // %*.*f 中，第一个 * 用 width 控制输出总宽度，第二个 * 用 precision 控制小数位数，输出 weight 
    printf("Weight = %*.*f\n", width, precision, weight);
    printf("Done!\n");

    return 0;
}
/*
Enter a field width:
4
The number is:  256
Now enter a width and a precision:
5 2
Weight = 242.50
Done!
*/