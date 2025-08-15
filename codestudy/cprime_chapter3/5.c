#include <stdio.h>
int main() {
    double p;
    printf("Enter a floating-point value: ");
    scanf("%lf", &p);
    printf("fixed-point notation: %f\n", p);
    printf("exponential notation: %e\n", p);
    // 检查系统是否支持 p 记数法（C99 及以上支持 ）
    #if __STDC_VERSION__ >= 199901L
    printf("p notation: %a\n", p); 
    #endif
    return 0;
}
