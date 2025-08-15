/*pizza.c--在比萨饼程序中使用已经定义的常量*/
#include<stdio.h>
#define PI 3.141592
int main (void)
{
    float area,circum,radius;
    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);
    area = PI *2.0 * radius;
    circum =2.0  * PI * radius;
    printf( "your pizza are follows:");
    printf("circumference = %1.2f, area = %1.2f\n",circum, area);

    return 0;

}