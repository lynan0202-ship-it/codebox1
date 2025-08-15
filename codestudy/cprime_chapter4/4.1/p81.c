//1.输入角度看scanf（）
#include <stdio.h>
int main (void)
{
    int  age ;
    scanf("%d",&age);
    printf("age=%d\n",age);


/*
    int  age1 ;
    scanf("%5d",&age1);
    printf("age1=%d\n",age1);
    */
    /*char name[40];
    scanf("%s",name);

    printf("name=%s\n",name);
*/
    return 0;

}
/*
       123
age=123

123abcd
age=123


123
age=123
123456
age=12345


A 123第一个错误其余也无法输入
age=0
age1=16

12 34
age=12



*/