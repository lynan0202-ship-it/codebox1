/*
请输入一个浮点数：6.3452
The input is 6.3 or 6.3e+000.
The input is +6.345 or +6.345e+000.
*/
#include <stdio.h>

int main(void) {
    double num;
    printf("请输入一个浮点数：");
    scanf("%lf", &num);

    // a. 小数点表示 + 指数表示（简短）
    printf("The input is %.1f or %.1e.\n", num, num);

    // b. 带符号小数点 + 指数表示（更多小数位）
    printf("The input is %+.3f or %+.3e.\n", num, num);

    return 0;
}
/*
请输入一个浮点数：3.12425
The input is 3.1 or 3.1e+000.
The input is +3.124 or +3.124e+000.
*/