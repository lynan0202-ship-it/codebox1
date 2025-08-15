#include<stdio.h>
int main(void)
{
    //使用short修饰int类型，表示短整型，占用的内存空间比int小，表示范围比int小

    //unsigned 修饰一个非负的整数 age 数羊的 业务逻辑
    unsigned short int num = 1111;//
    //使用long修饰int类型，表示长整型，占用的内存空间比int大，表示的范围比int大
    unsigned long long int num2 = 10000;

    unsigned long long num3 = 33ULL;

    printf("num3=%d\n",num3);//打印出一个有问题的值。

    return 0;
}