#include <stdio.h>
// 需包含 float.h 查看精度宏
#include <float.h>  

int main(void) {
    double d_val = 1.0/3.0;
    float f_val = 1.0f/3.0f;

    // 显示 6、12、16 位小数
    printf("double (6位小数): %.6f\n", d_val);
    printf("float  (6位小数): %.6f\n", f_val);

    printf("double (12位小数): %.12f\n", d_val);
    printf("float  (12位小数): %.12f\n", f_val);

    printf("double (16位小数): %.16f\n", d_val);
    printf("float  (16位小数): %.16f\n", f_val);

    // 显示 FLT_DIG（float 有效位数）和 DBL_DIG（double 有效位数）
    printf("FLT_DIG = %d, DBL_DIG = %d\n", FLT_DIG, DBL_DIG);

    return 0;
}
/*
double (6位小数): 0.333333
float  (6位小数): 0.333333
double (12位小数): 0.333333333333
float  (12位小数): 0.333333343267
double (16位小数): 0.3333333333333333
float  (16位小数): 0.3333333432674408
*/