#include<stdio.h>
int main(void)
{
    int i = 1;
    float n;
    printf("Watch out! Here come a bunch of fractions!\n");
    while (i < 30)
    {
        // 错误 1：1/i 是整数除法，结果多为 0，应写 1.0/i 转浮点数运算
        n = 1.0 / i;  
        printf("%f\n", n);
        // 错误 2：i 没自增，循环会无限执行，要加 i++
        i++;  
    }
    printf("That's all, folks!\n");
    // 错误 3：return 要带返回值，main 是 int 类型，应 return 0; 
    return 0;  
}
/*
Watch out! Here come a bunch of fractions!
1.000000
0.500000
0.333333
0.250000
0.200000
0.166667
0.142857
0.125000
0.111111
0.100000
0.090909
0.083333
0.076923
0.071429
0.066667
0.062500
0.058824
0.055556
0.052632
0.050000
0.047619
0.045455
0.043478
0.041667
0.040000
0.038462
0.037037
0.035714
0.034483
*/