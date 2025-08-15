  #include <stdio.h>
int main(void)
{
    int cost = 12.99;
    float num = 3.14159269887987249;
    /* C99 为类型大小提供 %zd 转换说明 */
    printf("Type int has a size of %zd bytes.\n", sizeof(int));
    printf("Type char has a size of %zd bytes.\n", sizeof(char));
    printf("Type long has a size of %zd bytes.\n", sizeof(long));
    printf("Type long long has a size of %zd bytes.\n", sizeof(long long));
    printf("Type double has a size of %zd bytes.\n", sizeof(double));
    printf("Type long double has a size of %zd bytes.\n", sizeof(long double));
    printf("my cost is %d \n and my num is %f \n",cost,num);

    return 0;
}
